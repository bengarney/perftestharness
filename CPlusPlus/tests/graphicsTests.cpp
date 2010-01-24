#include "testUtilities/stripper/Striper.h"
#include "harness/graphicsHarness.h"
#include "testUtilities/IUtil.h"
#include "testUtilities/Vertices.h"
#include "testUtilities/bunny.h"

/************************************************************************/
/* Bare minimum test that shows discernable graphics.                   */
/************************************************************************/
GRAPHICS_PERFORMANCE_TEST("basic/graphics/basicClear800x600", GraphicsBasicClear800x600, 8000)
{
   int frameCount;

   void initialize()
   {
      frameCount = 0;
      Parent::initialize();
      IUtil::GetUtilFullScreenQuad()->Init( &(iDevice)Parent::m_Device,Parent::m_ScreenWidth,Parent::m_ScreenHeight );
   }

   void renderFrame(IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime)
   {
      frameCount++;
      //pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, 0xFF000000 | frameCount << 8, 0, 0);
      pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, 0x00000000, 0, 0);


      IUtil::GetUtilFullScreenQuad()->RenderFullScreenQuad( &iDevice(pd3dDevice) );
   }
};

/************************************************************************/
/* Bare minimum test that shows discernable graphics.                   */
/************************************************************************/
GRAPHICS_PERFORMANCE_TEST("basic/graphics/basicClear1280x1024", GraphicsBasicClear1280x1024, 8000)
{
   int frameCount;

   static const unsigned int lWidth = 1280;
   static const unsigned int lHeight = 1024;
   static const bool lWin = true;
   static const bool lAStencil = false;
   static const D3DFORMAT SFormat = D3DFMT_D24S8;

   void initialize()
   {
      frameCount = 0;
      Parent::initialize(lWidth, lHeight, lWin, lAStencil, SFormat);
      IUtil::GetUtilFullScreenQuad()->Init( &(iDevice)Parent::m_Device,Parent::m_ScreenWidth,Parent::m_ScreenHeight );
   }

   void renderFrame(IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime)
   {
      frameCount++;
      //pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, 0xFF000000 | frameCount << 8, 0, 0);
      pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, 0x00000000, 0, 0);


      IUtil::GetUtilFullScreenQuad()->RenderFullScreenQuad( &iDevice(pd3dDevice) );
   }
};

/************************************************************************/
/* Bare minimum test that shows discernable graphics.                   */
/************************************************************************/
GRAPHICS_PERFORMANCE_TEST("basic/graphics/basicClear1400x1050", GraphicsBasicClear1400x1050, 8000)
{
   int frameCount;

   static const unsigned int lWidth = 1400;
   static const unsigned int lHeight = 1050;
   static const bool lWin = true;
   static const bool lAStencil = false;
   static const D3DFORMAT SFormat = D3DFMT_D24S8;

   void initialize()
   {
      frameCount = 0;
      Parent::initialize(lWidth, lHeight, lWin, lAStencil, SFormat);
      IUtil::GetUtilFullScreenQuad()->Init( &(iDevice)Parent::m_Device,Parent::m_ScreenWidth,Parent::m_ScreenHeight );
   }

   void renderFrame(IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime)
   {
      frameCount++;
      //pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, 0xFF000000 | frameCount << 8, 0, 0);
      pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, 0x00000000, 0, 0);


      IUtil::GetUtilFullScreenQuad()->RenderFullScreenQuad( &iDevice(pd3dDevice) );
   }
};

/************************************************************************/
/* Bare minimum test that shows discernable graphics.                   */
/************************************************************************/
GRAPHICS_PERFORMANCE_TEST("basic/graphics/ZClear1400x1050", GraphicsZClear1400x1050, 8000)
{
   int frameCount;

   static const unsigned int lWidth = 1400;
   static const unsigned int lHeight = 1050;
   static const bool lWin = true;
   static const bool lAStencil = false;
   static const D3DFORMAT SFormat = D3DFMT_D24S8;

   void initialize()
   {
      frameCount = 0;
      Parent::initialize(lWidth, lHeight, lWin, lAStencil, SFormat);
      IUtil::GetUtilFullScreenQuad()->Init( &(iDevice)Parent::m_Device,Parent::m_ScreenWidth,Parent::m_ScreenHeight );
   }

   void renderFrame(IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime)
   {
      frameCount++;
      //pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, 0xFF000000 | frameCount << 8, 0, 0);
      pd3dDevice->Clear(0, NULL, D3DCLEAR_ZBUFFER, 0x00000000, 0, 0);


      IUtil::GetUtilFullScreenQuad()->RenderFullScreenQuad( &iDevice(pd3dDevice) );
   }
};

/************************************************************************/
/* Bare minimum test that shows discernable graphics.                   */
/************************************************************************/
GRAPHICS_PERFORMANCE_TEST("basic/graphics/StencilClear1400x1050", GraphicsStencilClear1400x1050, 8000)
{
   int frameCount;

   static const unsigned int lWidth = 1400;
   static const unsigned int lHeight = 1050;
   static const bool lWin = true;
   static const bool lAStencil = true;
   static const D3DFORMAT SFormat = D3DFMT_D24S8;

   void initialize()
   {
      frameCount = 0;
      Parent::initialize(lWidth, lHeight, lWin, lAStencil, SFormat);
      IUtil::GetUtilFullScreenQuad()->Init( &(iDevice)Parent::m_Device,Parent::m_ScreenWidth,Parent::m_ScreenHeight );
   }

   void renderFrame(IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime)
   {
      frameCount++;
      //pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, 0xFF000000 | frameCount << 8, 0, 0);
      pd3dDevice->Clear(0, NULL, D3DCLEAR_STENCIL, 0x00000000, 0, 0);


      IUtil::GetUtilFullScreenQuad()->RenderFullScreenQuad( &iDevice(pd3dDevice) );
   }
};

/************************************************************************/
/* Bare minimum test that shows discernable graphics.                   */
/************************************************************************/
GRAPHICS_PERFORMANCE_TEST("basic/graphics/AllClear1400x1050", GraphicsAllClear1400x1050, 8000)
{
   int frameCount;

   static const unsigned int lWidth = 1400;
   static const unsigned int lHeight = 1050;
   static const bool lWin = true;
   static const bool lAStencil = true;
   static const D3DFORMAT SFormat = D3DFMT_D24S8;

   void initialize()
   {
      frameCount = 0;
      Parent::initialize(lWidth, lHeight, lWin, lAStencil, SFormat);
      IUtil::GetUtilFullScreenQuad()->Init( &(iDevice)Parent::m_Device,Parent::m_ScreenWidth,Parent::m_ScreenHeight );
   }

   void renderFrame(IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime)
   {
      frameCount++;
      //pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, 0xFF000000 | frameCount << 8, 0, 0);
      pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_STENCIL | D3DCLEAR_ZBUFFER, 0x00000000, 0, 0);


      IUtil::GetUtilFullScreenQuad()->RenderFullScreenQuad( &iDevice(pd3dDevice) );
   }
};

/************************************************************************/
/* Do a lot of surface clears so things are arbitrarily slower.         */
/************************************************************************/
GRAPHICS_PERFORMANCE_TEST("basic/graphics/extraSurfaceClears800x600", GraphicsExtraSurfaceClear800x600, 8000)
{
   int frameCount;

   void initialize()
   {
      frameCount = 0;
      Parent::initialize();
      IUtil::GetUtilFullScreenQuad()->Init( &(iDevice)Parent::m_Device,Parent::m_ScreenWidth,Parent::m_ScreenHeight );
   }

   void renderFrame(IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime)
   {
      frameCount++;
      for(int i=0; i<50; i++)
      {
         IUtil::GetUtilFullScreenQuad()->RenderFullScreenQuad( &iDevice(pd3dDevice) );
         pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, 0xFF000000 | frameCount << 8, 0, 0);
      }
   }
};

/************************************************************************/
/* Do a lot of surface clears so things are arbitrarily slower.         */
/************************************************************************/
GRAPHICS_PERFORMANCE_TEST("basic/graphics/extraSurfaceClears1280x1024", GraphicsExtraSurfaceClear1280x1024, 8000)
{
   int frameCount;

   static const unsigned int lWidth = 1280;
   static const unsigned int lHeight = 1024;
   static const bool lWin = true;
   static const bool lAStencil = false;
   static const D3DFORMAT SFormat = D3DFMT_D24S8;

   void initialize()
   {
      frameCount = 0;
      Parent::initialize(lWidth, lHeight, lWin, lAStencil, SFormat);
      IUtil::GetUtilFullScreenQuad()->Init( &(iDevice)Parent::m_Device,Parent::m_ScreenWidth,Parent::m_ScreenHeight );
   }

   void renderFrame(IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime)
   {
      frameCount++;
      for(int i=0; i<50; i++)
      {
         IUtil::GetUtilFullScreenQuad()->RenderFullScreenQuad( &iDevice(pd3dDevice) );
         pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, 0xFF000000 | frameCount << 8, 0, 0);
      }
   }
};

/************************************************************************/
/* Do a lot of surface clears so things are arbitrarily slower.         */
/************************************************************************/
GRAPHICS_PERFORMANCE_TEST("basic/graphics/extraSurfaceClears1400x1050", GraphicsExtraSurfaceClear1400x1050, 8000)
{
   int frameCount;

   static const unsigned int lWidth = 1400;
   static const unsigned int lHeight = 1050;
   static const bool lWin = true;
   static const bool lAStencil = false;
   static const D3DFORMAT SFormat = D3DFMT_D24S8;

   void initialize()
   {
      frameCount = 0;
      Parent::initialize(lWidth, lHeight, lWin, lAStencil, SFormat);
      IUtil::GetUtilFullScreenQuad()->Init( &(iDevice)Parent::m_Device,Parent::m_ScreenWidth,Parent::m_ScreenHeight );
   }

   void renderFrame(IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime)
   {
      frameCount++;
      for(int i=0; i<50; i++)
      {
         IUtil::GetUtilFullScreenQuad()->RenderFullScreenQuad( &iDevice(pd3dDevice) );
         pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, 0xFF000000 | frameCount << 8, 0, 0);
      }
   }
};

/************************************************************************/
/* Do a lot of stencil clears so things are arbitrarily slower.         */
/************************************************************************/
GRAPHICS_PERFORMANCE_TEST("basic/graphics/extraStencilClears800x600", GraphicsExtraStencilClear800x600, 8000)
{
   int frameCount;

   static const unsigned int lWidth = 800;
   static const unsigned int lHeight = 600;
   static const bool lWin = true;
   static const bool lAStencil = true;
   static const D3DFORMAT SFormat = D3DFMT_D24S8;

   void initialize()
   {
      frameCount = 0;
      Parent::initialize(lWidth, lHeight, lWin, lAStencil, SFormat);
      IUtil::GetUtilFullScreenQuad()->Init( &(iDevice)Parent::m_Device,Parent::m_ScreenWidth,Parent::m_ScreenHeight );
   }

   void renderFrame(IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime)
   {
      frameCount++;
      for(int i=0; i<50; i++)
      {
         IUtil::GetUtilFullScreenQuad()->RenderFullScreenQuad( &iDevice(pd3dDevice) );
         pd3dDevice->Clear(0, NULL, D3DCLEAR_STENCIL, 0xFF000000 | frameCount << 8, 0, 0);
      }
   }
};

