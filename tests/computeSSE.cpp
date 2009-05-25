#include <stdio.h>
#include "testUtilities/IUtil.h"
#include "xmmintrin.h"
#include "harness/performanceHarness.h"

float* floatSSEArray = IUtil::GetUtilMemory()->GetFStatic64Bytes();
float* floatSSEArrayA = IUtil::GetUtilMemory()->GetFStatic64BytesAligned();

__m128 gSum;

void gfInitSSEArray()
{
	for( int i=0;i<16;i++ )
	{
		floatSSEArray[i] = (rand()*1000.0f)/rand();
		floatSSEArrayA[i] = (rand()*1000.0f)/rand();
	}
}

PERFORMANCE_TEST("compute/sse/sse_aligned", sse_aligned)
{
   void initialize()
   {
		gfInitSSEArray();
   }

   void test()
   {
		int t = 0;
	    for( int j=0;j<10000000;j++)
		for( int i=0;i<4;i+=4 )
		{
			__m128 val = _mm_load_ps(&floatSSEArrayA[i]);
			gSum = _mm_add_ps(val,gSum);
		}
   }
};

PERFORMANCE_TEST("compute/sse/sse_unaligned", sse_unaligned)
{
   void initialize()
   {
		gfInitSSEArray();
   }

   void test()
   {
		int t = 0;
	    for( int j=0;j<10000000;j++)
		for( int i=0;i<4;i+=4 )
		{
			__m128 val = _mm_loadu_ps(&floatSSEArray[i]); 
			gSum = _mm_add_ps(val,gSum);
		}
   }
};