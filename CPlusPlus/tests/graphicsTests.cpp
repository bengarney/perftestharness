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
GRAPHICS_PERFORMANCE_TEST("basic/graphics/drawCalls", GraphicsDrawCallsTests, 8000)
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
      D3DXCreateTextureFromFileEx (m_Device.m_Dx9, L"Pharaoh.bmp", 0, 0, 0, D3DUSAGE_RENDERTARGET, 
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
