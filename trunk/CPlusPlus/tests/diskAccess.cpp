#include <process.h>
#define _WIN32_WINNT 0x400 
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <direct.h>
#include <sys/stat.h>

#include "harness/performanceHarness.h"
#include "testUtilities/mandelbrot.h"
#include "testUtilities/IUtil.h"

#define STBI_SIMD 1
#define STBI_HEADER_FILE_ONLY
#include "testUtilities/stb_image.c"

#define TEST_FILE_SIZE 50*1024*1024
#define TEST_FILE_NAME "performanceTestDataFile"
#define TEST_DIRECTORY "./testFiles"

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

   static const char *getIndependentVariableName()
   {
      return "number of IO threads";
   }

   static int getIndependentVariableMin()
   {
      return 1;
   }

   static int getIndependentVariableMax()
   {
      return 9;
   }

   int threadCount;
   void setIndependentVariable(int v)
   {
      threadCount = v;
   }

   void test()
   {
      HANDLE threads[8];

      // Kick off background IO threads.
      for(int i=0; i<threadCount; i++)
         threads[i] = (HANDLE)CreateThread(0, 0, &BackgroundIO, 0,  CREATE_SUSPENDED, NULL);

      for(int i=0; i<threadCount; i++)
         ResumeThread(threads[i]);

      // Solve the mandelbrot set.
      fractalLinear(NULL, MANDELBROT_WORKLOAD);

      // Wait for thread.
      WaitForMultipleObjects(threadCount, threads, true, INFINITE);
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

PERFORMANCE_TEST("disk/directoryList", DiskDirectoryList, 13007)
{
   static const char *getIndependentVariableName()
   {
      return "number of files in directory";
   }

   static int getIndependentVariableMin()
   {
      return 10;
   }

   static int getIndependentVariableMax()
   {
      return 1<<16;
   }

   static bool checkSkipIndependentValue(int independentValue)
   {
      return  !(((independentValue != 0) && !(independentValue & (independentValue - 1))));
   }

   int fileCount;
   void setIndependentVariable(int v)
   {
      fileCount = v;
   }

   void initialize()
   {
      // Make a test directory and blast out the appropriate number of files.
      _mkdir(TEST_DIRECTORY);

      for(int i=0; i<fileCount; i++)
      {
         char nameBuff[64];
         sprintf_s(nameBuff, 64, TEST_DIRECTORY"/file%d", i);
         FILE *f = fopen(nameBuff, "w");
         fwrite(&i, sizeof(i), 1, f);
         fclose(f);
      }
   }

   void teardown()
   {
      for(int i=0; i<fileCount; i++)
      {
         char nameBuff[64];
         sprintf_s(nameBuff, 64, TEST_DIRECTORY"/file%d", i);
         unlink(nameBuff);
      }

      _rmdir(TEST_DIRECTORY);
   }

   void test()
   {
      WIN32_FIND_DATAA ffd;
      HANDLE hFind = FindFirstFileA(TEST_DIRECTORY"/*", &ffd);

      if (INVALID_HANDLE_VALUE == hFind) 
         exit(1);

      // List all the files in the directory with some info about them.
      int n=0;
      do
      {
         // Don't do anything, just read 'em.
         n++;
      }
      while (FindNextFileA(hFind, &ffd) != 0);

      FindClose(hFind);

      // Fail if we didn't find as many as we expected.
      if(n < fileCount)
         exit(1);
   }
};


PERFORMANCE_TEST("disk/openingCostTest", DiskOpeningCostTest, 13008)
{
   static const char *getIndependentVariableName()
   {
      return "number of files in directory";
   }

   static int getIndependentVariableMin()
   {
      return 10;
   }

   static int getIndependentVariableMax()
   {
      return 1<<16;
   }

   static bool checkSkipIndependentValue(int independentValue)
   {
      return  !(((independentValue != 0) && !(independentValue & (independentValue - 1))));
   }

   int fileCount;
   void setIndependentVariable(int v)
   {
      fileCount = v;
   }

   void initialize()
   {
      // Make a test directory and blast out the appropriate number of files.
      _mkdir(TEST_DIRECTORY);

      for(int i=0; i<fileCount; i++)
      {
         char nameBuff[64];
         sprintf_s(nameBuff, 64, TEST_DIRECTORY"/file%d", i);
         FILE *f = fopen(nameBuff, "w");
         fwrite(&i, sizeof(i), 1, f);
         fclose(f);
      }
   }

   void teardown()
   {
      for(int i=0; i<fileCount; i++)
      {
         char nameBuff[64];
         sprintf_s(nameBuff, 64, TEST_DIRECTORY"/file%d", i);
         unlink(nameBuff);
      }

      _rmdir(TEST_DIRECTORY);
   }

   void test()
   {
      // Try opening 100 files randomly.
      for(int filesLeft=0; filesLeft<100; filesLeft++)
      {
         int fileToOpen = betterRand() % fileCount;

         char nameBuff[64];
         int fileContents;
         sprintf_s(nameBuff, 64, TEST_DIRECTORY"/file%d", fileToOpen);
         FILE *f = fopen(nameBuff, "r");
         fread(&fileContents, sizeof(fileContents), 1, f);
         fclose(f);
      }
   }
};

PERFORMANCE_TEST("disk/openingCostComparison/tare", DiskOpeningCostTestTare, 13009)
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
      // Try reading 100 ints randomly from the test file.
      FILE *f = fopen(TEST_FILE_NAME, "r");
      for(int i=0; i<100; i++)
      {
         fseek(f, betterRand() % TEST_FILE_SIZE, SEEK_SET);
         int garbage;
         fread(&garbage, sizeof(int), 1, f);
      }
      fclose(f);
   }
};

PERFORMANCE_TEST("disk/loading/jpeg", DiskLoadingNumbersJpeg, 13011)
{
   char *jpegData;
   int jpegLen;

   void test()
   {
      struct stat file_status;
      stat("lena.jpg", &file_status);

      FILE *f=fopen("lena.jpg", "rb");
      jpegLen = file_status.st_size;
      jpegData = (char*)malloc(jpegLen);
      fread(jpegData, jpegLen, 1, f);
      fclose(f);

      int x, y, comp;
      stbi_jpeg_load_from_memory((const unsigned char *)jpegData, jpegLen, &x, &y, &comp, 3 );

      free(jpegData);
   }
};

PERFORMANCE_TEST("disk/loading/raw", DiskLoadingNumbersRaw, 13012)
{
   char *rawData;
   int rawLen;

   void test()
   {
      struct stat file_status;
      stat("lena.dds", &file_status);

      FILE *f=fopen("lena.dds", "rb");
      rawLen = file_status.st_size;
      rawData = (char*)malloc(rawLen);
      fread(rawData, rawLen, 1, f);
      fclose(f);

      int x, y, comp;
      stbi_jpeg_load_from_memory((const unsigned char *)rawData, rawLen, &x, &y, &comp, 0 );

      free(rawData);
   }
};