/************************************************************************/
/* Do a lot of stencil clears so things are arbitrarily slower.         */
/************************************************************************/
GRAPHICS_PERFORMANCE_TEST("basic/graphics/extraStencilClears1280x1024", GraphicsExtraStencilClear1280x1024, 8000)
{
   int frameCount;

   static const unsigned int lWidth = 1280;
   static const unsigned int lHeight = 1024;
   static const bool lWin = true;
   static const bool lAStencil = true;
   static const D3DFORMAT SFormat = D3DFMT_D24S8;

   void initialize()
   {
      frameCount = 0;
      Parent::initialize(lWidth, lHeight, lWin, lAStencil, SFormat);
      IUtil::GetUtilFullScreenQuad()->Init( &(iDevice)Parent::m_Device,Parent::m_ScreenWidth,Parent::m_ScreenHeight );
   }

   void renderFrame(IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime)
   {
      frameCount++;
      for(int i=0; i<50; i++)
      {
         IUtil::GetUtilFullScreenQuad()->RenderFullScreenQuad( &iDevice(pd3dDevice) );
         pd3dDevice->Clear(0, NULL, D3DCLEAR_STENCIL, 0xFF000000 | frameCount << 8, 0, 0);
      }
   }
};

/************************************************************************/
/* Do a lot of stencil clears so things are arbitrarily slower.         */
/************************************************************************/
GRAPHICS_PERFORMANCE_TEST("basic/graphics/extraStencilClears1400x1050", GraphicsExtraStencilClear1400x1050, 8000)
{
   int frameCount;

   static const unsigned int lWidth = 1400;
   static const unsigned int lHeight = 1050;
   static const bool lWin = true;
   static const bool lAStencil = true;
   static const D3DFORMAT SFormat = D3DFMT_D24S8;

   void initialize()
   {
      frameCount = 0;
      Parent::initialize(lWidth, lHeight, lWin, lAStencil, SFormat);
      IUtil::GetUtilFullScreenQuad()->Init( &(iDevice)Parent::m_Device,Parent::m_ScreenWidth,Parent::m_ScreenHeight );
   }

   void renderFrame(IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime)
   {
      frameCount++;
      for(int i=0; i<50; i++)
      {
         IUtil::GetUtilFullScreenQuad()->RenderFullScreenQuad( &iDevice(pd3dDevice) );
         pd3dDevice->Clear(0, NULL, D3DCLEAR_STENCIL, 0xFF000000 | frameCount << 8, 0, 0);
      }
   }
};

/************************************************************************/
/* Do a lot of Z Buffer clears so things are arbitrarily slower.        */
/************************************************************************/
GRAPHICS_PERFORMANCE_TEST("basic/graphics/extraZBufferClears800x600", GraphicsExtraZBufferClear800x600, 8000)
{
   int frameCount;

   static const unsigned int lWidth = 800;
   static const unsigned int lHeight = 600;
   static const bool lWin = true;
   static const bool lAStencil = false;
   static const D3DFORMAT SFormat = D3DFMT_D24S8;

   void initialize()
   {
      frameCount = 0;
      Parent::initialize(lWidth, lHeight, lWin, lAStencil, SFormat);
      IUtil::GetUtilFullScreenQuad()->Init( &(iDevice)Parent::m_Device,Parent::m_ScreenWidth,Parent::m_ScreenHeight );
   }

   void renderFrame(IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime)
   {
      frameCount++;
      for(int i=0; i<50; i++)
      {
         IUtil::GetUtilFullScreenQuad()->RenderFullScreenQuad( &iDevice(pd3dDevice) );
         pd3dDevice->Clear(0, NULL, D3DCLEAR_ZBUFFER, 0xFF000000 | frameCount << 8, 0, 0);
      }
   }
};

/************************************************************************/
/* Do a lot of Z Buffer clears so things are arbitrarily slower.        */
/************************************************************************/
GRAPHICS_PERFORMANCE_TEST("basic/graphics/extraZBufferClears1280x1024", GraphicsExtraZBufferClear1280x1024, 8000)
{
   int frameCount;

   static const unsigned int lWidth = 1280;
   static const unsigned int lHeight = 1024;
   static const bool lWin = true;
   static const bool lAStencil = false;
   static const D3DFORMAT SFormat = D3DFMT_D24S8;

   void initialize()
   {
      frameCount = 0;
      Parent::initialize(lWidth, lHeight, lWin, lAStencil, SFormat);
      IUtil::GetUtilFullScreenQuad()->Init( &(iDevice)Parent::m_Device,Parent::m_ScreenWidth,Parent::m_ScreenHeight );
   }

   void renderFrame(IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime)
   {
      frameCount++;
      for(int i=0; i<50; i++)
      {
         IUtil::GetUtilFullScreenQuad()->RenderFullScreenQuad( &iDevice(pd3dDevice) );
         pd3dDevice->Clear(0, NULL, D3DCLEAR_ZBUFFER, 0xFF000000 | frameCount << 8, 0, 0);
      }
   }
};

/************************************************************************/
/* Do a lot of Z Buffer clears so things are arbitrarily slower.        */
/************************************************************************/
GRAPHICS_PERFORMANCE_TEST("basic/graphics/extraZBufferClears1400x1050", GraphicsExtraZBufferClear1400x1050, 8000)
{
   int frameCount;

   static const unsigned int lWidth = 1400;
   static const unsigned int lHeight = 1050;
   static const bool lWin = true;
   static const bool lAStencil = false;
   static const D3DFORMAT SFormat = D3DFMT_D24S8;

   void initialize()
   {
      frameCount = 0;
      Parent::initialize(lWidth, lHeight, lWin, lAStencil, SFormat);
      IUtil::GetUtilFullScreenQuad()->Init( &(iDevice)Parent::m_Device,Parent::m_ScreenWidth,Parent::m_ScreenHeight );
   }

   void renderFrame(IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime)
   {
      frameCount++;
      for(int i=0; i<50; i++)
      {
         IUtil::GetUtilFullScreenQuad()->RenderFullScreenQuad( &iDevice(pd3dDevice) );
         pd3dDevice->Clear(0, NULL, D3DCLEAR_ZBUFFER, 0xFF000000 | frameCount << 8, 0, 0);
      }
   }
};

/************************************************************************/
/* Do a lot of clears so things are arbitrarily slower.				    */
/************************************************************************/
GRAPHICS_PERFORMANCE_TEST("basic/graphics/extraAllClears800x600", GraphicsExtraAllClear800x600, 8000)
{
   int frameCount;

   static const unsigned int lWidth = 800;
   static const unsigned int lHeight = 600;
   static const bool lWin = true;
   static const bool lAStencil = true;
   static const D3DFORMAT SFormat = D3DFMT_D24S8;

   void initialize()
   {
      frameCount = 0;
      Parent::initialize(lWidth, lHeight, lWin, lAStencil, SFormat);
      IUtil::GetUtilFullScreenQuad()->Init( &(iDevice)Parent::m_Device,Parent::m_ScreenWidth,Parent::m_ScreenHeight );
   }

   void renderFrame(IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime)
   {
      frameCount++;
      for(int i=0; i<50; i++)
      {
         IUtil::GetUtilFullScreenQuad()->RenderFullScreenQuad( &iDevice(pd3dDevice) );
         pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_STENCIL | D3DCLEAR_ZBUFFER, 0xFF000000 | frameCount << 8, 0, 0);
      }
   }
};

/************************************************************************/
/* Do a lot of clears so things are arbitrarily slower.				    */
/************************************************************************/
GRAPHICS_PERFORMANCE_TEST("basic/graphics/extraAllClears1280X1024", GraphicsExtraAllClear1280X1024, 8000)
{
   int frameCount;

   static const unsigned int lWidth = 1280;
   static const unsigned int lHeight = 1024;
   static const bool lWin = true;
   static const bool lAStencil = true;
   static const D3DFORMAT SFormat = D3DFMT_D24S8;

   void initialize()
   {
      frameCount = 0;
      Parent::initialize(lWidth, lHeight, lWin, lAStencil, SFormat);
      IUtil::GetUtilFullScreenQuad()->Init( &(iDevice)Parent::m_Device,Parent::m_ScreenWidth,Parent::m_ScreenHeight );
   }

   void renderFrame(IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime)
   {
      frameCount++;
      for(int i=0; i<50; i++)
      {
         IUtil::GetUtilFullScreenQuad()->RenderFullScreenQuad( &iDevice(pd3dDevice) );
         pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_STENCIL | D3DCLEAR_ZBUFFER, 0xFF000000 | frameCount << 8, 0, 0);
      }
   }
};

/************************************************************************/
/* Do a lot of clears so things are arbitrarily slower.				    */
/************************************************************************/
GRAPHICS_PERFORMANCE_TEST("basic/graphics/extraAllClears1400X1050", GraphicsExtraAllClear1400X1050, 8000)
{
   int frameCount;

   static const unsigned int lWidth = 1400;
   static const unsigned int lHeight = 1050;
   static const bool lWin = true;
   static const bool lAStencil = true;
   static const D3DFORMAT SFormat = D3DFMT_D24S8;

   void initialize()
   {
      frameCount = 0;
      Parent::initialize(lWidth, lHeight, lWin, lAStencil, SFormat);
      IUtil::GetUtilFullScreenQuad()->Init( &(iDevice)Parent::m_Device,Parent::m_ScreenWidth,Parent::m_ScreenHeight );
   }

   void renderFrame(IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime)
   {
      frameCount++;
      for(int i=0; i<50; i++)
      {
         IUtil::GetUtilFullScreenQuad()->RenderFullScreenQuad( &iDevice(pd3dDevice) );
         pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_STENCIL | D3DCLEAR_ZBUFFER, 0xFF000000 | frameCount << 8, 0, 0);
      }
   }
};

/************************************************************************/
/* Do a lot of clears so things are arbitrarily slower.				    */
/************************************************************************/
GRAPHICS_PERFORMANCE_TEST("basic/graphics/extraIndClears1400X1050", GraphicsExtraIndClear1400X1050, 8000)
{
   int frameCount;

   static const unsigned int lWidth = 1400;
   static const unsigned int lHeight = 1050;
   static const bool lWin = true;
   static const bool lAStencil = true;
   static const D3DFORMAT SFormat = D3DFMT_D24S8;

   void initialize()
   {
      frameCount = 0;
      Parent::initialize(lWidth, lHeight, lWin, lAStencil, SFormat);
      IUtil::GetUtilFullScreenQuad()->Init( &(iDevice)Parent::m_Device,Parent::m_ScreenWidth,Parent::m_ScreenHeight );
   }

   void renderFrame(IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime)
   {
      frameCount++;
      for(int i=0; i<50; i++)
      {
         IUtil::GetUtilFullScreenQuad()->RenderFullScreenQuad( &iDevice(pd3dDevice) );
         pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, 0xFF000000 | frameCount << 8, 0, 0);
         pd3dDevice->Clear(0, NULL, D3DCLEAR_STENCIL, 0xFF000000 | frameCount << 8, 0, 0);
         pd3dDevice->Clear(0, NULL, D3DCLEAR_ZBUFFER, 0xFF000000 | frameCount << 8, 0, 0);
      }
   }
};

