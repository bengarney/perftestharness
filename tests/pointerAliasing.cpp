#include <stdio.h>
#include <stdlib.h>
#include "harness/performanceHarness.h"

#define DATA_SIZE (1024 * 1024)
 __declspec(align(16)) static int gStaticData[DATA_SIZE];

int gDataIn = 2;
int * gptr = 0;

void initStaticAliased()
{
	for( int i=0;i<DATA_SIZE;i++ )
	{
		gStaticData[i]=i;
	}
}

class AliasedPointer : public PerformanceTest
{
public:

   virtual void test()
   {

   }

   _declspec(noinline) void internaltestA( int *a, int *  p )
   {
		for( int i=0;i<DATA_SIZE;i++ )
		{
			a[i]=*p+5;
		}
   }

   _declspec(noinline) void internaltestU( int *a, int p )
   {
		for( int i=0;i<DATA_SIZE;i++ )
		{
			a[i]= p+5;
		}
   }

   virtual void initialize()
   {
		initStaticAliased();
   }
};

PERFORMANCE_TEST_SPECIALIZED("memory/Aliasing/aliased", MAAliased, AliasedPointer, 8000)
{
   virtual void test()
   {
	   internaltestA( gStaticData,gptr );   
   }

   virtual void initialize()
   {
	   gptr = &gDataIn;
	   AliasedPointer::initialize();
   }
};

PERFORMANCE_TEST_SPECIALIZED("memory/Aliasing/unaliased", MAUNAliased, AliasedPointer, 8000)
{
   virtual void test()
   {
	   internaltestU( gStaticData,gDataIn );
   }

   virtual void initialize()
   {
	   gptr = &gDataIn;
	   AliasedPointer::initialize();
   }
};