#ifndef _TESTUTILITIES_UTILLOGGER_H_
#define _TESTUTILITIES_UTILLOGGER_H_

class UtilStats;
class PerfTestMarkerBase;

class UtilLogger
{
public:
   void printHeader();

   void startTest(PerfTestMarkerBase *test);
   void startTestWithIndependent(PerfTestMarkerBase *test, int independent);
   void noteRun(double duration);
   void endTest(UtilStats *statistics);
   void endTestWithIndependent(UtilStats *statistics, int independent);

   void startIndependentGroup(PerfTestMarkerBase *test);
   void endIndependentGroup();

   void printFooter();
};

#endif