/************************************************************************/
/* Vertex Batching tests.											    */
/************************************************************************/
GRAPHICS_PERFORMANCE_TEST("basic/graphics/vertexBatchingControl", GraphicsVertexBatchingControl, 8000)
{
   int frameCount;

   static const unsigned int lWidth = 1280;
   static const unsigned int lHeight = 1024;
   static const bool lWin = true;
   static const bool lAStencil = false;
   static const D3DFORMAT SFormat = D3DFMT_D24S8;

   static const int Loop = 1;
   static const int Primitives = 1;

   void initialize()
   {
      frameCount = 0;
      Parent::initialize(lWidth, lHeight, lWin, lAStencil, SFormat);
      IUtil::GetUtilFullScreenQuad()->InitVert( &(iDevice)Parent::m_Device,Parent::m_ScreenWidth,Parent::m_ScreenHeight );
   }


   void renderFrame(IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime)
   {
      frameCount++;
      IUtil::GetUtilFullScreenQuad()->RenderFullScreenQuadVert( &iDevice(pd3dDevice), Loop, Primitives);
   }
};

/************************************************************************/
/* Vertex Batching tests.											    */
/************************************************************************/
GRAPHICS_PERFORMANCE_TEST("basic/graphics/vertexBatchingSmall", GraphicsVertexBatchingSmall, 8000)
{
   int frameCount;

   static const unsigned int lWidth = 1280;
   static const unsigned int lHeight = 1024;
   static const bool lWin = true;
   static const bool lAStencil = false;
   static const D3DFORMAT SFormat = D3DFMT_D24S8;

   static const int Loop = 1000;
   static const int Primitives = 1;

   void initialize()
   {
      frameCount = 0;
      Parent::initialize(lWidth, lHeight, lWin, lAStencil, SFormat);
      IUtil::GetUtilFullScreenQuad()->InitVert( &(iDevice)Parent::m_Device,Parent::m_ScreenWidth,Parent::m_ScreenHeight );
   }


   void renderFrame(IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime)
   {
      frameCount++;
      IUtil::GetUtilFullScreenQuad()->RenderFullScreenQuadVert( &iDevice(pd3dDevice), Loop, Primitives);
   }
};

/************************************************************************/
/* Vertex Batching tests.											    */
/************************************************************************/
GRAPHICS_PERFORMANCE_TEST("basic/graphics/vertexBatchingLarge", GraphicsVertexBatchingLarge, 8000)
{
   int frameCount;

   static const unsigned int lWidth = 1280;
   static const unsigned int lHeight = 1024;
   static const bool lWin = true;
   static const bool lAStencil = false;
   static const D3DFORMAT SFormat = D3DFMT_D24S8;

   static const int Loop = 1;
   static const int Primitives = 1000;

   void initialize()
   {
      frameCount = 0;
      Parent::initialize(lWidth, lHeight, lWin, lAStencil, SFormat);
      IUtil::GetUtilFullScreenQuad()->InitVert( &(iDevice)Parent::m_Device,Parent::m_ScreenWidth,Parent::m_ScreenHeight );
   }


   void renderFrame(IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime)
   {
      frameCount++;
      IUtil::GetUtilFullScreenQuad()->RenderFullScreenQuadVert( &iDevice(pd3dDevice), Loop, Primitives);
   }
};

/************************************************************************/
/* State tests.											    */
/************************************************************************/
GRAPHICS_PERFORMANCE_TEST("basic/graphics/stateBase", GraphicsStateBase, 8000)
{
   int frameCount;

   static const unsigned int lWidth = 1280;
   static const unsigned int lHeight = 1024;
   static const bool lWin = true;
   static const bool lAStencil = false;
   static const D3DFORMAT SFormat = D3DFMT_D24S8;

   static const int stateLoop = 1;

   void initialize()
   {
      frameCount = 0;
      Parent::initialize(lWidth, lHeight, lWin, lAStencil, SFormat);
      IUtil::GetUtilFullScreenQuad()->InitState( &(iDevice)Parent::m_Device,Parent::m_ScreenWidth,Parent::m_ScreenHeight );
   }


   void renderFrame(IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime)
   {
      frameCount++;
      IUtil::GetUtilFullScreenQuad()->RenderFullScreenQuadState( &iDevice(pd3dDevice), stateLoop );
   }
};

/************************************************************************/
/* State tests.														    */
/************************************************************************/
GRAPHICS_PERFORMANCE_TEST("basic/graphics/stateThrash", GraphicsStateThrash, 8000)
{
   int frameCount;

   static const unsigned int lWidth = 1280;
   static const unsigned int lHeight = 1024;
   static const bool lWin = true;
   static const bool lAStencil = false;
   static const D3DFORMAT SFormat = D3DFMT_D24S8;

   static const int stateLoop = 3000;

   void initialize()
   {
      frameCount = 0;
      Parent::initialize(lWidth, lHeight, lWin, lAStencil, SFormat);
      IUtil::GetUtilFullScreenQuad()->InitState( &(iDevice)Parent::m_Device,Parent::m_ScreenWidth,Parent::m_ScreenHeight );
   }


   void renderFrame(IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime)
   {
      frameCount++;
      IUtil::GetUtilFullScreenQuad()->RenderFullScreenQuadState( &iDevice(pd3dDevice), stateLoop );
   }
};

/************************************************************************/
/* Scissor tests.													    */
/************************************************************************/
GRAPHICS_PERFORMANCE_TEST("basic/graphics/scissorDisable", GraphicsScissorDisable, 8000)
{
   int frameCount;

   static const unsigned int lWidth = 1280;
   static const unsigned int lHeight = 1024;
   static const bool lWin = true;
   static const bool lAStencil = false;
   static const D3DFORMAT SFormat = D3DFMT_D24S8;

   static const int EnableScissor = 0;

   void initialize()
   {
      frameCount = 0;
      Parent::initialize(lWidth, lHeight, lWin, lAStencil, SFormat);
      IUtil::GetUtilFullScreenQuad()->InitScissor( &(iDevice)Parent::m_Device,Parent::m_ScreenWidth,Parent::m_ScreenHeight );
   }


   void renderFrame(IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime)
   {
      frameCount++;
      IUtil::GetUtilFullScreenQuad()->RenderFullScreenQuadScissor( &iDevice(pd3dDevice), EnableScissor);
   }
};

/************************************************************************/
/* Scissor tests.													    */
/************************************************************************/
GRAPHICS_PERFORMANCE_TEST("basic/graphics/scissorEnable", GraphicsScissorEnable, 8000)
{
   int frameCount;

   static const unsigned int lWidth = 1280;
   static const unsigned int lHeight = 1024;
   static const bool lWin = true;
   static const bool lAStencil = false;
   static const D3DFORMAT SFormat = D3DFMT_D24S8;

   static const int EnableScissor = 1;

   void initialize()
   {
      frameCount = 0;
      Parent::initialize(lWidth, lHeight, lWin, lAStencil, SFormat);
      IUtil::GetUtilFullScreenQuad()->InitScissor( &(iDevice)Parent::m_Device,Parent::m_ScreenWidth,Parent::m_ScreenHeight );
   }


   void renderFrame(IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime)
   {
      frameCount++;
      IUtil::GetUtilFullScreenQuad()->RenderFullScreenQuadScissor( &iDevice(pd3dDevice), EnableScissor);
   }
};

/************************************************************************/
/* Scissor tests.													    */
/************************************************************************/
GRAPHICS_PERFORMANCE_TEST("basic/graphics/scissorTest", GraphicsScissorTest, 8000)
{
   int frameCount;

   static const unsigned int lWidth = 1280;
   static const unsigned int lHeight = 1024;
   static const bool lWin = true;
   static const bool lAStencil = false;
   static const D3DFORMAT SFormat = D3DFMT_D24S8;

   static const int EnableScissor = 2;

   void initialize()
   {
      frameCount = 0;
      Parent::initialize(lWidth, lHeight, lWin, lAStencil, SFormat);
      IUtil::GetUtilFullScreenQuad()->InitScissor( &(iDevice)Parent::m_Device,Parent::m_ScreenWidth,Parent::m_ScreenHeight );
   }


   void renderFrame(IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime)
   {
      frameCount++;
      IUtil::GetUtilFullScreenQuad()->RenderFullScreenQuadScissor( &iDevice(pd3dDevice), EnableScissor );
   }
};

/************************************************************************/
/* TriStrip test.													    */
/************************************************************************/
GRAPHICS_PERFORMANCE_TEST("basic/graphics/triStripTest", GraphicsTriStripTest, 8000)
{
   int frameCount;

   static const unsigned int lWidth = 1280;
   static const unsigned int lHeight = 1024;
   static const bool lWin = true;
   static const bool lAStencil = false;
   static const D3DFORMAT SFormat = D3DFMT_D24S8;

   static const int DrawType = 1;

   void initialize()
   {
      frameCount = 0;
      Parent::initialize(lWidth, lHeight, lWin, lAStencil, SFormat);
      IUtil::GetUtilFullScreenQuad()->InitTri( &(iDevice)Parent::m_Device,Parent::m_ScreenWidth,Parent::m_ScreenHeight, DrawType );
   }


   void renderFrame(IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime)
   {
      frameCount++;
      IUtil::GetUtilFullScreenQuad()->RenderFullScreenQuadTri( &iDevice(pd3dDevice), DrawType);
   }

};

/************************************************************************/
/* TriList test.													    */
/************************************************************************/
GRAPHICS_PERFORMANCE_TEST("basic/graphics/triListTest", GraphicsTriListTest, 8000)
{
   int frameCount;

   static const unsigned int lWidth = 1280;
   static const unsigned int lHeight = 1024;
   static const bool lWin = true;
   static const bool lAStencil = false;
   static const D3DFORMAT SFormat = D3DFMT_D24S8;

   static const int DrawType = 0;

   void initialize()
   {
      frameCount = 0;
      Parent::initialize(lWidth, lHeight, lWin, lAStencil, SFormat);
      IUtil::GetUtilFullScreenQuad()->InitTri( &(iDevice)Parent::m_Device,Parent::m_ScreenWidth,Parent::m_ScreenHeight, DrawType );
   }


   void renderFrame(IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime)
   {
      frameCount++;
      IUtil::GetUtilFullScreenQuad()->RenderFullScreenQuadTri( &iDevice(pd3dDevice), DrawType);
   }

};

/************************************************************************/
/* Index test.													    */
/************************************************************************/
GRAPHICS_PERFORMANCE_TEST("basic/graphics/triListIndexTest", GraphicsTriListIndexTest, 8000)
{
   int frameCount;

   static const unsigned int lWidth = 1280;
   static const unsigned int lHeight = 1024;
   static const bool lWin = true;
   static const bool lAStencil = false;
   static const D3DFORMAT SFormat = D3DFMT_D24S8;

   static const int DrawType = 0;

   void initialize()
   {
      frameCount = 0;
      Parent::initialize(lWidth, lHeight, lWin, lAStencil, SFormat);
      IUtil::GetUtilFullScreenQuad()->InitIndex( &(iDevice)Parent::m_Device,Parent::m_ScreenWidth,Parent::m_ScreenHeight, DrawType );
   }


   void renderFrame(IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime)
   {
      frameCount++;
      IUtil::GetUtilFullScreenQuad()->RenderFullScreenQuadIndex( &iDevice(pd3dDevice), DrawType);
   }

};

