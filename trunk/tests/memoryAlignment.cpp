#include <stdio.h>
#include <stdlib.h>
#include "harness/performanceHarness.h"

#define MAX_ALIGMENT_TEST 65
#define DATA_SIZE (1024 * 1024)
__declspec(align(16)) static char gStaticDataAligment[DATA_SIZE*sizeof(int)];
static int gResult = 0;


void initStaticAlignment()
{
	for( int i=0;i<DATA_SIZE;i++ )
	{
		((int*)gStaticDataAligment)[i]=rand();
	}
}

class StaticMemoryUnAlignedPerformanceTest : public PerformanceTest
{
public:

   int m_NumReads;

   void test()
   {
      int* pInt = (int*)&gStaticDataAligment[1];
      for(int i=0; i<m_NumReads-1; i++)
	  {
	    gResult+= *pInt;
		pInt++;
	  }
   }
};

class StaticAlignedPerformanceTest : public PerformanceTest
{

public:

   int m_NumReads;

   void test()
   {
      int* pInt = (int*)&gStaticDataAligment;
      for(int i=0; i<m_NumReads-1; i++)
	  {
	    gResult+= *pInt;
		pInt++;
	  }
   }
};

#define UALIGNMENTMEMORY_PERFORMANCE_TEST(name, className) \
struct className##MemoryPerfTest; \
static PerfTestMarker<className##MemoryPerfTest> className##PerfTestMarkerInstance(name); \
struct className##MemoryPerfTest : public StaticMemoryUnAlignedPerformanceTest

#define ALIGNMENTMEMORY_PERFORMANCE_TEST(name, className) \
struct className##MemoryPerfTest; \
static PerfTestMarker<className##MemoryPerfTest> className##PerfTestMarkerInstance(name); \
struct className##MemoryPerfTest : public StaticAlignedPerformanceTest

UALIGNMENTMEMORY_PERFORMANCE_TEST("memory/alignment/linearUnalignedStatic", MTUnalignedStepStatic)
{

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
      return MAX_ALIGMENT_TEST;
   }

   void setIndependentVariable(int v)
   {
      m_NumReads = (DATA_SIZE)/(MAX_ALIGMENT_TEST-1) * v;
   }

    static bool checkSkipIndependentValue(int independentValue)
   {
		return!( independentValue%4==0 );
   }

   void initialize()
   {
	  initStaticAlignment();
   }
};

ALIGNMENTMEMORY_PERFORMANCE_TEST("memory/alignment/linearAlignedStatic", MTAlignedLStepStatic)
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
      return MAX_ALIGMENT_TEST;
   }

   void setIndependentVariable(int v)
   {
      m_NumReads = (DATA_SIZE)/(MAX_ALIGMENT_TEST-1) * v;
   }

   void initialize()
   {
	  initStaticAlignment();
   }

   static bool checkSkipIndependentValue(int independentValue)
   {
		return!( independentValue%4==0 );
   }
};