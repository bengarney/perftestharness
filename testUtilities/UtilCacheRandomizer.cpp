#include <stdlib.h>
#include <stdio.h>
#include "UtilCacheRandomizer.h"

UtilCacheRandomizer::UtilCacheRandomizer()
{
	m_NumBytes = 0;
}

UtilCacheRandomizer::~UtilCacheRandomizer()
{

}

int UtilCacheRandomizer::ScrambleCache()
{
	int ret = 0;
	for( unsigned int i=0;i<m_NumBytes;i+=8 )
	{
		ret+=m_pArray[i];
	}

	delete[] m_pArray;
	printf("Cache Scramble  %i", ret );

	return ret;
}


void UtilCacheRandomizer::Init( unsigned int numBytes )
{
	m_NumBytes = numBytes;

	m_pArray = new unsigned char[numBytes];
	for( unsigned int i=0;i<numBytes;i++ )
	{
		m_pArray[i]=rand();
	}
}