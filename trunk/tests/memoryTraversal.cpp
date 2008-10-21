#include <stdio.h>
#include <stdlib.h>
#include "harness/performanceHarness.h"

#define DATA_SIZE 1024 * 1024 * 32
static int gStaticData[DATA_SIZE];
static int gResult = 0;

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
      int sum = 0;
      for(int i=0; i<NumReads; i++)
         sum += gStaticData[accessPattern[i%NumReads]];

      gResult = sum;
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
      int sum = 0;
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

STATICMEMORY_PERFORMANCE_TEST("memory/traverse/randomStatic", MTRRandomStatic)
{
   void initialize()
   {
      // Generate an access pattern for this run.
      for(int i=0; i<NumReads; i++)
         accessPattern[i]=betterRand()%DATA_SIZE;
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
