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

PERFORMANCE_TEST("compute/bitwise/swapint/non_bit", swapint_non_bit)
{
   void test()
   {
		int t = 0;
      int *data = (int*)IUtil::GetUtilMemory()->Get16ByteAlignedDataBuffer();

      for(int i=0; i<UtilMemory::BufferSize / sizeof(int); i++)
		{
			t = data[i];
			data[i] = data[i+1];
			data[i+1] = t;
		}
   }
};

PERFORMANCE_TEST("compute/bitwise/swapint/bit", swapint_bit)
{
   void test()
   {
      int *data = (int*)IUtil::GetUtilMemory()->Get16ByteAlignedDataBuffer();

      for(int i=0; i<UtilMemory::BufferSize / sizeof(int); i++)
      {
         data[i]   ^= data[i+1];
			data[i+1] ^= data[i];
			data[i]   ^= data[i+1];
		}
   }
};

PERFORMANCE_TEST("compute/bitwise/bitmask/bit", bitmask_bit)
{
   void test()
   {
		int t=intBitwiseArray[0];
		int shift = 1;

      int *data = (int*)IUtil::GetUtilMemory()->Get16ByteAlignedDataBuffer();
      for(int i=0; i<UtilMemory::BufferSize / sizeof(int); i++)
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
   void test()
   {
      int *data = (int*)IUtil::GetUtilMemory()->Get16ByteAlignedDataBuffer();
      for(int i=0; i<UtilMemory::BufferSize / sizeof(int); i++)
		{
			int val = data[i];
			__asm
			{
				mov giBitwiseSum, eax;
			}
		}
   }
};

PERFORMANCE_TEST("compute/bitwise/bitmodulo/non_bit", bitmodulo_non_bit)
{
   void initialize()
   {
      IUtil::GetUtilMemory()->FillDataBufferWithRandomFloats();
   }

   void test()
   {
      int *data = (int*)IUtil::GetUtilMemory()->Get16ByteAlignedDataBuffer();
      for(int i=0; i<UtilMemory::BufferSize / sizeof(int); i++)
		{
			giBitwiseSum = data[i]%256;
		}
   }
};

PERFORMANCE_TEST("compute/bitwise/bitmodulo/bit", bitmodulo_bit)
{
   void initialize()
   {
      IUtil::GetUtilMemory()->FillDataBufferWithRandomFloats();
   }

   void test()
   {
      int *data = (int*)IUtil::GetUtilMemory()->Get16ByteAlignedDataBuffer();
      for(int i=0; i<UtilMemory::BufferSize / sizeof(int); i++)
		{
			giBitwiseSum += data[i]&255;
		}
   }
};


PERFORMANCE_TEST("compute/bitwise/absolute_value/non_bit", absolute_non_bit)
{
   void initialize()
   {
      IUtil::GetUtilMemory()->FillDataBufferWithRandomFloats();
   }

   void test()
   {
      int *data = (int*)IUtil::GetUtilMemory()->Get16ByteAlignedDataBuffer();
      for(int i=0; i<UtilMemory::BufferSize / sizeof(int); i++)
		{
			int x = data[i];
			giBitwiseSum += x < 0 ? -x : x; 
		}
   }
};

PERFORMANCE_TEST("compute/bitwise/absolute_value/bit", absolute_bit)
{
   void initialize()
   {
      IUtil::GetUtilMemory()->FillDataBufferWithRandomFloats();
   }

   void test()
   {
      int *data = (int*)IUtil::GetUtilMemory()->Get16ByteAlignedDataBuffer();
      for(int i=0; i<UtilMemory::BufferSize / sizeof(int); i++)
		{
			int x = data[i];
			giBitwiseSum += (x ^ (x >> 31)) - (x >> 31);
		}
   }
};



PERFORMANCE_TEST("compute/bitwise/evenness/non_bit", evenness_non_bit)
{
   void initialize()
   {
      IUtil::GetUtilMemory()->FillDataBufferWithRandomFloats();
   }

   void test()
   {
      int *data = (int*)IUtil::GetUtilMemory()->Get16ByteAlignedDataBuffer();
      for(int i=0; i<UtilMemory::BufferSize / sizeof(float); i++)
		{
			int x = data[i];
			gBoolBitwise = ((x % 2) == 0);
		}
   }
};

PERFORMANCE_TEST("compute/bitwise/evenness/bit", eveness_bit)
{
   void initialize()
   {
      IUtil::GetUtilMemory()->FillDataBufferWithRandomFloats();
   }

   void test()
   {
      int *data = (int*)IUtil::GetUtilMemory()->Get16ByteAlignedDataBuffer();
      for(int i=0; i<UtilMemory::BufferSize / sizeof(float); i++)
		{
			int x = data[i];
			gBoolBitwise = ( (x&1)==0 );
		}
   }
};


PERFORMANCE_TEST("compute/bitwise/equal_sign/non_bit", equal_sign_non_bit)
{
   void initialize()
   {
      IUtil::GetUtilMemory()->FillDataBufferWithRandomFloats();
   }

   void test()
   {
		int y=-3;

      int *data = (int*)IUtil::GetUtilMemory()->Get16ByteAlignedDataBuffer();
      for(int i=0; i<UtilMemory::BufferSize / sizeof(int); i++)
		{
			int x = data[i];
			gBoolBitwise ^= (x*y>0);
		}
   }
};

PERFORMANCE_TEST("compute/bitwise/equal_sign/bit", equal_sign_bit)
{
   void initialize()
   {
      IUtil::GetUtilMemory()->FillDataBufferWithRandomFloats();
   }

   void test()
   {
		int y=-3;

      int *data = (int*)IUtil::GetUtilMemory()->Get16ByteAlignedDataBuffer();
      for(int i=0; i<UtilMemory::BufferSize / sizeof(int); i++)
		{

			int x = data[i];
			gBoolBitwise ^= ((x^y)>=0);

		}
   }
};


PERFORMANCE_TEST("compute/bitwise/square_root/non_bit", square_root_non_bit )
{
   void initialize()
   {
      IUtil::GetUtilMemory()->FillDataBufferWithRandomFloats();
   }

   void test()
   {
      float *data = (float*)IUtil::GetUtilMemory()->Get16ByteAlignedDataBuffer();
      for(int i=0; i<UtilMemory::BufferSize / sizeof(float); i++)
			gfBitwiseSum += sqrtf(data[i]);
   }
};

PERFORMANCE_TEST("compute/bitwise/square_root/bit", square_root_bit )
{
   void initialize()
   {
      IUtil::GetUtilMemory()->FillDataBufferWithRandomFloats();
   }

   void test()
   {
      float *data = (float*)IUtil::GetUtilMemory()->Get16ByteAlignedDataBuffer();
      for(int i=0; i<UtilMemory::BufferSize / sizeof(float); i++)
		{
			int temp = *(int*)&data[i];
			temp -= FLOATING_POINT_ONE_POINT_ZERO;
			temp >>= 1;
			temp += FLOATING_POINT_ONE_POINT_ZERO;
			gfBitwiseSum += *(float*)&temp;
		}
   }
};