#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "harness/performanceHarness.h"

#define MAX_MEMORY_STEPS 65
#define DATA_SIZE (1024*1024)

__declspec(align(16)) static float gStaticData[DATA_SIZE];
static float gResult = 0;

void initStatic()
{
	for( int i=0;i<DATA_SIZE;i++ )
		gStaticData[i]=betterRandf();
}

static int last = 0;

class StaticMemoryPerformanceTest : public PerformanceTest
{
public:
   int m_NumReads;

   int accessPattern[DATA_SIZE];

   StaticMemoryPerformanceTest()
   {
      m_NumReads = 0;
      initStatic();
   }

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

   HeapMemoryPerformanceTest()
   {
      m_NumReads = 0;
      data = NULL;
   }

   virtual ~HeapMemoryPerformanceTest()
   {
      delete[] data;
   }

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

		for( int i=0;i<DATA_SIZE;i++ )
			gResult += data[i];
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

HEAPMEMORY_PERFORMANCE_TEST("memory/traverse/randomHeap", MTRRandomHeap)
{
   void initialize()
   {
      // Generate an access pattern for this run.
      for(int i=0; i<DATA_SIZE; i++)
         accessPattern[i]=betterRand()%(DATA_SIZE);
   }
};

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

   static bool checkSkipIndependentValue(int independentValue)
   {
		return!( independentValue%4==0 );
   }
};




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
         accessPattern[i]= (DATA_SIZE - i - 1);

	  initStatic();
   }

   static bool checkSkipIndependentValue(int independentValue)
   {
		return!( independentValue%4==0 );
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

   static bool checkSkipIndependentValue(int independentValue)
   {
		return!( independentValue%4==0 );
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

   static bool checkSkipIndependentValue(int independentValue)
   {
		return!( independentValue%4==0 );
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
      return MAX_MEMORY_STEPS;
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

   static bool checkSkipIndependentValue(int independentValue)
   {
		return!( independentValue%4==0 );
   }
};

STATICMEMORY_PERFORMANCE_TEST("memory/traverse/linearStep4ByteStatic", MTRLinearStep4Static)
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
         accessPattern[i]= (i*4)%(DATA_SIZE);

	  initStatic();
   }

   static bool checkSkipIndependentValue(int independentValue)
   {
		return!( independentValue%4==0 );
   }

};


STATICMEMORY_PERFORMANCE_TEST("memory/traverse/linearLT512byteRandomStatic", MTLT512byteRandomStatic)
{
   int m_stride;

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
      return 129;
   }

   void setIndependentVariable(int v)
   {
      m_stride=v;
   }

   void initialize()
   {
	   m_NumReads =  DATA_SIZE;

      for(unsigned int i=0; i<DATA_SIZE; i++)
         accessPattern[i]= i;

	  Scramble( accessPattern );
/*
	  for(unsigned int i=0; i<DATA_SIZE; i++)
         printf("%i, ",accessPattern[i]);

	  printf("\n ");
*/
	  initStatic();
   }

   static bool checkSkipIndependentValue(int independentValue)
   {
		return!( independentValue%8==0 );
   }

   void Scramble( int* scram )
   {

	   int strideSize = m_stride;

	   for( int i=0;i<DATA_SIZE;i+=strideSize )
	   {
			int ub = i+strideSize;
			if( ub>DATA_SIZE )
			ub = DATA_SIZE;

		   for( int j=i;j<ub;j++ )
		   {	
			    

			    int rand = randRange(i,ub);

				//swap
				int temp = scram[rand];
				scram[rand] =  scram[j];
				scram[j] = temp;
				
		   }
	   }
   }

   int randRange( int min, int max )
   {
	  int dist = (betterRand()*12345)%(max-min);
	  return min+dist;
   }


};