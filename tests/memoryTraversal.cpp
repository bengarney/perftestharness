#include <stdio.h>
#include <stdlib.h>
#include "harness/performanceHarness.h"
#include "xmmintrin.h"
#include "emmintrin.h"

#define DATA_SIZE 1024 * 1024 * 32
__declspec(align(16)) static float gStaticData[DATA_SIZE];
static float gResult = 0;
__m128 gVecResult;

void initStatic()
{
	for( int i=0;i<DATA_SIZE;i++ )
	{
		gStaticData[i]=betterRandf();
	}
}

class StaticMemoryPerformanceTest : public PerformanceTest
{
public:
   enum
   {
      NumReads = 1024*1024*12,
   };

   int accessPattern[NumReads];

   void test()
   {
      float sum = 0;
      for(int i=0; i<NumReads; i++)
         sum += gStaticData[accessPattern[i%NumReads]];

      gResult = sum;
   }
};

class StaticMemorySSEPerformanceTest : public PerformanceTest
{
public:
   enum
   {
      NumReads = 1024*1024*12,
   };

   int accessPattern[NumReads];

   void test()
   {
      __declspec(align(16)) float vecOut[4];
      for(int i=0; i<NumReads; i+=4)
	  {
	     __m128 vec = _mm_load_ps(&gStaticData[accessPattern[i%NumReads]]);
         gVecResult = _mm_add_ps(vec,gVecResult);
	  }

	  
	  _mm_store_ps(vecOut,gVecResult);
	  gResult+=vecOut[1];
   }
};

class HeapMemoryPerformanceTest : public PerformanceTest
{
public:
   enum
   {
      NumReads = 1024*1024*12,
   };

   int accessPattern[NumReads];
   int data[DATA_SIZE];

   void test()
   {
      float sum = 0;
      for(int i=0; i<NumReads; i++)
         sum += data[accessPattern[i%NumReads]];

      gResult = sum;
   }
};

#define STATICMEMORY_PERFORMANCE_TEST(name, className) \
struct className##MemoryPerfTest; \
static PerfTestMarker<className##MemoryPerfTest> className##PerfTestMarkerInstance(name); \
struct className##MemoryPerfTest : public StaticMemoryPerformanceTest

#define HEAPMEMORY_PERFORMANCE_TEST(name, className) \
struct className##MemoryPerfTest; \
static PerfTestMarker<className##MemoryPerfTest> className##PerfTestMarkerInstance(name); \
struct className##MemoryPerfTest : public HeapMemoryPerformanceTest

#define SSEMEMORY_PERFORMANCE_TEST(name, className) \
struct className##MemoryPerfTest; \
static PerfTestMarker<className##MemoryPerfTest> className##PerfTestMarkerInstance(name); \
struct className##MemoryPerfTest : public StaticMemorySSEPerformanceTest

STATICMEMORY_PERFORMANCE_TEST("memory/traverse/randomStatic", MTRRandomStatic)
{
   void initialize()
   {
      // Generate an access pattern for this run.
      for(int i=0; i<NumReads; i++)
         accessPattern[i]=betterRand()%DATA_SIZE;

	  initStatic();
   }
};

HEAPMEMORY_PERFORMANCE_TEST("memory/traverse/randomHeap", MTRRandomHeap)
{
   void initialize()
   {
      // Generate an access pattern for this run.
      for(int i=0; i<NumReads; i++)
         accessPattern[i]=betterRand()%DATA_SIZE;
   }
};

STATICMEMORY_PERFORMANCE_TEST("memory/traverse/linearStatic", MTRLinearStatic)
{
   void initialize()
   {
      for(int i=0; i<NumReads; i++)
         accessPattern[i]= i % DATA_SIZE;

	  initStatic();
   }


};

HEAPMEMORY_PERFORMANCE_TEST("memory/traverse/linearHeap", MTLinearHeap)
{
   void initialize()
   {
      for(int i=0; i<NumReads; i++)
         accessPattern[i]= i % DATA_SIZE;
   }
};

STATICMEMORY_PERFORMANCE_TEST("memory/traverse/linearBackwardsStatic", MTRLinearBackwardsStatic)
{
   void initialize()
   {
      for(int i=0; i<NumReads; i++)
         accessPattern[i]= (NumReads - i) % DATA_SIZE;
   }
};

HEAPMEMORY_PERFORMANCE_TEST("memory/traverse/linearBackwardsHeap", MTLinearBackwardsHeap)
{
   void initialize()
   {
      for(int i=0; i<NumReads; i++)
         accessPattern[i]= (NumReads - i) % DATA_SIZE;
   }
};

STATICMEMORY_PERFORMANCE_TEST("memory/traverse/linearStepStatic", MTLStepStatic)
{
   int stepSize;

   static const char * getIndependentVariableName()
   {
      return "step size (bytes)";
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
      stepSize = v;
   }

   void initialize()
   {
      for(int i=0; i<NumReads; i++)
         accessPattern[i]= (i * stepSize) % DATA_SIZE;
   }
};

STATICMEMORY_PERFORMANCE_TEST("memory/traverse/linearStepHeap", MTLStepHeap)
{
   int stepSize;

   static const char * getIndependentVariableName()
   {
      return "step size (bytes)";
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
      stepSize = v;
   }



   void initialize()
   {
      for(int i=0; i<NumReads; i++)
         accessPattern[i]= (i * stepSize) % DATA_SIZE;
   }
};


SSEMEMORY_PERFORMANCE_TEST("memory/traverse/SSElinearStepStatic", MTSSELStepStatic)
{
   int stepSize;

   static const char * getIndependentVariableName()
   {
      return "step size (bytes)";
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
      stepSize = v;
   }

   void initialize()
   {
      for(int i=0; i<NumReads; i++)
         accessPattern[i]= (i * stepSize) % DATA_SIZE;

	  initStatic();
   }
};