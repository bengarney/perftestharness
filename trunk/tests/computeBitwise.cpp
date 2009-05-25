#include <stdio.h>
#include "windows.h"
#include "testUtilities/IUtil.h"
#include "math.h"
#include "harness/performanceHarness.h"

#define FLOATING_POINT_ONE_POINT_ZERO 0x3f800000

int* intBitwiseArray = IUtil::GetUtilMemory()->GetIStatic64Bytes();
float* floatBitwiseArray = IUtil::GetUtilMemory()->GetFStatic64Bytes();

int giBitwiseSum = 0;
float gfBitwiseSum = 0;

bool gBoolBitwise = false;

void gIInitBitwiseArray()
{
	for(int i=0;i<16;i++ )
	{
		intBitwiseArray[i]=rand();
		if(rand()%2==0)
		{	
			intBitwiseArray[i]*=-1;
		}	
	}
}

void gFInitBitwiseArray()
{
	for(int i=0;i<16;i++ )
	{
		floatBitwiseArray[i]=(rand()*10.0f)/((float)rand());
		if(rand()%2==0)
		{	
			intBitwiseArray[i]*=-1;
		}	
	}
}

PERFORMANCE_TEST("compute/bitwise/swapint/non_bit", swapint_non_bit)
{
   void initialize()
   {
		gIInitBitwiseArray();
   }

   void test()
   {
		int t = 0;
	    for( int j=0;j<100000;j++)
		for( int i=0;i<15;i++ )
		{
			t=intBitwiseArray[i];
			intBitwiseArray[i]=intBitwiseArray[i+1];
			intBitwiseArray[i+1]=t;
		}
   }
};

PERFORMANCE_TEST("compute/bitwise/swapint/bit", swapint_bit)
{
   void initialize()
   {
		gIInitBitwiseArray();
   }

   void test()
   {
	    for( int j=0;j<100000;j++)
		for( int i=0;i<15;i++ )
		{
			intBitwiseArray[i]^=intBitwiseArray[i+1];
			intBitwiseArray[i+1]^=intBitwiseArray[i];
			intBitwiseArray[i]^=intBitwiseArray[i+1];
		}
   }

};


PERFORMANCE_TEST("compute/bitwise/bitmask/bit", bitmask_bit)
{
   void initialize()
   {
		gIInitBitwiseArray();
   }

   void test()
   {
		int t=intBitwiseArray[0];
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
		gIInitBitwiseArray();
   }

   void test()
   {
		int t = 0;
	    for( int j=0;j<100000;j++)
		for( int i=0;i<15;i++ )
		{
			int val = intBitwiseArray[i];
			__asm
			{
				mov giBitwiseSum,eax;
			}
		}
   }
};

PERFORMANCE_TEST("compute/bitwise/bitmodulo/non_bit", bitmodulo_non_bit)
{
   void initialize()
   {
		gIInitBitwiseArray();
   }

   void test()
   {
	    for( int j=0;j<100000;j++)
		for( int i=0;i<15;i++ )
		{
			giBitwiseSum = intBitwiseArray[i]%256;
		}
   }
};

PERFORMANCE_TEST("compute/bitwise/bitmodulo/bit", bitmodulo_bit)
{
   void initialize()
   {
		gIInitBitwiseArray();
   }

   void test()
   {
	    for( int j=0;j<100000;j++)
		for( int i=0;i<15;i++ )
		{
			giBitwiseSum += intBitwiseArray[i]&255;
		}
   }
};


PERFORMANCE_TEST("compute/bitwise/absolute_value/non_bit", absolute_non_bit)
{
   void initialize()
   {
		gIInitBitwiseArray();
   }

   void test()
   {
	    for( int j=0;j<100000;j++)
		for( int i=0;i<15;i++ )
		{
			int x = intBitwiseArray[i];
			x < 0 ? -x : x; 
			giBitwiseSum += x;
		}
   }
};

PERFORMANCE_TEST("compute/bitwise/absolute_value/bit", absolute_bit)
{
   void initialize()
   {
		gIInitBitwiseArray();
   }

   void test()
   {
	    for( int j=0;j<100000;j++)
		for( int i=0;i<15;i++ )
		{
			int x = intBitwiseArray[i];
			giBitwiseSum += (x ^ (x >> 31)) - (x >> 31);
		}
   }
};



PERFORMANCE_TEST("compute/bitwise/evenness/non_bit", evenness_non_bit)
{
   void initialize()
   {
		gIInitBitwiseArray();
   }

   void test()
   {
	    for( int j=0;j<100000;j++)
		for( int i=0;i<15;i++ )
		{
			int x = intBitwiseArray[i];
			gBoolBitwise = ((x % 2) == 0);
		}
   }
};

PERFORMANCE_TEST("compute/bitwise/evenness/bit", eveness_bit)
{
   void initialize()
   {
		gIInitBitwiseArray();
   }

   void test()
   {
	    for( int j=0;j<100000;j++)
		for( int i=0;i<15;i++ )
		{
			int x = intBitwiseArray[i];
			gBoolBitwise = ( (x&1)==0 );
		}
   }
};


PERFORMANCE_TEST("compute/bitwise/equal_sign/non_bit", equal_sign_non_bit)
{
   void initialize()
   {
		gIInitBitwiseArray();
   }

   void test()
   {
		int y=-3;
	    for( int j=0;j<100000;j++)
		for( int i=0;i<15;i++ )
		{
			int x = intBitwiseArray[i];
			gBoolBitwise = (x*y>0);
		}
   }
};

PERFORMANCE_TEST("compute/bitwise/equal_sign/bit", equal_sign_bit)
{
   void initialize()
   {
		gIInitBitwiseArray();
   }

   void test()
   {
		int y=-3;
	    for( int j=0;j<100000;j++)
		for( int i=0;i<15;i++ )
		{

			int x = intBitwiseArray[i];
			gBoolBitwise = ((x^y)>=0);

		}
   }
};


PERFORMANCE_TEST("compute/bitwise/square_root/non_bit", square_root_non_bit )
{
   void initialize()
   {
		gFInitBitwiseArray();
   }

   void test()
   {
	    for( int j=0;j<100000;j++)
		for( int i=0;i<15;i++ )
		{
			float x = floatBitwiseArray[i];
			gfBitwiseSum += sqrtf(x);
		}
   }
};

PERFORMANCE_TEST("compute/bitwise/square_root/bit", square_root_bit )
{
   void initialize()
   {
		gFInitBitwiseArray();
   }

   void test()
   {
	    for( int j=0;j<100000;j++)
		for( int i=0;i<15;i++ )
		{
			int temp = *(int*)&floatBitwiseArray[i];
			temp -= FLOATING_POINT_ONE_POINT_ZERO;
			temp >>= 1;
			temp += FLOATING_POINT_ONE_POINT_ZERO;
			gfBitwiseSum += *(float*)&temp;
			
		}
   }
};