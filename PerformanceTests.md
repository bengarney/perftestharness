# Introduction #

The core of the PTH are the tests. Each test fills out a different part of the performance map. Writing small, focused tests answers questions; writing big, goal-less tests creates more questions.

# How Are Tests Run? #

Tests are run by executing the `test()` method. You provide code in `initialize()`, `test()`, and `teardown()` to setup, execute, and clean up after a test.

test() will be run for 10 seconds or 100 iterations, whichever comes last. This approach makes sure that a sufficient sample size is gathered for analysis, even if a given test runs very quickly or slowly on some hardware.

Because `test()` will be called an arbitrary number of times, make sure that it can be safely run without affecting subsequent runs. In addition, all resources must be set up and torn down by `initialize()` and `teardown()` to avoid contaminating other test results. (Future versions of the harness will support launching each test in its own process to avoid this contamination issue.)

# What Makes A Good Test? #

Good tests will implement bare minimum code needed to test some performance concept. Each run call to `test()` should result in an appreciable amount of work - ideally `test()` takes 10-100ms to run. Of course, it's nearly impossible to find a fixed amount of work that will do this. The important thing is that the time be measurable. When in doubt, make the amount of work bigger rather than smaller.

## Bad Test ##

This test does too little work and will give inaccurate results. Just calling the `test()` function will introduce enough overhead to skew the results.

```
void test()
{
   int i = rand() + rand();
}
```

## Better Test ##

This test does enough work to be measurable with the `test()` call distorting the results.

```
void test()
{
   int i = 0;
   
   for(int count=0; count<1000000; i++)
      i += rand() + rand();
}
```

## Best Test ##

Calling `rand()` is actually very expensive compared to addition. Better to manipulate some globals. Note, you may need to inspect the assembly in order to confirm that the compiler isn't optimizing away the work you're doing.

```
void test()
{
   static globalVal1, globalVal2;
   int i = 0;
   
   for(int count=0; count<1000000; i++)
      i += globalVal1 + globalVal2;
}
```

# Writing Tests #

The following are some examples showing how to write tests using different features of the Performance Test Harness.

## Complete, Simple Test ##

A complete, simple test looks like this:

```
PERFORMANCE_TEST("basic/control/100000rand", RandomControl)
{
   void test()
   {
      int numReads = 100000;
      int sum = 0;
      while(numReads--)
      {
         sum += rand();
      }
   }
};
```

Note the first line. This lets you name the test - notice how we group the test names like file system paths - and also provide a class name to use. The class name is appended with PerfTest by the macro. (This will be important if you need to declare any static members.)

This macro also deals with registering the test with the test harness. As long as the file with the PERFORMANCE\_TEST macro is compiled into your project, it should be included in runs of the harness. If it doesn't show up, do a clean rebuild. If it still doesn't show up, confirm the file is really being compiled (for instance by introducing a syntax error so it will break). Finally, make sure that the class and display name are unique. If it still doesn't work, drop us a line.

You can provide several member functions to a test, but the only one that's really required (if you want the test to do anything) is `test()`.

## More Complete Test ##

A more complete test looks like this:

PERFORMANCE\_TEST("basic/control/100000randWithReport", RandomControlWithReport)
{
> int totalCount;

> void initialize()
> {
> > totalCount = 0;

> }

> void test()
> {
> > int numReads = 100000;
> > while(numReads--)
> > {
> > > totalCount  += rand();

> > }

> }

> void teardown()
> {
> > printf("We counted %d.", totalCount);

> }
};

`initialize()` and `teardown()` are called before/after the multiple runs of `test()`. They are not included in any timing calculations.

## Test With Independent Variable ##

Sometimes, you may want to run a test multiple times changing an independent variable. An independent variable is a variable which is changed between runs of the test. In this context, a run of the test means instantiating the test class, calling `setIndependentVariable()`, calling `initialize()`, calling `test()` multiple times, and finally calling `teardown()`. Full timing data is gathered with each possible value for the independent variable.

There are four static methods to implement if you want to use an independent variable with your test:

| Signature | Optional? | Description |
|:----------|:----------|:------------|
| `static const char *getIndependentVariableName()` | No | The name of the independent variable. For instance "# of iterations" or "step size." |
| `static int getIndependentVariableMin()` | No | The start value for the independent variable. The test harness will iterate from this value to `getIndependentVariableMax()-1`. |
| `static int getIndependentVariableMax()` | No | The end value plus one for the independent variable. The test harness will iterate from `getIndependentVariableMin()` to this minus one. |
| `static bool checkSkipIndependentValue(int v)` | Yes | Before each test run, the independent value is passed to this method, and the test run is skipped if the method returns false. Use this to skip values that are meaningless (like if you only want pow2 values). |

In addition, you must provide `void setIndependentVariable(int v)` in addition to `void initialize()`. This is called before `initialize()` when independent variables are in use.

Here is an example of a test using independent variables:

```
PERFORMANCE_TEST("memory/traverse/linearStep", MTLStep)
{
   int stepSize;

   static const char * getIndependentVariableName()
   {
      return "step size (b)";
   }

   static int getIndependentVariableMin()
   {
      return 4;
   }

   static int getIndependentVariableMax()
   {
      return 128;
   }

   void setIndependentVariable(int v)
   {
      stepSize = v;
   }

   void test()
   {
      int numReads = 0;
      int sum = 0;
      while(numReads < 100000)
      {
         sum += data[ (numReads * stepSize) % DATA_SIZE ];
         numReads++;
      }
   }
};
```

As you can see, using an independent variable in this case allowed us to avoid making several dozen duplicate tests just to vary the step size.

# Conclusion #

Now you know the basics of writing tests for the test harness. Remember to keep your tests focused and short. Use `initialize()` and `teardown()` to do setup not related to execution time. Independent variables are a powerful tool for getting more mileage out of a single test.

Check out GraphicsTests for information on how to write tests for graphics performance.