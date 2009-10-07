
#include "../Harness/graphicsHarness.h"
#include "dxut/SDKmisc.h"

#include "UtilFullScreenQuad.h"
#include "Vertices.h"

DWORD MyFVF = D3DFVF_XYZ;

float quad[6*3]={   -1.0f, 1.0f, 0.0f,//1
					1.0f,1.0f,0.0f,//2
					-1.0f,-1.0f,0.0f,//3
				
					1.0f,1.0f,0.0f,//2
					1.0f,-1.0f,0.0f,//4
					-1.0f,-1.0f,0.0f//3
				};

int gvbSize = 6*sizeof(float)*3;



//LPDIRECT3DVERTEXBUFFER9 g_pVB = NULL; // Buffer to hold Vertices



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

void UtilFullScreenQuad::InitState( iDevice* pDevice, unsigned int screenWidth, unsigned int screenHeight )
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
		//WCHAR str[MAX_PATH];
		//DXUTFindDXSDKMediaFileCch( str, MAX_PATH, L"testUtilities/FullScreenQuad.fx" );
		//D3DXCreateEffectFromFile( pDevice->m_Dx9, str, NULL, NULL, dwShaderFlags, NULL, &m_pEffect, NULL );

		/*D3DVERTEXELEMENT9 decl[] = 
		{
		{ 0, 0, D3DDECLTYPE_FLOAT3, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_POSITION, 0 },
		D3DDECL_END()
		};*/

		//pDevice->m_Dx9->CreateVertexDeclaration(decl,&m_DX9VDec);
		pDevice->m_Dx9->Clear( 0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB( 0, 255, 0 ), 1.0f, 0 );
		pDevice->m_Dx9->SetRenderState(D3DRS_ZENABLE, false);
		pDevice->m_Dx9->CreateVertexBuffer(sizeof (VerticesF) ,0 ,D3DFVF_CUSTOMVERTEX,D3DPOOL_DEFAULT,&m_pVB9,NULL);
		VOID * vertArray;
		m_pVB9->Lock (0, sizeof (VerticesF), (void**)&vertArray, 0);
		memcpy(vertArray, VerticesF, sizeof (VerticesF));
		m_pVB9->Unlock();

	}

	m_ScreenWidth = screenWidth; 
	m_ScreenHeight = screenHeight;

}

void UtilFullScreenQuad::InitVert( iDevice* pDevice, unsigned int screenWidth, unsigned int screenHeight )
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
		//WCHAR str[MAX_PATH];
		//DXUTFindDXSDKMediaFileCch( str, MAX_PATH, L"testUtilities/FullScreenQuad.fx" );
		//D3DXCreateEffectFromFile( pDevice->m_Dx9, str, NULL, NULL, dwShaderFlags, NULL, &m_pEffect, NULL );

		/*D3DVERTEXELEMENT9 decl[] = 
		{
		{ 0, 0, D3DDECLTYPE_FLOAT3, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_POSITION, 0 },
		D3DDECL_END()
		};*/

		//pDevice->m_Dx9->CreateVertexDeclaration(decl,&m_DX9VDec);
		pDevice->m_Dx9->Clear( 0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB( 0, 255, 0 ), 1.0f, 0 );
		//pDevice->m_Dx9->SetRenderState(D3DRS_ZENABLE, false);

		pDevice->m_Dx9->CreateVertexBuffer(sizeof (VerticesF) ,0 ,D3DFVF_CUSTOMVERTEX,D3DPOOL_DEFAULT,&m_pVB9,NULL);
		
		VOID * vertArray;
		m_pVB9->Lock (0, sizeof (VerticesF), (void**)&vertArray, 0);
		memcpy(vertArray, VerticesF, sizeof (VerticesF));
		m_pVB9->Unlock();
	
	}

	m_ScreenWidth = screenWidth; 
	m_ScreenHeight = screenHeight;

}

