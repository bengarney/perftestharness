#include <windows.h>
#include <assert.h>
#include <stdio.h>

#include "performanceHarness.h"

// Statics for the performance test list.
PerfTestMarkerBase *PerfTestMarkerBase::smHead = NULL;

// Our main function.
int main(int argc, char* argv[])
{
   for(PerfTestMarkerBase *walk=PerfTestMarkerBase::smHead; walk; walk=walk->mNext)
   {
      double avgTime = 0.0, minTime = 100000000.0, maxTime = 0.0;
      int runCount = 0;

      printf("Running %s\n", walk->mName);

      double startTime = currentTime();

      // Run it at least a hundred times or 1 second.
      while(runCount < 100 || (currentTime() - startTime) < 1.0)
      {
         // Run the test.
         double duration = walk->runTest();

         // Update min.
         if(duration < minTime)
            minTime = duration;

         // Update max.
         if(duration > maxTime)
            maxTime = duration;
         
         // Update average.
         avgTime += duration;
         runCount++;
      }

      printf("   - Ran performance test %d times.\n", runCount);
      printf("   - Timing: avg %lfms, min %lfms, max %lfms\n", avgTime / double(runCount), minTime, maxTime);
   }

   printf("Press ENTER to continue...\n");
   getc(stdin);

	return 0;
}