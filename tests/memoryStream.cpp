#include <stdio.h>
#include <stdlib.h>
#include "harness/performanceHarness.h"

#define DATA_SIZE_COLUMN 20
#define DATA_SIZE_ROW 1000

static int gStaticData[DATA_SIZE_COLUMN][DATA_SIZE_ROW];
static int gResult = 0;

class MemoryStreamPerformanceTest : public PerformanceTest
{
public:

   int numStream;

   void test()
   {
      int sum = 0;
	  
	  int readNum = DATA_SIZE_ROW/(numStream);

      for(int j=0; j<readNum; j++)
	  for(int i=0; i<numStream; i++)	  
	  {
         sum += gStaticData[i][j];
	  }

      gResult += sum;
   }
};

#define STREAMMEMORY_PERFORMANCE_TEST(name, className) \
struct className##MemoryPerfTest; \
static PerfTestMarker<className##MemoryPerfTest> className##PerfTestMarkerInstance(name); \
struct className##MemoryPerfTest : public MemoryStreamPerformanceTest

STREAMMEMORY_PERFORMANCE_TEST("memory/stream/memorystream", MStreamTest)
{
   

   static const char * getIndependentVariableName()
   {
      return "number of streams through cache";
   }

   static int getIndependentVariableMin()
   {
      return 1;
   }

   static int getIndependentVariableMax()
   {
      return DATA_SIZE_COLUMN;
   }


   void setIndependentVariable(int v)
   {
      numStream = v;
   }

   void initialize()
   {
      int ctr=0;

	  for(int i=0; i<DATA_SIZE_COLUMN; i++)
	  for(int j=0; j<DATA_SIZE_ROW; j++)
	  {
         gStaticData[i][j]=ctr++;
	  }
   }
};
