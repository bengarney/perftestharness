
#include "d3dx9Effect.h"

struct iDevice;

class UtilFullScreenQuad
{
	public:
		UtilFullScreenQuad();
		~UtilFullScreenQuad();

	void RenderFullScreenQuad( iDevice* pDevice);
	void RenderFullScreenQuadTri( iDevice* pDevice, int type);
	void RenderFullScreenQuadIndex( iDevice* pDevice, int type);
	void RenderFullScreenQuadTex( iDevice* pDevice, int type);
	void RenderFullScreenQuadState( iDevice* pDevice, int stateLoop);
	void RenderFullScreenQuadVert( iDevice* pDevice, int Loop, int Prims);
	void RenderFullScreenQuadScissor( iDevice* pDevice, int enableScissor);
	void Init( iDevice* pDevice, unsigned int screenWidth, unsigned int screenHeight );
	void InitState( iDevice* pDevice, unsigned int screenWidth, unsigned int screenHeight );
	void InitVert( iDevice* pDevice, unsigned int screenWidth, unsigned int screenHeight );
	void InitScissor( iDevice* pDevice, unsigned int screenWidth, unsigned int screenHeight );
	void InitTri( iDevice* pDevice, unsigned int screenWidth, unsigned int screenHeight, int type );
	void InitIndex( iDevice* pDevice, unsigned int screenWidth, unsigned int screenHeight, int type );
	void InitTex( iDevice* pDevice, unsigned int screenWidth, unsigned int screenHeight, int type );

	protected:
	LPD3DXEFFECT m_pEffect;
	IDirect3DVertexDeclaration9* m_DX9VDec;
	IDirect3DVertexBuffer9* m_pVB9;
	IDirect3DIndexBuffer9 *pIB9;
	IDirect3DTexture9 * pTex;
	unsigned int m_ScreenWidth;
	unsigned int m_ScreenHeight;

};