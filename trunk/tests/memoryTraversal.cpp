#include <stdio.h>
#include <stdlib.h>
#include "harness/performanceHarness.h"

#define MAX_MEMORY_STEPS 64
#define DATA_SIZE (1024 * 1024)
__declspec(align(16)) static float gStaticData[DATA_SIZE];
static float gResult = 0;


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
   int m_NumReads;

   int accessPattern[DATA_SIZE];

   void test()
   {
      float sum = 0;
      for(int i=0; i<m_NumReads; i++)
         sum += gStaticData[accessPattern[i]];

      gResult = sum;
   }
};



class HeapMemoryPerformanceTest : public PerformanceTest
{
public:
   int m_NumReads;

   int accessPattern[DATA_SIZE];
   float* data;

   virtual ~HeapMemoryPerformanceTest(){delete[] data;}

   void test()
   {
      float sum = 0;
      for(int i=0; i<m_NumReads; i++)
         sum += data[accessPattern[i]];

      gResult = sum;
   }

   void initHeap()
   {
		data = new float[DATA_SIZE];
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




/*
HEAPMEMORY_PERFORMANCE_TEST("memory/traverse/randomHeap", MTRRandomHeap)
{
   void initialize()
   {
      // Generate an access pattern for this run.
      for(int i=0; i<DATA_SIZE; i++)
         accessPattern[i]=betterRand()%(DATA_SIZE);
   }
};
*/

HEAPMEMORY_PERFORMANCE_TEST("memory/traverse/linearHeap", MTLinearHeap)
{
   static const char * getIndependentVariableName()
   {
      return "Data Amount";
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
      m_NumReads = DATA_SIZE/MAX_MEMORY_STEPS * v;
   }

   void initialize()
   {
      
      for(int i=0; i<DATA_SIZE; i++)
         accessPattern[i]= i;

	  initHeap();
   }
};


/*
HEAPMEMORY_PERFORMANCE_TEST("memory/traverse/linearBackwardsHeap", MTLinearBackwardsHeap)
{
   void initialize()
   {
      for(int i=0; i<DATA_SIZE; i++)
         accessPattern[i]= (DATA_SIZE - i) % (DATA_SIZE);
   }
};

HEAPMEMORY_PERFORMANCE_TEST("memory/traverse/linearStepHeap", MTLStepHeap)
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
      for(int i=0; i<DATA_SIZE; i++)
         accessPattern[i]= (i * stepSize) % (DATA_SIZE);


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
      return 1;
   }

   static int getIndependentVariableMax()
   {
      return 128;
   }


   void setIndependentVariable(int v)
   {
      stepSize = v*4;
   }

   void initialize()
   {
      for(int i=0; i<DATA_SIZE; i++)
         accessPattern[i]= (i * stepSize) % (DATA_SIZE);

	  initStatic();
   }
};
*/

STATICMEMORY_PERFORMANCE_TEST("memory/traverse/linearBackwardsStatic", MTRLinearBackwardsStatic)
{
   static const char * getIndependentVariableName()
   {
      return "Data Amount";
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
      m_NumReads = DATA_SIZE/MAX_MEMORY_STEPS * v;
   }

   void initialize()
   {
      for(int i=0; i<DATA_SIZE; i++)
         accessPattern[i]= (DATA_SIZE - i);

	  initStatic();
   }
};

STATICMEMORY_PERFORMANCE_TEST("memory/traverse/randomStatic", MTRRandomStatic)
{
   static const char * getIndependentVariableName()
   {
      return "Data Amount";
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
      m_NumReads = DATA_SIZE/MAX_MEMORY_STEPS * v;
   }

   void initialize()
   {
      for(int i=0; i<DATA_SIZE; i++)
         accessPattern[i]=(betterRand()*480)%(DATA_SIZE);

	  initStatic();
   }
};

STATICMEMORY_PERFORMANCE_TEST("memory/traverse/linearStatic", MTRLinearStatic)
{
   static const char * getIndependentVariableName()
   {
      return "Data Amount";
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
      m_NumReads = DATA_SIZE/MAX_MEMORY_STEPS * v;
   }

   void initialize()
   {
      for(int i=0; i<DATA_SIZE; i++)
         accessPattern[i]= i;

	  initStatic();
   }

};

STATICMEMORY_PERFORMANCE_TEST("memory/traverse/linearPseudoRandomStatic", MTRLinearStaticLT64byteRandom)
{
   int m_Stride;

   static const char * getIndependentVariableName()
   {
      return "Data Amount";
   }

   static int getIndependentVariableMin()
   {
      return 1;
   }

   static int getIndependentVariableMax()
   {
      return MAX_MEMORY_STEPS*2;
   }

   void setIndependentVariable(int v)
   {
	  m_Stride = v;    
   }

   void initialize()
   {
      m_NumReads = DATA_SIZE;

	  int ctr = 0;
      for(int i=0; i<DATA_SIZE; i+=m_Stride)
	  {
	     for( int j=0;j<m_Stride;j++ )
		 {
		    if( ctr<DATA_SIZE )
			{
				accessPattern[ctr++] = (i+((betterRand()*480)%m_Stride))%(DATA_SIZE);
			}
		 }
	  }

	  initStatic();
   }

};

STATICMEMORY_PERFORMANCE_TEST("memory/traverse/linearStep480ByteStatic", MTRLinearStep480Static)
{
   static const char * getIndependentVariableName()
   {
      return "Data Amount";
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
      m_NumReads = DATA_SIZE/MAX_MEMORY_STEPS * v;
   }

   void initialize()
   {
      for(unsigned int i=0; i<DATA_SIZE; i++)
         accessPattern[i]= (i*480)%(DATA_SIZE);

	  initStatic();
   }

};
