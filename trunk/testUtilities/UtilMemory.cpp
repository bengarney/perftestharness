
#include "UtilMemory.h"




__declspec(align(16)) static float gStaticData1024x1024[(1024 * 1024)];

static int gIStaticData64Bytes[16];
static float gFStaticData64Bytes[16];

UtilMemory::UtilMemory()
{

}

UtilMemory::~UtilMemory()
{

}

float* UtilMemory::GetStatic1024x1024_16_Aligned()
{
	return gStaticData1024x1024;
}

int* UtilMemory::GetIStatic64Bytes()
{
	return gIStaticData64Bytes;
}

float* UtilMemory::GetFStatic64Bytes()
{
	return gFStaticData64Bytes;
}