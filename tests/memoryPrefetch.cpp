#include <stdio.h>
#include <stdlib.h>
#include "xmmintrin.h"
#include "harness/performanceHarness.h"


#define DATA_SIZE_ROW 1000000

static int gStaticData[DATA_SIZE_ROW];
static int gResult = 0;

class MemoryPrefetchTest : public PerformanceTest
{
public:

	int m_Stride;

   void test()
   { 
      int loc = 0;

	  for(int k=0;k<100;k++)
	  for(int i=0; i<DATA_SIZE_ROW; i++)
	  {
		 _mm_prefetch((char*)&gStaticData[loc+m_Stride],_MM_HINT_T0); 
		 loc = gStaticData[loc];
	  }

	  gResult +=loc;
   }
};

#define PREFETCH_PERFORMANCE_TEST(name, className) \
struct className##MemoryPerfTest; \
static PerfTestMarker<className##MemoryPerfTest> className##PerfTestMarkerInstance(name); \
struct className##MemoryPerfTest : public MemoryPrefetchTest

PREFETCH_PERFORMANCE_TEST("memory/prefetch/prefetch", MPrefetchTest)
{
   

   static const char * getIndependentVariableName()
   {
      return "distance of prefetch";
   }

   static int getIndependentVariableMin()
   {
      return 1;
   }

   static int getIndependentVariableMax()
   {
      return 20;
   }


   void setIndependentVariable(int v)
   {
		m_Stride = v;
   }

   void initialize()
   {
	  
	  int ctr=0;
	  
	  for(int j=0;j<DATA_SIZE_ROW; j++)
	  {
		 gStaticData[j]=rand()%DATA_SIZE_ROW;
	  }
	  
   }
};






class MemoryNoPrefetchTest : public PerformanceTest
{
public:

	int m_Stride;

   void test()
   { 
      int loc = 0;

	  for(int k=0;k<100;k++)
	  for(int i=0; i<DATA_SIZE_ROW; i++)
	  {
		 loc = gStaticData[loc];
	  }

	  gResult +=loc;
   }
};

#define NOPREFETCH_PERFORMANCE_TEST(name, className) \
struct className##MemoryPerfTest; \
static PerfTestMarker<className##MemoryPerfTest> className##PerfTestMarkerInstance(name); \
struct className##MemoryPerfTest : public MemoryNoPrefetchTest

NOPREFETCH_PERFORMANCE_TEST("memory/prefetch/noprefetch", MNoPrefetchTest)
{
   

   static const char * getIndependentVariableName()
   {
      return "distance of prefetch";
   }

   static int getIndependentVariableMin()
   {
      return 1;
   }

   static int getIndependentVariableMax()
   {
      return 20;
   }


   void setIndependentVariable(int v)
   {
		m_Stride = v;
   }

   void initialize()
   {
	  
	  int ctr=0;
	  
	  for(int j=0;j<DATA_SIZE_ROW; j++)
	  {
		 gStaticData[j]=rand()%DATA_SIZE_ROW;
	  }
	  
   }
};

