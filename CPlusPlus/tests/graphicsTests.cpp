#include "harness/graphicsHarness.h"
#include "testUtilities/IUtil.h"

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

	static const int Vertex = 1;

   void initialize()
   {
      frameCount = 0;
      Parent::initialize(lWidth, lHeight, lWin, lAStencil, SFormat);
	  IUtil::GetUtilFullScreenQuad()->Init( &(iDevice)Parent::m_Device,Parent::m_ScreenWidth,Parent::m_ScreenHeight, 1 );
   }


   void renderFrame(IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime)
   {
      frameCount++;
	  IUtil::GetUtilFullScreenQuad()->RenderFullScreenQuad( &iDevice(pd3dDevice), Vertex, 0, 0 );
   }
};

/************************************************************************/
/* Vertex Batching tests.											    */
/************************************************************************/
GRAPHICS_PERFORMANCE_TEST("basic/graphics/vertexBatchingSmall", GraphicsVertexBatchingLargeSmall, 8000)
{
   int frameCount;

    static const unsigned int lWidth = 1280;
	static const unsigned int lHeight = 1024;
	static const bool lWin = true;
	static const bool lAStencil = false;
	static const D3DFORMAT SFormat = D3DFMT_D24S8;
	
	static const int Vertex = 100000;

   void initialize()
   {
      frameCount = 0;
      Parent::initialize(lWidth, lHeight, lWin, lAStencil, SFormat);
	  IUtil::GetUtilFullScreenQuad()->Init( &(iDevice)Parent::m_Device,Parent::m_ScreenWidth,Parent::m_ScreenHeight, 1 );
   }


   void renderFrame(IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime)
   {
      frameCount++;
	  IUtil::GetUtilFullScreenQuad()->RenderFullScreenQuad( &iDevice(pd3dDevice), Vertex, 0, 0 );
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
	
	static const int Vertex = 1;

   void initialize()
   {
      frameCount = 0;
      Parent::initialize(lWidth, lHeight, lWin, lAStencil, SFormat);
	  IUtil::GetUtilFullScreenQuad()->Init( &(iDevice)Parent::m_Device,Parent::m_ScreenWidth,Parent::m_ScreenHeight, 1 );
   }


   void renderFrame(IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime)
   {
      frameCount++;
	  IUtil::GetUtilFullScreenQuad()->RenderFullScreenQuad( &iDevice(pd3dDevice), Vertex, 0, 0 );
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
	
	static const int Vertex = 1;

   void initialize()
   {
      frameCount = 0;
      Parent::initialize(lWidth, lHeight, lWin, lAStencil, SFormat);
	  IUtil::GetUtilFullScreenQuad()->Init( &(iDevice)Parent::m_Device,Parent::m_ScreenWidth,Parent::m_ScreenHeight, 1 );
   }


   void renderFrame(IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime)
   {
      frameCount++;
	  IUtil::GetUtilFullScreenQuad()->RenderFullScreenQuad( &iDevice(pd3dDevice), Vertex, 1, 1 );
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
	
	static const int Vertex = 1;

   void initialize()
   {
      frameCount = 0;
      Parent::initialize(lWidth, lHeight, lWin, lAStencil, SFormat);
	  IUtil::GetUtilFullScreenQuad()->Init( &(iDevice)Parent::m_Device,Parent::m_ScreenWidth,Parent::m_ScreenHeight, 1 );
   }


   void renderFrame(IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime)
   {
      frameCount++;
	  IUtil::GetUtilFullScreenQuad()->RenderFullScreenQuad( &iDevice(pd3dDevice), Vertex, 1, 1000 );
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
	  IUtil::GetUtilFullScreenQuad()->Init( &(iDevice)Parent::m_Device,Parent::m_ScreenWidth,Parent::m_ScreenHeight, 3 );
   }


   void renderFrame(IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime)
   {
      frameCount++;
	  IUtil::GetUtilFullScreenQuad()->RenderFullScreenQuadScissor( &iDevice(pd3dDevice), EnableScissor, 1, 1 );
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
	  IUtil::GetUtilFullScreenQuad()->Init( &(iDevice)Parent::m_Device,Parent::m_ScreenWidth,Parent::m_ScreenHeight, 3 );
   }


   void renderFrame(IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime)
   {
      frameCount++;
	  IUtil::GetUtilFullScreenQuad()->RenderFullScreenQuadScissor( &iDevice(pd3dDevice), EnableScissor, 1, 1 );
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
	  IUtil::GetUtilFullScreenQuad()->Init( &(iDevice)Parent::m_Device,Parent::m_ScreenWidth,Parent::m_ScreenHeight, 3 );
   }


   void renderFrame(IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime)
   {
      frameCount++;
	  IUtil::GetUtilFullScreenQuad()->RenderFullScreenQuadScissor( &iDevice(pd3dDevice), EnableScissor, 1, 1 );
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
