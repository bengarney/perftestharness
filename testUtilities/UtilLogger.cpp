#include <stdio.h>
#include <vector>
#include <string>
#include <math.h>
#include "testUtilities/UtilLogger.h"
#include "testUtilities/UtilStats.h"
#include "harness/performanceHarness.h"

static FILE *xmlLog = NULL;
static FILE *reportHtml = NULL;
static int runCount = 0;

struct SeriesData
{
   double min, max, mean, stdDev;
   int independent;
};

PerfTestMarkerBase *gCurrentTest = NULL;
std::vector<SeriesData> gSeries;

/************************************************************************/
/*
The following copyright message applies to curl_escape:

COPYRIGHT AND PERMISSION NOTICE

Copyright (c) 1996 - 2009, Daniel Stenberg, <daniel@haxx.se>.

All rights reserved.

Permission to use, copy, modify, and distribute this software for any purpose
with or without fee is hereby granted, provided that the above copyright
notice and this permission notice appear in all copies.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT OF THIRD PARTY RIGHTS. IN
NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE
OR OTHER DEALINGS IN THE SOFTWARE.

Except as contained in this notice, the name of a copyright holder shall not
be used in advertising or otherwise to promote the sale, use or other dealings
in this Software without prior written authorization of the copyright holder. */
/************************************************************************/
char *curl_escape(const char *string, int inlength = 0)
{
   size_t alloc = (inlength?(size_t)inlength:strlen(string))+1;
   char *ns;
   char *testing_ptr = NULL;
   unsigned char in;
   size_t newlen = alloc;
   int strindex=0;
   size_t length;

   ns = (char*)malloc(alloc);
   if(!ns)
      return NULL;

   length = alloc-1;
   while(length--) {
      in = *string;
      if(!(in >= 'a' && in <= 'z') &&
         !(in >= 'A' && in <= 'Z') &&
         !(in >= '0' && in <= '9')) {
            /* encode it */
            newlen += 2; /* the size grows with two, since this'll become a %XX */
            if(newlen > alloc) {
               alloc *= 2;
               testing_ptr = (char*)realloc(ns, alloc);
               if(!testing_ptr) {
                  free( ns );
                  return NULL;
               }
               else {
                  ns = testing_ptr;
               }
            }
            sprintf_s(&ns[strindex], 4, "%%%02X", in);

            strindex+=3;
      }
      else {
         /* just copy this */
         ns[strindex++]=in;
      }
      string++;
   }
   ns[strindex]=0; /* terminate it */
   return ns;
}

void UtilLogger::printHeader()
{
   // Open the XML log.
   fopen_s(&xmlLog, "times.xml", "w");
   fclose(xmlLog);

   fopen_s(&xmlLog, "times.xml", "w+");
   fputs("<PerformanceTests>\n", xmlLog);
   fclose(xmlLog);

   xmlLog = NULL;

   // Start the HTML
   fopen_s(&reportHtml, "report.html", "w");
   fclose(reportHtml);

   fopen_s(&reportHtml, "report.html", "w+");
   fputs("<h1>Performance Report</h1>\n", reportHtml);
   fclose(reportHtml);

}

