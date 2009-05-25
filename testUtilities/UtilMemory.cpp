#include "UtilMemory.h"

static int gIStaticData64Bytes[16];
static float gFStaticData64Bytes[16];
__declspec(align(16)) static float gFStaticData64ABytes[16];
__declspec(align(16)) static char gData[128*(1024 * 1024)];
__declspec(align(16)) static char gAccess[128*(1024 * 1024)];

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

void* UtilMemory::Get16ByteAlignedAccessBuffer()
{
   return gAccess;
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