void UtilFullScreenQuad::InitScissor( iDevice* pDevice, unsigned int screenWidth, unsigned int screenHeight )
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
		//WCHAR str[MAX_PATH];
		//DXUTFindDXSDKMediaFileCch( str, MAX_PATH, L"testUtilities/FullScreenQuad.fx" );
		//D3DXCreateEffectFromFile( pDevice->m_Dx9, str, NULL, NULL, dwShaderFlags, NULL, &m_pEffect, NULL );

		/*D3DVERTEXELEMENT9 decl[] = 
		{
		{ 0, 0, D3DDECLTYPE_FLOAT3, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_POSITION, 0 },
		D3DDECL_END()
		};*/

		//pDevice->m_Dx9->CreateVertexDeclaration(decl,&m_DX9VDec);
		pDevice->m_Dx9->Clear( 0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB( 0, 255, 0 ), 1.0f, 0 );
		pDevice->m_Dx9->SetRenderState(D3DRS_CLIPPING, false);
		pDevice->m_Dx9->SetRenderState(D3DRS_ZENABLE, false);
		pDevice->m_Dx9->CreateVertexBuffer(sizeof (VerticesF) ,0 ,D3DFVF_CUSTOMVERTEX,D3DPOOL_DEFAULT,&m_pVB9,NULL);
		VOID * vertArray;
		m_pVB9->Lock (0, sizeof (VerticesF), (void**)&vertArray, 0);
		memcpy(vertArray, VerticesF, sizeof (VerticesF));
		m_pVB9->Unlock();
		
	}

	m_ScreenWidth = screenWidth; 
	m_ScreenHeight = screenHeight;

}

void UtilFullScreenQuad::InitTri( iDevice* pDevice, unsigned int screenWidth, unsigned int screenHeight, int type )
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
		//WCHAR str[MAX_PATH];
		//DXUTFindDXSDKMediaFileCch( str, MAX_PATH, L"testUtilities/FullScreenQuad.fx" );
		//D3DXCreateEffectFromFile( pDevice->m_Dx9, str, NULL, NULL, dwShaderFlags, NULL, &m_pEffect, NULL );

		/*D3DVERTEXELEMENT9 decl[] = 
		{
		{ 0, 0, D3DDECLTYPE_FLOAT3, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_POSITION, 0 },
		D3DDECL_END()
		};*/

		//pDevice->m_Dx9->CreateVertexDeclaration(decl,&m_DX9VDec);
		pDevice->m_Dx9->Clear( 0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB( 0, 255, 0 ), 1.0f, 0 );
		//pDevice->m_Dx9->SetRenderState(D3DRS_ZENABLE, false);
		/*if (type == 0)
		{
			pDevice->m_Dx9->CreateVertexBuffer(sizeof (TriList) ,0 ,D3DFVF_CUSTOMVERTEX,D3DPOOL_DEFAULT,&m_pVB9,NULL);
			VOID * vertArray;
			m_pVB9->Lock (0, sizeof (TriList), (void**)&vertArray, 0);
			memcpy(vertArray, TriList, sizeof (TriList));
			m_pVB9->Unlock();
		}
		if (type == 1)
		{
			pDevice->m_Dx9->CreateVertexBuffer(sizeof (TriStrip) ,0 ,D3DFVF_CUSTOMVERTEX,D3DPOOL_DEFAULT,&m_pVB9,NULL);
			VOID * vertArray;
			m_pVB9->Lock (0, sizeof (TriStrip), (void**)&vertArray, 0);
			memcpy(vertArray, TriStrip, sizeof (TriStrip));
			m_pVB9->Unlock();
		}*/
	
	}

	m_ScreenWidth = screenWidth; 
	m_ScreenHeight = screenHeight;

}

