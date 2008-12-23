#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include "UtilCacheRandomizer.h"
int gCacheRandomizer = 0;

unsigned char m_pArray[MAX_CACHE_SCRAMBLE];

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
	for( unsigned int i=0;i<m_NumBytes;i+=64 )
	{
		ret+=m_pArray[i];
		ret+=m_pArray[i+8];
		ret+=m_pArray[i+16];
		ret+=m_pArray[i+32];
		ret+=m_pArray[i+40];
		ret+=m_pArray[i+48];
		ret+=m_pArray[i+56];
	}

	gCacheRandomizer+=ret;
	
    
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
