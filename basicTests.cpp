#include <stdio.h>
#include "windows.h"
#include "performanceHarness.h"

PERFORMANCE_TEST("basic/delay/10ms", Delay10ms)
{
   void test()
   {
      Sleep(10);
   }
};

PERFORMANCE_TEST("basic/delay/1ms", Delay1ms)
{
   void test()
   {
      Sleep(1);
   }
};

PERFORMANCE_TEST("basic/control/100000rand", RandomControl)
{
   void test()
   {
      int numReads = 100000;
      int sum = 0;
      while(numReads--)
      {
         sum += rand();
      }
   }
};

PERFORMANCE_TEST("basic/control/100000sum", SumControl)
{
   void test()
   {
      int numReads = 100000;
      int sum = 0;
      while(numReads--)
      {
         sum ++;
      }
   }
};
