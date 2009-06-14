
#include "../Harness/graphicsHarness.h"
#include "dxut/SDKmisc.h"

#include "UtilFullScreenQuad.h"

DWORD MyFVF = D3DFVF_XYZ;

float quad[6*3]={   -1.0f, 1.0f, 0.0f,//1
					1.0f,1.0f,0.0f,//2
					-1.0f,-1.0f,0.0f,//3
				
					1.0f,1.0f,0.0f,//2
					1.0f,-1.0f,0.0f,//4
					-1.0f,-1.0f,0.0f//3
				};

int gvbSize = 6*sizeof(float)*3;

UtilFullScreenQuad::UtilFullScreenQuad()
{
	m_pEffect=0;
	m_ScreenWidth = 0;
	m_ScreenHeight = 0;
};

UtilFullScreenQuad::~UtilFullScreenQuad()
{
	SAFE_RELEASE(m_pEffect);
};

void UtilFullScreenQuad::Init( iDevice* pDevice, unsigned int screenWidth, unsigned int screenHeight )
{
	if( pDevice->m_Dx9  != 0 )
	{
		   // Define DEBUG_VS and/or DEBUG_PS to debug vertex and/or pixel shaders with the 
		// shader debugger. Debugging vertex shaders requires either REF or software vertex 
		// processing, and debugging pixel shaders requires REF.  The 
		// D3DXSHADER_FORCE_*_SOFTWARE_NOOPT flag improves the debug experience in the 
		// shader debugger.  It enables source level debugging, prevents instruction 
		// reordering, prevents dead code elimination, and forces the compiler to compile 
		// against the next higher available software target, which ensures that the 
		// unoptimized shaders do not exceed the shader model limitations.  Setting these 
		// flags will cause slower rendering since the shaders will be unoptimized and 
		// forced into software.  See the DirectX documentation for more information about 
		// using the shader debugger.
		DWORD dwShaderFlags = D3DXFX_NOT_CLONEABLE;

		#if defined( DEBUG ) || defined( _DEBUG )
		// Set the D3DXSHADER_DEBUG flag to embed debug information in the shaders.
		// Setting this flag improves the shader debugging experience, but still allows 
		// the shaders to be optimized and to run exactly the way they will run in 
		// the release configuration of this program.
		dwShaderFlags |= D3DXSHADER_DEBUG;
		#endif

		#ifdef DEBUG_VS
			dwShaderFlags |= D3DXSHADER_FORCE_VS_SOFTWARE_NOOPT;
		#endif
		#ifdef DEBUG_PS
			dwShaderFlags |= D3DXSHADER_FORCE_PS_SOFTWARE_NOOPT;
		#endif

		// Preshaders are parts of the shader that the effect system pulls out of the 
		// shader and runs on the host CPU. They should be used if you are GPU limited. 
		// The D3DXSHADER_NO_PRESHADER flag disables preshaders.
		dwShaderFlags |= D3DXSHADER_NO_PRESHADER;

		    // Read the D3DX effect file
		WCHAR str[MAX_PATH];
		DXUTFindDXSDKMediaFileCch( str, MAX_PATH, L"testUtilities/FullScreenQuad.fx" );
		D3DXCreateEffectFromFile( pDevice->m_Dx9, str, NULL, NULL, dwShaderFlags, NULL, &m_pEffect, NULL );

		D3DVERTEXELEMENT9 decl[] = 
		{
		{ 0, 0, D3DDECLTYPE_FLOAT3, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_POSITION, 0 },
		D3DDECL_END()
		}; 

		pDevice->m_Dx9->CreateVertexDeclaration(decl,&m_DX9VDec);

		
		
		pDevice->m_Dx9->CreateVertexBuffer(gvbSize,D3DUSAGE_WRITEONLY,MyFVF,D3DPOOL_DEFAULT,&m_pVB9,0);
		
		float* vertArray = 0;
		m_pVB9->Lock(0,gvbSize,(void**)&vertArray,0);
		memcpy(vertArray,quad,gvbSize);
		m_pVB9->Unlock();
	}

	m_ScreenWidth = screenWidth; 
	m_ScreenHeight = screenHeight;

}

void UtilFullScreenQuad::RenderFullScreenQuad( iDevice* pDevice)
{
	if( pDevice->m_Dx9 )
	{
		D3DVIEWPORT9 vp;
		vp.Height=m_ScreenHeight;
		vp.Width=m_ScreenWidth;
		vp.X = 0;
		vp.Y = 0;
		vp.MaxZ = 1;
		vp.MinZ = 0;

		pDevice->m_Dx9->SetViewport(&vp);
		UINT numPasses = 0;
		
		pDevice->m_Dx9->BeginScene();
		m_pEffect->Begin(&numPasses,0 );
		pDevice->m_Dx9->SetRenderState(D3DRS_ZENABLE,false);
		pDevice->m_Dx9->SetVertexDeclaration( m_DX9VDec );
		pDevice->m_Dx9->SetStreamSource(0,m_pVB9,0,sizeof(float)*3);
		m_pEffect->BeginPass(0);
		pDevice->m_Dx9->DrawPrimitive(D3DPT_TRIANGLELIST,0,2);
		m_pEffect->EndPass();
		pDevice->m_Dx9->SetRenderState(D3DRS_ZENABLE,true);
		m_pEffect->End();
		pDevice->m_Dx9->EndScene();
	}
}