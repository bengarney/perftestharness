#include "harness/performanceHarness.h"
#include <process.h>
#define _WIN32_WINNT 0x400 
#include <stdio.h>
#include <windows.h>

HANDLE g_threadHandleA=0;
HANDLE g_threadHandleB=0;
HANDLE g_threadHandleC=0;
HANDLE g_threadHandleD=0;

unsigned int g_Ctr = 0;

unsigned __stdcall  MyReader(LPVOID lpParameter);
unsigned __stdcall  MyWriter(LPVOID lpParameter);

int g_ThreadOut = 0;

#define BLOCK_LENGTH 10
#define ARRAY_SIZE 10

struct CBlock
{
	CRITICAL_SECTION m_CS;
	int m_Member[BLOCK_LENGTH];
	int m_Ctr;
	__declspec(align(64)) bool m_Dirty;
	__declspec(align(64)) bool m_WriteLocked;
	__declspec(align(64)) bool m_ReadLocked;

	CBlock(){InitializeCriticalSection(&m_CS); m_Ctr = 0;m_Dirty=false; m_WriteLocked=false;m_ReadLocked=false;}
	
	bool WLock(){	
					bool ret = ( m_Dirty==false&&TryEnterCriticalSection(&m_CS)==TRUE );
					
					if( ret )
					{
						m_Ctr=0;
						m_Dirty=true;
						m_WriteLocked=true;
					}

					return ret;
				}

	bool WUnLock()
				{
					if( m_WriteLocked )
					{	
						m_WriteLocked = false;
						LeaveCriticalSection(&m_CS);
						
					}else
					{
						return false;//can't unlock the unlocked
					}

					return true;
				}

	bool RLock()
				{ 
					bool ret = ( m_Dirty==true&&TryEnterCriticalSection(&m_CS)==TRUE );
					
					if( ret )
					{
						m_ReadLocked=true;
					}

					return ret;
				}

	bool RUnLock()
				{
					if( m_ReadLocked )
					{	
						m_Dirty=false;
						m_ReadLocked = false;
						LeaveCriticalSection(&m_CS);
						

					}else
					{
						return false;//can't unlock the unlocked
					}

					return true;
				}

	bool Add( int val )
	{	
		
		if( m_Ctr<BLOCK_LENGTH )
		{
			m_Member[m_Ctr] = val;
			m_Ctr++;
			return true;

		}else
		return false;
	}
	
	bool Remove( int& val )
	{	
		if( m_Ctr>0 )
		{
			m_Ctr--;
			val = m_Member[m_Ctr];
			return true;

		}else
		return false;
	}
};


class ThreadedStream
{
public:
	__declspec(align(64)) volatile long m_WritePos;//ewww fals sharing
	__declspec(align(64)) volatile long int m_ReadPos;

	CBlock m_Data[ARRAY_SIZE];
	
	void Init(){ 
					m_WritePos = 0;
					m_ReadPos = 0;
				}

	bool WriteInt( int val, int& address );
	bool ReadInt(  int &retVal, int& block );
	void CloseStream( int address );
};

bool ThreadedStream::WriteInt( int writeVal, int& address )
{
	
	if( address==-1 )
	{
		address = InterlockedIncrement(&m_WritePos);//make thread safe increment
		address %= ARRAY_SIZE;

		//acquire the lock
		if( m_Data[address].WLock() )
		{
			printf("WLock %i\n",address);
		}else
		{
			address = -1;//failed lock
			return false;
		}
						
	}
	
	if( !m_Data[address].Add(writeVal) )
	{	
		if( m_Data[address].WUnLock() )//this addres is now availble for readers.
		{	
			printf("WUnLock %i\n",address);
			//allocate a new block
			address = -1;
		}else
		{
			address = -1;
			return false;
		}
	}

	return true;
}

void ThreadedStream::CloseStream( int address )
{
	if( m_Data[address].WUnLock() )//this addres is now availble for readers.
	{	
		printf("WUnLock %i\n",address);
		//allocate a new block
		address = -1;
	}
}

bool ThreadedStream::ReadInt( int &readVal, int& address )
{
	if( address==-1 )
	{
		address = InterlockedIncrement(&m_ReadPos);//make thread safe increment
		address %= ARRAY_SIZE;

		//acquire the lock
		if( m_Data[address].RLock() )
		{
			printf("RLock %i\n",address);
		}else
		{
			address = -1;//
			return false;
		}				
	}

	if( !m_Data[address].Remove(readVal) )
	{	
		if( m_Data[address].RUnLock() )//this addres is now availble for writers.
		{	
			printf("RUnLock %i\n",address);
			//allocate a new block
			address = -1;
		}else
		{
			return false;
		}
	}

	return true;
}

PERFORMANCE_TEST("threading/writeReader", writeReader,13000)
{
	ThreadedStream m_ReadWriter;

void test()
{g_ThreadOut=0;
	ResumeThread( g_threadHandleA );
	ResumeThread( g_threadHandleB );
    ResumeThread( g_threadHandleC );
	ResumeThread( g_threadHandleD );

	WaitForSingleObject(g_threadHandleA,INFINITE);
	WaitForSingleObject(g_threadHandleB,INFINITE);
	WaitForSingleObject(g_threadHandleC,INFINITE);
	WaitForSingleObject(g_threadHandleD,INFINITE);

	printf("%i\n",g_ThreadOut);
}

virtual void initialize()
{
	m_ReadWriter.Init();
	unsigned int dwThreadID = 0;
	g_threadHandleA = (HANDLE)_beginthreadex(0, 0, &MyReader, &this->m_ReadWriter,  CREATE_SUSPENDED , &dwThreadID);
	g_threadHandleB = (HANDLE)_beginthreadex(0, 0, &MyReader, &this->m_ReadWriter,  CREATE_SUSPENDED , &dwThreadID);
	g_threadHandleC = (HANDLE)_beginthreadex(0, 0, &MyWriter, &this->m_ReadWriter,  CREATE_SUSPENDED , &dwThreadID);
	g_threadHandleD = (HANDLE)_beginthreadex(0, 0, &MyWriter, &this->m_ReadWriter,  CREATE_SUSPENDED , &dwThreadID);
}

static int getIndependentVariableMin()
{
  return 1;
}

static int getIndependentVariableMax()
{
  return 20;
}

void setIndependentVariable(int v)
{
  
}

static const char * getIndependentVariableName()
{
  return "";
}
};


unsigned __stdcall  MyReader(LPVOID lpParameter)
{
	ThreadedStream* q = (ThreadedStream*)lpParameter;

	int ret = 0;
	int address = -1;

	for( int i=0;i<10000;i++ )
	{
		while( !q->ReadInt( ret,address )){}
		g_ThreadOut+=ret;

	}

	return 1;
}

unsigned __stdcall  MyWriter(LPVOID lpParameter)
{
	ThreadedStream* q = (ThreadedStream*)lpParameter;
	int address = -1;

	for( int i=0;i<10000;i++ )
	{
		while(!q->WriteInt( 1,address )){};
		g_Ctr++;
	}

	q->CloseStream(address);

	return 1;
}


