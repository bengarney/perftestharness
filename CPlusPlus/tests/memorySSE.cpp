
#include <stdio.h>
#include <stdlib.h>
#include "harness/performanceHarness.h"
#include "testUtilities/IUtil.h"

#include "xmmintrin.h"
#include "emmintrin.h"

//#define MAX_SEE_TEST 65
#define DATA_SIZE (UtilMemory::BufferSize / sizeof(float))
static float gResult = 0;
__m128 gVecResult;

PERFORMANCE_TEST("memory/sse/SSElinearStepStatic", MTSSELStepStatic, 8000)
{
   int m_NumReads;

   void test()
   {
      float *data = (float*)IUtil::GetUtilMemory()->Get16ByteAlignedDataBuffer();
      __declspec(align(16)) float vecOut[4];

      for(int i=0; i<m_NumReads; i+=4)
      {
         __m128 vec = _mm_load_ps(&data[i]);
         gVecResult = _mm_add_ps(vec,gVecResult);
      }

      _mm_store_ps(vecOut,gVecResult);
      gResult+=vecOut[1];
   }

   static bool checkSkipIndependentValue(int independentValue)
   {
      return!( independentValue%4==0 );
   }

   static const char * getIndependentVariableName()
   {
      return "data amount";
   }

   static int getIndependentVariableMin()
   {
      return 4;
   }

   static int getIndependentVariableMax()
   {
      return 64;
   }

   void setIndependentVariable(int v)
   {
      m_NumReads = DATA_SIZE/65 * v;
   }

   void initialize()
   {
      IUtil::GetUtilMemory()->FillDataBufferWithRandomFloats();
   }
};

PERFORMANCE_TEST("memory/sse/NonSSElinearStepStatic", MTNONSSELStepStatic, 8000)
{

   int m_NumReads;

   void test()
   {
      float *data = (float*)IUtil::GetUtilMemory()->Get16ByteAlignedDataBuffer();
      for(int i=0; i<m_NumReads; i++)
      {
         gResult += data[i];
      }
   }

   static bool checkSkipIndependentValue(int independentValue)
   {
      return!( independentValue%4==0 );
   }

   static const char * getIndependentVariableName()
   {
      return "data amount";
   }

   static int getIndependentVariableMin()
   {
      return 4;
   }

   static int getIndependentVariableMax()
   {
      return 65;
   }

   void setIndependentVariable(int v)
   {
      m_NumReads = DATA_SIZE/65 * v;
   }

   void initialize()
   {
      IUtil::GetUtilMemory()->FillDataBufferWithRandomFloats();
   }
};