void UtilFullScreenQuad::InitIndex( iDevice* pDevice, unsigned int screenWidth, unsigned int screenHeight, int type )
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
		//WCHAR str[MAX_PATH];
		//DXUTFindDXSDKMediaFileCch( str, MAX_PATH, L"testUtilities/FullScreenQuad.fx" );
		//D3DXCreateEffectFromFile( pDevice->m_Dx9, str, NULL, NULL, dwShaderFlags, NULL, &m_pEffect, NULL );

		/*D3DVERTEXELEMENT9 decl[] = 
		{
		{ 0, 0, D3DDECLTYPE_FLOAT3, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_POSITION, 0 },
		D3DDECL_END()
		};*/

		//pDevice->m_Dx9->CreateVertexDeclaration(decl,&m_DX9VDec);
		pDevice->m_Dx9->Clear( 0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB( 0, 200, 100 ), 1.0f, 0 );
		//pDevice->m_Dx9->SetRenderState(D3DRS_ZENABLE, false);
		/*if (type == 0)
		{
			pDevice->m_Dx9->CreateVertexBuffer(sizeof (TriStrip) ,0 ,D3DFVF_CUSTOMVERTEX,D3DPOOL_DEFAULT,&m_pVB9,NULL);
			VOID * vertArray;
			m_pVB9->Lock (0, sizeof (TriStrip), (void**)&vertArray, 0);
			memcpy(vertArray, TriStrip, sizeof (TriStrip));
			m_pVB9->Unlock();
			pDevice->m_Dx9->CreateIndexBuffer (sizeof (IBuffer), D3DUSAGE_DONOTCLIP, D3DFMT_INDEX32, D3DPOOL_DEFAULT, &pIB9, NULL); //360
			VOID * pIndices;
			pIB9->Lock(0, sizeof(IBuffer), (VOID**)&pIndices, 0);
			memcpy(pIndices, IBuffer, sizeof(IBuffer));
			pIB9->Unlock();
			pDevice->m_Dx9->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
			pDevice->m_Dx9->SetIndices(pIB9);
		}
		if (type == 1)
		{
			pDevice->m_Dx9->CreateVertexBuffer(sizeof(TriStrip) ,0 ,D3DFVF_CUSTOMVERTEX,D3DPOOL_DEFAULT,&m_pVB9,NULL);
			VOID * vertArray;
			m_pVB9->Lock (0, sizeof (TriStrip), (void**)&vertArray, 0);
			memcpy(vertArray, TriStrip, sizeof (TriStrip));
			m_pVB9->Unlock();
		}*/
	
	}

	m_ScreenWidth = screenWidth; 
	m_ScreenHeight = screenHeight;

}

