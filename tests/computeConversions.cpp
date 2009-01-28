#include <stdio.h>
#include "windows.h"
#include "testUtilities/IUtil.h"
#include "harness/performanceHarness.h"

int* intConversionArray = IUtil::Get()->GetUtilMemory()->GetIStatic64Bytes();
float* floatConversionArray = IUtil::Get()->GetUtilMemory()->GetFStatic64Bytes();

int gIntConversion = 0;
float gFloatConversion = 0;

void gIInitConversionArray()
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

PERFORMANCE_TEST("compute/conversions/ftoi", ftoi)
{
   void initialize()
   {
		gIInitConversionArray();
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
		gIInitConversionArray();
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