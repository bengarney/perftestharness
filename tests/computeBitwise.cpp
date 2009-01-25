#include <stdio.h>
#include "windows.h"
#include "testUtilities/IUtil.h"
#include "harness/performanceHarness.h"

int* intSwapArray = IUtil::Get()->GetUtilMemory()->GetIStatic64Bytes();

int giSwapSum = 0;
bool gBool = false;

void gIInitSwapArray()
{
	for(int i=0;i<16;i++ )
	{
		intSwapArray[i]=rand();
		if(rand()%2==0)
		{	
			intSwapArray[i]*=-1;
		}	
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
			t=intSwapArray[i];
			intSwapArray[i]=intSwapArray[i+1];
			intSwapArray[i+1]=t;
		}
   }
};


PERFORMANCE_TEST("compute/bitwise/bitmask/bit", bitmask_bit)
{
   void initialize()
   {
		gIInitSwapArray();
   }

   void test()
   {
		int t=intSwapArray[0];
		int shift = 1;



	    for( int j=0;j<100000;j++)
		for( int i=0;i<15;i++ )
		{
			__asm
			{
				mov eax,shift;
				mov ebx,eax;
				and ebx,t;
				shl eax,1;
				mov shift,eax;
			}
		}
   }
};

PERFORMANCE_TEST("compute/bitwise/bitmask/non_bit", bitmask_non_bit)
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
			int val = intSwapArray[i];
			__asm
			{
				mov giSwapSum,eax;
			}
		}
   }
};

PERFORMANCE_TEST("compute/bitwise/bitmodulo/non_bit", bitmodulo_non_bit)
{
   void initialize()
   {
		gIInitSwapArray();
   }

   void test()
   {
	    for( int j=0;j<100000;j++)
		for( int i=0;i<15;i++ )
		{
			giSwapSum = intSwapArray[i]%256;
		}
   }
};

PERFORMANCE_TEST("compute/bitwise/bitmodulo/bit", bitmodulo_bit)
{
   void initialize()
   {
		gIInitSwapArray();
   }

   void test()
   {
	    for( int j=0;j<100000;j++)
		for( int i=0;i<15;i++ )
		{
			giSwapSum = intSwapArray[i]&255;
		}
   }
};


PERFORMANCE_TEST("compute/bitwise/absolute_value/non_bit", absolute_non_bit)
{
   void initialize()
   {
		gIInitSwapArray();
   }

   void test()
   {
	    for( int j=0;j<100000;j++)
		for( int i=0;i<15;i++ )
		{
			int x = intSwapArray[i];
			x < 0 ? -x : x; 
			giSwapSum += x;
		}
   }
};

PERFORMANCE_TEST("compute/bitwise/absolute_value/bit", absolute_bit)
{
   void initialize()
   {
		gIInitSwapArray();
   }

   void test()
   {
	    for( int j=0;j<100000;j++)
		for( int i=0;i<15;i++ )
		{
			int x = intSwapArray[i];
			giSwapSum += (x ^ (x >> 31)) - (x >> 31);
		}
   }
};



PERFORMANCE_TEST("compute/bitwise/evenness/non_bit", evenness_non_bit)
{
   void initialize()
   {
		gIInitSwapArray();
   }

   void test()
   {
	    for( int j=0;j<100000;j++)
		for( int i=0;i<15;i++ )
		{
			int x = intSwapArray[i];
			gBool = ((x % 2) == 0);
		}
   }
};

PERFORMANCE_TEST("compute/bitwise/evenness/bit", eveness_bit)
{
   void initialize()
   {
		gIInitSwapArray();
   }

   void test()
   {
	    for( int j=0;j<100000;j++)
		for( int i=0;i<15;i++ )
		{
			int x = intSwapArray[i];
			gBool = ( (x&1)==0 );
		}
   }
};


PERFORMANCE_TEST("compute/bitwise/equal_sign/non_bit", equal_sign_non_bit)
{
   void initialize()
   {
		gIInitSwapArray();
   }

   void test()
   {
		int y=-3;
	    for( int j=0;j<100000;j++)
		for( int i=0;i<15;i++ )
		{
			int x = intSwapArray[i];
			gBool = (x*y>0);
		}
   }
};

PERFORMANCE_TEST("compute/bitwise/equal_sign/bit", equal_sign_bit)
{
   void initialize()
   {
		gIInitSwapArray();
   }

   void test()
   {
		int y=-3;
	    for( int j=0;j<100000;j++)
		for( int i=0;i<15;i++ )
		{
			int x = intSwapArray[i];
			gBool = (x^y>=0);
		}
   }
};