void UtilFullScreenQuad::InitTex( iDevice* pDevice, unsigned int screenWidth, unsigned int screenHeight, int type )
{

	float left = 0.0f;
	float right = screenWidth;
	float top = 0.0f;
	float bottom = screenHeight;

	CUSTOMVERT2 Vertices[] =
	{
		{ left, top, 0.5f, 1.0f, 0.0f, 0.0f }, // x, y, z, rhw, u, v
		{ right, top, 0.5f, 1.0f, 1.0f, 0.0f },
		{ right, bottom, 0.5f, 1.0f, 1.0f, 1.0f },
		{ left, top, 0.5f, 1.0f, 0.0f, 0.0f },
		{ right, bottom, 0.5f, 1.0f, 1.0f, 1.0f },
		{ left, bottom, 0.5f, 1.0f, 0.0f, 1.0f }
	};
	
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
		//WCHAR str[MAX_PATH];
		//DXUTFindDXSDKMediaFileCch( str, MAX_PATH, L"testUtilities/FullScreenQuad.fx" );
		//D3DXCreateEffectFromFile( pDevice->m_Dx9, str, NULL, NULL, dwShaderFlags, NULL, &m_pEffect, NULL );

		/*D3DVERTEXELEMENT9 decl[] = 
		{
		{ 0, 0, D3DDECLTYPE_FLOAT3, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_POSITION, 0 },
		D3DDECL_END()
		};*/

		pDevice->m_Dx9->Clear( 0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB( 200, 100, 0 ), 1.0f, 0 );
		pDevice->m_Dx9->CreateVertexBuffer(sizeof (Vertices) ,0 ,D3DFVF_VERT2,D3DPOOL_DEFAULT,&m_pVB9,NULL);
		VOID * vertArray;
		m_pVB9->Lock (0, sizeof (Vertices), (void**)&vertArray, 0);
		memcpy(vertArray, Vertices, sizeof (Vertices));
		m_pVB9->Unlock();
		pDevice->m_Dx9->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
		pDevice->m_Dx9->SetRenderState(D3DRS_ZENABLE,false);
		pDevice->m_Dx9->SetStreamSource( 0, m_pVB9, 0, sizeof( CUSTOMVERT2 ) );
		pDevice->m_Dx9->SetFVF( D3DFVF_VERT2 );
		pDevice->m_Dx9->SetIndices(pIB9);
		
		/*if (type == 0)
		{
			D3DXCreateTextureFromFileEx (pDevice->m_Dx9, L"Pharaoh.bmp", 1280, 1024, 1, D3DUSAGE_RENDERTARGET, D3DFMT_A32B32G32R32F, D3DPOOL_DEFAULT, D3DX_DEFAULT, D3DX_DEFAULT, 0, NULL, NULL, &pTex);
			pDevice->m_Dx9->SetTexture (0, pTex);
		}
		if (type == 1)
		{
			D3DXCreateTextureFromFileEx (pDevice->m_Dx9, L"Pharaoh.bmp", 1280, 1024, 1, D3DUSAGE_RENDERTARGET, D3DFMT_R3G3B2, D3DPOOL_DEFAULT, D3DX_DEFAULT, D3DX_DEFAULT, 0, NULL, NULL, &pTex);
			pDevice->m_Dx9->SetTexture (0, pTex);
		}
		if (type == 2)
		{
			D3DXCreateTextureFromFileEx (pDevice->m_Dx9, L"Pharaoh.bmp", 2, 2, 1, D3DUSAGE_RENDERTARGET, D3DFMT_R3G3B2, D3DPOOL_DEFAULT, D3DX_DEFAULT, D3DX_DEFAULT, 0, NULL, NULL, &pTex);
			pDevice->m_Dx9->SetTexture (0, pTex);
		}*/
	
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

void UtilFullScreenQuad::RenderFullScreenQuadTri( iDevice* pDevice, int type)
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
		
		pDevice->m_Dx9->BeginScene();
		pDevice->m_Dx9->SetRenderState(D3DRS_ZENABLE,false);
		pDevice->m_Dx9->SetStreamSource( 0, m_pVB9, 0, sizeof( CUSTOMVERTEX ) );
		pDevice->m_Dx9->SetFVF( D3DFVF_CUSTOMVERTEX );
		if (type == 0)
		{
			pDevice->m_Dx9->CreateVertexBuffer(sizeof (TriList) ,0 ,D3DFVF_CUSTOMVERTEX,D3DPOOL_DEFAULT,&m_pVB9,NULL);
			VOID * vertArray;
			m_pVB9->Lock (0, sizeof (TriList), (void**)&vertArray, 0);
			memcpy(vertArray, TriList, sizeof (TriList));
			m_pVB9->Unlock();
			pDevice->m_Dx9->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
			pDevice->m_Dx9->DrawPrimitive( D3DPT_TRIANGLELIST, 0, 120 );
		}
		else
		{
			pDevice->m_Dx9->CreateVertexBuffer(sizeof (TriStrip) ,0 ,D3DFVF_CUSTOMVERTEX,D3DPOOL_DEFAULT,&m_pVB9,NULL);
			VOID * vertArray;
			m_pVB9->Lock (0, sizeof (TriStrip), (void**)&vertArray, 0);
			memcpy(vertArray, TriStrip, sizeof (TriStrip));
			m_pVB9->Unlock();
			pDevice->m_Dx9->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 120);
		}
	
		pDevice->m_Dx9->SetRenderState(D3DRS_ZENABLE,true);
		pDevice->m_Dx9->EndScene();
		pDevice->m_Dx9->Present (NULL, NULL, NULL, NULL);
	}
}

