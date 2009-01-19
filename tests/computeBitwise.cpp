#include <stdio.h>
#include "windows.h"
#include "testUtilities/IUtil.h"
#include "harness/performanceHarness.h"

int* intSwapArray = IUtil::Get()->GetUtilMemory()->GetIStatic64Bytes();

int giSwapSum = 0;

void gIInitSwapArray()
{
	for(int i=0;i<16;i++ )
	{
		intSwapArray[i]=rand();
	}
}

PERFORMANCE_TEST("compute/bitwise/swapint_non_bit", swapint_non_bit)
{
   void initialize()
   {
		gIInitSwapArray();
   }

   void test()
   {
		int t = 0;
	    for( int j=0;j<100000;j++)
		for( int i=0;i<15;i++ )
		{
			t=intSwapArray[i];
			intSwapArray[i]=intSwapArray[i+1];
			intSwapArray[i+1]=t;
		}
   }
};

PERFORMANCE_TEST("compute/bitwise/swapint_bit", swapint_bit)
{
   void initialize()
   {
		gIInitSwapArray();
   }

   void test()
   {
		int t = 0;
	    for( int j=0;j<100000;j++)
		for( int i=0;i<15;i++ )
		{
			intSwapArray[i]^=intSwapArray[i+1];
			intSwapArray[i+1]^=intSwapArray[i];
			intSwapArray[i]^=intSwapArray[i+1];
		}
   }
};
