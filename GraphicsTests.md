# Introduction #

You may want to test performance of graphics code. Currently, PTH ships with support for Direct3D 9 via the DXUT framework. The following sections explain how to create a graphics performance test.

# Example Test #

This is how a graphics performance test looks:

```
GRAPHICS_PERFORMANCE_TEST("basic/graphics/basicClear", GraphicsBasicClear)
{
   int frameCount;

   void initialize()
   {
      frameCount = 0;
      Parent::initialize();
   }

   void renderFrame(IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime)
   {
      frameCount++;
      pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, 0xFF000000 | frameCount << 8, 0, 0);
   }
};
```

There are two main differences here. First, `GRAPHICS_PERFORMANCE_TEST` is used instead of `PERFORMANCE_TEST`. Second, `renderFrame()` is used instead of `test()`.

Also, notice that `initialize()` calls up to its parent class using the automatically provided `Parent` typedef. This is important, as the graphics performance test base class initializes DXUT in `initialize()`. If you override `initialize()`, `teardown()`, or `test()`, be sure to call Parent. You should also review the `GraphicsPerformanceTest` class to make sure that your code does not conflict.

There are a few members you can set or call that are useful for writing graphics tests. See `GraphicsPerformanceTest` for the definitive list.