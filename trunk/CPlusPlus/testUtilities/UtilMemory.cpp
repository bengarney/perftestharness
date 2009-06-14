#include "mtwist/mtwist.h"
#include "UtilMemory.h"

static int gIStaticData64Bytes[16];
static float gFStaticData64Bytes[16];
__declspec(align(16)) static float gFStaticData64ABytes[16];
__declspec(align(16)) static char gData[UtilMemory::BufferSize];
__declspec(align(16)) static char gAccess[UtilMemory::BufferSize];

UtilMemory::UtilMemory()
{
}

UtilMemory::~UtilMemory()
{
}

void* UtilMemory::Get16ByteAlignedDataBuffer()
{
	return gData;
}

int* UtilMemory::Get16ByteAlignedAccessBuffer()
{
   return (int*)gAccess;
}

int* UtilMemory::GetIStatic64Bytes()
{
	return gIStaticData64Bytes;
}

float* UtilMemory::GetFStatic64Bytes()
{
	return gFStaticData64Bytes;
}

float* UtilMemory::GetFStatic64BytesAligned()
{
	return gFStaticData64ABytes;
}

void UtilMemory::FillAccessBufferWithRandomRange( int min, int max, int count)
{
   mt_bestseed();
   int *accessPattern = (int*)gAccess;
   for(int i=0; i<count; i++)
      accessPattern[i] = (mt_lrand() % (max - min)) + min;
}

void UtilMemory::FillDataBufferWithRandomFloats( int count /*= BufferSize / sizeof(float)*/ )
{
   float *data = (float*)gData;
   for(int i=0; i<count; i++)
      data[i] = (float)mt_drand();
}