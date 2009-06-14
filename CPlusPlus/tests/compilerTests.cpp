
#include "harness/performanceHarness.h"

float gCommon = 0.0f;
int gCommonI = 0;

PERFORMANCE_TEST("compilerTest/sameFunction", sameFunction,8000)
{
   void test()
   {
      gCommon +=TestLoopOne();
	  gCommon +=TestLoopTwo();
   }

   float TestLoopOne()
   {
		float test1=0.0f;
		for( int i=0;i<1000;i++ )
		{
			test1 +=  betterRandf();
		}

		return test1;
   }

   float TestLoopTwo()
   {
		float test2=0.0f;
		for( int i=0;i<1000;i++ )
		{
			test2 +=  betterRandf();
		}

		return test2;
   }
};

PERFORMANCE_TEST("compilerTest/invarient", invarient, 8000 )
{
   inline void test()
   {
        float j=0;
		float k=22/(float)7;
		for( int i=0;i<100;i++ ) 
		{
			j=10.0f;
			k+= j;
		}

		gCommon = k;
   }
};