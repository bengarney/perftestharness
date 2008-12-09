#include <stdio.h>
#include <stdlib.h>
#include "harness/performanceHarness.h"

#define DATA_SIZE_COLUMN 20
#define DATA_SIZE_ROW 10000

static int gStaticData[DATA_SIZE_COLUMN][DATA_SIZE_ROW];
static int gStaticDataCopy[DATA_SIZE_COLUMN][DATA_SIZE_ROW];
static int gResult = 0;
bool m_Init=false;

class MemoryStreamPerformanceTest : public PerformanceTest
{
public:

   int numStream;
   int m_readNum;


   void test()
   { 
	  for(int k=0;k<10;k++ )
	  for(int j=0; j<m_readNum; j++)
	  for(int i=0; i<numStream; i++)
	  {
		 gResult += gStaticData[i][j];
	  }

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
	  m_readNum = DATA_SIZE_ROW/(numStream);
   }

   void initialize()
   {
	  if( !m_Init )
	  {
		  m_Init=true;
		  int ctr=0;
		  
		  for(int i=0; i<DATA_SIZE_COLUMN; i++)
		  for(int j=0; j<DATA_SIZE_ROW; j++)
		  {
			 gStaticData[i][j]=ctr++;
		  }
	  }
   }
};
