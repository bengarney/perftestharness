
#include "d3dx9Effect.h"

struct iDevice;

class UtilFullScreenQuad
{
	public:
		UtilFullScreenQuad();
		~UtilFullScreenQuad();

	void RenderFullScreenQuad( iDevice* pDevice);
	void Init( iDevice* pDevice, unsigned int screenWidth, unsigned int screenHeight );

	protected:
	LPD3DXEFFECT m_pEffect;
	IDirect3DVertexDeclaration9* m_DX9VDec;
	IDirect3DVertexBuffer9* m_pVB9;
	unsigned int m_ScreenWidth;
	unsigned int m_ScreenHeight;

};