#ifndef _PERFORMANCEHARNESS_H_
#define _PERFORMANCEHARNESS_H_

// These are implemented in winTimer.cpp.
extern void startTimer();
extern double stopTimer();
extern double currentTime();

class PerformanceTest
{
public:
   virtual void test()=0;
};

class PerfTestMarkerBase
{
public:
   static PerfTestMarkerBase *smHead;
   PerfTestMarkerBase *mNext;
   const char *mName;

   PerfTestMarkerBase(const char *name)
      : mName(name)
   {
      mNext = smHead;
      smHead = this;
   }

   virtual double runTest()=0;
};

template<class T> class PerfTestMarker : public PerfTestMarkerBase
{
public:
   PerfTestMarker(const char *name)
      : PerfTestMarkerBase(name)
   {
   }

   double runTest()
   {
	  // Allocate the test.
      PerformanceTest *theTest = new T();

	  // Run it, timing it.
      startTimer();
      theTest->test();
      double result = stopTimer();

	  // Clean up.
      delete theTest;

	  // And return the duration.
      return result;
   }
};

#define PERFORMANCE_TEST(name, className) \
   class className##PerfTest; \
   static PerfTestMarker<className##PerfTest> className##PerfTestMarkerInstance(name); \
   class className##PerfTest : public PerformanceTest

#endif