#include <stdio.h>
#include <stdlib.h>
#include "performanceHarness.h"

#define DATA_SIZE 1024 * 1024 * 16
static char data[1024 * 1024 * 16];

PERFORMANCE_TEST("memory/traverse/random", MTR)
{
   void test()
   {
      int numReads = 100000;
      int sum = 0;
      while(numReads--)
      {
         sum += data[ rand() % DATA_SIZE ];
      }
   }
};

PERFORMANCE_TEST("memory/traverse/linear", MTL)
{
   void test()
   {
      int numReads = 0;
      int sum = 0;
      while(numReads < 100000)
      {
         sum += data[ numReads ];
         numReads++;
      }
   }
};

PERFORMANCE_TEST("memory/traverse/linearStep", MTLStep)
{
   int stepSize;

   static const char * getIndependentVariableName()
   {
      return "step size (b)";
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

   void test()
   {
      int numReads = 0;
      int sum = 0;
      while(numReads < 100000)
      {
         sum += data[ (numReads * stepSize) % DATA_SIZE ];
         numReads++;
      }
   }
};
