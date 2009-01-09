
#include "UtilMemory.h"



#define DATA_SIZE (1024 * 1024)
__declspec(align(16)) static float gStaticData1024x1024[DATA_SIZE];

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
