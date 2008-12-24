#include <stdio.h>
#include "testUtilities/UtilLogger.h"
#include "testUtilities/UtilStats.h"
#include "harness/performanceHarness.h"

static FILE *xmlLog = NULL;
static int runCount = 0;

void UtilLogger::printHeader()
{
   // Open the XML log.
   fopen_s(&xmlLog, "times.xml", "w");
   fclose(xmlLog);

   fopen_s(&xmlLog, "times.xml", "w+");
   fputs("<PerformanceTests>\n", xmlLog);
   fclose(xmlLog);

   xmlLog = NULL;
}

void UtilLogger::startTest( PerfTestMarkerBase *test )
{
   runCount = 0;
   printf("Running %s\n", test->mName);

   fopen_s(&xmlLog, "times.xml", "a");
   fprintf_s(xmlLog, "<Entry><Title>%s</Title>", test->mName);
}

void UtilLogger::startTestWithIndependent(PerfTestMarkerBase *test, int independent)
{
   runCount = 0;
   printf("   - Trial with %s = %d\n", test->getIndependentVariableName(), independent);

   fopen_s(&xmlLog, "times.xml", "a");
   fprintf_s(xmlLog, "<Entry><Title>%s %s=%d</Title>", test->mName, test->getIndependentVariableName(), independent);
}

void UtilLogger::noteRun( double duration )
{
   runCount++;
   fprintf_s(xmlLog, "<DataPoint%d>%f</DataPoint%d>", runCount,duration,runCount);
}

void UtilLogger::endTest( UtilStats *statistics )
{
   fprintf_s(xmlLog, "<RunCount>%d</RunCount>", statistics->GetCount() );
   fprintf_s(xmlLog, "<Average>%f</Average><Min>%f</Min><Max>%f</Max><stdDev>%f</stdDev>", 
      statistics->GetMean(), statistics->GetMin(), statistics->GetMax(),statistics->GetStdDeviation());
   fprintf_s(xmlLog, "</Entry>\n");
   fclose(xmlLog);

   printf("   - Ran performance test %d times.\n", statistics->GetCount());
   printf("   - Timing: avg %lfms, min %lfms, max %lfms, stddev %lf\n", 
      statistics->GetMean(), statistics->GetMin(), statistics->GetMax(),statistics->GetStdDeviation());
}

void UtilLogger::printFooter()
{
   // Close the XML output.
   fopen_s(&xmlLog, "times.xml", "a");
   fputs("</PerformanceTests>\n", xmlLog);
   fclose(xmlLog);

   xmlLog = NULL;
}

void UtilLogger::startIndependentGroup( PerfTestMarkerBase *test )
{
   printf("Running %s with independent value %s (%d to %d)\n", 
      test->mName, test->getIndependentVariableName(), 
      test->getIndependentVariableMin(), test->getIndependentVariableMax());
}

void UtilLogger::endIndependentGroup()
{

}

void UtilLogger::endTestWithIndependent( UtilStats *statistics )
{
   endTest(statistics);
}