#include <stdio.h>
#include "windows.h"
#include "testUtilities/IUtil.h"
#include "harness/performanceHarness.h"

int* intConversionArray = IUtil::GetUtilMemory()->GetIStatic64Bytes();
float* floatConversionArray = IUtil::GetUtilMemory()->GetFStatic64Bytes();

int gIntConversion = 0;
float gFloatConversion = 0;

#define FLOAT_FTOI_MAGIC_NUM (float)(3<<21)
#define IT_FTOI_MAGIC_NUM 0x4ac00000


void gInitConversionArray()
{
	for(int i=0;i<16;i++ )
	{
		intConversionArray[i]=rand();
		if(rand()%2==0)
		{	
			intConversionArray[i]*=-1;
		}

		floatConversionArray[i]=rand()/(float)rand();
	}
}

PERFORMANCE_TEST("compute/conversions/ftoi_fast", ftoi_fast )
{
   void initialize()
   {
		gInitConversionArray();
   }

   void test()
   {
	    for( int j=0;j<100000;j++)
		for( int i=0;i<15;i++ )
		{
			float f = floatConversionArray[i]+FLOAT_FTOI_MAGIC_NUM;
			gFloatConversion += (*((int *)&f) - IT_FTOI_MAGIC_NUM) >> 1;
		}
   }
};

PERFORMANCE_TEST("compute/conversions/ftoi", ftoi)
{
   void initialize()
   {
		gInitConversionArray();
   }

   void test()
   {
		int t = 0;
	    for( int j=0;j<100000;j++)
		for( int i=0;i<15;i++ )
		{
			gIntConversion+=(int)floatConversionArray[i];
		}
   }
};


PERFORMANCE_TEST("compute/conversions/itof", itof)
{
   void initialize()
   {
		gInitConversionArray();
   }

   void test()
   {
	    for( int j=0;j<100000;j++)
		for( int i=0;i<15;i++ )
		{
			gFloatConversion+=(float)intConversionArray[i];
		}
   }
};

