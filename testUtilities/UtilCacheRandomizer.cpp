#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include "UtilCacheRandomizer.h"
int gCacheRandomizer = 0;

unsigned char m_pArray[1024000];

UtilCacheRandomizer::UtilCacheRandomizer()
{
	m_NumBytes = 0;
}

UtilCacheRandomizer::~UtilCacheRandomizer()
{

}

int UtilCacheRandomizer::ScrambleCache()
{
	char ret = 0;
	for( unsigned int i=0;i<m_NumBytes;i+=8 )
	{
		ret+=m_pArray[i];
	}

	Sleep(1);
	gCacheRandomizer+=ret;
	//printf("Clearing Cache\n");
    
	return ret;
}


void UtilCacheRandomizer::Init( unsigned int numBytes )
{
	m_NumBytes = numBytes;

	
	for( unsigned int i=0;i<numBytes;i++ )
	{
		m_pArray[i]=rand();
	}
}