/************************************************************************/
/* Index test.													    */
/************************************************************************/
GRAPHICS_PERFORMANCE_TEST("basic/graphics/triListNonIndexTest", GraphicsTriListNonIndexTest, 8000)
{
   int frameCount;

   static const unsigned int lWidth = 1280;
   static const unsigned int lHeight = 1024;
   static const bool lWin = true;
   static const bool lAStencil = false;
   static const D3DFORMAT SFormat = D3DFMT_D24S8;

   static const int DrawType = 1;

   void initialize()
   {
      frameCount = 0;
      Parent::initialize(lWidth, lHeight, lWin, lAStencil, SFormat);
      IUtil::GetUtilFullScreenQuad()->InitIndex( &(iDevice)Parent::m_Device,Parent::m_ScreenWidth,Parent::m_ScreenHeight, DrawType );
   }


   void renderFrame(IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime)
   {
      frameCount++;
      IUtil::GetUtilFullScreenQuad()->RenderFullScreenQuadIndex( &iDevice(pd3dDevice), DrawType);
   }

};

/************************************************************************/
/* Texture test.													    */
/************************************************************************/
GRAPHICS_PERFORMANCE_TEST("basic/graphics/textureABGR32FTest12x10", GraphicsTextureABGR32FTest12x10, 8000)
{
   int frameCount;

   static const unsigned int lWidth = 1280;
   static const unsigned int lHeight = 1024;
   static const bool lWin = true;
   static const bool lAStencil = false;
   static const D3DFORMAT SFormat = D3DFMT_D24S8;

   static const int DrawType = 0;

   void initialize()
   {
      frameCount = 0;
      Parent::initialize(lWidth, lHeight, lWin, lAStencil, SFormat);
      IUtil::GetUtilFullScreenQuad()->InitTex( &(iDevice)Parent::m_Device,Parent::m_ScreenWidth,Parent::m_ScreenHeight, DrawType );
   }


   void renderFrame(IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime)
   {
      frameCount++;
      IUtil::GetUtilFullScreenQuad()->RenderFullScreenQuadTex( &iDevice(pd3dDevice), DrawType);
   }

};

/************************************************************************/
/* Texture test.													    */
/************************************************************************/
GRAPHICS_PERFORMANCE_TEST("basic/graphics/textureABGR32FTest6x4", GraphicsTextureABGR32FTest6x4, 8000)
{
   int frameCount;

   static const unsigned int lWidth = 640;
   static const unsigned int lHeight = 480;
   static const bool lWin = true;
   static const bool lAStencil = false;
   static const D3DFORMAT SFormat = D3DFMT_D24S8;

   static const int DrawType = 0;

   void initialize()
   {
      frameCount = 0;
      Parent::initialize(lWidth, lHeight, lWin, lAStencil, SFormat);
      IUtil::GetUtilFullScreenQuad()->InitTex( &(iDevice)Parent::m_Device,Parent::m_ScreenWidth,Parent::m_ScreenHeight, DrawType );
   }


   void renderFrame(IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime)
   {
      frameCount++;
      IUtil::GetUtilFullScreenQuad()->RenderFullScreenQuadTex( &iDevice(pd3dDevice), DrawType);
   }

};

/************************************************************************/
/* Texture test.													    */
/************************************************************************/
GRAPHICS_PERFORMANCE_TEST("basic/graphics/textureR3G3B2Test12x10", GraphicsTextureR3G3B2Test12x10, 8000)
{
   int frameCount;

   static const unsigned int lWidth = 1280;
   static const unsigned int lHeight = 1024;
   static const bool lWin = true;
   static const bool lAStencil = false;
   static const D3DFORMAT SFormat = D3DFMT_D24S8;

   static const int DrawType = 1;

   void initialize()
   {
      frameCount = 0;
      Parent::initialize(lWidth, lHeight, lWin, lAStencil, SFormat);
      IUtil::GetUtilFullScreenQuad()->InitTex( &(iDevice)Parent::m_Device,Parent::m_ScreenWidth,Parent::m_ScreenHeight, DrawType );
   }


   void renderFrame(IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime)
   {
      frameCount++;
      IUtil::GetUtilFullScreenQuad()->RenderFullScreenQuadTex( &iDevice(pd3dDevice), DrawType);
   }

};

/************************************************************************/
/* Texture test.													    */
/************************************************************************/
GRAPHICS_PERFORMANCE_TEST("basic/graphics/textureR3G3B2Test6x4", GraphicsTextureR3G3B2Test6x4, 8000)
{
   int frameCount;

   static const unsigned int lWidth = 640;
   static const unsigned int lHeight = 480;
   static const bool lWin = true;
   static const bool lAStencil = false;
   static const D3DFORMAT SFormat = D3DFMT_D24S8;

   static const int DrawType = 1;

   void initialize()
   {
      frameCount = 0;
      Parent::initialize(lWidth, lHeight, lWin, lAStencil, SFormat);
      IUtil::GetUtilFullScreenQuad()->InitTex( &(iDevice)Parent::m_Device,Parent::m_ScreenWidth,Parent::m_ScreenHeight, DrawType );
   }


   void renderFrame(IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime)
   {
      frameCount++;
      IUtil::GetUtilFullScreenQuad()->RenderFullScreenQuadTex( &iDevice(pd3dDevice), DrawType);
   }

};

/************************************************************************/
/* Texture test.													    */
/************************************************************************/
GRAPHICS_PERFORMANCE_TEST("basic/graphics/textureR3G3B2_2x2Test", GraphicsTextureR3G3B2_2x2Test, 8000)
{
   int frameCount;

   static const unsigned int lWidth = 1280;
   static const unsigned int lHeight = 1024;
   static const bool lWin = true;
   static const bool lAStencil = false;
   static const D3DFORMAT SFormat = D3DFMT_D24S8;

   static const int DrawType = 2;

   void initialize()
   {
      frameCount = 0;
      Parent::initialize(lWidth, lHeight, lWin, lAStencil, SFormat);
      IUtil::GetUtilFullScreenQuad()->InitTex( &(iDevice)Parent::m_Device,Parent::m_ScreenWidth,Parent::m_ScreenHeight, DrawType );
   }


   void renderFrame(IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime)
   {
      frameCount++;
      IUtil::GetUtilFullScreenQuad()->RenderFullScreenQuadTex( &iDevice(pd3dDevice), DrawType);
   }

};

/************************************************************************/
/* Texture test.													    */
/************************************************************************/
GRAPHICS_PERFORMANCE_TEST("basic/graphics/textureDXT5Test", GraphicsTextureDXT5Test, 8000)
{
   int frameCount;

   static const unsigned int lWidth = 1280;
   static const unsigned int lHeight = 1024;
   static const bool lWin = true;
   static const bool lAStencil = false;
   static const D3DFORMAT SFormat = D3DFMT_D24S8;

   static const int DrawType = 3;

   void initialize()
   {
      frameCount = 0;
      Parent::initialize(lWidth, lHeight, lWin, lAStencil, SFormat);
      IUtil::GetUtilFullScreenQuad()->InitTex( &(iDevice)Parent::m_Device,Parent::m_ScreenWidth,Parent::m_ScreenHeight, DrawType );
   }


   void renderFrame(IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime)
   {
      frameCount++;
      IUtil::GetUtilFullScreenQuad()->RenderFullScreenQuadTex( &iDevice(pd3dDevice), DrawType);
   }

};

/************************************************************************/
/* Texture test.													    */
/************************************************************************/
GRAPHICS_PERFORMANCE_TEST("basic/graphics/texture16BitTest", GraphicsTexture16BitTest, 8000)
{
   int frameCount;

   static const unsigned int lWidth = 1280;
   static const unsigned int lHeight = 1024;
   static const bool lWin = true;
   static const bool lAStencil = false;
   static const D3DFORMAT SFormat = D3DFMT_D24S8;

   static const int DrawType = 4;

   void initialize()
   {
      frameCount = 0;
      Parent::initialize(lWidth, lHeight, lWin, lAStencil, SFormat);
      IUtil::GetUtilFullScreenQuad()->InitTex( &(iDevice)Parent::m_Device,Parent::m_ScreenWidth,Parent::m_ScreenHeight, DrawType );
   }


   void renderFrame(IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime)
   {
      frameCount++;
      IUtil::GetUtilFullScreenQuad()->RenderFullScreenQuadTex( &iDevice(pd3dDevice), DrawType);
   }

};

/************************************************************************/
/* Texture test.													    */
/************************************************************************/
GRAPHICS_PERFORMANCE_TEST("basic/graphics/texture32BitTest", GraphicsTexture32BitTest, 8000)
{
   int frameCount;

   static const unsigned int lWidth = 1280;
   static const unsigned int lHeight = 1024;
   static const bool lWin = true;
   static const bool lAStencil = false;
   static const D3DFORMAT SFormat = D3DFMT_D24S8;

   static const int DrawType = 5;

   void initialize()
   {
      frameCount = 0;
      Parent::initialize(lWidth, lHeight, lWin, lAStencil, SFormat);
      IUtil::GetUtilFullScreenQuad()->InitTex( &(iDevice)Parent::m_Device,Parent::m_ScreenWidth,Parent::m_ScreenHeight, DrawType );
   }


   void renderFrame(IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime)
   {
      frameCount++;
      IUtil::GetUtilFullScreenQuad()->RenderFullScreenQuadTex( &iDevice(pd3dDevice), DrawType);
   }

};

/**************************************************************************/
/* Do a lot of clears so things are arbitrarily slower, with varying MSAA Quality level */
/**************************************************************************/
GRAPHICS_PERFORMANCE_TEST("basic/graphics/extraClearsMSAAQuality", GraphicsExtraClearMSAAQuality, 8000)
{
   int frameCount;

   static const char * getIndependentVariableName()
   {
      return "Non-Masked MSAA level";
   }

   static int getIndependentVariableMin()
   {
      return 0;
   }

   static int getIndependentVariableMax()
   {
      return getMaxMSAALevel();
   }

   void setIndependentVariable(int v)
   {
      desiredMSAAQuality = v;
   }

   void initialize()
   {
      frameCount = 0;
      desiredMSAAType = D3DMULTISAMPLE_NONMASKABLE;
      Parent::initialize();
   }

   void renderFrame(IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime)
   {
      frameCount++;
      for(int i=0; i<50; i++)
         pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, 0xFF000000 | frameCount << 8, 0, 0);
   }
};

