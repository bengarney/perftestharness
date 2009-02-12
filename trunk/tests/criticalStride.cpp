#include <stdio.h>
#include <stdlib.h>
#include "testUtilities/Iutil.h"
#include "harness/performanceHarness.h"

#define DATA_SIZE (1024*1024)
#define MAX_MEMORY_STEPS 65

static float gResult = 0;
static float* gStaticData = IUtil::Get()->GetUtilMemory()->GetStatic1024x1024_16_Aligned();

void initCriticalStride()
{
	for( int i=0;i<DATA_SIZE;i++ )
	{
		gStaticData[i]=betterRandf();
	}
}

class CSMemoryPerformanceTest : public PerformanceTest
{
public:
   int m_NumReads;

   unsigned int accessPattern[DATA_SIZE];

   void test()
   {
      float sum = 0;
      for(int i=0; i<m_NumReads; i++)
         sum += gStaticData[accessPattern[i]];

      gResult = sum;
   }

   static const char * getIndependentVariableName()
   {
      return "sizeof(DATA_SIZE/MAX_MEMORY_STEPS) * ";
   }

   static int getIndependentVariableMin()
   {
      return 1;
   }

   static int getIndependentVariableMax()
   {
      return 2;
   }

   void setIndependentVariable(int v)
   {
      
   }

   static bool checkSkipIndependentValue(int independentValue)
   {
		return!( independentValue%1==0 );
   }
};


#define CSMEMORY_PERFORMANCE_TEST(name, className) \
struct className##CSMemoryPerfTest; \
static PerfTestMarker<className##CSMemoryPerfTest> className##PerfTestMarkerInstance(name); \
struct className##CSMemoryPerfTest : public CSMemoryPerformanceTest




CSMEMORY_PERFORMANCE_TEST("memory/criticalStride/2116", MCSStatic2116)
{


   void initialize()
   {
      for(unsigned int i=0; i<DATA_SIZE; i++)
         accessPattern[i]=(i*529)%(DATA_SIZE);

	  initCriticalStride();

	  m_NumReads = DATA_SIZE/529;
   }
};

CSMEMORY_PERFORMANCE_TEST("memory/criticalStride/2048", MCSStatic2048)
{


   void initialize()
   {
      for(unsigned int i=0; i<DATA_SIZE; i++)
         accessPattern[i]=(i*512)%(DATA_SIZE);

	  initCriticalStride();
	
	  m_NumReads = DATA_SIZE/529;

   }
};




CSMEMORY_PERFORMANCE_TEST("memory/criticalStride/4164", MCSStatic4164)
{


   void initialize()
   {
      for(unsigned int i=0; i<DATA_SIZE; i++)
         accessPattern[i]=(i*1041)%(DATA_SIZE);

	  initCriticalStride();

	  m_NumReads = DATA_SIZE/1041;
   }
};



CSMEMORY_PERFORMANCE_TEST("memory/criticalStride/4096", MCSStatic4096)
{


   void initialize()
   {
      for(unsigned int i=0; i<DATA_SIZE; i++)
         accessPattern[i]=(i*1024)%(DATA_SIZE);

	  initCriticalStride();

	  m_NumReads = DATA_SIZE/1041;
   }
};



CSMEMORY_PERFORMANCE_TEST("memory/criticalStride/8260", MCSStatic8260)
{


   void initialize()
   {
      for(unsigned int i=0; i<DATA_SIZE; i++)
         accessPattern[i]=(i*2065)%(DATA_SIZE);

	  initCriticalStride();

	  m_NumReads = DATA_SIZE/2065;
   }
};

CSMEMORY_PERFORMANCE_TEST("memory/criticalStride/8192", MCSStatic8192)
{


   void initialize()
   {
      for(unsigned int i=0; i<DATA_SIZE; i++)
         accessPattern[i]=(i*2048)%(DATA_SIZE);

	  m_NumReads = DATA_SIZE/2065;

	  initCriticalStride();
   }
};



CSMEMORY_PERFORMANCE_TEST("memory/criticalStride/16656", MCSStatic16656)
{


   void initialize()
   {
      for(unsigned int i=0; i<DATA_SIZE; i++)
	  {

         accessPattern[i]=(i*4164)%(DATA_SIZE);
	  }

	  m_NumReads = DATA_SIZE/4164;

	  initCriticalStride();
   }

};

CSMEMORY_PERFORMANCE_TEST("memory/criticalStride/16384", MCSStatic16384)
{


   void initialize()
   {
      for(unsigned int i=0; i<DATA_SIZE; i++)
         accessPattern[i]=(i*4096)%(DATA_SIZE);

	  m_NumReads = DATA_SIZE/4164;

	  initCriticalStride();
   }

};

CSMEMORY_PERFORMANCE_TEST("memory/criticalStride/32836", MCSStatic32836)
{


   void initialize()
   {
      for(unsigned int i=0; i<DATA_SIZE; i++)
	  {

         accessPattern[i]=(i*8209)%(DATA_SIZE);
	  }

	  m_NumReads = DATA_SIZE/8209;

	  initCriticalStride();
   }

};

CSMEMORY_PERFORMANCE_TEST("memory/criticalStride/32768", MCSStatic32768)
{


   void initialize()
   {
      for(unsigned int i=0; i<DATA_SIZE; i++)
         accessPattern[i]=(i*8192)%(DATA_SIZE);

	  m_NumReads = DATA_SIZE/8209;

	  initCriticalStride();
   }

};
/*
CSMEMORY_PERFORMANCE_TEST("memory/criticalStride/4", MCSStatic1)
{


   void initialize()
   {
      for(unsigned int i=0; i<DATA_SIZE; i++)
         accessPattern[i]=i;

	  initCriticalStride();
   }
};*/