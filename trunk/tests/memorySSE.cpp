
#include <stdio.h>
#include <stdlib.h>
#include "harness/performanceHarness.h"
#include "xmmintrin.h"
#include "emmintrin.h"

#define MAX_SEE_TEST 128
#define DATA_SIZE 1024 * 1024 * 32
__declspec(align(16)) static float gStaticSSEData[DATA_SIZE];
__declspec(align(16)) static float gStaticData[DATA_SIZE];
static float gResult = 0;
__m128 gVecResult;


void initStaticSSE()
{
	for( int i=0;i<DATA_SIZE;i++ )
	{
		gStaticData[i]=betterRandf();
	}
}

class StaticMemorySSEPerformanceTest : public PerformanceTest
{
public:

   int m_NumReads;

   void test()
   {
      __declspec(align(16)) float vecOut[4];
      for(int i=0; i<m_NumReads; i+=4)
	  {
	     __m128 vec = _mm_load_ps(&gStaticSSEData[i]);
         gVecResult = _mm_add_ps(vec,gVecResult);
	  }

	  _mm_store_ps(vecOut,gVecResult);
	  gResult+=vecOut[1];
   }
};

class StaticLinearPerformanceTest : public PerformanceTest
{

public:

   int m_NumReads;

   void test()
   {
      for(int i=0; i<m_NumReads; i++)
	  {
	     gResult += gStaticData[i];
	  }
   }
};

#define SSEMEMORY_PERFORMANCE_TEST(name, className) \
struct className##MemoryPerfTest; \
static PerfTestMarker<className##MemoryPerfTest> className##PerfTestMarkerInstance(name); \
struct className##MemoryPerfTest : public StaticMemorySSEPerformanceTest

#define NONSSEMEMORY_PERFORMANCE_TEST(name, className) \
struct className##MemoryPerfTest; \
static PerfTestMarker<className##MemoryPerfTest> className##PerfTestMarkerInstance(name); \
struct className##MemoryPerfTest : public StaticLinearPerformanceTest

SSEMEMORY_PERFORMANCE_TEST("memory/sse/SSElinearStepStatic", MTSSELStepStatic)
{

   static const char * getIndependentVariableName()
   {
      return "data ammount";
   }

   static int getIndependentVariableMin()
   {
      return 4;
   }

   static int getIndependentVariableMax()
   {
      return MAX_SEE_TEST;
   }

   void setIndependentVariable(int v)
   {
      m_NumReads = (DATA_SIZE)/(MAX_SEE_TEST) * v;
   }

   void initialize()
   {
	  initStaticSSE();
   }
};

NONSSEMEMORY_PERFORMANCE_TEST("memory/sse/NonSSElinearStepStatic", MTNONSSELStepStatic)
{
 

   static const char * getIndependentVariableName()
   {
      return "data ammount";
   }

   static int getIndependentVariableMin()
   {
      return 4;
   }

   static int getIndependentVariableMax()
   {
      return 128;
   }

   void setIndependentVariable(int v)
   {
      m_NumReads = (DATA_SIZE)/(MAX_SEE_TEST) * v;
   }

   void initialize()
   {
	  initStaticSSE();
   }
};