/**************************************************************************/
/* Do a lot of clears so things are arbitrarily slower, with varying MSAA level */
/**************************************************************************/
GRAPHICS_PERFORMANCE_TEST("basic/graphics/extraClearsMSAA", GraphicsExtraClearMSAA, 8000)
{
   int frameCount;

   static const char * getIndependentVariableName()
   {
      return "MSAA quality";
   }

   static int getIndependentVariableMin()
   {
      return D3DMULTISAMPLE_2_SAMPLES;
   }

   static int getIndependentVariableMax()
   {
      return D3DMULTISAMPLE_16_SAMPLES + 1;
   }

   static bool checkSkipIndependentValue(int v)
   {
      if(getMaxMSAALevel(v) - 1 == 0)
         return true;
      return false;
   }

   void setIndependentVariable(int v)
   {
      desiredMSAAType = v;
   }

   void initialize()
   {
      frameCount = 0;
      desiredMSAAQuality = getMaxMSAALevel(desiredMSAAType) - 1;
      printf("      - Requesting quality = %d\n", desiredMSAAQuality);
      Parent::initialize();

      printf("      - Ended up with type=%d, quality=%d\n", DXUTGetD3D9PresentParameters().MultiSampleType, DXUTGetD3D9PresentParameters().MultiSampleQuality);
   }

   void renderFrame(IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime)
   {
      frameCount++;
      for(int i=0; i<50; i++)
         pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, 0xFF000000 | frameCount << 8, 0, 0);
   }
};


/************************************************************************/
/* Count cost of draw calls per frame.                                  */
/************************************************************************/
GRAPHICS_PERFORMANCE_TEST("basic/graphics/drawCalls", GraphicsDrawCallsTests, 8001)
{
   int drawsPerFrame;
   IDirect3DTexture9 * mTextureA;
   IDirect3DTexture9 * mTextureB;
   IDirect3DTexture9 * mTextureC;

   static const char * getIndependentVariableName()
   {
      return "draw call count";
   }

   static int getIndependentVariableMin()
   {
      return 1;
   }

   static int getIndependentVariableMax()
   {
      return 6000;
   }

   static bool checkSkipIndependentValue(int v)
   {
      if(v==1)
         return false;
      return (v%500)!=0;
   }

   void setIndependentVariable(int v)
   {
      drawsPerFrame = v;
   }

   void initialize()
   {
      // Very small so we don't tax fill rate.
      Parent::initialize(64,64);

      // Load some textures. This is a leak, but whatever.
      mTextureA = mTextureB = mTextureC = NULL;

      // Initialize a quad to draw.
      IUtil::GetUtilFullScreenQuad()->InitTex( &(iDevice)Parent::m_Device,Parent::m_ScreenWidth,Parent::m_ScreenHeight, 0);
   }

   void teardown()
   {
      Parent::teardown();

      SAFE_RELEASE(mTextureA);
      SAFE_RELEASE(mTextureB);
      SAFE_RELEASE(mTextureC);
   }

   void renderFrame(IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime)
   {
      pd3dDevice->BeginScene();

      for(int i=0; i<drawsPerFrame; i++)
         pd3dDevice->DrawPrimitive( D3DPT_TRIANGLELIST, 0, 2 );

      pd3dDevice->EndScene();
   }
};

/************************************************************************/
/* Count cost of draw calls per frame.                                  */
/************************************************************************/
GRAPHICS_PERFORMANCE_TEST("basic/graphics/drawCallsTextureChanges", GraphicsDrawCallsTextureChangesTests, 8002)
{
   int drawsPerFrame;
   IDirect3DTexture9 * mTextureA;
   IDirect3DTexture9 * mTextureB;
   IDirect3DTexture9 * mTextureC;

   static const char * getIndependentVariableName()
   {
      return "draw call count";
   }

   static int getIndependentVariableMin()
   {
      return 1;
   }

   static int getIndependentVariableMax()
   {
      return 6000;
   }

   static bool checkSkipIndependentValue(int v)
   {
      if(v==1)
         return false;
      return (v%500)!=0;
   }

   void setIndependentVariable(int v)
   {
      drawsPerFrame = v;
   }

   void initialize()
   {
      // Very small so we don't tax fill rate.
      Parent::initialize(64,64);

      // Load some textures. This is a leak, but whatever.
      mTextureA = mTextureB = mTextureC = NULL;
      D3DXCreateTextureFromFileEx (m_Device.m_Dx9, L"lena.jpg", 0, 0, 0, D3DUSAGE_RENDERTARGET, 
         D3DFMT_A8B8G8R8, D3DPOOL_DEFAULT, D3DX_DEFAULT, D3DX_DEFAULT, 0, NULL, NULL, &mTextureA);
      D3DXCreateTextureFromFileEx (m_Device.m_Dx9, L"lena.jpg", 0, 0, 0, D3DUSAGE_RENDERTARGET, 
         D3DFMT_A8B8G8R8, D3DPOOL_DEFAULT, D3DX_DEFAULT, D3DX_DEFAULT, 0, NULL, NULL, &mTextureB);
      D3DXCreateTextureFromFileEx (m_Device.m_Dx9, L"lena.dds", 0, 0, 0, D3DUSAGE_RENDERTARGET, 
         D3DFMT_A8B8G8R8, D3DPOOL_DEFAULT, D3DX_DEFAULT, D3DX_DEFAULT, 0, NULL, NULL, &mTextureC);

      // Initialize a quad to draw.
      IUtil::GetUtilFullScreenQuad()->InitTex( &(iDevice)Parent::m_Device,Parent::m_ScreenWidth,Parent::m_ScreenHeight, 0);
   }

   void teardown()
   {
      Parent::teardown();

      SAFE_RELEASE(mTextureA);
      SAFE_RELEASE(mTextureB);
      SAFE_RELEASE(mTextureC);
   }

   void renderFrame(IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime)
   {
      pd3dDevice->BeginScene();

      for(int i=0; i<drawsPerFrame; i++)
      {
         switch((i+drawsPerFrame/500)%3)
         {
         case 0:
            pd3dDevice->SetTexture(0, mTextureA);
            break;
         case 1:
            pd3dDevice->SetTexture(1, mTextureB);
            break;
         case 2:
            pd3dDevice->SetTexture(1, mTextureC);
            break;
         }
         pd3dDevice->DrawPrimitive( D3DPT_TRIANGLELIST, 0, 2 );
      }

      pd3dDevice->EndScene();
   }
};

#define FILL_COUNT 8000
IDirect3DVertexBuffer9 *fill;
IDirect3DIndexBuffer9 *fillIdx;

void initFillrateRenderer(IDirect3DDevice9 *device)
{
   fill = NULL;
   device->CreateVertexBuffer(sizeof(CUSTOMVERTEX) * 4, D3DUSAGE_WRITEONLY, D3DFVF_CUSTOMVERTEX, D3DPOOL_DEFAULT, &fill, NULL );
   CUSTOMVERTEX *tri = NULL;
   fill->Lock(0, 4, (void**)&tri, 0);

   tri[0].x = 0;
   tri[0].y = 0;
   tri[0].z = 0.5;
   tri[0].rhw = 1.0;
   tri[0].color = rand();

   tri[1].x = 512;
   tri[1].y = 0;
   tri[1].z = 0.5;
   tri[1].rhw = 1.0;
   tri[1].color = rand();

   tri[2].x = 512;
   tri[2].y = 512;
   tri[2].z = 0.5;
   tri[2].rhw = 1.0;
   tri[2].color = rand();

   tri[3].x = 0;
   tri[3].y = 512;
   tri[3].z = 0.5;
   tri[3].rhw = 1.0;
   tri[3].color = rand();

   fill->Unlock();

   fillIdx = NULL;
   device->CreateIndexBuffer(6*FILL_COUNT*2, D3DUSAGE_WRITEONLY, D3DFMT_INDEX16, D3DPOOL_DEFAULT, &fillIdx, NULL);

   unsigned short *index = NULL;
   fillIdx->Lock(0, 6*FILL_COUNT*2, (void**)&index, 0);
   for(int i=0; i<FILL_COUNT; i++)
   {
      *(index++) = 0;
      *(index++) = 1;
      *(index++) = 2;

      *(index++) = 0;
      *(index++) = 2;
      *(index++) = 3;
   }
   fillIdx->Unlock();
}

void initFillrateRendererTexture(IDirect3DDevice9 *device)
{
   fill = NULL;
   device->CreateVertexBuffer(sizeof(CUSTOMVERT2) * 4, D3DUSAGE_WRITEONLY, D3DFVF_VERT2, D3DPOOL_DEFAULT, &fill, NULL );
   CUSTOMVERT2 *tri = NULL;
   fill->Lock(0, 4, (void**)&tri, 0);

   tri[0].x = 0;
   tri[0].y = 0;
   tri[0].z = 0.5;
   tri[0].rhw = 1.0;
   tri[0].tu = 0;
   tri[0].tv = 0;

   tri[1].x = 512;
   tri[1].y = 0;
   tri[1].z = 0.5;
   tri[1].rhw = 1.0;
   tri[1].tu = 0.5;
   tri[1].tv = 0;

   tri[2].x = 512;
   tri[2].y = 512;
   tri[2].z = 0.5;
   tri[2].rhw = 1.0;
   tri[2].tu = 1;
   tri[2].tv = 1.5;

   tri[3].x = 0;
   tri[3].y = 512;
   tri[3].z = 0.5;
   tri[3].rhw = 1.0;
   tri[3].tu = 0;
   tri[3].tv = 200;

   fill->Unlock();

   fillIdx = NULL;
   device->CreateIndexBuffer(6*FILL_COUNT*2, D3DUSAGE_WRITEONLY, D3DFMT_INDEX16, D3DPOOL_DEFAULT, &fillIdx, NULL);

   unsigned short *index = NULL;
   fillIdx->Lock(0, 6*FILL_COUNT*2, (void**)&index, 0);
   for(int i=0; i<FILL_COUNT; i++)
   {
      *(index++) = 0;
      *(index++) = 1;
      *(index++) = 2;

      *(index++) = 0;
      *(index++) = 2;
      *(index++) = 3;
   }
   fillIdx->Unlock();
}

void drawFillrateRenderer(IDirect3DDevice9 *pd3dDevice)
{
   pd3dDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
   pd3dDevice->SetRenderState(D3DRS_ZENABLE, false);
   pd3dDevice->SetStreamSource( 0, fill, 0, sizeof( CUSTOMVERTEX ) );
   pd3dDevice->SetFVF( D3DFVF_CUSTOMVERTEX );
   pd3dDevice->SetIndices(fillIdx);

   IDirect3DQuery9 *query = NULL;
   pd3dDevice->CreateQuery(D3DQUERYTYPE_EVENT, &query);
   pd3dDevice->DrawIndexedPrimitive( D3DPT_TRIANGLELIST, 0, 0, 4, 0, 2*FILL_COUNT );
   query->Issue(D3DISSUE_END);
   while(S_FALSE == query->GetData( NULL, 0, D3DGETDATA_FLUSH ));
   query->Release();
}

void drawFillrateRendererTexture(IDirect3DDevice9 *pd3dDevice)
{
   pd3dDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
   pd3dDevice->SetRenderState(D3DRS_ZENABLE, false);
   pd3dDevice->SetStreamSource( 0, fill, 0, sizeof( CUSTOMVERT2 ) );
   pd3dDevice->SetFVF( D3DFVF_VERT2 );
   pd3dDevice->SetIndices(fillIdx);

   IDirect3DQuery9 *query = NULL;
   pd3dDevice->CreateQuery(D3DQUERYTYPE_EVENT, &query);
   pd3dDevice->DrawIndexedPrimitive( D3DPT_TRIANGLELIST, 0, 0, 4, 0, 2*FILL_COUNT );
   query->Issue(D3DISSUE_END);
   while(S_FALSE == query->GetData( NULL, 0, D3DGETDATA_FLUSH ));
   query->Release();
}

