#include <windows.h>
#include <assert.h>
#include <stdio.h>

#include "performanceHarness.h"
#include "mtwist/mtwist.h"
#include "testUtilities/IUtil.h"

FILE *xmlLog = NULL;

unsigned int gRunNum = 30;

//prototype
void RunTest( PerfTestMarkerBase * walk );

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

   IUtil::GetInstance()->GetUtilStats()->Reset();



   // Run it at least 10 times or 1 second.
   //while(runCount < 1 || (currentTime() - startTime) < 2.0)
   while(runCount < gRunNum )
   {
	      // Init the cache to a standard
	   IUtil::GetInstance()->GetUtilCacheRandomizer()->Init(8388608);
	   IUtil::GetInstance()->GetUtilCacheRandomizer()->ScrambleCache();

      // Run the test.
      double duration = walk->runTest();
	  fprintf_s(xmlLog, "<DataPoint%d>%f</DataPoint%d>", runCount,duration,runCount);

      // Update min.
      if(duration < minTime)
         minTime = duration;

      // Update max.
      if(duration > maxTime)
         maxTime = duration;

      // Update stats
	  IUtil::GetInstance()->GetUtilStats()->AddDataPoint(duration);
	  runCount++;
   }

   walk->teardown();

   int count = IUtil::GetInstance()->GetUtilStats()->GetCount();
   double average = IUtil::GetInstance()->GetUtilStats()->GetMean();
   double stdDev = IUtil::GetInstance()->GetUtilStats()->GetStdDeviation();

   fprintf_s(xmlLog, "<RunCount>%d</RunCount>", count );
   fprintf_s(xmlLog, "<Average>%f</Average><Min>%f</Min><Max>%f</Max><stdDev>%f</stdDev>", average, minTime, maxTime,stdDev);
   fprintf_s(xmlLog, "</Entry>\n");

   printf("   - Ran performance test %d times.\n", count);
   printf("   - Timing: avg %lfms, min %lfms, max %lfms, stddev\n", average, minTime, maxTime,stdDev);
}

void runTestWithIndependent(PerfTestMarkerBase *walk, int independentValue)
{
   double avgTime = 0.0, minTime = 100000000.0, maxTime = 0.0;
   int runCount = 0;

   printf("   - Trial with %s = %d\n", walk->getIndependentVariableName(), independentValue);

   fprintf_s(xmlLog, "<Entry><Title>%s %s=%d</Title>", walk->mName, walk->getIndependentVariableName(), independentValue);

   double startTime = currentTime();

   walk->initializeWithIndependent(independentValue);

   IUtil::GetInstance()->GetUtilStats()->Reset();

   // Run it at least a hundred times or 1 second.
   //while(runCount < 1 || (currentTime() - startTime) < 2.0)
   while( runCount < gRunNum )
   {
	   // Init the cache to a standard
	  IUtil::GetInstance()->GetUtilCacheRandomizer()->Init(8388608);
      IUtil::GetInstance()->GetUtilCacheRandomizer()->ScrambleCache();
	  

      // Run the test.
      double duration = walk->runTest();
	  fprintf_s(xmlLog, "<DataPoint%d>%f</DataPoint%d>", runCount,duration,runCount);
      // Update min.
      if(duration < minTime)
         minTime = duration;

      // Update max.
      if(duration > maxTime)
         maxTime = duration;

      // Update stats
	  IUtil::GetInstance()->GetUtilStats()->AddDataPoint(duration);
	  runCount++;
   }

   walk->teardown();

   int count = IUtil::GetInstance()->GetUtilStats()->GetCount();
   double average = IUtil::GetInstance()->GetUtilStats()->GetMean();
   double stdDev = IUtil::GetInstance()->GetUtilStats()->GetStdDeviation();

   fprintf_s(xmlLog, "<RunCount>%d</RunCount>", count );
   fprintf_s(xmlLog, "<Average>%f</Average><Min>%f</Min><Max>%f</Max><stdDev>%f</stdDev>", average, minTime, maxTime,stdDev);
   fprintf_s(xmlLog, "</Entry>\n");

   printf("   - Ran performance test %d times.\n", count);
   printf("   - Timing: avg %lfms, min %lfms, max %lfms, stddev%lfms\n", average, minTime, maxTime,stdDev);
}

// Our main function.
int main(int argc, char* argv[])
{
	// Initialize the random number generator.
	mt_bestseed();

	initTimer();
	IUtil::GetInstance();//init utillities

	SetThreadPriority( GetCurrentThread(),THREAD_PRIORITY_ABOVE_NORMAL );
		
	DWORD ProcessAffinityMask = 0x01;
	HANDLE hCurrentProcess = GetCurrentProcess();     
	SetProcessAffinityMask( hCurrentProcess, (DWORD_PTR)&ProcessAffinityMask );

	SetThreadIdealProcessor( GetCurrentThread(),1);
  
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
   {
	   
		   // Open the XML log.
			fopen_s(&xmlLog, "times.xml", "w");
			fclose(xmlLog);

			fopen_s(&xmlLog, "times.xml", "w+");
			fputs("<PerformanceTests>\n", xmlLog);
			fclose(xmlLog);
   }

	STARTUPINFOA si;
	PROCESS_INFORMATION pi;

	ZeroMemory( &si, sizeof(si) );
	si.cb = sizeof(si);
	ZeroMemory( &pi, sizeof(pi) );

	for(PerfTestMarkerBase *walk=PerfTestMarkerBase::smHead; walk; walk=walk->mNext)
	{
		  // Check for prefix match...
		  if(argc > 2 && _strnicmp(argv[argc-1], walk->mName, strlen(argv[argc-1])))
			 continue;

		  if( createProcess )
		  {
			  char args[512];
			  if( !fast )
			  {
				sprintf_s( args,"-run %s",walk->mName );
			  }else
			  {
				sprintf_s( args,"-run -fast %s",walk->mName );
			  }
			  printf("Creating new process: %s\n",args);
			  CreateProcessA("performanceHarness.exe",(LPSTR)args,0,0,false,0,0,0,&si,&pi);
			  WaitForSingleObject(pi.hProcess,INFINITE);
			  printf("Process Closed process\n");
		  
		  }else
		  {
			 RunTest( walk );
		  }
	}

   	if( writeFooter )
	{
		// Close the XML output.
	   fopen_s(&xmlLog, "times.xml", "a");
	   fputs("</PerformanceTests>\n", xmlLog);
	   fclose(xmlLog);
  
       if( !exit )
	   {
		   // Give user a chance to respond.
		   printf("Press ENTER to continue...\n");
		   getc(stdin);
	   }
	}

   return 0;
}

void RunTest( PerfTestMarkerBase * walk )
{
	fopen_s(&xmlLog, "times.xml", "a");
	
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

	fclose(xmlLog);
}

unsigned int betterRand()
{
   return (unsigned int)mt_lrand();
}