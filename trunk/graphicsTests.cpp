#include <stdio.h>
#include "dxut/DXUT.h"
#include "performanceHarness.h"

PERFORMANCE_TEST("basic/graphics/barebones", GraphicsBarebones)
{
   static int frameCount;

   static void CALLBACK handleFrame( IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime, void* pUserContext )
   {
      frameCount++;

      if(frameCount > 100)
      {
         DXUTShutdown();
      }
   }

   void test()
   {
      frameCount = 0;

      DXUTInit();

      DXUTSetCallbackD3D9FrameRender(handleFrame);

      DXUTMainLoop();
   }
};

int GraphicsBarebonesPerfTest::frameCount = 0;