void teardownFillrateRenderer()
{
   // Free the VB.
   fill->Release();
   fillIdx->Release();
}

GRAPHICS_PERFORMANCE_TEST("chapter9-gpu/opaqueFillrate", GraphicsFillRateOpaque, 9003)
{
   void initialize()
   {
      Parent::initialize(512, 512);

      initFillrateRenderer(m_Device.m_Dx9);
   }

   void renderFrame(IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime)
   {
      pd3dDevice->BeginScene();

      drawFillrateRenderer(pd3dDevice);

      pd3dDevice->EndScene();
   }

   void teardown()
   {
      teardownFillrateRenderer();
   }
};

GRAPHICS_PERFORMANCE_TEST("chapter9-gpu/alphaFillrate", GraphicsFillRateAlpha, 9003)
{
   void initialize()
   {
      Parent::initialize(512, 512);

      initFillrateRenderer(m_Device.m_Dx9);
   }

   void renderFrame(IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime)
   {
      pd3dDevice->BeginScene();

      pd3dDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, true);
      pd3dDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_ZERO);
      pd3dDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_SRCCOLOR);

      drawFillrateRenderer(pd3dDevice);

      pd3dDevice->EndScene();
   }

   void teardown()
   {
      teardownFillrateRenderer();
   }
};


GRAPHICS_PERFORMANCE_TEST("chapter9-gpu/alphaWithTestFillrate", GraphicsFillRateAlphaWithTest, 9003)
{
   void initialize()
   {
      Parent::initialize(512, 512);

      initFillrateRenderer(m_Device.m_Dx9);
   }

   void renderFrame(IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime)
   {
      pd3dDevice->BeginScene();

      pd3dDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, true);
      pd3dDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_ZERO);
      pd3dDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_SRCCOLOR);

      pd3dDevice->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_GREATEREQUAL); 
      pd3dDevice->SetRenderState(D3DRS_ALPHAREF, (DWORD)8); 
      pd3dDevice->SetRenderState(D3DRS_ALPHATESTENABLE, TRUE); 

      drawFillrateRenderer(pd3dDevice);

      pd3dDevice->EndScene();
   }

   void teardown()
   {
      teardownFillrateRenderer();
   }
};

GRAPHICS_PERFORMANCE_TEST("chapter9-gpu/textureFormatRateVariation/ABGR8", GraphicsFillRateForTextureFormatsAGBR8, 9004)
{
   IDirect3DTexture9 *mTextureA;

   void initialize()
   {
      Parent::initialize(512, 512);

      initFillrateRendererTexture(m_Device.m_Dx9);

      mTextureA = NULL;
      D3DXCreateTextureFromFileEx (m_Device.m_Dx9, L"lena.jpg", 0, 0, 0, 0, 
         D3DFMT_A8B8G8R8, D3DPOOL_DEFAULT, D3DX_DEFAULT, D3DX_DEFAULT, 0, NULL, NULL, &mTextureA);
   }

   void renderFrame(IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime)
   {
      pd3dDevice->BeginScene();

      pd3dDevice->SetTexture(0, mTextureA);
      pd3dDevice->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_LINEAR);
      pd3dDevice->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR);
      pd3dDevice->SetSamplerState(0, D3DSAMP_MIPFILTER, D3DTEXF_LINEAR);

      drawFillrateRendererTexture(pd3dDevice);

      pd3dDevice->EndScene();
   }

   void teardown()
   {
      mTextureA->Release();
      teardownFillrateRenderer();
   }

};

GRAPHICS_PERFORMANCE_TEST("chapter9-gpu/textureFormatRateVariation/16bit", GraphicsFillRateForTextureFormats16Bit, 9004)
{
   IDirect3DTexture9 *mTextureA;

   void initialize()
   {
      Parent::initialize(512, 512);

      initFillrateRendererTexture(m_Device.m_Dx9);

      mTextureA = NULL;
      D3DXCreateTextureFromFileEx (m_Device.m_Dx9, L"lena.jpg", 0, 0, 0, 0, 
         D3DFMT_R5G6B5, D3DPOOL_DEFAULT, D3DX_DEFAULT, D3DX_DEFAULT, 0, NULL, NULL, &mTextureA);
   }

   void renderFrame(IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime)
   {
      pd3dDevice->BeginScene();

      pd3dDevice->SetTexture(0, mTextureA);
      pd3dDevice->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_LINEAR);
      pd3dDevice->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR);
      pd3dDevice->SetSamplerState(0, D3DSAMP_MIPFILTER, D3DTEXF_LINEAR);

      drawFillrateRendererTexture(pd3dDevice);

      pd3dDevice->EndScene();
   }

   void teardown()
   {
      mTextureA->Release();
      teardownFillrateRenderer();
   }

};

GRAPHICS_PERFORMANCE_TEST("chapter9-gpu/textureFormatRateVariation/64bit", GraphicsFillRateForTextureFormats64Bit, 9004)
{
   IDirect3DTexture9 *mTextureA;

   void initialize()
   {
      Parent::initialize(512, 512);

      initFillrateRendererTexture(m_Device.m_Dx9);

      mTextureA = NULL;
      D3DXCreateTextureFromFileEx (m_Device.m_Dx9, L"lena.jpg", 0, 0, 0, 0, 
         D3DFMT_A16B16G16R16, D3DPOOL_DEFAULT, D3DX_DEFAULT, D3DX_DEFAULT, 0, NULL, NULL, &mTextureA);
   }

   void renderFrame(IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime)
   {
      pd3dDevice->BeginScene();

      pd3dDevice->SetTexture(0, mTextureA);
      pd3dDevice->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_LINEAR);
      pd3dDevice->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR);
      pd3dDevice->SetSamplerState(0, D3DSAMP_MIPFILTER, D3DTEXF_LINEAR);

      drawFillrateRendererTexture(pd3dDevice);

      pd3dDevice->EndScene();
   }

   void teardown()
   {
      mTextureA->Release();
      teardownFillrateRenderer();
   }

};

GRAPHICS_PERFORMANCE_TEST("chapter9-gpu/textureFormatRateVariation/128bit", GraphicsFillRateForTextureFormats128Bit, 9004)
{
   IDirect3DTexture9 *mTextureA;

   void initialize()
   {
      Parent::initialize(512, 512);

      initFillrateRendererTexture(m_Device.m_Dx9);

      mTextureA = NULL;
      D3DXCreateTextureFromFileEx (m_Device.m_Dx9, L"lena.jpg", 0, 0, 0, 0, 
         D3DFMT_A32B32G32R32F, D3DPOOL_DEFAULT, D3DX_DEFAULT, D3DX_DEFAULT, 0, NULL, NULL, &mTextureA);
   }

   void renderFrame(IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime)
   {
      pd3dDevice->BeginScene();

      pd3dDevice->SetTexture(0, mTextureA);
      pd3dDevice->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_LINEAR);
      pd3dDevice->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR);
      pd3dDevice->SetSamplerState(0, D3DSAMP_MIPFILTER, D3DTEXF_LINEAR);

      drawFillrateRendererTexture(pd3dDevice);

      pd3dDevice->EndScene();
   }

   void teardown()
   {
      mTextureA->Release();
      teardownFillrateRenderer();
   }

};

GRAPHICS_PERFORMANCE_TEST("chapter9-gpu/textureFormatRateVariation/DXT1", GraphicsFillRateForTextureFormatsDXT1, 9004)
{
   IDirect3DTexture9 *mTextureA;

   void initialize()
   {
      Parent::initialize(512, 512);

      initFillrateRendererTexture(m_Device.m_Dx9);

      mTextureA = NULL;
      D3DXCreateTextureFromFileEx (m_Device.m_Dx9, L"lena.jpg", 0, 0, 0, 0, 
         D3DFMT_DXT1, D3DPOOL_DEFAULT, D3DX_DEFAULT, D3DX_DEFAULT, 0, NULL, NULL, &mTextureA);
   }

   void renderFrame(IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime)
   {
      pd3dDevice->BeginScene();

      pd3dDevice->SetTexture(0, mTextureA);
      pd3dDevice->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_LINEAR);
      pd3dDevice->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR);

      drawFillrateRendererTexture(pd3dDevice);

      pd3dDevice->EndScene();
   }

   void teardown()
   {
      mTextureA->Release();
      teardownFillrateRenderer();
   }

};

GRAPHICS_PERFORMANCE_TEST("chapter9-gpu/SampleModeVsMipMap/PointNoMips", GraphicsSampleModeAndMipMapPointNoMips, 9005)
{
   IDirect3DTexture9 *mTextureA;

   void initialize()
   {
      Parent::initialize(512, 512);

      initFillrateRendererTexture(m_Device.m_Dx9);

      mTextureA = NULL;
      D3DXCreateTextureFromFileEx (m_Device.m_Dx9, L"lena.jpg", 0, 0, 1, 0, 
         D3DFMT_A8B8G8R8, D3DPOOL_DEFAULT, D3DX_DEFAULT, D3DX_DEFAULT, 0, NULL, NULL, &mTextureA);
   }

   void renderFrame(IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime)
   {
      pd3dDevice->BeginScene();

      pd3dDevice->SetTexture(0, mTextureA);
      pd3dDevice->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_POINT);
      pd3dDevice->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_POINT);

      drawFillrateRendererTexture(pd3dDevice);

      pd3dDevice->EndScene();
   }

   void teardown()
   {
      mTextureA->Release();
      teardownFillrateRenderer();
   }
};


GRAPHICS_PERFORMANCE_TEST("chapter9-gpu/SampleModeVsMipMap/PointMips", GraphicsSampleModeAndMipMapPointMips, 9005)
{
   IDirect3DTexture9 *mTextureA;

   void initialize()
   {
      Parent::initialize(512, 512);

      initFillrateRendererTexture(m_Device.m_Dx9);

      mTextureA = NULL;
      D3DXCreateTextureFromFileEx (m_Device.m_Dx9, L"lena.jpg", 0, 0, D3DX_DEFAULT, 0, 
         D3DFMT_A8B8G8R8, D3DPOOL_DEFAULT, D3DX_DEFAULT, D3DX_DEFAULT, 0, NULL, NULL, &mTextureA);
   }

   void renderFrame(IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime)
   {
      pd3dDevice->BeginScene();

      pd3dDevice->SetTexture(0, mTextureA);
      pd3dDevice->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_POINT);
      pd3dDevice->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_POINT);

      drawFillrateRendererTexture(pd3dDevice);

      pd3dDevice->EndScene();
   }

   void teardown()
   {
      mTextureA->Release();
      teardownFillrateRenderer();
   }
};