void UtilFullScreenQuad::RenderFullScreenQuadIndex( iDevice* pDevice, int type)
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
		
		pDevice->m_Dx9->BeginScene();
		pDevice->m_Dx9->SetRenderState(D3DRS_ZENABLE,false);
		pDevice->m_Dx9->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
		//pDevice->m_Dx9->SetStreamSource( 0, m_pVB9, 0, sizeof( CUSTOMVERTEX ) );
		//pDevice->m_Dx9->SetFVF( D3DFVF_CUSTOMVERTEX );
		if (type == 0)
		{
			pDevice->m_Dx9->CreateVertexBuffer(sizeof (TriStrip) ,0 ,D3DFVF_CUSTOMVERTEX,D3DPOOL_DEFAULT,&m_pVB9,NULL);
			VOID * vertArray;
			m_pVB9->Lock (0, sizeof (TriStrip), (void**)&vertArray, 0);
			memcpy(vertArray, TriStrip, sizeof (TriStrip));
			m_pVB9->Unlock();
			for (int i = 0; i < 10; i++)
			{
				pDevice->m_Dx9->CreateIndexBuffer (sizeof (IBuffer), D3DUSAGE_DONOTCLIP, D3DFMT_INDEX32, D3DPOOL_DEFAULT, &pIB9, NULL); //360
				VOID * pIndices;
				pIB9->Lock(0, sizeof(IBuffer), (VOID**)&pIndices, 0);
				memcpy(pIndices, IBuffer, sizeof(IBuffer));
				pIB9->Unlock();
				pDevice->m_Dx9->SetStreamSource( 0, m_pVB9, 0, sizeof( CUSTOMVERTEX ) );
				pDevice->m_Dx9->SetFVF( D3DFVF_CUSTOMVERTEX );
				pDevice->m_Dx9->SetIndices(pIB9);
				pDevice->m_Dx9->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 121, 0, 120);
			}
		}
		else
		{
			for (int i = 0; i < 10; i++)
			{
				pDevice->m_Dx9->CreateVertexBuffer(sizeof(TriList) ,0 ,D3DFVF_CUSTOMVERTEX,D3DPOOL_DEFAULT,&m_pVB9,NULL);
				VOID * vertArray;
				m_pVB9->Lock (0, sizeof (TriList), (void**)&vertArray, 0);
				memcpy(vertArray, TriList, sizeof (TriList));
				m_pVB9->Unlock();
				pDevice->m_Dx9->SetStreamSource( 0, m_pVB9, 0, sizeof( CUSTOMVERTEX ) );
				pDevice->m_Dx9->SetFVF( D3DFVF_CUSTOMVERTEX );
				pDevice->m_Dx9->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 120);
			}
		}
	
		pDevice->m_Dx9->EndScene();
		pDevice->m_Dx9->Present (NULL, NULL, NULL, NULL);
	}
}

