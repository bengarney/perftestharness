#include <stdio.h>
#include "windows.h"
#include "testUtilities/IUtil.h"
#include "harness/performanceHarness.h"


float* fpmodel_floatConversionArray = IUtil::GetUtilMemory()->GetFStatic64Bytes();
float fpmodel_gFloatConversion = 0;


void gfpmodel_InitConversionArray()
{
	for(int i=0;i<16;i++ )
	{
		fpmodel_floatConversionArray[i]=rand()/(float)rand();
	}
}

PERFORMANCE_TEST("compute/fp_model", fp_model, 8000 )
{
   void initialize()
   {
		gfpmodel_InitConversionArray();
   }

   void test()
   {
	    for( int j=0;j<100000;j++)
		for( int i=0;i<15;i++ )
		{
			float f = fpmodel_floatConversionArray[i];
			fpmodel_gFloatConversion += f;
		}
   }

};