GRAPHICS_PERFORMANCE_TEST("chapter9-gpu/SampleModeVsMipMap/LinearNoMips", GraphicsSampleModeAndMipMapLinearNoMips, 9005)
{
   IDirect3DTexture9 *mTextureA;

   void initialize()
   {
      Parent::initialize(512, 512);

      initFillrateRendererTexture(m_Device.m_Dx9);

      mTextureA = NULL;
      D3DXCreateTextureFromFileEx (m_Device.m_Dx9, L"lena.jpg", 0, 0, 1, 0, 
         D3DFMT_A8B8G8R8, D3DPOOL_DEFAULT, D3DX_DEFAULT, D3DX_DEFAULT, 0, NULL, NULL, &mTextureA);
   }

   void renderFrame(IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime)
   {
      pd3dDevice->BeginScene();

      pd3dDevice->SetTexture(0, mTextureA);
      pd3dDevice->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_LINEAR);
      pd3dDevice->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR);

      drawFillrateRendererTexture(pd3dDevice);

      pd3dDevice->EndScene();
   }

   void teardown()
   {
      mTextureA->Release();
      teardownFillrateRenderer();
   }
};


GRAPHICS_PERFORMANCE_TEST("chapter9-gpu/SampleModeVsMipMap/LinearMips", GraphicsSampleModeAndMipMapLinearMips, 9005)
{
   IDirect3DTexture9 *mTextureA;

   void initialize()
   {
      Parent::initialize(512, 512);

      initFillrateRendererTexture(m_Device.m_Dx9);

      mTextureA = NULL;
      D3DXCreateTextureFromFileEx (m_Device.m_Dx9, L"lena.jpg", 0, 0, D3DX_DEFAULT, 0, 
         D3DFMT_A8B8G8R8, D3DPOOL_DEFAULT, D3DX_DEFAULT, D3DX_DEFAULT, 0, NULL, NULL, &mTextureA);
   }

   void renderFrame(IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime)
   {
      pd3dDevice->BeginScene();

      pd3dDevice->SetTexture(0, mTextureA);
      pd3dDevice->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_LINEAR);
      pd3dDevice->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR);

      drawFillrateRendererTexture(pd3dDevice);

      pd3dDevice->EndScene();
   }

   void teardown()
   {
      mTextureA->Release();
      teardownFillrateRenderer();
   }
};

GRAPHICS_PERFORMANCE_TEST("chapter9-gpu/textureCount", GraphicsFillRateActiveTextures, 9006)
{
   static const char *getIndependentVariableName()
   {
      return "# of Samplers";
   }

   static int getIndependentVariableMin()
   {
      return 1;
   }

   static int getIndependentVariableMax()
   {
      return 16;
   }
   
   void setIndependentVariable(int v)
   {
      samplerCount = v;
   }

   int samplerCount;
   IDirect3DTexture9 *mTextureA;

   void initialize()
   {
      Parent::initialize(512, 512);

      initFillrateRendererTexture(m_Device.m_Dx9);

      mTextureA = NULL;
      D3DXCreateTextureFromFileEx (m_Device.m_Dx9, L"lena.jpg", 0, 0, D3DX_DEFAULT, 0, 
         D3DFMT_A8B8G8R8, D3DPOOL_DEFAULT, D3DX_DEFAULT, D3DX_DEFAULT, 0, NULL, NULL, &mTextureA);
   }

   void renderFrame(IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime)
   {
      pd3dDevice->BeginScene();

      for(int i=0; i<samplerCount; i++)
      {
         pd3dDevice->SetTexture(i, mTextureA);
         pd3dDevice->SetTextureStageState( i, D3DTSS_COLORARG1, D3DTA_CURRENT ); 
         pd3dDevice->SetTextureStageState( i, D3DTSS_COLORARG2, D3DTA_TEXTURE ); 
         pd3dDevice->SetTextureStageState( i, D3DTSS_COLOROP, D3DTOP_ADDSIGNED );
      }

      drawFillrateRendererTexture(pd3dDevice);

      pd3dDevice->EndScene();
   }

   void teardown()
   {
      mTextureA->Release();
      teardownFillrateRenderer();
   }
};

IDirect3DIndexBuffer9 *bunnyIndices;
IDirect3DVertexBuffer9 *bunnyVertices;
int bunnyPrimCount = 0;
unsigned short *bunnyStrip = NULL;

void initBunnyRenderer(IDirect3DDevice9 *device, bool optimizeIndexOrder, bool useTriStrip = false,
                       bool use16BitIndices = true, int vertexFormat = D3DFVF_CUSTOMVERTEX)
{
   // Optimize the index order if required.
   DWORD outIndices[BUNNY_NUM_TRIANGLES*3];
   if(optimizeIndexOrder)
   {
      D3DXOptimizeFaces((void*)bunny_triangles, BUNNY_NUM_TRIANGLES, BUNNY_NUM_POINTS, false, &outIndices[0]);
   }
   else
   {
      for(int i=0; i<BUNNY_NUM_TRIANGLES*3; i++)
         outIndices[i] = bunny_triangles[i];
   }

   // Stripify it.
   if(useTriStrip)
   {
      STRIPERCREATE sc;
      sc.AskForWords = false;
      sc.ConnectAllStrips = true;
      sc.DFaces = (udword*)bunny_triangles;
      sc.NbFaces = BUNNY_NUM_TRIANGLES;
      sc.OneSided = true;
      sc.SGIAlgorithm = true;

      Striper s;
      s.Init(sc);

      STRIPERRESULT sr;
      sr.AskForWords = false;
      s.Compute(sr);

      memcpy(outIndices, ((int*)sr.StripRuns), *sr.StripLengths * 4);
      bunnyPrimCount = sr.StripLengths[0];
   }
   else
   {
      bunnyPrimCount = BUNNY_NUM_TRIANGLES;
   }

   unsigned short *indices16 = NULL;
   unsigned int *indices32 = NULL;

   int idxFormat = use16BitIndices ? D3DFMT_INDEX16 : D3DFMT_INDEX32;
   int idxStride = use16BitIndices ? 2 : 4;

   device->CreateIndexBuffer(idxStride * bunnyPrimCount * 3, D3DUSAGE_WRITEONLY, (D3DFORMAT)idxFormat, D3DPOOL_DEFAULT, &bunnyIndices, NULL);

   bunnyIndices->Lock(0, idxStride * bunnyPrimCount * 3, use16BitIndices ? (void**)&indices16 : (void**)&indices32, 0);

   if(useTriStrip || optimizeIndexOrder)
   {
      if(use16BitIndices)
      {
         for(int i=0; i<bunnyPrimCount; i++)
            indices16[i] = outIndices[i];
      }
      else
      {
         for(int i=0; i<bunnyPrimCount; i++)
            indices32[i] = outIndices[i];
      }
   }
   else
   {
      if(use16BitIndices)
      {
         for(int i=0; i<bunnyPrimCount; i++)
            indices16[i] = bunny_triangles[i];
      }
      else
      {
         for(int i=0; i<bunnyPrimCount; i++)
            indices32[i] = bunny_triangles[i];
      }
   }
   bunnyIndices->Unlock();

   CUSTOMVERTEX *verts = NULL;
   CUSTOMVERT2 *verts2 = NULL;
   CUSTOMVERT3 *verts3 = NULL;
   CUSTOMVERT4 *verts4 = NULL;
   CUSTOMVERT5 *verts5 = NULL;

   switch(vertexFormat)
   {
   case D3DFVF_CUSTOMVERTEX:
      device->CreateVertexBuffer(sizeof(CUSTOMVERTEX) * BUNNY_NUM_POINTS, D3DUSAGE_WRITEONLY, vertexFormat, D3DPOOL_DEFAULT, &bunnyVertices, NULL);

      bunnyVertices->Lock(0, sizeof(CUSTOMVERTEX) * BUNNY_NUM_POINTS, (void**)&verts, 0);
      for(int i=0; i<BUNNY_NUM_POINTS; i++)
      {
         verts[i].x = bunny_points[i*3+0] * 256.f + 256.f;
         verts[i].y = bunny_points[i*3+1] * 256.f + 256.f;
         verts[i].z = 1; //bunny_points[i*3+2] * 256.f + 256.f;
         verts[i].rhw = 1.0;
      }
      break;
   case D3DFVF_VERT2:
      device->CreateVertexBuffer(sizeof(CUSTOMVERT2) * BUNNY_NUM_POINTS, D3DUSAGE_WRITEONLY, vertexFormat, D3DPOOL_DEFAULT, &bunnyVertices, NULL);

      bunnyVertices->Lock(0, sizeof(CUSTOMVERT2) * BUNNY_NUM_POINTS, (void**)&verts2, 0);
      for(int i=0; i<BUNNY_NUM_POINTS; i++)
      {
         verts2[i].x = bunny_points[i*3+0] * 256.f + 256.f;
         verts2[i].y = bunny_points[i*3+1] * 256.f + 256.f;
         verts2[i].z = 1; //bunny_points[i*3+2] * 256.f + 256.f;
         verts2[i].rhw = 1.0;
      }
      break;
   case D3DFVF_VERT3:
      device->CreateVertexBuffer(sizeof(CUSTOMVERT3) * BUNNY_NUM_POINTS, D3DUSAGE_WRITEONLY, vertexFormat, D3DPOOL_DEFAULT, &bunnyVertices, NULL);

      bunnyVertices->Lock(0, sizeof(CUSTOMVERT3) * BUNNY_NUM_POINTS, (void**)&verts3, 0);
      for(int i=0; i<BUNNY_NUM_POINTS; i++)
      {
         verts3[i].x = bunny_points[i*3+0] * 256.f + 256.f;
         verts3[i].y = bunny_points[i*3+1] * 256.f + 256.f;
         verts3[i].z = 1; //bunny_points[i*3+2] * 256.f + 256.f;
         verts3[i].rhw = 1.0;
      }
      break;
   case D3DFVF_VERT4:
      device->CreateVertexBuffer(sizeof(CUSTOMVERT4) * BUNNY_NUM_POINTS, D3DUSAGE_WRITEONLY, vertexFormat, D3DPOOL_DEFAULT, &bunnyVertices, NULL);

      bunnyVertices->Lock(0, sizeof(CUSTOMVERT4) * BUNNY_NUM_POINTS, (void**)&verts4, 0);
      for(int i=0; i<BUNNY_NUM_POINTS; i++)
      {
         verts4[i].x = bunny_points[i*3+0] * 256.f + 256.f;
         verts4[i].y = bunny_points[i*3+1] * 256.f + 256.f;
         verts4[i].z = 1; // bunny_points[i*3+2] * 256.f + 256.f;
         verts4[i].rhw = 1.0;
      }
      break;
   case D3DFVF_VERT5:
      device->CreateVertexBuffer(sizeof(CUSTOMVERT5) * BUNNY_NUM_POINTS, D3DUSAGE_WRITEONLY, vertexFormat, D3DPOOL_DEFAULT, &bunnyVertices, NULL);

      bunnyVertices->Lock(0, sizeof(CUSTOMVERT5) * BUNNY_NUM_POINTS, (void**)&verts5, 0);
      for(int i=0; i<BUNNY_NUM_POINTS; i++)
      {
         verts5[i].x = bunny_points[i*3+0] * 256.f + 256.f;
         verts5[i].y = bunny_points[i*3+1] * 256.f + 256.f;
         verts5[i].z = 1; //bunny_points[i*3+2] * 256.f + 256.f;
         verts5[i].rhw = 1.0;
      }
      break;

   }

   // Don't forget to unlock.
   bunnyVertices->Unlock();
}

