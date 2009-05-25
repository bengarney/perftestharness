#include "harness/graphicsHarness.h"
#include "testUtilities/IUtil.h"

/************************************************************************/
/* Bare minimum test that shows discernable graphics.                   */
/************************************************************************/
GRAPHICS_PERFORMANCE_TEST("basic/graphics/basicClear", GraphicsBasicClear)
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
/* Do a lot of clears so things are arbitrarily slower.                 */
/************************************************************************/
GRAPHICS_PERFORMANCE_TEST("basic/graphics/extraClears", GraphicsExtraClear)
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
      for(int i=0; i<50; i++)
         pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, 0xFF000000 | frameCount << 8, 0, 0);
   }
};

/**************************************************************************/
/* Do a lot of clears so things are arbitrarily slower, with varying MSAA Quality level */
/**************************************************************************/
GRAPHICS_PERFORMANCE_TEST("basic/graphics/extraClearsMSAAQuality", GraphicsExtraClearMSAAQuality)
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
GRAPHICS_PERFORMANCE_TEST("basic/graphics/extraClearsMSAA", GraphicsExtraClearMSAA)
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