void UtilFullScreenQuad::RenderFullScreenQuadTex( iDevice* pDevice, int type)
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
		//UINT numPasses = 0;
		
		pDevice->m_Dx9->BeginScene();
		//m_pEffect->Begin(&numPasses,0 );

		if (type == 0)
		{
			D3DXCreateTextureFromFileEx (pDevice->m_Dx9, L"Pharaoh.bmp", m_ScreenWidth, m_ScreenHeight, 1, D3DUSAGE_RENDERTARGET, D3DFMT_A32B32G32R32F, D3DPOOL_DEFAULT, D3DX_DEFAULT, D3DX_DEFAULT, 0, NULL, NULL, &pTex);
			pDevice->m_Dx9->SetTexture (0, pTex);
		}
		else if (type == 1)
		{
			D3DXCreateTextureFromFileEx (pDevice->m_Dx9, L"Pharaoh.bmp", m_ScreenWidth, m_ScreenHeight, 1, D3DUSAGE_RENDERTARGET, D3DFMT_R3G3B2, D3DPOOL_DEFAULT, D3DX_DEFAULT, D3DX_DEFAULT, 0, NULL, NULL, &pTex);
			pDevice->m_Dx9->SetTexture (0, pTex);
		}
		else if (type == 2)
		{
			D3DXCreateTextureFromFileEx (pDevice->m_Dx9, L"Pharaoh.bmp", 2, 2, 1, D3DUSAGE_RENDERTARGET, D3DFMT_R3G3B2, D3DPOOL_DEFAULT, D3DX_DEFAULT, D3DX_DEFAULT, 0, NULL, NULL, &pTex);
			pDevice->m_Dx9->SetTexture (0, pTex);
		}
		else if (type == 3)
		{
			D3DXCreateTextureFromFileEx (pDevice->m_Dx9, L"Pharaoh.bmp", m_ScreenWidth, m_ScreenHeight, 1, D3DUSAGE_RENDERTARGET, D3DFMT_DXT5, D3DPOOL_DEFAULT, D3DX_DEFAULT, D3DX_DEFAULT, 0, NULL, NULL, &pTex);
			pDevice->m_Dx9->SetTexture (0, pTex);
		}
		else if (type == 4)
		{
			D3DXCreateTextureFromFileEx (pDevice->m_Dx9, L"Pharaoh.bmp", m_ScreenWidth, m_ScreenHeight, 1, D3DUSAGE_RENDERTARGET, D3DFMT_R5G6B5, D3DPOOL_DEFAULT, D3DX_DEFAULT, D3DX_DEFAULT, 0, NULL, NULL, &pTex);
			pDevice->m_Dx9->SetTexture (0, pTex);
		}
		else if (type == 5)
		{
			D3DXCreateTextureFromFileEx (pDevice->m_Dx9, L"Pharaoh.bmp", m_ScreenWidth, m_ScreenHeight, 1, D3DUSAGE_RENDERTARGET, D3DFMT_A2R10G10B10, D3DPOOL_DEFAULT, D3DX_DEFAULT, D3DX_DEFAULT, 0, NULL, NULL, &pTex);
			pDevice->m_Dx9->SetTexture (0, pTex);
		}
		else if (type == 6)
		{
			D3DXCreateTextureFromFileEx (pDevice->m_Dx9, L"Pharaoh.bmp", m_ScreenWidth, m_ScreenHeight, 1, D3DUSAGE_RENDERTARGET, D3DFMT_DXT1, D3DPOOL_DEFAULT, D3DX_DEFAULT, D3DX_DEFAULT, 0, NULL, NULL, &pTex);
			pDevice->m_Dx9->SetTexture (0, pTex);
		}
		
		pDevice->m_Dx9->DrawPrimitive( D3DPT_TRIANGLELIST, 0, 2 );
		pDevice->m_Dx9->EndScene();
		pDevice->m_Dx9->Present (NULL, NULL, NULL, NULL);
	}
}


void UtilFullScreenQuad::RenderFullScreenQuadState( iDevice* pDevice, int stateLoop)
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
		pDevice->m_Dx9->BeginScene();
		
		for (int i = 0; i < stateLoop; i++)
		{
			pDevice->m_Dx9->SetRenderState (D3DRS_FILLMODE, D3DFILL_WIREFRAME);
			pDevice->m_Dx9->SetRenderState (D3DRS_FILLMODE, D3DFILL_SOLID);
			pDevice->m_Dx9->SetRenderState (D3DRS_LASTPIXEL, false);
			pDevice->m_Dx9->SetRenderState (D3DRS_LASTPIXEL, true);
			pDevice->m_Dx9->SetRenderState (D3DRS_FOGENABLE, true);
			pDevice->m_Dx9->SetRenderState (D3DRS_FOGENABLE, false);
		}
		pDevice->m_Dx9->SetStreamSource( 0, m_pVB9, 0, sizeof( CUSTOMVERTEX ) );
		pDevice->m_Dx9->SetFVF( D3DFVF_CUSTOMVERTEX );
		pDevice->m_Dx9->DrawPrimitive( D3DPT_TRIANGLELIST, 0, 1 );
		
		pDevice->m_Dx9->EndScene();
		pDevice->m_Dx9->Present (NULL, NULL, NULL, NULL);
	}

}