void UtilLogger::startTest( PerfTestMarkerBase *test )
{
   runCount = 0;
   printf("Running %s\n", test->mName);

   fopen_s(&xmlLog, "times.xml", "a");
   fprintf_s(xmlLog, "<Entry><Title>%s</Title>", test->mName);

   fopen_s(&reportHtml, "report.html", "a");
   fprintf_s(reportHtml, "<p><b>#%d %s:</b> ", test->mTestID, test->mName);
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

void UtilLogger::endTest( UtilStats *statistics, bool suppressHtml )
{
   fprintf_s(xmlLog, "<RunCount>%d</RunCount>", statistics->GetCount() );
   fprintf_s(xmlLog, "<Average>%f</Average><Min>%f</Min><Max>%f</Max><stdDev>%f</stdDev>", 
      statistics->GetMean(), statistics->GetMin(), statistics->GetMax(),statistics->GetStdDeviation());
   fprintf_s(xmlLog, "</Entry>\n");

   fclose(xmlLog);

   printf("   - Ran performance test %d times.\n", statistics->GetCount());
   printf("   - Timing: avg %lfms, min %lfms, max %lfms, stddev %lf\n", 
      statistics->GetMean(), statistics->GetMin(), statistics->GetMax(),statistics->GetStdDeviation());

   if(!suppressHtml)
   {
      fprintf_s(reportHtml, "<br>Ran performance test %d times.", statistics->GetCount());
      fprintf_s(reportHtml, "<br>Timing: avg %lfms, min %lfms, max %lfms, stddev %lf</p>", 
         statistics->GetMean(), statistics->GetMin(), statistics->GetMax(),statistics->GetStdDeviation());
      fclose(reportHtml);
   }
}

void UtilLogger::endTestWithIndependent( UtilStats *statistics, int independent )
{
   endTest(statistics, true);

   // Note the results for printing a chart.
   SeriesData sd;
   sd.min = statistics->GetMin();
   sd.max = statistics->GetMax();
   sd.mean = statistics->GetMean();
   sd.stdDev = statistics->GetStdDeviation();
   sd.independent = independent;
   gSeries.push_back(sd);
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
   fopen_s(&reportHtml, "report.html", "a");

   printf("Running %s with independent value %s (%d to %d)\n", 
      test->mName, test->getIndependentVariableName(), 
      test->getIndependentVariableMin(), test->getIndependentVariableMax());

   gCurrentTest = test;
   gSeries.clear();
}

void printDoubleLabels(double min, double max, int numSteps, const char *units="")
{
   for(double i = min; i <= max; i += (max-min) / double(numSteps))
      fprintf_s(reportHtml, "%s%.2Lf%s", (i==min) ? "" : "|", i, units);
}

void printIntegerLabels(int min, int max, int numSteps, const char *units="")
{
   for(double i = min; i <= max; i += (max-min) / double(numSteps))
      fprintf_s(reportHtml, "%s%d%s", (i==min) ? "" : "|", (int)floor(i), units);
}

void smartPrintIndependentLabels(PerfTestMarkerBase *test)
{
   std::vector<int> independentValues;

   // Build list of independent values.
   for(int i=test->getIndependentVariableMin(); i<test->getIndependentVariableMax(); i++)
      if(test->checkSkipIndependentValue(i) == false)
         independentValues.push_back(i);

   /* // Filter the list to about 20 items somehow.
   while(independentValues.size() > 15 && false)
   {
      // Skip by half.
      for(int i=0; i<independentValues.size(); i+=2)
      {
         independentValues.erase(independentValues.begin() + i);
         i--;
      }
   } */

   // Output selected values with their positions.
   fprintf_s(reportHtml, "||1:");
   for(int i=0; i<independentValues.size(); i++)
      fprintf_s(reportHtml, "%s%d", "|", independentValues[i]);
   
   // Position is actually a bad idea, it just makes it hard to read.
   /*fprintf_s(reportHtml, "&chxp=1");
   for(int i=0; i<independentValues.size(); i++)
      fprintf_s(reportHtml, ",%d", (int)floor(double(i) / double(independentValues.size()) * 100.0)); */
}

void UtilLogger::endIndependentGroup()
{
   // Kick out an image showing the means. 500px wide, 300px tall
   fprintf_s(reportHtml, "<img src='http://chart.apis.google.com/chart?cht=bvs&chs=600x400");

   // Title.
   fprintf_s(reportHtml, "&chtt=No. %d %s", gCurrentTest->mTestID, curl_escape(gCurrentTest->mName));

   // Include the datapoints.
   // &chd=t:30,-60,50,120,80,-90
   fprintf_s(reportHtml, "&chd=t:");

   double min = 1e10;
   double max = -1e10;

   for(int i=0; i<gSeries.size(); i++)
   {
      fprintf_s(reportHtml, "%s%.2Lf", (i!=0) ? "," : "", gSeries[i].mean);

      if(min > gSeries[i].mean) min = gSeries[i].mean;
      if(max < gSeries[i].mean) max = gSeries[i].mean;
   }

   // Fudge min and max so that we never have more than 0.2ms per pixel.
   if(max - min < 60.0)
   {
      double avg = (max + min) / 2.0;
      
      if(avg < 15.0) avg = 15.0;

      max = avg + 15.0;
      min = avg - 15.0;
   }

   // Indicate min/max.
   // &chds=-80,150
   fprintf_s(reportHtml, "&chds=%.2Lf,%.2Lf", min, max);

   // Series labels.
   fprintf_s(reportHtml, "&chdlp=b&chdl=%s", curl_escape(gCurrentTest->getIndependentVariableName()));

   /* Axis labels.
   chxt=x,y,r,x
   chxl=
      0:|Jan|July|Jan|July|Jan|
      1:|0|50|100|
      2:|A|B|C|
      3:|2005|2006|2007
   */
   fprintf_s(reportHtml, "&chxt=y,x&chxl=0:|");
   printDoubleLabels(min, max, 10, "ms");
   smartPrintIndependentLabels(gCurrentTest);

   // Close the tag.
   fprintf_s(reportHtml, "'><br>\n");

   // Close the file.
   fclose(reportHtml);

   // Clean up.
   gCurrentTest = NULL;
   gSeries.clear();
}