void renderBunny(IDirect3DDevice9 *device, bool useTriStrip = false)
{
   device->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
   device->SetRenderState(D3DRS_ZENABLE, false);
   device->SetStreamSource( 0, bunnyVertices, 0, sizeof( CUSTOMVERTEX ) );
   device->SetFVF( D3DFVF_CUSTOMVERTEX );
   device->SetIndices(bunnyIndices);

   IDirect3DQuery9 *query = NULL;
   device->CreateQuery(D3DQUERYTYPE_EVENT, &query);
   
   for(int i=0; i<20; i++)
      device->DrawIndexedPrimitive( useTriStrip ? D3DPT_TRIANGLESTRIP : D3DPT_TRIANGLELIST, 0, 0, BUNNY_NUM_POINTS, 0, bunnyPrimCount);
   
   query->Issue(D3DISSUE_END);

   for(int i=0; i<20; i++)
      device->DrawIndexedPrimitive( useTriStrip ? D3DPT_TRIANGLESTRIP : D3DPT_TRIANGLELIST, 0, 0, BUNNY_NUM_POINTS, 0, bunnyPrimCount);

   device->EndScene();

   int data;
   while(S_FALSE == query->GetData( &data, 4, D3DGETDATA_FLUSH ));
   query->Release();
}

void shutdownBunnyRenderer()
{
   SAFE_RELEASE(bunnyIndices);
   SAFE_RELEASE(bunnyVertices);
}

GRAPHICS_PERFORMANCE_TEST("chapter9-gpu/bunny/triList", GraphicsBunnyTriList, 9007)
{
   void initialize()
   {
      Parent::initialize(64, 64);

      initBunnyRenderer(m_Device.m_Dx9, false);
   }

   void renderFrame(IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime)
   {
      pd3dDevice->BeginScene();

      renderBunny(pd3dDevice);
   }

   void teardown()
   {
      shutdownBunnyRenderer();
   }
};

GRAPHICS_PERFORMANCE_TEST("chapter9-gpu/bunny/triListOpt", GraphicsBunnyTriListOpt, 9007)
{
   void initialize()
   {
      Parent::initialize(64, 64);

      initBunnyRenderer(m_Device.m_Dx9, true);
   }

   void renderFrame(IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime)
   {
      pd3dDevice->BeginScene();

      renderBunny(pd3dDevice);

   }

   void teardown()
   {
      shutdownBunnyRenderer();
   }
};

GRAPHICS_PERFORMANCE_TEST("chapter9-gpu/bunny/triStrip", GraphicsBunnyTriStrip, 9007)
{
   void initialize()
   {
      Parent::initialize(64, 64);

      initBunnyRenderer(m_Device.m_Dx9, false, true);
   }

   void renderFrame(IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime)
   {
      pd3dDevice->BeginScene();

      renderBunny(pd3dDevice, true);
   }

   void teardown()
   {
      shutdownBunnyRenderer();
   }
};

GRAPHICS_PERFORMANCE_TEST("chapter9-gpu/bunny/triStripOpt", GraphicsBunnyTriStripOpt, 9007)
{
   void initialize()
   {
      Parent::initialize(64, 64);

      initBunnyRenderer(m_Device.m_Dx9, true, true);
   }

   void renderFrame(IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime)
   {
      pd3dDevice->BeginScene();

      renderBunny(pd3dDevice, true);
   }

   void teardown()
   {
      shutdownBunnyRenderer();
   }
};

GRAPHICS_PERFORMANCE_TEST("chapter9-gpu/bunny/index16", GraphicsBunnyIndex16, 9007)
{
   void initialize()
   {
      Parent::initialize(64, 64);

      initBunnyRenderer(m_Device.m_Dx9, true, false, true);
   }

   void renderFrame(IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime)
   {
      pd3dDevice->BeginScene();

      renderBunny(pd3dDevice, true);

   }

   void teardown()
   {
      shutdownBunnyRenderer();
   }
};

GRAPHICS_PERFORMANCE_TEST("chapter9-gpu/bunny/index32", GraphicsBunnyIndex32, 9007)
{
   void initialize()
   {
      Parent::initialize(64, 64);

      initBunnyRenderer(m_Device.m_Dx9, true, false, false);
   }

   void renderFrame(IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime)
   {
      pd3dDevice->BeginScene();

      renderBunny(pd3dDevice, true);
   }

   void teardown()
   {
      shutdownBunnyRenderer();
   }
};

GRAPHICS_PERFORMANCE_TEST("chapter9-gpu/bunnyVertSize", GraphicsVertexSize, 9006)
{
   static const char *getIndependentVariableName()
   {
      return "Vertex Size (bytes)";
   }

   static int getIndependentVariableMin()
   {
      return 1;
   }

   static int getIndependentVariableMax()
   {
      return 1024;
   }

   static int checkSkipIndependentValue(int v)
   {
      if(v == sizeof(CUSTOMVERTEX)) return false;
      if(v == sizeof(CUSTOMVERT2)) return false;
      if(v == sizeof(CUSTOMVERT3)) return false;
      if(v == sizeof(CUSTOMVERT4)) return false;
      if(v == sizeof(CUSTOMVERT5)) return false;
      return true;
   }

   void setIndependentVariable(int v)
   {
      if(v == sizeof(CUSTOMVERTEX)) vertexFormat = D3DFVF_CUSTOMVERTEX;
      if(v == sizeof(CUSTOMVERT2)) vertexFormat = D3DFVF_VERT2;
      if(v == sizeof(CUSTOMVERT3)) vertexFormat = D3DFVF_VERT3;
      if(v == sizeof(CUSTOMVERT4)) vertexFormat = D3DFVF_VERT4;
      if(v == sizeof(CUSTOMVERT5)) vertexFormat = D3DFVF_VERT5;
   }

   int vertexFormat;

   void initialize()
   {
      Parent::initialize(64, 64);

      initBunnyRenderer(m_Device.m_Dx9, true, false, true, vertexFormat);
   }

   void renderFrame(IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime)
   {
      pd3dDevice->BeginScene();

      renderBunny(pd3dDevice, false);
   }

   void teardown()
   {
      shutdownBunnyRenderer();
   }
};

GRAPHICS_PERFORMANCE_TEST("chapter9-gpu/renderTargetSwitch", GraphicsSwitchingRenderTargets, 9006)
{
   static const char *getIndependentVariableName()
   {
      return "Target Count";
   }

   static int getIndependentVariableMin()
   {
      return 1;
   }

   static int getIndependentVariableMax()
   {
      return 6;
   }

   void setIndependentVariable(int v)
   {
      targetCount = v;
   }

   int targetCount;
   IDirect3DSurface9 *renderTarget[8];

   void initialize()
   {
      Parent::initialize(512, 512);

      IDirect3DDevice9 *device = m_Device.m_Dx9;
      for(int i=0; i<targetCount; i++)
         device->CreateRenderTarget(512, 512, D3DFMT_X8R8G8B8, D3DMULTISAMPLE_NONE, 0, false, &renderTarget[i], NULL);

      initFillrateRenderer(device);
   }

   void renderFrame(IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime)
   {
      pd3dDevice->BeginScene();

      IDirect3DSurface9 *oldSurf = NULL;
      pd3dDevice->GetRenderTarget(0, &oldSurf);

      for(int i=0; i<targetCount; i++)
      {
         pd3dDevice->SetRenderTarget(0, renderTarget[i]);
         pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, 0, 0, 0);

         drawFillrateRenderer(pd3dDevice);
      }

      pd3dDevice->SetRenderTarget(0, oldSurf);
      oldSurf->Release();
      pd3dDevice->EndScene();
   }

   void teardown()
   {
      for(int i=0; i<targetCount; i++)
         renderTarget[i]->Release();

      teardownFillrateRenderer();
   }

};

GRAPHICS_PERFORMANCE_TEST("chapter9-gpu/renderTargetMultiple", GraphicsMultipleRenderTargets, 9006)
{
   static const char *getIndependentVariableName()
   {
      return "Target Count";
   }

   static int getIndependentVariableMin()
   {
      return 1;
   }

   static int getIndependentVariableMax()
   {
      return 5;
   }

   void setIndependentVariable(int v)
   {
      targetCount = v;
   }

   int targetCount;
   IDirect3DSurface9 *renderTarget[8];
   IDirect3DTexture9 *mTextureA;
   ID3DXEffect *effect;

   void initialize()
   {
      Parent::initialize(512, 512);

      IDirect3DDevice9 *device = m_Device.m_Dx9;
      for(int i=0; i<targetCount; i++)
         device->CreateRenderTarget(512, 512, D3DFMT_X8R8G8B8, D3DMULTISAMPLE_NONE, 0, false, &renderTarget[i], NULL);

      const char *file;
      switch(targetCount)
      {
      case 1: file = "mrt1.fx"; break;
      case 2: file = "mrt2.fx"; break;
      case 3: file = "mrt3.fx"; break;
      case 4: file = "mrt4.fx"; break;
      }

      ID3DXBuffer *buff = NULL;
      D3DXCreateBuffer(8192, &buff);

      D3DXCreateEffectFromFileA(device, file, NULL, NULL, 0, NULL, &effect, &buff);

      const char *errors = buff ? (const char*)(buff->GetBufferPointer()) : "OK";

      initFillrateRendererTexture(device);

      mTextureA = NULL;
      D3DXCreateTextureFromFileEx (m_Device.m_Dx9, L"lena.jpg", 0, 0, 0, 0, 
         D3DFMT_A8B8G8R8, D3DPOOL_DEFAULT, D3DX_DEFAULT, D3DX_DEFAULT, 0, NULL, NULL, &mTextureA);
   }

   void renderFrame(IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime)
   {
      pd3dDevice->BeginScene();

      IDirect3DSurface9 *oldSurf = NULL;
      pd3dDevice->GetRenderTarget(0, &oldSurf);

      UINT passes;
      effect->Begin(&passes, 0);
      for(int i=0; i<passes; i++)
      {
         effect->BeginPass(i);

         for(int i=0; i<targetCount; i++)
            pd3dDevice->SetRenderTarget(i, renderTarget[i]);

         pd3dDevice->SetTexture(0, mTextureA);
         pd3dDevice->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_LINEAR);
         pd3dDevice->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR);
         pd3dDevice->SetSamplerState(0, D3DSAMP_MIPFILTER, D3DTEXF_LINEAR);

         drawFillrateRendererTexture(pd3dDevice);

         for(int i=1; i<targetCount; i++)
            pd3dDevice->SetRenderTarget(i, NULL);

         effect->EndPass();
      }
      effect->End();

      pd3dDevice->SetRenderTarget(0, oldSurf);
      oldSurf->Release();
      
      pd3dDevice->SetTexture(0, NULL);

      pd3dDevice->EndScene();
   }

   void teardown()
   {
      for(int i=0; i<targetCount; i++)
         renderTarget[i]->Release();

      effect->Release();

      mTextureA->Release();

      teardownFillrateRenderer();
   }

};