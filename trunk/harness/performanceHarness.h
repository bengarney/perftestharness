#ifndef _PERFORMANCEHARNESS_H_
#define _PERFORMANCEHARNESS_H_

#ifndef NULL
#define NULL 0
#endif

// These are implemented in winTimer.cpp.
extern void startTimer();
extern double stopTimer();
extern double currentTime();

/// Base class for performance tests.
///
/// Subclassed and auto-registered using the PERFORMANCE_TEST macro, this
/// class is the interface which all performance tests must implement.
///
/// @see runTest, runTestWithIndependent
class PerformanceTest
{
public:
   /// Reference parent members with Parent, so that code can be copied to
   /// a GraphicsPerformanceTest (or any other subclass) without a problem.
   typedef PerformanceTest Parent;

   /// Notify the test of the value of its independent variable, if it
   /// overrides the independent-related static methods below.
   virtual void setIndependentVariable(int v) {}

   /// Do any one-time setup for the test.
   virtual void initialize() {};

   /// Run through the test. This will be run many times to get accurate
   /// timing, so please make sure it represents significant work.
   virtual void test()=0;

   /// Run after test() is done being called. Release resources and tear
   /// down everything that was set up in initialize().
   virtual void teardown() {};

   /// The name of the independent for display/logging purposes.
   static const char *getIndependentVariableName() { return NULL; };

   /// Minimum value for the independent variable.
   static int getIndependentVariableMin() { return -1; };

   /// Maximum value for the independent variable; iteration is done from 
   /// min to max-1 inclusive.
   static int getIndependentVariableMax() { return -1; };

   /// Every time we are going to run the test with an independent variable
   /// value, this function is called to give an opportunity to skip that
   /// value (for instance if we only want to test pow2 values and this is 
   /// not). Return true to skip. 
   ///
   /// Overriding this is optional.
   static bool checkSkipIndependentValue(int v) { return false; }
};

/// Internal interface to keep track of performance tests.
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

/// Type specific class to allow us to query information about a 
/// performance test, instantiate it, and run it.
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

/// Macro to declare and register a performance test.
///
/// @param name Display name for the test. Set up like a file folder, for
///             instance "basic/test/myTest".
#define PERFORMANCE_TEST(name, className) \
   struct className##PerfTest; \
   static PerfTestMarker<className##PerfTest> className##PerfTestMarkerInstance(name); \
   struct className##PerfTest : public PerformanceTest

#endif