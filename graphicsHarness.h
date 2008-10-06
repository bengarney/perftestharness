#ifndef _GRAPHICSHARNESS_H_
#define _GRAPHICSHARNESS_H_

#include "dxut/DXUT.h"
#include "performanceHarness.h"

class GraphicsPerformanceTest : public PerformanceTest
{
public:

   GraphicsPerformanceTest();

   typedef GraphicsPerformanceTest Parent;

   void initialize();

   virtual void renderFrame(IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime)=0;

   static GraphicsPerformanceTest *smCurTest;
   static void CALLBACK handleFrame( IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime, void* pUserContext );

   void test();
   void teardown();

   static int getMaxMSAALevel(int type=D3DMULTISAMPLE_NONMASKABLE);

   int desiredMSAAType;
   int desiredMSAAQuality;

};

#define GRAPHICS_PERFORMANCE_TEST(name, className) \
   struct className##PerfTest; \
   static PerfTestMarker<className##PerfTest> className##PerfTestMarkerInstance(name); \
   struct className##PerfTest : public GraphicsPerformanceTest

#endif