#include "graphicsHarness.h"

GraphicsPerformanceTest *GraphicsPerformanceTest::smCurTest = NULL;

GraphicsPerformanceTest::GraphicsPerformanceTest()
{
   desiredMSAAQuality = 0;
   desiredMSAAType = D3DMULTISAMPLE_NONE;
   m_ScreenWidth = 0;
   m_ScreenHeight = 0;
}

void GraphicsPerformanceTest::initialize()
{
   smCurTest = this;

   DXUTInit();
   DXUTSetCallbackD3D9FrameRender(handleFrame);

   DXUTDeviceSettings deviceSettings;
   ZeroMemory( &deviceSettings, sizeof(DXUTDeviceSettings) );
   deviceSettings.ver = DXUT_D3D9_DEVICE;
   deviceSettings.d3d9.pp.Windowed         = true;
   deviceSettings.d3d9.pp.BackBufferWidth  = 800;
   deviceSettings.d3d9.pp.BackBufferHeight = 600;
   deviceSettings.d3d9.pp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE; 
   deviceSettings.d3d9.pp.SwapEffect           = D3DSWAPEFFECT_DISCARD;
   deviceSettings.d3d9.pp.MultiSampleType      = (D3DMULTISAMPLE_TYPE)desiredMSAAType;
   deviceSettings.d3d9.pp.MultiSampleQuality   = desiredMSAAQuality;

   DXUTCreateDeviceFromSettings(&deviceSettings);

   m_Device.m_Dx9 =  DXUTGetD3D9Device();
   m_Device.m_Dx10 = DXUTGetD3D10Device();

   m_ScreenWidth = deviceSettings.d3d9.pp.BackBufferWidth;
   m_ScreenHeight = deviceSettings.d3d9.pp.BackBufferHeight;
}

void CALLBACK GraphicsPerformanceTest::handleFrame( IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime, void* pUserContext )
{
   if(smCurTest == NULL)
   {
      DXUTShutdown();
      return;
   }

   smCurTest->renderFrame(pd3dDevice, fTime, fElapsedTime);
}

void GraphicsPerformanceTest::test()
{
   DXUTRender3DEnvironment();
}

void GraphicsPerformanceTest::teardown()
{
   smCurTest = NULL;
   DXUTMainLoop();
   DXUTSetCallbackD3D9FrameRender(NULL);
}

int GraphicsPerformanceTest::getMaxMSAALevel(int type)
{
   // Based on http://cboard.cprogramming.com/showthread.php?t=66083

   // Get the display mode.
   D3DDISPLAYMODE d3ddm;
   DXUTGetD3D9Object()->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &d3ddm);

   // Get the max number of MSAA levels.
   DWORD numLevels = 0;
   DXUTGetD3D9Object()->CheckDeviceMultiSampleType(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, d3ddm.Format, true, (D3DMULTISAMPLE_TYPE)type, &numLevels);

   return numLevels;
}
