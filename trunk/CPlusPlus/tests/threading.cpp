#include "harness/performanceHarness.h"
#include <process.h>
#define _WIN32_WINNT 0x400 
#include <windows.h>

#define MAX_NUM_LOOP 100
#define MAX_THREADS 100
HANDLE gThreadHandles[ MAX_THREADS ];

unsigned int m_ID[MAX_THREADS];
unsigned __stdcall  MyThreadProc(LPVOID lpParameter);

int ThreadMemArray[MAX_THREADS][MAX_NUM_LOOP];
__declspec(align(64)) int  gThreadSum[MAX_THREADS];
bool m_NumThreadsSet=false;
unsigned int m_NumThreads=0;

void initCriticalStride( unsigned int id )
{
	for( int j=0;j<id;j++ )
	for( int i=0;i<MAX_NUM_LOOP;i++ )
	{
		ThreadMemArray[j][i]=betterRand();
	}
}

PERFORMANCE_TEST("threading/threadCount", threadCount,13000)
{
   void test()
   {
	   for( int i=0;i<m_NumThreads;i++ )
	   {
			ResumeThread( gThreadHandles[i] );
	   }

	   DWORD ret = WaitForMultipleObjects(m_NumThreads,gThreadHandles,false,INFINITE);
	   int i=0;
   }

   virtual void initialize()
   {
	  if( m_NumThreadsSet==false )
	   {
		   m_NumThreads=0;
		   m_NumThreadsSet = true;
	   }
    
	   m_NumThreads++;

	   unsigned int  g_dwThreadID;

	   for( int i=0;i<m_NumThreads;i++ )
	   {
			initCriticalStride(i);
		    m_ID[i]=i;
			CloseHandle(gThreadHandles[i]);
			gThreadHandles[i] = (HANDLE)_beginthreadex(0, 0, &MyThreadProc, &(m_ID[i]),  CREATE_SUSPENDED , &g_dwThreadID);

	   }
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
      return "NumThreads";
   }
};

unsigned __stdcall  MyThreadProc(LPVOID lpParameter)
{
	unsigned int id = *(unsigned int*)lpParameter;

    for( int i=0;i<MAX_NUM_LOOP;i++ )
	{
		gThreadSum[id] += ThreadMemArray[id][i];
	}

	for( int j=0;j<100000000;j++ )
	for( int i=0;i<MAX_NUM_LOOP;i++ )
	{
		gThreadSum[id] += ThreadMemArray[id][i];
	}

	return 1;
}
