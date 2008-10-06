#ifndef _PERFORMANCEHARNESS_H_
#define _PERFORMANCEHARNESS_H_

// These are implemented in winTimer.cpp.
extern void startTimer();
extern double stopTimer();
extern double currentTime();

class PerformanceTest
{
public:

   typedef PerformanceTest Parent;

   virtual void setIndependentVariable(int v) {}
   virtual void initialize() {};
   virtual void test()=0;
   virtual void teardown() {};

   static const char *getIndependentVariableName() { return NULL; };
   static int getIndependentVariableMin() { return -1; };
   static int getIndependentVariableMax() { return -1; };
   static bool checkSkipIndependentValue(int v) { return false; }
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

   virtual const char *getIndependentVariableName() = 0;
   virtual int getIndependentVariableMin() = 0;
   virtual int getIndependentVariableMax() = 0;
   virtual bool checkSkipIndependentValue(int v) = 0;

   virtual void initialize()=0;
   virtual void initializeWithIndependent(int v)=0;
   virtual double runTest()=0;
   virtual void teardown()=0;
};

template<class T> class PerfTestMarker : public PerfTestMarkerBase
{
public:

   T *testInstance;

   PerfTestMarker(const char *name)
      : PerfTestMarkerBase(name)
   {
   }

   const char *getIndependentVariableName()
   {
      return T::getIndependentVariableName();
   }

   int getIndependentVariableMin()
   {
      return T::getIndependentVariableMin();
   }

   int getIndependentVariableMax()
   {
      return T::getIndependentVariableMax();
   }

   bool checkSkipIndependentValue(int v)
   {
      return T::checkSkipIndependentValue(v);
   }

   void initialize()
   {
      testInstance = new T();
      testInstance->initialize();
   }

   void initializeWithIndependent(int v)
   {
      testInstance = new T();
      testInstance->setIndependentVariable(v);
      testInstance->initialize();      
   }

   double runTest()
   {
      // Run and time the test.
      startTimer();
      testInstance->test();
      return stopTimer();
   }

   void teardown()
   {
      testInstance->teardown();
      delete testInstance;
   }
};

#define PERFORMANCE_TEST(name, className) \
   struct className##PerfTest; \
   static PerfTestMarker<className##PerfTest> className##PerfTestMarkerInstance(name); \
   struct className##PerfTest : public PerformanceTest

#endif