#include <windows.h>
#include <assert.h>
#include <stdio.h>

#include "performanceHarness.h"

FILE *xmlLog = NULL;

// Statics for the performance test list.
PerfTestMarkerBase *PerfTestMarkerBase::smHead = NULL;

void runTest(PerfTestMarkerBase *walk)
{
   double avgTime = 0.0, minTime = 100000000.0, maxTime = 0.0;
   int runCount = 0;

   printf("Running %s\n", walk->mName);

   fprintf_s(xmlLog, "<Entry><Title>%s</Title>", walk->mName);

   double startTime = currentTime();

   walk->initialize();

   // Run it at least a hundred times or 1 second.
   while(runCount < 10000 || (currentTime() - startTime) < 10.0)
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

   walk->teardown();

   fprintf_s(xmlLog, "<RunCount>%d</RunCount>", runCount);
   fprintf_s(xmlLog, "<Average>%f</Average><Min>%f</Min><Max>%f</Max>", avgTime / double(runCount), minTime, maxTime);
   fprintf_s(xmlLog, "</Entry>\n");

   printf("   - Ran performance test %d times.\n", runCount);
   printf("   - Timing: avg %lfms, min %lfms, max %lfms\n", avgTime / double(runCount), minTime, maxTime);
}

void runTestWithIndependent(PerfTestMarkerBase *walk, int independentValue)
{
   double avgTime = 0.0, minTime = 100000000.0, maxTime = 0.0;
   int runCount = 0;

   printf("   - Trial with %s = %d\n", walk->getIndependentVariableName(), independentValue);

   fprintf_s(xmlLog, "<Entry><Title>%s %s=%d</Title>", walk->mName, walk->getIndependentVariableName(), independentValue);

   double startTime = currentTime();

   walk->initializeWithIndependent(independentValue);

   // Run it at least a hundred times or 1 second.
   while(runCount < 10000 || (currentTime() - startTime) < 10.0)
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

   walk->teardown();

   fprintf_s(xmlLog, "<RunCount>%d</RunCount>", runCount);
   fprintf_s(xmlLog, "<Average>%f</Average><Min>%f</Min><Max>%f</Max>", avgTime / double(runCount), minTime, maxTime);

   fprintf_s(xmlLog, "</Entry>\n");

   printf("      o Ran performance test %d times.\n", runCount);
   printf("      o Timing: avg %lfms, min %lfms, max %lfms\n", avgTime / double(runCount), minTime, maxTime);
}

// Our main function.
int main(int argc, char* argv[])
{
   // Open the XML log.
   fopen_s(&xmlLog, "times.xml", "w+");
   fputs("<PerformanceTests>\n", xmlLog);

   for(PerfTestMarkerBase *walk=PerfTestMarkerBase::smHead; walk; walk=walk->mNext)
   {
      // Check for prefix match...
      if(argc > 1 && _strnicmp(argv[1], walk->mName, strlen(argv[1])))
         continue;


      // Check if we have independent variables...
      if(walk->getIndependentVariableName() == NULL)
      {
         // Nope, no independent. So run the test.
         runTest(walk);
      }
      else
      {
         printf("Running %s with independent value %s (%d to %d)\n", 
            walk->mName, walk->getIndependentVariableName(), 
            walk->getIndependentVariableMin(), walk->getIndependentVariableMax());

         // We have an independent variable. So iterate through it, running
         // the test for each value.
         for(int independentValue = walk->getIndependentVariableMin(); 
            independentValue < walk->getIndependentVariableMax(); 
            independentValue++)
         {
            // Let the test indicate if it wants to skip.
            if(walk->checkSkipIndependentValue(independentValue))
               continue;

            runTestWithIndependent(walk, independentValue);
         }
      }
   }

   // Close the XML output.
   fputs("</PerformanceTests>\n", xmlLog);
   fclose(xmlLog);

   // Give user a chance to respond.
   printf("Press ENTER to continue...\n");
   getc(stdin);

	return 0;
}