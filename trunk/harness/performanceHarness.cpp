#include <windows.h>
#include <assert.h>
#include <stdio.h>

#include "performanceHarness.h"
#include "mtwist/mtwist.h"
#include "testUtilities/IUtil.h"

// How many times to run tests?
unsigned int gRunNum = 10;

// Rand helper code.
unsigned int betterRand()
{
   return (unsigned int)mt_lrand();
}

float betterRandf()
{
   return (float)mt_drand();
}

// Statics for the performance test list.
PerfTestMarkerBase *PerfTestMarkerBase::smHead = NULL;

void doTestRun(PerfTestMarkerBase *walk)
{
   double avgTime = 0.0, minTime = 100000000.0, maxTime = 0.0;
   unsigned int runCount = 0;

   double startTime = currentTime();

   IUtil::Get()->GetUtilLogger()->startTest(walk);

   walk->initialize();

   IUtil::Get()->GetUtilStats()->Reset();

   // Run it at least 10 times or 1 second.
   //while(runCount < 1 || (currentTime() - startTime) < 2.0)
   while(runCount < gRunNum )
   {
      // Init the cache to a standard
      IUtil::Get()->GetUtilCacheRandomizer()->Init();
      IUtil::Get()->GetUtilCacheRandomizer()->ScrambleCache();

      // Run the test.
      double duration = walk->runTest();

      // Record results.
      IUtil::Get()->GetUtilLogger()->noteRun(duration);
      IUtil::Get()->GetUtilStats()->AddDataPoint(duration);

      // Track so we can terminate.
      runCount++;
   }

   // Teardown the test.
   walk->teardown();

   // Note completion of test.
   IUtil::Get()->GetUtilLogger()->endTest(IUtil::Get()->GetUtilStats());
}

void runTestWithIndependent(PerfTestMarkerBase *walk, int independentValue)
{
   double avgTime = 0.0, minTime = 100000000.0, maxTime = 0.0;
   unsigned int runCount = 0;

   IUtil::Get()->GetUtilLogger()->startTestWithIndependent(walk, independentValue);

   double startTime = currentTime();

   walk->initializeWithIndependent(independentValue);

   IUtil::Get()->GetUtilStats()->Reset();

   // Run it at least a hundred times or 1 second.
   //while(runCount < 1 || (currentTime() - startTime) < 2.0)
   while( runCount < gRunNum )
   {
      // Init the cache to a standard
      IUtil::Get()->GetUtilCacheRandomizer()->Init();
      IUtil::Get()->GetUtilCacheRandomizer()->ScrambleCache();

      // Run the test.
      double duration = walk->runTest();

      // Record results.
      IUtil::Get()->GetUtilLogger()->noteRun(duration);
      IUtil::Get()->GetUtilStats()->AddDataPoint(duration);

      // Track so we can terminate.
      runCount++;
   }

   walk->teardown();

   // Note completion of test.
   IUtil::Get()->GetUtilLogger()->endTestWithIndependent(IUtil::Get()->GetUtilStats(), independentValue);
}

/************************************************************************/
/* Helper function to run a test one or more times.                     */
/************************************************************************/
void runTest( PerfTestMarkerBase * walk )
{
   // Check if we have independent variables...
   if(walk->getIndependentVariableName() == NULL)
   {
      // Nope, no independent. So run the test.
      doTestRun(walk);
   }
   else
   {
      IUtil::Get()->GetUtilLogger()->startIndependentGroup(walk);

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

      IUtil::Get()->GetUtilLogger()->endIndependentGroup();
   }
}

// Our main function.
int main(int argc, char* argv[])
{	
   // Initialize the random number generator.
   mt_bestseed();

   initTimer();

   // Initialize the utilities.
   IUtil::Get();

   // Try to run just so, so that we are consistent.
   SetThreadPriority( GetCurrentThread(),THREAD_PRIORITY_ABOVE_NORMAL );

   DWORD ProcessAffinityMask = 0x01;
   HANDLE hCurrentProcess = GetCurrentProcess();     
   SetProcessAffinityMask( hCurrentProcess, (DWORD_PTR)&ProcessAffinityMask );

   bool writeHeader = true;
   bool writeFooter = true;
   bool createProcess = true;
   bool fast = false;
   bool exit = false;

   for( int i=0;i<argc;i++ )
   {
      if( strcmp(argv[i],"-force")==0 )
      {
         writeHeader = true;
         writeFooter = true;
         createProcess = false;

      }

      if( strcmp(argv[i],"-run")==0 )
      {
         writeHeader = false;
         writeFooter = false;
         createProcess = false;
      }

      //aids in debugging
      if( strcmp(argv[i],"-fast")==0 )
      {
         fast=true;
         gRunNum = 1;
      }

      //aids in using v-tune
      if( strcmp(argv[i],"-exit")==0 )
      {
         exit=true;
      }
   }

   if( writeHeader )
      IUtil::Get()->GetUtilLogger()->printHeader();

   STARTUPINFOA si;
   PROCESS_INFORMATION pi;

   ZeroMemory( &si, sizeof(si) );
   si.cb = sizeof(si);
   ZeroMemory( &pi, sizeof(pi) );

   for(PerfTestMarkerBase *walk=PerfTestMarkerBase::smHead; walk; walk=walk->mNext)
   {
      // Check for prefix match...
      if( argc!=1 )
      if( argv[argc-1][0] != '-' && strstr( walk->mName,argv[argc-1])==0 )
         continue;

      if( createProcess )
      {
         char args[512];
         if( !fast )
            sprintf_s( args,"-run %s",walk->mName );
         else
            sprintf_s( args,"-run -fast %s",walk->mName );

         printf("Creating new process: %s\n",args);

         if( !CreateProcessA("performanceHarness.exe",(LPSTR)args,0,0,false,0,0,0,&si,&pi))
            printf("Please set your working directory and try again.");

         WaitForSingleObject(pi.hProcess,INFINITE);
         printf("Process Closed process\n");
      }
      else
      {
         runTest( walk );
      }
   }

   if( writeFooter )
   {
      IUtil::Get()->GetUtilLogger()->printFooter();

      if( !exit )
      {
         // Give user a chance to respond.
         printf("Press ENTER to continue...\n");
         getc(stdin);
      }
   }

   return 0;
}