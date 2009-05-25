#include "harness/performanceHarness.h"


#define DATA_SIZE_ROW 1000000
#define MAX_TESTS 20

static int* gStaticData;
static int gResult = 0;

class MemoryNewDeleteTest : public PerformanceTest
{
public:

	int m_Ammount;

   void test()
   { 
      int loc = 0;

	  for(int k=0;k<100;k++)
	  {
		 gStaticData = new int[m_Ammount];
		 delete[] gStaticData;
	  }

	  gResult +=loc;
   }
};

#define NEWDELETE_PERFORMANCE_TEST(name, className) \
struct className##MemoryPerfTest; \
static PerfTestMarker<className##MemoryPerfTest> className##PerfTestMarkerInstance(name); \
struct className##MemoryPerfTest : public MemoryNewDeleteTest

NEWDELETE_PERFORMANCE_TEST("memory/allocation/newdelete", MNewDeleteTest)
{
   static const char * getIndependentVariableName()
   {
      return "DATA_SIZE_ROW/MAX_TESTS * ";
   }

   static int getIndependentVariableMin()
   {
      return 1;
   }

   static int getIndependentVariableMax()
   {
      return MAX_TESTS;
   }


   void setIndependentVariable(int v)
   {
		m_Ammount =  DATA_SIZE_ROW/MAX_TESTS *(v);
   }

   void initialize()
   {
	  
   }
};
