
#include "harness/performanceHarness.h"

extern float gCommon = 0.0f;

PERFORMANCE_TEST("compilerTest/sameFunction", sameFunction)
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