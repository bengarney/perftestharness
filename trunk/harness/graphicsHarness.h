#ifndef _GRAPHICSHARNESS_H_
#define _GRAPHICSHARNESS_H_

#include "dxut/DXUT.h"
#include "performanceHarness.h"

struct iDevice
{
	iDevice(){m_Dx9=0;m_Dx10=0;};
	iDevice(IDirect3DDevice9* dPtr){m_Dx9=dPtr;}
	iDevice(ID3D10Device* dPtr){m_Dx10=dPtr;}
	IDirect3DDevice9* m_Dx9;
 	ID3D10Device* m_Dx10;
};

/// Base class for all D3D9 performance tests that use EDXUT.
class GraphicsPerformanceTest : public PerformanceTest
{
public:
   GraphicsPerformanceTest();

   typedef GraphicsPerformanceTest Parent;

   void initialize();

   /// To be implemented by actual tests. We present after each call to
   /// this.
   virtual void renderFrame(IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime)=0;

   static GraphicsPerformanceTest *smCurTest;
   static void CALLBACK handleFrame( IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime, void* pUserContext );

   void test();
   void teardown();

   /// Query the maximum support MSAA quality for a given type.
   static int getMaxMSAALevel(int type=D3DMULTISAMPLE_NONMASKABLE);

   /// Used when initialize() is called, to specify a desired MSAA type.
   int desiredMSAAType;

   /// Used when initialize() is called, to specify a desired MSAA quality.
   int desiredMSAAQuality;

   //Dx9 and Dx10 Device
   iDevice m_Device;

   //Screen Resolution
   unsigned int m_ScreenWidth;
   unsigned int m_ScreenHeight;
};

/// Just like PERFORMANCE_TEST, but it makes a subclass of GraphicsPerformanceTest
/// instead.
#define GRAPHICS_PERFORMANCE_TEST(name, className) \
   struct className##PerfTest; \
   static PerfTestMarker<className##PerfTest> className##PerfTestMarkerInstance(name); \
   struct className##PerfTest : public GraphicsPerformanceTest

#endif