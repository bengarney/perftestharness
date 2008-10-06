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

PERFORMANCE_TEST("memory/traverse/linearStep100Byte", MTLStep100Byte)
{
   void test()
   {
      int numReads = 0;
      int sum = 0;
      while(numReads < 100000)
      {
         sum += data[ (numReads * 100) % DATA_SIZE ];
         numReads++;
      }
   }
};

PERFORMANCE_TEST("memory/traverse/linearStep8Byte", MTLStep8Byte)
{
   void test()
   {
      int numReads = 0;
      int sum = 0;
      while(numReads < 100000)
      {
         sum += data[ (numReads * 8) % DATA_SIZE ];
         numReads++;
      }
   }
};

PERFORMANCE_TEST("memory/traverse/linearStep32Byte", MTLStep32Byte)
{
   void test()
   {
      int numReads = 0;
      int sum = 0;
      while(numReads < 100000)
      {
         sum += data[ (numReads * 32) % DATA_SIZE ];
         numReads++;
      }
   }
};

PERFORMANCE_TEST("memory/traverse/linearStep33Byte", MTLStep33Byte)
{
   void test()
   {
      int numReads = 0;
      int sum = 0;
      while(numReads < 100000)
      {
         sum += data[ (numReads * 33) % DATA_SIZE ];
         numReads++;
      }
   }
};