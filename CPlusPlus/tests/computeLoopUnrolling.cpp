#include <stdio.h>
#include "windows.h"
#include "testUtilities/IUtil.h"
#include "harness/performanceHarness.h"

float gfSum = 0.0f;
int giSum = 0;

int* intArray = IUtil::GetUtilMemory()->GetIStatic64Bytes();
float* floatArray = IUtil::GetUtilMemory()->GetFStatic64Bytes();


void gIInitLoopUnrolling()
{
	for(int i=0;i<16;i++ )
	{
		intArray[i]=rand();
	}
}

void gFInitLoopUnrolling()
{
	for(int i=0;i<16;i++ )
	{
		floatArray[i]=rand()/(float)rand();
	}
}

PERFORMANCE_TEST("compute/loopunrolling/rolledI", rolledLoop, 8000)
{
   void initialize()
   {
		gIInitLoopUnrolling();
   }

   void test()
   {
	    for( int j=0;j<100000;j++)
		for( int i=0;i<16;i++ )
		{
			giSum += intArray[i];
		}
   }
};

PERFORMANCE_TEST("compute/loopunrolling/unrolledI", unrolledLoop, 8000)
{

   void initialize()
   {
		gIInitLoopUnrolling();
   }

   void test()
   {
		for( int j=0;j<100000;j++)
		for( int i=0;i<16;i+=4)
		{
			giSum += intArray[i+1];
			giSum += intArray[i+2];
			giSum += intArray[i+3];
			giSum += intArray[i+4];
		}
   }
};

PERFORMANCE_TEST("compute/loopunrolling/unrolledEI", unrolledELoop, 8000)
{

   void initialize()
   {
		gIInitLoopUnrolling();
   }

   void test()
   {
		int t1=0, t2=0,t3=0,t4=0;
		
		for( int j=0;j<100000;j++)
		for( int i=0;i<16;i+=4 )
		{
			t1 += intArray[i+1];
			t2 += intArray[i+2];
			t3 += intArray[i+3];
			t4 += intArray[i+4];
		}

		giSum = t1+t2+t3+t4;
   }
};

PERFORMANCE_TEST("compute/loopunrolling/rolledF", FrolledLoop, 8000)
{
   void initialize()
   {
		gFInitLoopUnrolling();
   }

   void test()
   {
		for( int j=0;j<100000;j++)
		for( int i=0;i<16;i++ )
		{
			gfSum += floatArray[i];
		}
   }
};

PERFORMANCE_TEST("compute/loopunrolling/unrolledF", FunrolledLoop, 8000)
{

   void initialize()
   {
		gFInitLoopUnrolling();
   }

   void test()
   {
	    for( int j=0;j<100000;j++)
		for( int i=0;i<16;i+=4)
		{
			gfSum += floatArray[i+1];
			gfSum += floatArray[i+2];
			gfSum += floatArray[i+3];
			gfSum += floatArray[i+4];
		}
   }
};

PERFORMANCE_TEST("compute/loopunrolling/unrolledEF", FunrolledELoop, 8000)
{

   void initialize()
   {
		gFInitLoopUnrolling();
   }

   void test()
   {
		float t1=0,t2=0,t3=0,t4=0;
		
		for( int j=0;j<100000;j++)
		for( int i=0;i<16;i+=4 )
		{
			t1 += floatArray[i+1];
			t2 += floatArray[i+2];
			t3 += floatArray[i+3];
			t4 += floatArray[i+4];
		}

		gfSum = t1+t2+t3+t4;
   }
};

