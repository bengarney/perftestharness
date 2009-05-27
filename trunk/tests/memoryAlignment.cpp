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

PERFORMANCE_TEST("memory/alignment/linearUnalignedStatic", MTUnalignedStepStatic, 8000)
{
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

PERFORMANCE_TEST("memory/alignment/linearAlignedStatic", MTAlignedLStepStatic, 8000)
{
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

   void initialize()
   {
	  initStaticAlignment();
   }

   static bool checkSkipIndependentValue(int independentValue)
   {
		return!( independentValue%4==0 );
   }
};