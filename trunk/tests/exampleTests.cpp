#include "harness/performanceHarness.h"

/*************************************************************************
   HOW TO MAKE A PERFORMANCE TEST:

      1. Prepare the test header macro:

            PERFORMANCE_TEST("examples/basicTest", ExampleTest)

         The first parameter is the display name. Group them by category
         and delimit with slashes.

         The second parameter is the actual class name that will be used
         internally. It needs to be unique, ought to be descriptive, and
         is otherwise not used.

      2. Fill in the actual test. An empty version of the above test will
         look like:

            PERFORMANCE_TEST("examples/basicTest", ExampleTest)
            {
               void test()
               {
                  // Code to be timed is in here.
               }
            };

      3. Make sure the file containing the test is included in your project.

      4. Recompile, and run! 
      
         (If the test does not appear to be run, do a clean rebuild.)

*************************************************************************/

PERFORMANCE_TEST("examples/basicTest", ExampleTest)
{
   void test()
   {
      int numReads = 100000;
      int sum = 0;
      while(numReads--)
      {
         sum += numReads & 0x10101010;
      }
   }
};