void UtilFullScreenQuad::RenderFullScreenQuadVert( iDevice* pDevice, int Loop, int Prims)
{
	int offset = 0;
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
		//UINT numPasses = 0;
		
		//pDevice->m_Dx9->BeginScene();
		//m_pEffect->Begin(&numPasses,0 );
		//pDevice->m_Dx9->SetRenderState (D3DRS_ZENABLE, false);
		//pDevice->m_Dx9->SetStreamSource(0, m_pVB9, 0, sizeof(CUSTOMVERTEX));
		//pDevice->m_Dx9->SetFVF(D3DFVF_CUSTOMVERTEX);
		
		for (int i = 0; i < Loop; i++)
		{
			pDevice->m_Dx9->BeginScene();
			pDevice->m_Dx9->SetRenderState(D3DRS_ZENABLE, false);
			pDevice->m_Dx9->SetStreamSource(0, m_pVB9, 0, sizeof(CUSTOMVERTEX));
			pDevice->m_Dx9->SetFVF(D3DFVF_CUSTOMVERTEX);
			pDevice->m_Dx9->DrawPrimitive(D3DPT_TRIANGLELIST, offset, Prims);
			pDevice->m_Dx9->SetRenderState(D3DRS_ZENABLE, true);
			pDevice->m_Dx9->EndScene();			
			offset = offset + 3;
		}

		//pDevice->m_Dx9->SetRenderState (D3DRS_ZENABLE, true);
		//pDevice->m_Dx9->SetRenderState(D3DRS_ZENABLE,false);
		//pDevice->m_Dx9->SetVertexDeclaration( m_DX9VDec );
		//pDevice->m_Dx9->SetStreamSource(0,m_pVB9,0,sizeof(float)*3);
		//m_pEffect->BeginPass(0);
		//pDevice->m_Dx9->DrawPrimitive(D3DPT_TRIANGLELIST,0,2);
		//m_pEffect->EndPass();
		//pDevice->m_Dx9->SetRenderState(D3DRS_ZENABLE,true);
		//m_pEffect->End();
		//pDevice->m_Dx9->EndScene();
		pDevice->m_Dx9->Present (NULL, NULL, NULL, NULL);
	}

}

void UtilFullScreenQuad::RenderFullScreenQuadScissor( iDevice* pDevice, int enableScissor)
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
		
		const RECT Rect1 = {0, 0, 1280, 800};
		const RECT Rect0 = {0};
		if (enableScissor == 1)
			pDevice->m_Dx9->SetScissorRect (&Rect1);
		if (enableScissor == 2)
			pDevice->m_Dx9->SetScissorRect (&Rect0);

		pDevice->m_Dx9->SetViewport(&vp);
		//UINT numPasses = 0;
		
		pDevice->m_Dx9->BeginScene();
		//m_pEffect->Begin(&numPasses,0 );
		//pDevice->m_Dx9->SetRenderState (D3DRS_ZENABLE, false);
		if (enableScissor > 0)
			pDevice->m_Dx9->SetRenderState (D3DRS_SCISSORTESTENABLE, true);
		for (int i = 0; i<50; i++)
			pDevice->m_Dx9->Clear( 0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB( 255, 0, 0 ), 1.0f, 0 );

		pDevice->m_Dx9->SetStreamSource( 0, m_pVB9, 0, sizeof( CUSTOMVERTEX ) );
		pDevice->m_Dx9->SetFVF( D3DFVF_CUSTOMVERTEX );
		pDevice->m_Dx9->DrawPrimitive( D3DPT_TRIANGLELIST, 0, 8 );
		//pDevice->m_Dx9->SetRenderState (D3DRS_ZENABLE, true);
		//pDevice->m_Dx9->SetRenderState(D3DRS_ZENABLE,false);
		//pDevice->m_Dx9->SetVertexDeclaration( m_DX9VDec );
		//pDevice->m_Dx9->SetStreamSource(0,m_pVB9,0,sizeof(float)*3);
		//m_pEffect->BeginPass(0);
		//pDevice->m_Dx9->DrawPrimitive(D3DPT_TRIANGLELIST,0,2);
		//m_pEffect->EndPass();
		//pDevice->m_Dx9->SetRenderState(D3DRS_ZENABLE,true);
		//m_pEffect->End();
		pDevice->m_Dx9->EndScene();
		pDevice->m_Dx9->Present (NULL, NULL, NULL, NULL);
	}


}