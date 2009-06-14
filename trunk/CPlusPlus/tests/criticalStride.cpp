#include <stdio.h>
#include <stdlib.h>
#include "testUtilities/Iutil.h"
#include "harness/performanceHarness.h"

static float gResult = 0;

void initCriticalStride()
{
   float *data = (float*)IUtil::GetUtilMemory()->Get16ByteAlignedDataBuffer();
   for(int i=0; i<UtilMemory::BufferSize/sizeof(float); i++)
      data[i]=betterRandf();
}

#define STRIDE_COUNT 10
static int criticalStride[STRIDE_COUNT][2] = 
{
   // Read divisor, Stride
   { 529, 512 },
   { 529, 529 },
   { 1041, 1024 },
   { 1041, 1041 },
   { 2065, 2048 },
   { 2065, 2065 },
   { 4164, 4096 },
   { 4164, 4164 },
   { 8209, 8192 },
   { 8209, 8209 },
};

PERFORMANCE_TEST("memory/traversal/criticalStride", MemoryTraverseCriticalStride, 8000)
{
   void test()
   {
      int *accessPattern = (int*)IUtil::GetUtilMemory()->Get16ByteAlignedAccessBuffer();
      float *data = (float*)IUtil::GetUtilMemory()->Get16ByteAlignedDataBuffer();

      float sum = 0;
      for(int i=0; i< UtilMemory::BufferSize / sizeof(int); i++)
         sum += data[accessPattern[i]];
      gResult = sum;
   }

   static const char * getIndependentVariableName()
   {
      return "Stride (bytes)";
   }

   static int getIndependentVariableMin()
   {
      return criticalStride[0][1] - 1;
   }

   static int getIndependentVariableMax()
   {
      return criticalStride[STRIDE_COUNT-1][1] + 1;
   }

   void setIndependentVariable(int v)
   {
      int *accessPattern = (int*)IUtil::GetUtilMemory()->Get16ByteAlignedAccessBuffer();
      for(unsigned int i=0; i< UtilMemory::BufferSize / sizeof(int); i++)
         accessPattern[i]=(i*v)%( UtilMemory::BufferSize / sizeof(int));

      initCriticalStride();
   }

   static bool checkSkipIndependentValue(int independentValue)
   {
      // If it's not a stride on the list, skip it.
      for(int i=0; i<STRIDE_COUNT; i++)
         if(independentValue == criticalStride[i][1])
            return false;
      return true;
   }
};


