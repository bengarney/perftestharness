#include "harness/performanceHarness.h"
#include "testUtilities/IUtil.h"

#define MAX_FLOATING_ALLOCATIONS 1024
void *gMemPtrs[MAX_FLOATING_ALLOCATIONS];

PERFORMANCE_TEST("memory/allocation/varyActiveAllocations", MNewDeleteTest, 8000)
{
   int m_NumberOfActiveAllocations;

   void test()
   {
      int *allocPattern = (int*)IUtil::GetUtilMemory()->Get16ByteAlignedAccessBuffer();
      memset(gMemPtrs, 0, MAX_FLOATING_ALLOCATIONS);

      // Keep 1024 floating allocations
      for(int curAlloc=0; curAlloc < 10000; /*UtilMemory::BufferSize / sizeof(int) ; */ curAlloc++)
      {
         if(gMemPtrs[curAlloc % m_NumberOfActiveAllocations]) 
            free(gMemPtrs[curAlloc % m_NumberOfActiveAllocations]);

         gMemPtrs[curAlloc % m_NumberOfActiveAllocations] = malloc(allocPattern[curAlloc]);
      }

      // Clear out remaining allocations.
      for(int i=0; i<MAX_FLOATING_ALLOCATIONS; i++)
      {
         SAFE_FREE(gMemPtrs[i]);
      }
   }

   static const char * getIndependentVariableName()
   {
      return "# of active allocations";
   }

   static int getIndependentVariableMin()
   {
      return 1;
   }

   static int getIndependentVariableMax()
   {
      return MAX_FLOATING_ALLOCATIONS;
   }

   static bool checkSkipIndependentValue(int v)
   {
      // Let's just do powers of 2.
      return (v & (v - 1)) != 0;
   }

   void setIndependentVariable(int v)
   {
      m_NumberOfActiveAllocations = v;
   }

   void initialize()
   {
      IUtil::GetUtilMemory()->FillAccessBufferWithRandomRange(1, 999999, 100000);
   }
};
