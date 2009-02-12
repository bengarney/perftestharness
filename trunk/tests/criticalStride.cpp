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
      return MAX_MEMORY_STEPS;
   }

   void setIndependentVariable(int v)
   {
      m_NumReads = DATA_SIZE/(MAX_MEMORY_STEPS-1) * v;
   }

   static bool checkSkipIndependentValue(int independentValue)
   {
		return!( independentValue%4==0 );
   }
};


#define CSMEMORY_PERFORMANCE_TEST(name, className) \
struct className##CSMemoryPerfTest; \
static PerfTestMarker<className##CSMemoryPerfTest> className##PerfTestMarkerInstance(name); \
struct className##CSMemoryPerfTest : public CSMemoryPerformanceTest



CSMEMORY_PERFORMANCE_TEST("memory/criticalStride/256", MCSStatic256)
{


   void initialize()
   {
      for(int i=0; i<DATA_SIZE; i++)
         accessPattern[i]=(i*64)%(DATA_SIZE);

	  initCriticalStride();
   }
};

CSMEMORY_PERFORMANCE_TEST("memory/criticalStride/512", MCSStatic512)
{


   void initialize()
   {
      for(unsigned int i=0; i<DATA_SIZE; i++)
         accessPattern[i]=(i*128)%(DATA_SIZE);

	  initCriticalStride();
   }
};

CSMEMORY_PERFORMANCE_TEST("memory/criticalStride/1024", MCSStatic1024)
{


   void initialize()
   {
      for(unsigned int i=0; i<DATA_SIZE; i++)
         accessPattern[i]=(i*256)%(DATA_SIZE);

	  initCriticalStride();
   }
};

CSMEMORY_PERFORMANCE_TEST("memory/criticalStride/2116", MCSStatic2116)
{


   void initialize()
   {
      for(unsigned int i=0; i<DATA_SIZE; i++)
         accessPattern[i]=(i*529)%(DATA_SIZE);

	  initCriticalStride();
   }
};

CSMEMORY_PERFORMANCE_TEST("memory/criticalStride/2048", MCSStatic2048)
{


   void initialize()
   {
      for(unsigned int i=0; i<DATA_SIZE; i++)
         accessPattern[i]=(i*512)%(DATA_SIZE);

	  initCriticalStride();
   }
};




CSMEMORY_PERFORMANCE_TEST("memory/criticalStride/4164", MCSStatic4164)
{


   void initialize()
   {
      for(unsigned int i=0; i<DATA_SIZE; i++)
         accessPattern[i]=(i*1041)%(DATA_SIZE);

	  initCriticalStride();
   }
};



CSMEMORY_PERFORMANCE_TEST("memory/criticalStride/4096", MCSStatic4096)
{


   void initialize()
   {
      for(unsigned int i=0; i<DATA_SIZE; i++)
         accessPattern[i]=(i*1024)%(DATA_SIZE);

	  initCriticalStride();
   }
};



CSMEMORY_PERFORMANCE_TEST("memory/criticalStride/8260", MCSStatic8260)
{


   void initialize()
   {
      for(unsigned int i=0; i<DATA_SIZE; i++)
         accessPattern[i]=(i*2065)%(DATA_SIZE);

	  initCriticalStride();
   }
};

CSMEMORY_PERFORMANCE_TEST("memory/criticalStride/8192", MCSStatic8192)
{


   void initialize()
   {
      for(unsigned int i=0; i<DATA_SIZE; i++)
         accessPattern[i]=(i*2048)%(DATA_SIZE);

	  initCriticalStride();
   }
};



CSMEMORY_PERFORMANCE_TEST("memory/criticalStride/16656", MCSStatic16656)
{


   void initialize()
   {
      for(unsigned int i=0; i<DATA_SIZE; i++)
         accessPattern[i]=(i*4164)%(DATA_SIZE);

	  initCriticalStride();
   }

};

CSMEMORY_PERFORMANCE_TEST("memory/criticalStride/16384", MCSStatic16384)
{


   void initialize()
   {
      for(unsigned int i=0; i<DATA_SIZE; i++)
         accessPattern[i]=(i*4096)%(DATA_SIZE);

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