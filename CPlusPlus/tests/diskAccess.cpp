#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <assert.h>

#include "harness/performanceHarness.h"
#include "testUtilities/mandelbrot.h"

#define TEST_FILE_SIZE 50*1024*1024
#define TEST_FILE_NAME "performanceTestDataFile"

#define MANDELBROT_WORKLOAD 256
#define THREAD_READ_SIZE 64

/// Helper to read from a file in order with a specified read size.
struct DiskReadHelper
{
   DiskReadHelper(int rs = 1<<16)
   {
      file = fopen(TEST_FILE_NAME, "rb");
      curOffset = 0;
      readSize = rs;
      readBuff = malloc(rs);
   }

   ~DiskReadHelper()
   {
      fclose(file);
      free(readBuff);
   }


   FILE *file;
   int curOffset;
   int readSize;
   void *readBuff;

   bool Read()
   {
      if(curOffset >= TEST_FILE_SIZE)
         return false;

      // Read.
      fread(readBuff, readSize, 1, file);
      curOffset += readSize;
      return true;
   }

   static void CreateTestFile()
   {
      // Create a scratch file for IO.
      FILE *f = fopen(TEST_FILE_NAME, "wb");
      for(int i=0; i<TEST_FILE_SIZE/4; i++)
         fwrite(&i, sizeof(int), 1, f);
      fclose(f);
   }

   static void DestroyTestFile()
   {
      // Nuke the scratch file.
      unlink(TEST_FILE_NAME);
   }
};

struct DiskPerformanceTest : public PerformanceTest
{
   void initialize()
   {
      DiskReadHelper::CreateTestFile();
   }

   void teardown()
   {
      DiskReadHelper::DestroyTestFile();
   }
};

struct DiskReadPerformanceTest : public DiskPerformanceTest
{
   int readSize;

   static const char * getIndependentVariableName()
   {
      return "read size";
   }

   static int getIndependentVariableMin()
   {
      return 1;
   }

   static int getIndependentVariableMax()
   {
      return 1<<16;
   }

   void setIndependentVariable(int v)
   {
      readSize = v;
   }

   static bool checkSkipIndependentValue(int independentValue)
   {
      return  !(((independentValue != 0) && !(independentValue & (independentValue - 1))));
   }

   void test()
   {
      DiskReadHelper drh(readSize);
      while(drh.Read());
   }
};

PERFORMANCE_TEST_SPECIALIZED("disk/readSizeSmall", DiskReadSizeSmall, DiskReadPerformanceTest, 13001)
{
   static int getIndependentVariableMin()
   {
      return 1;
   }

   static int getIndependentVariableMax()
   {
      return 17;
   }
};

PERFORMANCE_TEST_SPECIALIZED("disk/readSizeMedium", DiskReadSizeMedium, DiskReadPerformanceTest, 13002)
{
   static int getIndependentVariableMin()
   {
      return 32;
   }

   static int getIndependentVariableMax()
   {
      return (1<<9)+1;
   }
};

PERFORMANCE_TEST_SPECIALIZED("disk/readSizeBig", DiskReadSizeBig, DiskReadPerformanceTest, 13003)
{
   static int getIndependentVariableMin()
   {
      return 1<<10;
   }

   static int getIndependentVariableMax()
   {
      return TEST_FILE_SIZE;
   }
};

DWORD WINAPI BackgroundIO(LPVOID lpParameter)
{
   DiskReadHelper drh(THREAD_READ_SIZE);
   int count = MANDELBROT_WORKLOAD*MANDELBROT_WORKLOAD*4;
   while(drh.Read() && count-- > 0);
   assert(count == -1 && drh.Read());
   ExitThread(0);
}

PERFORMANCE_TEST("disk/threads/backgroundThread", DiskReadBackgroundThread, 13004)
{
   void initialize()
   {
      DiskReadHelper::CreateTestFile();
   }

   void teardown()
   {
      DiskReadHelper::DestroyTestFile();
   }

   void test()
   {
      // Kick off background IO thread.
      HANDLE bgthread = CreateThread(NULL, 0, &BackgroundIO, NULL, 0, 0);

      // Solve the mandelbrot set.
      fractalLinear(NULL, MANDELBROT_WORKLOAD);

      // Wait for thread.
      WaitForSingleObject(bgthread, INFINITE);
   }
};


PERFORMANCE_TEST("disk/threads/foregroundThread", DiskReadForegroundThread, 13005)
{
   void initialize()
   {
      DiskReadHelper::CreateTestFile();
   }

   void teardown()
   {
      DiskReadHelper::DestroyTestFile();
   }

   static DiskReadHelper *drh;
   static void doRead()
   {
      drh->Read();
      drh->Read();
      drh->Read();

      // Make sure we have something to read.
      if(!drh->Read())
      {
         assert(false);
      }
   }

   void test()
   {
      drh = new DiskReadHelper(THREAD_READ_SIZE);
      
      // Solve the mandelbrot set, reading in between pixels
      fractalLinear(doRead, MANDELBROT_WORKLOAD);

      delete drh;
   }
};

DiskReadHelper *DiskReadForegroundThreadPerfTest::drh = NULL;

PERFORMANCE_TEST("disk/threads/foregroundThreadNoCompute", DiskReadForegroundThreadNoCompute, 13006)
{
   void initialize()
   {
      DiskReadHelper::CreateTestFile();
   }

   void teardown()
   {
      DiskReadHelper::DestroyTestFile();
   }

   static DiskReadHelper *drh;
   static void doRead()
   {
      drh->Read();
   }

   void test()
   {
      drh = new DiskReadHelper(THREAD_READ_SIZE);
      int count = MANDELBROT_WORKLOAD*MANDELBROT_WORKLOAD*4;
      while(drh->Read() && count-- > 0);
      assert(count == -1 && drh->Read());

      delete drh;
      drh = NULL;
   }
};

DiskReadHelper *DiskReadForegroundThreadNoComputePerfTest::drh = NULL;
