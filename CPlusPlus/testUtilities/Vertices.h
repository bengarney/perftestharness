#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZRHW|D3DFVF_DIFFUSE)
#define D3DFVF_VERT2 (D3DFVF_XYZRHW | D3DFVF_TEX1)

struct CUSTOMVERTEX
{
    FLOAT x, y, z, rhw; // The transformed position for the vertex
    DWORD color;        // The vertex color
};

struct CUSTOMVERT2
{
	FLOAT x, y, z, rhw;
	FLOAT tu, tv;
};

CUSTOMVERTEX VerticesF[] =
{	
	{ 150.0f,  50.0f, 0.5f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 250.0f, 250.0f, 0.5f, 1.0f, 0xff00ff00, },
	{  50.0f, 250.0f, 0.5f, 1.0f, 0xff00ffff, },
	{ 640.0f,  10.0f, 0.15f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.15f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.15f, 1.0f, 0xff00ffff, },
	{ 0.0f,  0.0f, 0.51f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.51f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.51f, 1.0f, 0xff00ffff, },
	{ 240.0f,  1.0f, 0.52f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.52f, 1.0f, 0xff00ff00, },
	{ 10.0f, 50.0f, 0.52f, 1.0f, 0xff00ffff, },
	{ 640.0f,  10.0f, 0.53f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1200.0f, 0.0f, 0.53f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.53f, 1.0f, 0xff00ffff, },
	{ 40.0f,  100.0f, 0.54f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 750.0f, 30.0f, 0.54f, 1.0f, 0xff00ff00, },
	{ 100.0f, 1050.0f, 0.54f, 1.0f, 0xff00ffff, },
	{ 27.0f,  27.0f, 0.55f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 50.0f, 1250.0f, 0.55f, 1.0f, 0xff00ff00, },
	{ 1000.0f, 2250.0f, 0.55f, 1.0f, 0xff00ffff, },
	{ 64.0f,  12.0f, 0.56f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 950.0f, 450.0f, 0.56f, 1.0f, 0xff00ff00, },
	{ 500.0f, 12.0f, 0.56f, 1.0f, 0xff00ffff, },
	{ 640.0f,  0.0f, 0.57f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 70.0f, 125.0f, 0.57f, 1.0f, 0xff00ff00, },
	{ 710.0f, 2250.0f, 0.57f, 1.0f, 0xff00ffff, },	
		{ 900.0f,  1000.0f, 0.1f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 13.0f, 2.0f, 1.0f, 1.0f, 0xff00ff00, },
	{ 1280.0f, 1024.0f, 0.01f, 1.0f, 0xff00ffff, },
	{ 0.0f,  0.0f, 0.51f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.51f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.51f, 1.0f, 0xff00ffff, },
	{ 240.0f,  1.0f, 0.52f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.52f, 1.0f, 0xff00ff00, },
	{ 10.0f, 50.0f, 0.52f, 1.0f, 0xff00ffff, },
	{ 640.0f,  10.0f, 0.53f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1200.0f, 0.0f, 0.53f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.53f, 1.0f, 0xff00ffff, },
	{ 40.0f,  100.0f, 0.54f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 750.0f, 30.0f, 0.54f, 1.0f, 0xff00ff00, },
	{ 100.0f, 1050.0f, 0.54f, 1.0f, 0xff00ffff, },
	{ 27.0f,  27.0f, 0.55f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 50.0f, 1250.0f, 0.55f, 1.0f, 0xff00ff00, },
	{ 1000.0f, 2250.0f, 0.55f, 1.0f, 0xff00ffff, },
	{ 64.0f,  12.0f, 0.56f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 950.0f, 450.0f, 0.56f, 1.0f, 0xff00ff00, },
	{ 500.0f, 12.0f, 0.56f, 1.0f, 0xff00ffff, },
	{ 640.0f,  0.0f, 0.57f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 70.0f, 125.0f, 0.57f, 1.0f, 0xff00ff00, },
	{ 710.0f, 2250.0f, 0.57f, 1.0f, 0xff00ffff, },
	{ 640.0f,  10.0f, 0.5f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.5f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.5f, 1.0f, 0xff00ffff, },
	{ 0.0f,  0.0f, 0.51f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.51f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.51f, 1.0f, 0xff00ffff, },
	{ 240.0f,  1.0f, 0.52f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.52f, 1.0f, 0xff00ff00, },
	{ 10.0f, 50.0f, 0.52f, 1.0f, 0xff00ffff, },
	{ 640.0f,  10.0f, 0.53f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1200.0f, 0.0f, 0.53f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.53f, 1.0f, 0xff00ffff, },
	{ 40.0f,  100.0f, 0.54f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 750.0f, 30.0f, 0.54f, 1.0f, 0xff00ff00, },
	{ 100.0f, 1050.0f, 0.54f, 1.0f, 0xff00ffff, },
	{ 27.0f,  27.0f, 0.55f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 50.0f, 1250.0f, 0.55f, 1.0f, 0xff00ff00, },
	{ 1000.0f, 2250.0f, 0.55f, 1.0f, 0xff00ffff, },
	{ 64.0f,  12.0f, 0.56f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 950.0f, 450.0f, 0.56f, 1.0f, 0xff00ff00, },
	{ 500.0f, 12.0f, 0.56f, 1.0f, 0xff00ffff, },
	{ 640.0f,  0.0f, 0.57f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 70.0f, 125.0f, 0.57f, 1.0f, 0xff00ff00, },
	{ 710.0f, 2250.0f, 0.57f, 1.0f, 0xff00ffff, },
	{ 640.0f,  10.0f, 0.5f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.5f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.5f, 1.0f, 0xff00ffff, },
	{ 0.0f,  0.0f, 0.51f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.51f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.51f, 1.0f, 0xff00ffff, },
	{ 240.0f,  1.0f, 0.52f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.52f, 1.0f, 0xff00ff00, },
	{ 10.0f, 50.0f, 0.52f, 1.0f, 0xff00ffff, },
	{ 640.0f,  10.0f, 0.53f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1200.0f, 0.0f, 0.53f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.53f, 1.0f, 0xff00ffff, },
	{ 40.0f,  100.0f, 0.54f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 750.0f, 30.0f, 0.54f, 1.0f, 0xff00ff00, },
	{ 100.0f, 1050.0f, 0.54f, 1.0f, 0xff00ffff, },
	{ 27.0f,  27.0f, 0.55f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 50.0f, 1250.0f, 0.55f, 1.0f, 0xff00ff00, },
	{ 1000.0f, 2250.0f, 0.55f, 1.0f, 0xff00ffff, },
	{ 64.0f,  12.0f, 0.56f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 950.0f, 450.0f, 0.56f, 1.0f, 0xff00ff00, },
	{ 500.0f, 12.0f, 0.56f, 1.0f, 0xff00ffff, },
	{ 640.0f,  0.0f, 0.57f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 70.0f, 125.0f, 0.57f, 1.0f, 0xff00ff00, },
	{ 710.0f, 2250.0f, 0.57f, 1.0f, 0xff00ffff, },
	{ 640.0f,  10.0f, 0.5f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.5f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.5f, 1.0f, 0xff00ffff, },
	{ 0.0f,  0.0f, 0.51f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.51f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.51f, 1.0f, 0xff00ffff, },
	{ 240.0f,  1.0f, 0.52f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.52f, 1.0f, 0xff00ff00, },
	{ 10.0f, 50.0f, 0.52f, 1.0f, 0xff00ffff, },
	{ 640.0f,  10.0f, 0.53f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1200.0f, 0.0f, 0.53f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.53f, 1.0f, 0xff00ffff, },
	{ 40.0f,  100.0f, 0.54f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 750.0f, 30.0f, 0.54f, 1.0f, 0xff00ff00, },
	{ 100.0f, 1050.0f, 0.54f, 1.0f, 0xff00ffff, },
	{ 27.0f,  27.0f, 0.55f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 50.0f, 1250.0f, 0.55f, 1.0f, 0xff00ff00, },
	{ 1000.0f, 2250.0f, 0.55f, 1.0f, 0xff00ffff, },
	{ 64.0f,  12.0f, 0.56f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 950.0f, 450.0f, 0.56f, 1.0f, 0xff00ff00, },
	{ 500.0f, 12.0f, 0.56f, 1.0f, 0xff00ffff, },
	{ 640.0f,  0.0f, 0.57f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 70.0f, 125.0f, 0.57f, 1.0f, 0xff00ff00, },
	{ 710.0f, 2250.0f, 0.57f, 1.0f, 0xff00ffff, },
	{ 640.0f,  10.0f, 0.5f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.5f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.5f, 1.0f, 0xff00ffff, },
	{ 0.0f,  0.0f, 0.51f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.51f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.51f, 1.0f, 0xff00ffff, },
	{ 240.0f,  1.0f, 0.52f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.52f, 1.0f, 0xff00ff00, },
	{ 10.0f, 50.0f, 0.52f, 1.0f, 0xff00ffff, },
	{ 640.0f,  10.0f, 0.53f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1200.0f, 0.0f, 0.53f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.53f, 1.0f, 0xff00ffff, },
	{ 40.0f,  100.0f, 0.54f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 750.0f, 30.0f, 0.54f, 1.0f, 0xff00ff00, },
	{ 100.0f, 1050.0f, 0.54f, 1.0f, 0xff00ffff, },
	{ 27.0f,  27.0f, 0.55f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 50.0f, 1250.0f, 0.55f, 1.0f, 0xff00ff00, },
	{ 1000.0f, 2250.0f, 0.55f, 1.0f, 0xff00ffff, },
	{ 64.0f,  12.0f, 0.56f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 950.0f, 450.0f, 0.56f, 1.0f, 0xff00ff00, },
	{ 500.0f, 12.0f, 0.56f, 1.0f, 0xff00ffff, },
	{ 640.0f,  0.0f, 0.57f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 70.0f, 125.0f, 0.57f, 1.0f, 0xff00ff00, },
	{ 710.0f, 2250.0f, 0.57f, 1.0f, 0xff00ffff, },
	{ 640.0f,  10.0f, 0.5f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.5f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.5f, 1.0f, 0xff00ffff, },
	{ 0.0f,  0.0f, 0.51f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.51f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.51f, 1.0f, 0xff00ffff, },
	{ 240.0f,  1.0f, 0.52f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.52f, 1.0f, 0xff00ff00, },
	{ 10.0f, 50.0f, 0.52f, 1.0f, 0xff00ffff, },
	{ 640.0f,  10.0f, 0.53f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1200.0f, 0.0f, 0.53f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.53f, 1.0f, 0xff00ffff, },
	{ 40.0f,  100.0f, 0.54f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 750.0f, 30.0f, 0.54f, 1.0f, 0xff00ff00, },
	{ 100.0f, 1050.0f, 0.54f, 1.0f, 0xff00ffff, },
	{ 27.0f,  27.0f, 0.55f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 50.0f, 1250.0f, 0.55f, 1.0f, 0xff00ff00, },
	{ 1000.0f, 2250.0f, 0.55f, 1.0f, 0xff00ffff, },
	{ 64.0f,  12.0f, 0.56f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 950.0f, 450.0f, 0.56f, 1.0f, 0xff00ff00, },
	{ 500.0f, 12.0f, 0.56f, 1.0f, 0xff00ffff, },
	{ 640.0f,  0.0f, 0.57f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 70.0f, 125.0f, 0.57f, 1.0f, 0xff00ff00, },
	{ 710.0f, 2250.0f, 0.57f, 1.0f, 0xff00ffff, },
	{ 640.0f,  10.0f, 0.5f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.5f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.5f, 1.0f, 0xff00ffff, },
	{ 0.0f,  0.0f, 0.51f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.51f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.51f, 1.0f, 0xff00ffff, },
	{ 240.0f,  1.0f, 0.52f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.52f, 1.0f, 0xff00ff00, },
	{ 10.0f, 50.0f, 0.52f, 1.0f, 0xff00ffff, },
	{ 640.0f,  10.0f, 0.53f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1200.0f, 0.0f, 0.53f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.53f, 1.0f, 0xff00ffff, },
	{ 40.0f,  100.0f, 0.54f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 750.0f, 30.0f, 0.54f, 1.0f, 0xff00ff00, },
	{ 100.0f, 1050.0f, 0.54f, 1.0f, 0xff00ffff, },
	{ 27.0f,  27.0f, 0.55f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 50.0f, 1250.0f, 0.55f, 1.0f, 0xff00ff00, },
	{ 1000.0f, 2250.0f, 0.55f, 1.0f, 0xff00ffff, },
	{ 64.0f,  12.0f, 0.56f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 950.0f, 450.0f, 0.56f, 1.0f, 0xff00ff00, },
	{ 500.0f, 12.0f, 0.56f, 1.0f, 0xff00ffff, },
	{ 640.0f,  0.0f, 0.57f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 70.0f, 125.0f, 0.57f, 1.0f, 0xff00ff00, },
	{ 710.0f, 2250.0f, 0.57f, 1.0f, 0xff00ffff, },
	{ 640.0f,  10.0f, 0.5f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.5f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.5f, 1.0f, 0xff00ffff, },
	{ 0.0f,  0.0f, 0.51f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.51f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.51f, 1.0f, 0xff00ffff, },
	{ 240.0f,  1.0f, 0.52f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.52f, 1.0f, 0xff00ff00, },
	{ 10.0f, 50.0f, 0.52f, 1.0f, 0xff00ffff, },
	{ 640.0f,  10.0f, 0.53f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1200.0f, 0.0f, 0.53f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.53f, 1.0f, 0xff00ffff, },
	{ 40.0f,  100.0f, 0.54f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 750.0f, 30.0f, 0.54f, 1.0f, 0xff00ff00, },
	{ 100.0f, 1050.0f, 0.54f, 1.0f, 0xff00ffff, },
	{ 27.0f,  27.0f, 0.55f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 50.0f, 1250.0f, 0.55f, 1.0f, 0xff00ff00, },
	{ 1000.0f, 2250.0f, 0.55f, 1.0f, 0xff00ffff, },
	{ 64.0f,  12.0f, 0.56f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 950.0f, 450.0f, 0.56f, 1.0f, 0xff00ff00, },
	{ 500.0f, 12.0f, 0.56f, 1.0f, 0xff00ffff, },
	{ 640.0f,  0.0f, 0.57f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 70.0f, 125.0f, 0.57f, 1.0f, 0xff00ff00, },
	{ 710.0f, 2250.0f, 0.57f, 1.0f, 0xff00ffff, },
	{ 640.0f,  10.0f, 0.5f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.5f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.5f, 1.0f, 0xff00ffff, },
	{ 0.0f,  0.0f, 0.51f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.51f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.51f, 1.0f, 0xff00ffff, },
	{ 240.0f,  1.0f, 0.52f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.52f, 1.0f, 0xff00ff00, },
	{ 10.0f, 50.0f, 0.52f, 1.0f, 0xff00ffff, },
	{ 640.0f,  10.0f, 0.53f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1200.0f, 0.0f, 0.53f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.53f, 1.0f, 0xff00ffff, },
	{ 40.0f,  100.0f, 0.54f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 750.0f, 30.0f, 0.54f, 1.0f, 0xff00ff00, },
	{ 100.0f, 1050.0f, 0.54f, 1.0f, 0xff00ffff, },
	{ 27.0f,  27.0f, 0.55f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 50.0f, 1250.0f, 0.55f, 1.0f, 0xff00ff00, },
	{ 1000.0f, 2250.0f, 0.55f, 1.0f, 0xff00ffff, },
	{ 64.0f,  12.0f, 0.56f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 950.0f, 450.0f, 0.56f, 1.0f, 0xff00ff00, },
	{ 500.0f, 12.0f, 0.56f, 1.0f, 0xff00ffff, },
	{ 640.0f,  0.0f, 0.57f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 70.0f, 125.0f, 0.57f, 1.0f, 0xff00ff00, },
	{ 710.0f, 2250.0f, 0.57f, 1.0f, 0xff00ffff, },
	{ 640.0f,  10.0f, 0.5f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.5f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.5f, 1.0f, 0xff00ffff, },
	{ 0.0f,  0.0f, 0.51f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.51f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.51f, 1.0f, 0xff00ffff, },
	{ 240.0f,  1.0f, 0.52f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.52f, 1.0f, 0xff00ff00, },
	{ 10.0f, 50.0f, 0.52f, 1.0f, 0xff00ffff, },
	{ 640.0f,  10.0f, 0.53f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1200.0f, 0.0f, 0.53f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.53f, 1.0f, 0xff00ffff, },
	{ 40.0f,  100.0f, 0.54f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 750.0f, 30.0f, 0.54f, 1.0f, 0xff00ff00, },
	{ 100.0f, 1050.0f, 0.54f, 1.0f, 0xff00ffff, },
	{ 27.0f,  27.0f, 0.55f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 50.0f, 1250.0f, 0.55f, 1.0f, 0xff00ff00, },
	{ 1000.0f, 2250.0f, 0.55f, 1.0f, 0xff00ffff, },
	{ 64.0f,  12.0f, 0.56f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 950.0f, 450.0f, 0.56f, 1.0f, 0xff00ff00, },
	{ 500.0f, 12.0f, 0.56f, 1.0f, 0xff00ffff, },
	{ 640.0f,  0.0f, 0.57f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 70.0f, 125.0f, 0.57f, 1.0f, 0xff00ff00, },
	{ 710.0f, 2250.0f, 0.57f, 1.0f, 0xff00ffff, },
	{ 640.0f,  10.0f, 0.5f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.5f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.5f, 1.0f, 0xff00ffff, },
	{ 0.0f,  0.0f, 0.51f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.51f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.51f, 1.0f, 0xff00ffff, },
	{ 240.0f,  1.0f, 0.52f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.52f, 1.0f, 0xff00ff00, },
	{ 10.0f, 50.0f, 0.52f, 1.0f, 0xff00ffff, },
	{ 640.0f,  10.0f, 0.53f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1200.0f, 0.0f, 0.53f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.53f, 1.0f, 0xff00ffff, },
	{ 40.0f,  100.0f, 0.54f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 750.0f, 30.0f, 0.54f, 1.0f, 0xff00ff00, },
	{ 100.0f, 1050.0f, 0.54f, 1.0f, 0xff00ffff, },
	{ 27.0f,  27.0f, 0.55f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 50.0f, 1250.0f, 0.55f, 1.0f, 0xff00ff00, },
	{ 1000.0f, 2250.0f, 0.55f, 1.0f, 0xff00ffff, },
	{ 64.0f,  12.0f, 0.56f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 950.0f, 450.0f, 0.56f, 1.0f, 0xff00ff00, },
	{ 500.0f, 12.0f, 0.56f, 1.0f, 0xff00ffff, },
	{ 640.0f,  0.0f, 0.57f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 70.0f, 125.0f, 0.57f, 1.0f, 0xff00ff00, },
	{ 710.0f, 2250.0f, 0.57f, 1.0f, 0xff00ffff, },
	{ 640.0f,  10.0f, 0.5f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.5f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.5f, 1.0f, 0xff00ffff, },
	{ 0.0f,  0.0f, 0.51f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.51f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.51f, 1.0f, 0xff00ffff, },
	{ 240.0f,  1.0f, 0.52f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.52f, 1.0f, 0xff00ff00, },
	{ 10.0f, 50.0f, 0.52f, 1.0f, 0xff00ffff, },
	{ 640.0f,  10.0f, 0.53f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1200.0f, 0.0f, 0.53f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.53f, 1.0f, 0xff00ffff, },
	{ 40.0f,  100.0f, 0.54f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 750.0f, 30.0f, 0.54f, 1.0f, 0xff00ff00, },
	{ 100.0f, 1050.0f, 0.54f, 1.0f, 0xff00ffff, },
	{ 27.0f,  27.0f, 0.55f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 50.0f, 1250.0f, 0.55f, 1.0f, 0xff00ff00, },
	{ 1000.0f, 2250.0f, 0.55f, 1.0f, 0xff00ffff, },
	{ 64.0f,  12.0f, 0.56f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 950.0f, 450.0f, 0.56f, 1.0f, 0xff00ff00, },
	{ 500.0f, 12.0f, 0.56f, 1.0f, 0xff00ffff, },
	{ 640.0f,  0.0f, 0.57f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 70.0f, 125.0f, 0.57f, 1.0f, 0xff00ff00, },
	{ 710.0f, 2250.0f, 0.57f, 1.0f, 0xff00ffff, },
	{ 640.0f,  10.0f, 0.5f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.5f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.5f, 1.0f, 0xff00ffff, },
	{ 0.0f,  0.0f, 0.51f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.51f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.51f, 1.0f, 0xff00ffff, },
	{ 240.0f,  1.0f, 0.52f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.52f, 1.0f, 0xff00ff00, },
	{ 10.0f, 50.0f, 0.52f, 1.0f, 0xff00ffff, },
	{ 640.0f,  10.0f, 0.53f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1200.0f, 0.0f, 0.53f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.53f, 1.0f, 0xff00ffff, },
	{ 40.0f,  100.0f, 0.54f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 750.0f, 30.0f, 0.54f, 1.0f, 0xff00ff00, },
	{ 100.0f, 1050.0f, 0.54f, 1.0f, 0xff00ffff, },
	{ 27.0f,  27.0f, 0.55f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 50.0f, 1250.0f, 0.55f, 1.0f, 0xff00ff00, },
	{ 1000.0f, 2250.0f, 0.55f, 1.0f, 0xff00ffff, },
	{ 64.0f,  12.0f, 0.56f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 950.0f, 450.0f, 0.56f, 1.0f, 0xff00ff00, },
	{ 500.0f, 12.0f, 0.56f, 1.0f, 0xff00ffff, },
	{ 640.0f,  0.0f, 0.57f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 70.0f, 125.0f, 0.57f, 1.0f, 0xff00ff00, },
	{ 710.0f, 2250.0f, 0.57f, 1.0f, 0xff00ffff, },
	{ 640.0f,  10.0f, 0.5f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.5f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.5f, 1.0f, 0xff00ffff, },
	{ 0.0f,  0.0f, 0.51f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.51f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.51f, 1.0f, 0xff00ffff, },
	{ 240.0f,  1.0f, 0.52f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.52f, 1.0f, 0xff00ff00, },
	{ 10.0f, 50.0f, 0.52f, 1.0f, 0xff00ffff, },
	{ 640.0f,  10.0f, 0.53f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1200.0f, 0.0f, 0.53f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.53f, 1.0f, 0xff00ffff, },
	{ 40.0f,  100.0f, 0.54f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 750.0f, 30.0f, 0.54f, 1.0f, 0xff00ff00, },
	{ 100.0f, 1050.0f, 0.54f, 1.0f, 0xff00ffff, },
	{ 27.0f,  27.0f, 0.55f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 50.0f, 1250.0f, 0.55f, 1.0f, 0xff00ff00, },
	{ 1000.0f, 2250.0f, 0.55f, 1.0f, 0xff00ffff, },
	{ 64.0f,  12.0f, 0.56f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 950.0f, 450.0f, 0.56f, 1.0f, 0xff00ff00, },
	{ 500.0f, 12.0f, 0.56f, 1.0f, 0xff00ffff, },
	{ 640.0f,  0.0f, 0.57f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 70.0f, 125.0f, 0.57f, 1.0f, 0xff00ff00, },
	{ 710.0f, 2250.0f, 0.57f, 1.0f, 0xff00ffff, },
	{ 640.0f,  10.0f, 0.5f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.5f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.5f, 1.0f, 0xff00ffff, },
	{ 0.0f,  0.0f, 0.51f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.51f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.51f, 1.0f, 0xff00ffff, },
	{ 240.0f,  1.0f, 0.52f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.52f, 1.0f, 0xff00ff00, },
	{ 10.0f, 50.0f, 0.52f, 1.0f, 0xff00ffff, },
	{ 640.0f,  10.0f, 0.53f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1200.0f, 0.0f, 0.53f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.53f, 1.0f, 0xff00ffff, },
	{ 40.0f,  100.0f, 0.54f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 750.0f, 30.0f, 0.54f, 1.0f, 0xff00ff00, },
	{ 100.0f, 1050.0f, 0.54f, 1.0f, 0xff00ffff, },
	{ 27.0f,  27.0f, 0.55f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 50.0f, 1250.0f, 0.55f, 1.0f, 0xff00ff00, },
	{ 1000.0f, 2250.0f, 0.55f, 1.0f, 0xff00ffff, },
	{ 64.0f,  12.0f, 0.56f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 950.0f, 450.0f, 0.56f, 1.0f, 0xff00ff00, },
	{ 500.0f, 12.0f, 0.56f, 1.0f, 0xff00ffff, },
	{ 640.0f,  0.0f, 0.57f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 70.0f, 125.0f, 0.57f, 1.0f, 0xff00ff00, },
	{ 710.0f, 2250.0f, 0.57f, 1.0f, 0xff00ffff, },
	{ 640.0f,  10.0f, 0.5f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.5f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.5f, 1.0f, 0xff00ffff, },
	{ 0.0f,  0.0f, 0.51f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.51f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.51f, 1.0f, 0xff00ffff, },
	{ 240.0f,  1.0f, 0.52f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.52f, 1.0f, 0xff00ff00, },
	{ 10.0f, 50.0f, 0.52f, 1.0f, 0xff00ffff, },
	{ 640.0f,  10.0f, 0.53f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1200.0f, 0.0f, 0.53f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.53f, 1.0f, 0xff00ffff, },
	{ 40.0f,  100.0f, 0.54f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 750.0f, 30.0f, 0.54f, 1.0f, 0xff00ff00, },
	{ 100.0f, 1050.0f, 0.54f, 1.0f, 0xff00ffff, },
	{ 27.0f,  27.0f, 0.55f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 50.0f, 1250.0f, 0.55f, 1.0f, 0xff00ff00, },
	{ 1000.0f, 2250.0f, 0.55f, 1.0f, 0xff00ffff, },
	{ 64.0f,  12.0f, 0.56f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 950.0f, 450.0f, 0.56f, 1.0f, 0xff00ff00, },
	{ 500.0f, 12.0f, 0.56f, 1.0f, 0xff00ffff, },
	{ 640.0f,  0.0f, 0.57f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 70.0f, 125.0f, 0.57f, 1.0f, 0xff00ff00, },
	{ 710.0f, 2250.0f, 0.57f, 1.0f, 0xff00ffff, },
	{ 640.0f,  10.0f, 0.5f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.5f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.5f, 1.0f, 0xff00ffff, },
	{ 0.0f,  0.0f, 0.51f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.51f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.51f, 1.0f, 0xff00ffff, },
	{ 240.0f,  1.0f, 0.52f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.52f, 1.0f, 0xff00ff00, },
	{ 10.0f, 50.0f, 0.52f, 1.0f, 0xff00ffff, },
	{ 640.0f,  10.0f, 0.53f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1200.0f, 0.0f, 0.53f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.53f, 1.0f, 0xff00ffff, },
	{ 40.0f,  100.0f, 0.54f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 750.0f, 30.0f, 0.54f, 1.0f, 0xff00ff00, },
	{ 100.0f, 1050.0f, 0.54f, 1.0f, 0xff00ffff, },
	{ 27.0f,  27.0f, 0.55f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 50.0f, 1250.0f, 0.55f, 1.0f, 0xff00ff00, },
	{ 1000.0f, 2250.0f, 0.55f, 1.0f, 0xff00ffff, },
	{ 64.0f,  12.0f, 0.56f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 950.0f, 450.0f, 0.56f, 1.0f, 0xff00ff00, },
	{ 500.0f, 12.0f, 0.56f, 1.0f, 0xff00ffff, },
	{ 640.0f,  0.0f, 0.57f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 70.0f, 125.0f, 0.57f, 1.0f, 0xff00ff00, },
	{ 710.0f, 2250.0f, 0.57f, 1.0f, 0xff00ffff, },
	{ 640.0f,  10.0f, 0.5f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.5f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.5f, 1.0f, 0xff00ffff, },
	{ 0.0f,  0.0f, 0.51f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.51f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.51f, 1.0f, 0xff00ffff, },
	{ 240.0f,  1.0f, 0.52f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.52f, 1.0f, 0xff00ff00, },
	{ 10.0f, 50.0f, 0.52f, 1.0f, 0xff00ffff, },
	{ 640.0f,  10.0f, 0.53f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1200.0f, 0.0f, 0.53f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.53f, 1.0f, 0xff00ffff, },
	{ 40.0f,  100.0f, 0.54f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 750.0f, 30.0f, 0.54f, 1.0f, 0xff00ff00, },
	{ 100.0f, 1050.0f, 0.54f, 1.0f, 0xff00ffff, },
	{ 27.0f,  27.0f, 0.55f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 50.0f, 1250.0f, 0.55f, 1.0f, 0xff00ff00, },
	{ 1000.0f, 2250.0f, 0.55f, 1.0f, 0xff00ffff, },
	{ 64.0f,  12.0f, 0.56f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 950.0f, 450.0f, 0.56f, 1.0f, 0xff00ff00, },
	{ 500.0f, 12.0f, 0.56f, 1.0f, 0xff00ffff, },
	{ 640.0f,  0.0f, 0.57f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 70.0f, 125.0f, 0.57f, 1.0f, 0xff00ff00, },
	{ 710.0f, 2250.0f, 0.57f, 1.0f, 0xff00ffff, },
	{ 640.0f,  10.0f, 0.5f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.5f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.5f, 1.0f, 0xff00ffff, },
	{ 0.0f,  0.0f, 0.51f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.51f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.51f, 1.0f, 0xff00ffff, },
	{ 240.0f,  1.0f, 0.52f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.52f, 1.0f, 0xff00ff00, },
	{ 10.0f, 50.0f, 0.52f, 1.0f, 0xff00ffff, },
	{ 640.0f,  10.0f, 0.53f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1200.0f, 0.0f, 0.53f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.53f, 1.0f, 0xff00ffff, },
	{ 40.0f,  100.0f, 0.54f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 750.0f, 30.0f, 0.54f, 1.0f, 0xff00ff00, },
	{ 100.0f, 1050.0f, 0.54f, 1.0f, 0xff00ffff, },
	{ 27.0f,  27.0f, 0.55f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 50.0f, 1250.0f, 0.55f, 1.0f, 0xff00ff00, },
	{ 1000.0f, 2250.0f, 0.55f, 1.0f, 0xff00ffff, },
	{ 64.0f,  12.0f, 0.56f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 950.0f, 450.0f, 0.56f, 1.0f, 0xff00ff00, },
	{ 500.0f, 12.0f, 0.56f, 1.0f, 0xff00ffff, },
	{ 640.0f,  0.0f, 0.57f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 70.0f, 125.0f, 0.57f, 1.0f, 0xff00ff00, },
	{ 710.0f, 2250.0f, 0.57f, 1.0f, 0xff00ffff, },
	{ 640.0f,  10.0f, 0.5f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.5f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.5f, 1.0f, 0xff00ffff, },
	{ 0.0f,  0.0f, 0.51f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.51f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.51f, 1.0f, 0xff00ffff, },
	{ 240.0f,  1.0f, 0.52f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.52f, 1.0f, 0xff00ff00, },
	{ 10.0f, 50.0f, 0.52f, 1.0f, 0xff00ffff, },
	{ 640.0f,  10.0f, 0.53f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1200.0f, 0.0f, 0.53f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.53f, 1.0f, 0xff00ffff, },
	{ 40.0f,  100.0f, 0.54f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 750.0f, 30.0f, 0.54f, 1.0f, 0xff00ff00, },
	{ 100.0f, 1050.0f, 0.54f, 1.0f, 0xff00ffff, },
	{ 27.0f,  27.0f, 0.55f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 50.0f, 1250.0f, 0.55f, 1.0f, 0xff00ff00, },
	{ 1000.0f, 2250.0f, 0.55f, 1.0f, 0xff00ffff, },
	{ 64.0f,  12.0f, 0.56f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 950.0f, 450.0f, 0.56f, 1.0f, 0xff00ff00, },
	{ 500.0f, 12.0f, 0.56f, 1.0f, 0xff00ffff, },
	{ 640.0f,  0.0f, 0.57f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 70.0f, 125.0f, 0.57f, 1.0f, 0xff00ff00, },
	{ 710.0f, 2250.0f, 0.57f, 1.0f, 0xff00ffff, },
	{ 640.0f,  10.0f, 0.5f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.5f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.5f, 1.0f, 0xff00ffff, },
	{ 0.0f,  0.0f, 0.51f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.51f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.51f, 1.0f, 0xff00ffff, },
	{ 240.0f,  1.0f, 0.52f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.52f, 1.0f, 0xff00ff00, },
	{ 10.0f, 50.0f, 0.52f, 1.0f, 0xff00ffff, },
	{ 640.0f,  10.0f, 0.53f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1200.0f, 0.0f, 0.53f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.53f, 1.0f, 0xff00ffff, },
	{ 40.0f,  100.0f, 0.54f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 750.0f, 30.0f, 0.54f, 1.0f, 0xff00ff00, },
	{ 100.0f, 1050.0f, 0.54f, 1.0f, 0xff00ffff, },
	{ 27.0f,  27.0f, 0.55f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 50.0f, 1250.0f, 0.55f, 1.0f, 0xff00ff00, },
	{ 1000.0f, 2250.0f, 0.55f, 1.0f, 0xff00ffff, },
	{ 64.0f,  12.0f, 0.56f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 950.0f, 450.0f, 0.56f, 1.0f, 0xff00ff00, },
	{ 500.0f, 12.0f, 0.56f, 1.0f, 0xff00ffff, },
	{ 640.0f,  0.0f, 0.57f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 70.0f, 125.0f, 0.57f, 1.0f, 0xff00ff00, },
	{ 710.0f, 2250.0f, 0.57f, 1.0f, 0xff00ffff, },
	{ 640.0f,  10.0f, 0.5f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.5f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.5f, 1.0f, 0xff00ffff, },
	{ 0.0f,  0.0f, 0.51f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.51f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.51f, 1.0f, 0xff00ffff, },
	{ 240.0f,  1.0f, 0.52f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.52f, 1.0f, 0xff00ff00, },
	{ 10.0f, 50.0f, 0.52f, 1.0f, 0xff00ffff, },
	{ 640.0f,  10.0f, 0.53f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1200.0f, 0.0f, 0.53f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.53f, 1.0f, 0xff00ffff, },
	{ 40.0f,  100.0f, 0.54f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 750.0f, 30.0f, 0.54f, 1.0f, 0xff00ff00, },
	{ 100.0f, 1050.0f, 0.54f, 1.0f, 0xff00ffff, },
	{ 27.0f,  27.0f, 0.55f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 50.0f, 1250.0f, 0.55f, 1.0f, 0xff00ff00, },
	{ 1000.0f, 2250.0f, 0.55f, 1.0f, 0xff00ffff, },
	{ 64.0f,  12.0f, 0.56f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 950.0f, 450.0f, 0.56f, 1.0f, 0xff00ff00, },
	{ 500.0f, 12.0f, 0.56f, 1.0f, 0xff00ffff, },
	{ 640.0f,  0.0f, 0.57f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 70.0f, 125.0f, 0.57f, 1.0f, 0xff00ff00, },
	{ 710.0f, 2250.0f, 0.57f, 1.0f, 0xff00ffff, },
	{ 640.0f,  10.0f, 0.5f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.5f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.5f, 1.0f, 0xff00ffff, },
	{ 0.0f,  0.0f, 0.51f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.51f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.51f, 1.0f, 0xff00ffff, },
	{ 240.0f,  1.0f, 0.52f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.52f, 1.0f, 0xff00ff00, },
	{ 10.0f, 50.0f, 0.52f, 1.0f, 0xff00ffff, },
	{ 640.0f,  10.0f, 0.53f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1200.0f, 0.0f, 0.53f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.53f, 1.0f, 0xff00ffff, },
	{ 40.0f,  100.0f, 0.54f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 750.0f, 30.0f, 0.54f, 1.0f, 0xff00ff00, },
	{ 100.0f, 1050.0f, 0.54f, 1.0f, 0xff00ffff, },
	{ 27.0f,  27.0f, 0.55f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 50.0f, 1250.0f, 0.55f, 1.0f, 0xff00ff00, },
	{ 1000.0f, 2250.0f, 0.55f, 1.0f, 0xff00ffff, },
	{ 64.0f,  12.0f, 0.56f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 950.0f, 450.0f, 0.56f, 1.0f, 0xff00ff00, },
	{ 500.0f, 12.0f, 0.56f, 1.0f, 0xff00ffff, },
	{ 640.0f,  0.0f, 0.57f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 70.0f, 125.0f, 0.57f, 1.0f, 0xff00ff00, },
	{ 710.0f, 2250.0f, 0.57f, 1.0f, 0xff00ffff, },
	{ 640.0f,  10.0f, 0.5f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.5f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.5f, 1.0f, 0xff00ffff, },
	{ 0.0f,  0.0f, 0.51f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.51f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.51f, 1.0f, 0xff00ffff, },
	{ 240.0f,  1.0f, 0.52f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.52f, 1.0f, 0xff00ff00, },
	{ 10.0f, 50.0f, 0.52f, 1.0f, 0xff00ffff, },
	{ 640.0f,  10.0f, 0.53f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1200.0f, 0.0f, 0.53f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.53f, 1.0f, 0xff00ffff, },
	{ 40.0f,  100.0f, 0.54f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 750.0f, 30.0f, 0.54f, 1.0f, 0xff00ff00, },
	{ 100.0f, 1050.0f, 0.54f, 1.0f, 0xff00ffff, },
	{ 27.0f,  27.0f, 0.55f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 50.0f, 1250.0f, 0.55f, 1.0f, 0xff00ff00, },
	{ 1000.0f, 2250.0f, 0.55f, 1.0f, 0xff00ffff, },
	{ 64.0f,  12.0f, 0.56f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 950.0f, 450.0f, 0.56f, 1.0f, 0xff00ff00, },
	{ 500.0f, 12.0f, 0.56f, 1.0f, 0xff00ffff, },
	{ 640.0f,  0.0f, 0.57f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 70.0f, 125.0f, 0.57f, 1.0f, 0xff00ff00, },
	{ 710.0f, 2250.0f, 0.57f, 1.0f, 0xff00ffff, },
	{ 640.0f,  10.0f, 0.5f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.5f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.5f, 1.0f, 0xff00ffff, },
	{ 0.0f,  0.0f, 0.51f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.51f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.51f, 1.0f, 0xff00ffff, },
	{ 240.0f,  1.0f, 0.52f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.52f, 1.0f, 0xff00ff00, },
	{ 10.0f, 50.0f, 0.52f, 1.0f, 0xff00ffff, },
	{ 640.0f,  10.0f, 0.53f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1200.0f, 0.0f, 0.53f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.53f, 1.0f, 0xff00ffff, },
	{ 40.0f,  100.0f, 0.54f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 750.0f, 30.0f, 0.54f, 1.0f, 0xff00ff00, },
	{ 100.0f, 1050.0f, 0.54f, 1.0f, 0xff00ffff, },
	{ 27.0f,  27.0f, 0.55f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 50.0f, 1250.0f, 0.55f, 1.0f, 0xff00ff00, },
	{ 1000.0f, 2250.0f, 0.55f, 1.0f, 0xff00ffff, },
	{ 64.0f,  12.0f, 0.56f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 950.0f, 450.0f, 0.56f, 1.0f, 0xff00ff00, },
	{ 500.0f, 12.0f, 0.56f, 1.0f, 0xff00ffff, },
	{ 640.0f,  0.0f, 0.57f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 70.0f, 125.0f, 0.57f, 1.0f, 0xff00ff00, },
	{ 710.0f, 2250.0f, 0.57f, 1.0f, 0xff00ffff, },
	{ 640.0f,  10.0f, 0.5f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.5f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.5f, 1.0f, 0xff00ffff, },
	{ 0.0f,  0.0f, 0.51f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.51f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.51f, 1.0f, 0xff00ffff, },
	{ 240.0f,  1.0f, 0.52f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.52f, 1.0f, 0xff00ff00, },
	{ 10.0f, 50.0f, 0.52f, 1.0f, 0xff00ffff, },
	{ 640.0f,  10.0f, 0.53f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1200.0f, 0.0f, 0.53f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.53f, 1.0f, 0xff00ffff, },
	{ 40.0f,  100.0f, 0.54f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 750.0f, 30.0f, 0.54f, 1.0f, 0xff00ff00, },
	{ 100.0f, 1050.0f, 0.54f, 1.0f, 0xff00ffff, },
	{ 27.0f,  27.0f, 0.55f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 50.0f, 1250.0f, 0.55f, 1.0f, 0xff00ff00, },
	{ 1000.0f, 2250.0f, 0.55f, 1.0f, 0xff00ffff, },
	{ 64.0f,  12.0f, 0.56f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 950.0f, 450.0f, 0.56f, 1.0f, 0xff00ff00, },
	{ 500.0f, 12.0f, 0.56f, 1.0f, 0xff00ffff, },
	{ 640.0f,  0.0f, 0.57f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 70.0f, 125.0f, 0.57f, 1.0f, 0xff00ff00, },
	{ 710.0f, 2250.0f, 0.57f, 1.0f, 0xff00ffff, },
	{ 640.0f,  10.0f, 0.5f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.5f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.5f, 1.0f, 0xff00ffff, },
	{ 0.0f,  0.0f, 0.51f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.51f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.51f, 1.0f, 0xff00ffff, },
	{ 240.0f,  1.0f, 0.52f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.52f, 1.0f, 0xff00ff00, },
	{ 10.0f, 50.0f, 0.52f, 1.0f, 0xff00ffff, },
	{ 640.0f,  10.0f, 0.53f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1200.0f, 0.0f, 0.53f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.53f, 1.0f, 0xff00ffff, },
	{ 40.0f,  100.0f, 0.54f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 750.0f, 30.0f, 0.54f, 1.0f, 0xff00ff00, },
	{ 100.0f, 1050.0f, 0.54f, 1.0f, 0xff00ffff, },
	{ 27.0f,  27.0f, 0.55f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 50.0f, 1250.0f, 0.55f, 1.0f, 0xff00ff00, },
	{ 1000.0f, 2250.0f, 0.55f, 1.0f, 0xff00ffff, },
	{ 64.0f,  12.0f, 0.56f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 950.0f, 450.0f, 0.56f, 1.0f, 0xff00ff00, },
	{ 500.0f, 12.0f, 0.56f, 1.0f, 0xff00ffff, },
	{ 640.0f,  0.0f, 0.57f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 70.0f, 125.0f, 0.57f, 1.0f, 0xff00ff00, },
	{ 710.0f, 2250.0f, 0.57f, 1.0f, 0xff00ffff, },
	{ 640.0f,  10.0f, 0.5f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.5f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.5f, 1.0f, 0xff00ffff, },
	{ 0.0f,  0.0f, 0.51f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.51f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.51f, 1.0f, 0xff00ffff, },
	{ 240.0f,  1.0f, 0.52f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.52f, 1.0f, 0xff00ff00, },
	{ 10.0f, 50.0f, 0.52f, 1.0f, 0xff00ffff, },
	{ 640.0f,  10.0f, 0.53f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1200.0f, 0.0f, 0.53f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.53f, 1.0f, 0xff00ffff, },
	{ 40.0f,  100.0f, 0.54f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 750.0f, 30.0f, 0.54f, 1.0f, 0xff00ff00, },
	{ 100.0f, 1050.0f, 0.54f, 1.0f, 0xff00ffff, },
	{ 27.0f,  27.0f, 0.55f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 50.0f, 1250.0f, 0.55f, 1.0f, 0xff00ff00, },
	{ 1000.0f, 2250.0f, 0.55f, 1.0f, 0xff00ffff, },
	{ 64.0f,  12.0f, 0.56f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 950.0f, 450.0f, 0.56f, 1.0f, 0xff00ff00, },
	{ 500.0f, 12.0f, 0.56f, 1.0f, 0xff00ffff, },
	{ 640.0f,  0.0f, 0.57f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 70.0f, 125.0f, 0.57f, 1.0f, 0xff00ff00, },
	{ 710.0f, 2250.0f, 0.57f, 1.0f, 0xff00ffff, },
	{ 640.0f,  10.0f, 0.5f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.5f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.5f, 1.0f, 0xff00ffff, },
	{ 0.0f,  0.0f, 0.51f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.51f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.51f, 1.0f, 0xff00ffff, },
	{ 240.0f,  1.0f, 0.52f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.52f, 1.0f, 0xff00ff00, },
	{ 10.0f, 50.0f, 0.52f, 1.0f, 0xff00ffff, },
	{ 640.0f,  10.0f, 0.53f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1200.0f, 0.0f, 0.53f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.53f, 1.0f, 0xff00ffff, },
	{ 40.0f,  100.0f, 0.54f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 750.0f, 30.0f, 0.54f, 1.0f, 0xff00ff00, },
	{ 100.0f, 1050.0f, 0.54f, 1.0f, 0xff00ffff, },
	{ 27.0f,  27.0f, 0.55f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 50.0f, 1250.0f, 0.55f, 1.0f, 0xff00ff00, },
	{ 1000.0f, 2250.0f, 0.55f, 1.0f, 0xff00ffff, },
	{ 64.0f,  12.0f, 0.56f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 950.0f, 450.0f, 0.56f, 1.0f, 0xff00ff00, },
	{ 500.0f, 12.0f, 0.56f, 1.0f, 0xff00ffff, },
	{ 640.0f,  0.0f, 0.57f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 70.0f, 125.0f, 0.57f, 1.0f, 0xff00ff00, },
	{ 710.0f, 2250.0f, 0.57f, 1.0f, 0xff00ffff, },
	{ 640.0f,  10.0f, 0.5f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.5f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.5f, 1.0f, 0xff00ffff, },
	{ 0.0f,  0.0f, 0.51f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.51f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.51f, 1.0f, 0xff00ffff, },
	{ 240.0f,  1.0f, 0.52f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.52f, 1.0f, 0xff00ff00, },
	{ 10.0f, 50.0f, 0.52f, 1.0f, 0xff00ffff, },
	{ 640.0f,  10.0f, 0.53f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1200.0f, 0.0f, 0.53f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.53f, 1.0f, 0xff00ffff, },
	{ 40.0f,  100.0f, 0.54f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 750.0f, 30.0f, 0.54f, 1.0f, 0xff00ff00, },
	{ 100.0f, 1050.0f, 0.54f, 1.0f, 0xff00ffff, },
	{ 27.0f,  27.0f, 0.55f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 50.0f, 1250.0f, 0.55f, 1.0f, 0xff00ff00, },
	{ 1000.0f, 2250.0f, 0.55f, 1.0f, 0xff00ffff, },
	{ 64.0f,  12.0f, 0.56f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 950.0f, 450.0f, 0.56f, 1.0f, 0xff00ff00, },
	{ 500.0f, 12.0f, 0.56f, 1.0f, 0xff00ffff, },
	{ 640.0f,  0.0f, 0.57f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 70.0f, 125.0f, 0.57f, 1.0f, 0xff00ff00, },
	{ 710.0f, 2250.0f, 0.57f, 1.0f, 0xff00ffff, },
	{ 640.0f,  10.0f, 0.5f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.5f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.5f, 1.0f, 0xff00ffff, },
	{ 0.0f,  0.0f, 0.51f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.51f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.51f, 1.0f, 0xff00ffff, },
	{ 240.0f,  1.0f, 0.52f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.52f, 1.0f, 0xff00ff00, },
	{ 10.0f, 50.0f, 0.52f, 1.0f, 0xff00ffff, },
	{ 640.0f,  10.0f, 0.53f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1200.0f, 0.0f, 0.53f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.53f, 1.0f, 0xff00ffff, },
	{ 40.0f,  100.0f, 0.54f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 750.0f, 30.0f, 0.54f, 1.0f, 0xff00ff00, },
	{ 100.0f, 1050.0f, 0.54f, 1.0f, 0xff00ffff, },
	{ 27.0f,  27.0f, 0.55f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 50.0f, 1250.0f, 0.55f, 1.0f, 0xff00ff00, },
	{ 1000.0f, 2250.0f, 0.55f, 1.0f, 0xff00ffff, },
	{ 64.0f,  12.0f, 0.56f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 950.0f, 450.0f, 0.56f, 1.0f, 0xff00ff00, },
	{ 500.0f, 12.0f, 0.56f, 1.0f, 0xff00ffff, },
	{ 640.0f,  0.0f, 0.57f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 70.0f, 125.0f, 0.57f, 1.0f, 0xff00ff00, },
	{ 710.0f, 2250.0f, 0.57f, 1.0f, 0xff00ffff, },
	{ 640.0f,  10.0f, 0.5f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.5f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.5f, 1.0f, 0xff00ffff, },
	{ 0.0f,  0.0f, 0.51f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.51f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.51f, 1.0f, 0xff00ffff, },
	{ 240.0f,  1.0f, 0.52f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.52f, 1.0f, 0xff00ff00, },
	{ 10.0f, 50.0f, 0.52f, 1.0f, 0xff00ffff, },
	{ 640.0f,  10.0f, 0.53f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1200.0f, 0.0f, 0.53f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.53f, 1.0f, 0xff00ffff, },
	{ 40.0f,  100.0f, 0.54f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 750.0f, 30.0f, 0.54f, 1.0f, 0xff00ff00, },
	{ 100.0f, 1050.0f, 0.54f, 1.0f, 0xff00ffff, },
	{ 27.0f,  27.0f, 0.55f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 50.0f, 1250.0f, 0.55f, 1.0f, 0xff00ff00, },
	{ 1000.0f, 2250.0f, 0.55f, 1.0f, 0xff00ffff, },
	{ 64.0f,  12.0f, 0.56f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 950.0f, 450.0f, 0.56f, 1.0f, 0xff00ff00, },
	{ 500.0f, 12.0f, 0.56f, 1.0f, 0xff00ffff, },
	{ 640.0f,  0.0f, 0.57f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 70.0f, 125.0f, 0.57f, 1.0f, 0xff00ff00, },
	{ 710.0f, 2250.0f, 0.57f, 1.0f, 0xff00ffff, },
	{ 640.0f,  10.0f, 0.5f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.5f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.5f, 1.0f, 0xff00ffff, },
	{ 0.0f,  0.0f, 0.51f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.51f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.51f, 1.0f, 0xff00ffff, },
	{ 240.0f,  1.0f, 0.52f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.52f, 1.0f, 0xff00ff00, },
	{ 10.0f, 50.0f, 0.52f, 1.0f, 0xff00ffff, },
	{ 640.0f,  10.0f, 0.53f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1200.0f, 0.0f, 0.53f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.53f, 1.0f, 0xff00ffff, },
	{ 40.0f,  100.0f, 0.54f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 750.0f, 30.0f, 0.54f, 1.0f, 0xff00ff00, },
	{ 100.0f, 1050.0f, 0.54f, 1.0f, 0xff00ffff, },
	{ 27.0f,  27.0f, 0.55f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 50.0f, 1250.0f, 0.55f, 1.0f, 0xff00ff00, },
	{ 1000.0f, 2250.0f, 0.55f, 1.0f, 0xff00ffff, },
	{ 64.0f,  12.0f, 0.56f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 950.0f, 450.0f, 0.56f, 1.0f, 0xff00ff00, },
	{ 500.0f, 12.0f, 0.56f, 1.0f, 0xff00ffff, },
	{ 640.0f,  0.0f, 0.57f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 70.0f, 125.0f, 0.57f, 1.0f, 0xff00ff00, },
	{ 710.0f, 2250.0f, 0.57f, 1.0f, 0xff00ffff, },
	{ 640.0f,  10.0f, 0.5f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.5f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.5f, 1.0f, 0xff00ffff, },
	{ 0.0f,  0.0f, 0.51f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.51f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.51f, 1.0f, 0xff00ffff, },
	{ 240.0f,  1.0f, 0.52f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.52f, 1.0f, 0xff00ff00, },
	{ 10.0f, 50.0f, 0.52f, 1.0f, 0xff00ffff, },
	{ 640.0f,  10.0f, 0.53f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1200.0f, 0.0f, 0.53f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.53f, 1.0f, 0xff00ffff, },
	{ 40.0f,  100.0f, 0.54f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 750.0f, 30.0f, 0.54f, 1.0f, 0xff00ff00, },
	{ 100.0f, 1050.0f, 0.54f, 1.0f, 0xff00ffff, },
	{ 27.0f,  27.0f, 0.55f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 50.0f, 1250.0f, 0.55f, 1.0f, 0xff00ff00, },
	{ 1000.0f, 2250.0f, 0.55f, 1.0f, 0xff00ffff, },
	{ 64.0f,  12.0f, 0.56f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 950.0f, 450.0f, 0.56f, 1.0f, 0xff00ff00, },
	{ 500.0f, 12.0f, 0.56f, 1.0f, 0xff00ffff, },
	{ 640.0f,  0.0f, 0.57f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 70.0f, 125.0f, 0.57f, 1.0f, 0xff00ff00, },
	{ 710.0f, 2250.0f, 0.57f, 1.0f, 0xff00ffff, },
	{ 640.0f,  10.0f, 0.5f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.5f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.5f, 1.0f, 0xff00ffff, },
	{ 0.0f,  0.0f, 0.51f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.51f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.51f, 1.0f, 0xff00ffff, },
	{ 240.0f,  1.0f, 0.52f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.52f, 1.0f, 0xff00ff00, },
	{ 10.0f, 50.0f, 0.52f, 1.0f, 0xff00ffff, },
	{ 640.0f,  10.0f, 0.53f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1200.0f, 0.0f, 0.53f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.53f, 1.0f, 0xff00ffff, },
	{ 40.0f,  100.0f, 0.54f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 750.0f, 30.0f, 0.54f, 1.0f, 0xff00ff00, },
	{ 100.0f, 1050.0f, 0.54f, 1.0f, 0xff00ffff, },
	{ 27.0f,  27.0f, 0.55f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 50.0f, 1250.0f, 0.55f, 1.0f, 0xff00ff00, },
	{ 1000.0f, 2250.0f, 0.55f, 1.0f, 0xff00ffff, },
	{ 64.0f,  12.0f, 0.56f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 950.0f, 450.0f, 0.56f, 1.0f, 0xff00ff00, },
	{ 500.0f, 12.0f, 0.56f, 1.0f, 0xff00ffff, },
	{ 640.0f,  0.0f, 0.57f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 70.0f, 125.0f, 0.57f, 1.0f, 0xff00ff00, },
	{ 710.0f, 2250.0f, 0.57f, 1.0f, 0xff00ffff, },
	{ 640.0f,  10.0f, 0.5f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.5f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.5f, 1.0f, 0xff00ffff, },
	{ 0.0f,  0.0f, 0.51f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.51f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.51f, 1.0f, 0xff00ffff, },
	{ 240.0f,  1.0f, 0.52f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.52f, 1.0f, 0xff00ff00, },
	{ 10.0f, 50.0f, 0.52f, 1.0f, 0xff00ffff, },
	{ 640.0f,  10.0f, 0.53f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1200.0f, 0.0f, 0.53f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.53f, 1.0f, 0xff00ffff, },
	{ 40.0f,  100.0f, 0.54f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 750.0f, 30.0f, 0.54f, 1.0f, 0xff00ff00, },
	{ 100.0f, 1050.0f, 0.54f, 1.0f, 0xff00ffff, },
	{ 27.0f,  27.0f, 0.55f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 50.0f, 1250.0f, 0.55f, 1.0f, 0xff00ff00, },
	{ 1000.0f, 2250.0f, 0.55f, 1.0f, 0xff00ffff, },
	{ 64.0f,  12.0f, 0.56f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 950.0f, 450.0f, 0.56f, 1.0f, 0xff00ff00, },
	{ 500.0f, 12.0f, 0.56f, 1.0f, 0xff00ffff, },
	{ 640.0f,  0.0f, 0.57f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 70.0f, 125.0f, 0.57f, 1.0f, 0xff00ff00, },
	{ 710.0f, 2250.0f, 0.57f, 1.0f, 0xff00ffff, },
	{ 40.0f,  100.0f, 0.54f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 750.0f, 30.0f, 0.54f, 1.0f, 0xff00ff00, },
	{ 100.0f, 1050.0f, 0.54f, 1.0f, 0xff00ffff, },
	{ 27.0f,  27.0f, 0.55f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 50.0f, 1250.0f, 0.55f, 1.0f, 0xff00ff00, },
	{ 1000.0f, 2250.0f, 0.55f, 1.0f, 0xff00ffff, },
	{ 64.0f,  12.0f, 0.56f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 950.0f, 450.0f, 0.56f, 1.0f, 0xff00ff00, },
	{ 500.0f, 12.0f, 0.56f, 1.0f, 0xff00ffff, },
	{ 640.0f,  0.0f, 0.57f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 70.0f, 125.0f, 0.57f, 1.0f, 0xff00ff00, },
	{ 710.0f, 2250.0f, 0.57f, 1.0f, 0xff00ffff, },
	{ 640.0f,  10.0f, 0.5f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.5f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.5f, 1.0f, 0xff00ffff, },
	{ 0.0f,  0.0f, 0.51f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.51f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.51f, 1.0f, 0xff00ffff, },
	{ 240.0f,  1.0f, 0.52f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.52f, 1.0f, 0xff00ff00, },
	{ 10.0f, 50.0f, 0.52f, 1.0f, 0xff00ffff, },
	{ 640.0f,  10.0f, 0.53f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1200.0f, 0.0f, 0.53f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.53f, 1.0f, 0xff00ffff, },
	{ 40.0f,  100.0f, 0.54f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 750.0f, 30.0f, 0.54f, 1.0f, 0xff00ff00, },
	{ 100.0f, 1050.0f, 0.54f, 1.0f, 0xff00ffff, },
	{ 27.0f,  27.0f, 0.55f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 50.0f, 1250.0f, 0.55f, 1.0f, 0xff00ff00, },
	{ 1000.0f, 2250.0f, 0.55f, 1.0f, 0xff00ffff, },
	{ 64.0f,  12.0f, 0.56f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 950.0f, 450.0f, 0.56f, 1.0f, 0xff00ff00, },
	{ 500.0f, 12.0f, 0.56f, 1.0f, 0xff00ffff, },
	{ 640.0f,  0.0f, 0.57f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 70.0f, 125.0f, 0.57f, 1.0f, 0xff00ff00, },
	{ 710.0f, 2250.0f, 0.57f, 1.0f, 0xff00ffff, },
	{ 640.0f,  10.0f, 0.5f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.5f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.5f, 1.0f, 0xff00ffff, },
	{ 0.0f,  0.0f, 0.51f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.51f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.51f, 1.0f, 0xff00ffff, },
	{ 240.0f,  1.0f, 0.52f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.52f, 1.0f, 0xff00ff00, },
	{ 10.0f, 50.0f, 0.52f, 1.0f, 0xff00ffff, },
	{ 640.0f,  10.0f, 0.53f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1200.0f, 0.0f, 0.53f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.53f, 1.0f, 0xff00ffff, },
	{ 40.0f,  100.0f, 0.54f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 750.0f, 30.0f, 0.54f, 1.0f, 0xff00ff00, },
	{ 100.0f, 1050.0f, 0.54f, 1.0f, 0xff00ffff, },
	{ 27.0f,  27.0f, 0.55f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 50.0f, 1250.0f, 0.55f, 1.0f, 0xff00ff00, },
	{ 1000.0f, 2250.0f, 0.55f, 1.0f, 0xff00ffff, },
	{ 64.0f,  12.0f, 0.56f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 950.0f, 450.0f, 0.56f, 1.0f, 0xff00ff00, },
	{ 500.0f, 12.0f, 0.56f, 1.0f, 0xff00ffff, },
	{ 640.0f,  0.0f, 0.57f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 70.0f, 125.0f, 0.57f, 1.0f, 0xff00ff00, },
	{ 710.0f, 2250.0f, 0.57f, 1.0f, 0xff00ffff, },
	{ 640.0f,  10.0f, 0.5f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.5f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.5f, 1.0f, 0xff00ffff, },
	{ 0.0f,  0.0f, 0.51f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.51f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.51f, 1.0f, 0xff00ffff, },
	{ 240.0f,  1.0f, 0.52f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.52f, 1.0f, 0xff00ff00, },
	{ 10.0f, 50.0f, 0.52f, 1.0f, 0xff00ffff, },
	{ 640.0f,  10.0f, 0.53f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1200.0f, 0.0f, 0.53f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.53f, 1.0f, 0xff00ffff, },
	{ 40.0f,  100.0f, 0.54f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 750.0f, 30.0f, 0.54f, 1.0f, 0xff00ff00, },
	{ 100.0f, 1050.0f, 0.54f, 1.0f, 0xff00ffff, },
	{ 27.0f,  27.0f, 0.55f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 50.0f, 1250.0f, 0.55f, 1.0f, 0xff00ff00, },
	{ 1000.0f, 2250.0f, 0.55f, 1.0f, 0xff00ffff, },
	{ 64.0f,  12.0f, 0.56f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 950.0f, 450.0f, 0.56f, 1.0f, 0xff00ff00, },
	{ 500.0f, 12.0f, 0.56f, 1.0f, 0xff00ffff, },
	{ 640.0f,  0.0f, 0.57f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 70.0f, 125.0f, 0.57f, 1.0f, 0xff00ff00, },
	{ 710.0f, 2250.0f, 0.57f, 1.0f, 0xff00ffff, },
	{ 640.0f,  10.0f, 0.5f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.5f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.5f, 1.0f, 0xff00ffff, },
	{ 0.0f,  0.0f, 0.51f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.51f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.51f, 1.0f, 0xff00ffff, },
	{ 240.0f,  1.0f, 0.52f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.52f, 1.0f, 0xff00ff00, },
	{ 10.0f, 50.0f, 0.52f, 1.0f, 0xff00ffff, },
	{ 640.0f,  10.0f, 0.53f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1200.0f, 0.0f, 0.53f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.53f, 1.0f, 0xff00ffff, },
	{ 40.0f,  100.0f, 0.54f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 750.0f, 30.0f, 0.54f, 1.0f, 0xff00ff00, },
	{ 100.0f, 1050.0f, 0.54f, 1.0f, 0xff00ffff, },
	{ 27.0f,  27.0f, 0.55f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 50.0f, 1250.0f, 0.55f, 1.0f, 0xff00ff00, },
	{ 1000.0f, 2250.0f, 0.55f, 1.0f, 0xff00ffff, },
	{ 64.0f,  12.0f, 0.56f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 950.0f, 450.0f, 0.56f, 1.0f, 0xff00ff00, },
	{ 500.0f, 12.0f, 0.56f, 1.0f, 0xff00ffff, },
	{ 640.0f,  0.0f, 0.57f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 70.0f, 125.0f, 0.57f, 1.0f, 0xff00ff00, },
	{ 710.0f, 2250.0f, 0.57f, 1.0f, 0xff00ffff, },
	{ 640.0f,  10.0f, 0.5f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.5f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.5f, 1.0f, 0xff00ffff, },
	{ 0.0f,  0.0f, 0.51f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.51f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.51f, 1.0f, 0xff00ffff, },
	{ 240.0f,  1.0f, 0.52f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.52f, 1.0f, 0xff00ff00, },
	{ 10.0f, 50.0f, 0.52f, 1.0f, 0xff00ffff, },
	{ 640.0f,  10.0f, 0.53f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1200.0f, 0.0f, 0.53f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.53f, 1.0f, 0xff00ffff, },
	{ 40.0f,  100.0f, 0.54f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 750.0f, 30.0f, 0.54f, 1.0f, 0xff00ff00, },
	{ 100.0f, 1050.0f, 0.54f, 1.0f, 0xff00ffff, },
	{ 27.0f,  27.0f, 0.55f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 50.0f, 1250.0f, 0.55f, 1.0f, 0xff00ff00, },
	{ 1000.0f, 2250.0f, 0.55f, 1.0f, 0xff00ffff, },
	{ 64.0f,  12.0f, 0.56f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 950.0f, 450.0f, 0.56f, 1.0f, 0xff00ff00, },
	{ 500.0f, 12.0f, 0.56f, 1.0f, 0xff00ffff, },
	{ 640.0f,  0.0f, 0.57f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 70.0f, 125.0f, 0.57f, 1.0f, 0xff00ff00, },
	{ 710.0f, 2250.0f, 0.57f, 1.0f, 0xff00ffff, },
	{ 640.0f,  10.0f, 0.5f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.5f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.5f, 1.0f, 0xff00ffff, },
	{ 0.0f,  0.0f, 0.51f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.51f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.51f, 1.0f, 0xff00ffff, },
	{ 240.0f,  1.0f, 0.52f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.52f, 1.0f, 0xff00ff00, },
	{ 10.0f, 50.0f, 0.52f, 1.0f, 0xff00ffff, },
	{ 640.0f,  10.0f, 0.53f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1200.0f, 0.0f, 0.53f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.53f, 1.0f, 0xff00ffff, },
	{ 40.0f,  100.0f, 0.54f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 750.0f, 30.0f, 0.54f, 1.0f, 0xff00ff00, },
	{ 100.0f, 1050.0f, 0.54f, 1.0f, 0xff00ffff, },
	{ 27.0f,  27.0f, 0.55f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 50.0f, 1250.0f, 0.55f, 1.0f, 0xff00ff00, },
	{ 1000.0f, 2250.0f, 0.55f, 1.0f, 0xff00ffff, },
	{ 64.0f,  12.0f, 0.56f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 950.0f, 450.0f, 0.56f, 1.0f, 0xff00ff00, },
	{ 500.0f, 12.0f, 0.56f, 1.0f, 0xff00ffff, },
	{ 640.0f,  0.0f, 0.57f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 70.0f, 125.0f, 0.57f, 1.0f, 0xff00ff00, },
	{ 710.0f, 2250.0f, 0.57f, 1.0f, 0xff00ffff, },
	{ 640.0f,  10.0f, 0.5f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.5f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.5f, 1.0f, 0xff00ffff, },
	{ 0.0f,  0.0f, 0.51f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.51f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.51f, 1.0f, 0xff00ffff, },
	{ 240.0f,  1.0f, 0.52f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1850.0f, 1250.0f, 0.52f, 1.0f, 0xff00ff00, },
	{ 10.0f, 50.0f, 0.52f, 1.0f, 0xff00ffff, },
	{ 640.0f,  10.0f, 0.53f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 1200.0f, 0.0f, 0.53f, 1.0f, 0xff00ff00, },
	{ 10.0f, 2250.0f, 0.53f, 1.0f, 0xff00ffff, },
	{ 40.0f,  100.0f, 0.54f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 750.0f, 30.0f, 0.54f, 1.0f, 0xff00ff00, },
	{ 100.0f, 1050.0f, 0.54f, 1.0f, 0xff00ffff, },
	{ 27.0f,  27.0f, 0.55f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 50.0f, 1250.0f, 0.55f, 1.0f, 0xff00ff00, },
	{ 1000.0f, 2250.0f, 0.55f, 1.0f, 0xff00ffff, },
	{ 64.0f,  12.0f, 0.56f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 950.0f, 450.0f, 0.56f, 1.0f, 0xff00ff00, },
	{ 500.0f, 12.0f, 0.56f, 1.0f, 0xff00ffff, },
	{ 640.0f,  0.0f, 0.57f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{ 70.0f, 125.0f, 0.57f, 1.0f, 0xff00ff00, },
	{ 710.0f, 2250.0f, 0.57f, 1.0f, 0xff00ffff, }
};

CUSTOMVERTEX TriStrip[] = 
{
	{   0.0f, 15.0f, 0.5f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{   5.0f, 10.0f, 0.5f, 1.0f, 0xff00ff00, },
	{  10.0f, 15.0f, 0.5f, 1.0f, 0xff00ffff, },
	{  15.0f, 10.0f, 0.5f, 1.0f, 0x00000000, },
	{  20.0f, 15.0f, 0.5f, 1.0f, 0xf00ff00f, },
	{  25.0f, 10.0f, 0.5f, 1.0f, 0xffffffff, },
	{  30.0f, 15.0f, 0.5f, 1.0f, 0x000ff000, },
	{  35.0f, 10.0f, 0.5f, 1.0f, 0xff00ff00, },
	{  40.0f, 15.0f, 0.5f, 1.0f, 0x00ff00ff, },
	{  45.0f, 10.0f, 0.5f, 1.0f, 0xf0000000, },
	{  50.0f, 15.0f, 0.5f, 1.0f, 0x0f000000, },
	{  55.0f, 10.0f, 0.5f, 1.0f, 0x00f00000, },//10
	{  60.0f, 15.0f, 0.5f, 1.0f, 0x000f0000, },
	{  65.0f, 10.0f, 0.5f, 1.0f, 0x0000f000, },
	{  70.0f, 15.0f, 0.5f, 1.0f, 0x00000f00, },
	{  75.0f, 10.0f, 0.5f, 1.0f, 0x000000f0, },
	{  80.0f, 15.0f, 0.5f, 1.0f, 0x0000000f, },
	{  85.0f, 10.0f, 0.5f, 1.0f, 0xff000000, },
	{  90.0f, 15.0f, 0.5f, 1.0f, 0x0ff00000, },
	{  95.0f, 10.0f, 0.5f, 1.0f, 0x00ff0000, },
	{ 100.0f, 15.0f, 0.5f, 1.0f, 0x000ff000, },
	{ 105.0f, 10.0f, 0.5f, 1.0f, 0x0000ff00, },//20
	{ 110.0f, 15.0f, 0.5f, 1.0f, 0x00000ff0, },
	{ 115.0f, 10.0f, 0.5f, 1.0f, 0x000000ff, },
	{ 120.0f, 15.0f, 0.5f, 1.0f, 0xfff00000, },
	{ 125.0f, 10.0f, 0.5f, 1.0f, 0x0fff0000, },
	{ 130.0f, 15.0f, 0.5f, 1.0f, 0x00fff000, },
	{ 135.0f, 10.0f, 0.5f, 1.0f, 0x000fff00, },
	{ 140.0f, 15.0f, 0.5f, 1.0f, 0x0000fff0, },
	{ 145.0f, 15.0f, 0.5f, 1.0f, 0x00000fff, },
	{ 150.0f, 10.0f, 0.5f, 1.0f, 0xffff0000, },
	{ 155.0f, 15.0f, 0.5f, 1.0f, 0xff00ff00, },//30
	{ 160.0f, 15.0f, 0.5f, 1.0f, 0x0000ffff, },
	{ 165.0f, 10.0f, 0.5f, 1.0f, 0x00000000, },
	{ 170.0f, 15.0f, 0.5f, 1.0f, 0xffffffff, },
	{ 175.0f, 10.0f, 0.5f, 1.0f, 0x00ff00ff, },
	{ 180.0f, 15.0f, 0.5f, 1.0f, 0xff00ffff, },
	{ 185.0f, 10.0f, 0.5f, 1.0f, 0xffff00ff, },
	{ 190.0f, 15.0f, 0.5f, 1.0f, 0xf0000000, },
	{ 195.0f, 10.0f, 0.5f, 1.0f, 0x0f000000, },
	{ 200.0f, 15.0f, 0.5f, 1.0f, 0x00f00000, },
	{ 205.0f, 10.0f, 0.5f, 1.0f, 0x000f0000, },//40
	{ 210.0f, 15.0f, 0.5f, 1.0f, 0x0000f000, },
	{ 215.0f, 10.0f, 0.5f, 1.0f, 0x00000f00, },
	{ 220.0f, 10.0f, 0.5f, 1.0f, 0x000000f0, },
	{ 225.0f, 10.0f, 0.5f, 1.0f, 0x0000000f, },
	{ 230.0f, 15.0f, 0.5f, 1.0f, 0xff000000, },
	{ 235.0f, 10.0f, 0.5f, 1.0f, 0x0ff00000, },
	{ 240.0f, 15.0f, 0.5f, 1.0f, 0x00ff0000, },
	{ 245.0f, 10.0f, 0.5f, 1.0f, 0x000ff000, },
	{ 250.0f, 15.0f, 0.5f, 1.0f, 0x0000ff00, },
	{ 255.0f, 10.0f, 0.5f, 1.0f, 0x00000ff0, },//50
	{ 260.0f, 15.0f, 0.5f, 1.0f, 0x000000ff, },
	{ 265.0f, 10.0f, 0.5f, 1.0f, 0xfff00000, },
	{ 270.0f, 15.0f, 0.5f, 1.0f, 0x0fff0000, },
	{ 275.0f, 10.0f, 0.5f, 1.0f, 0x00fff000, },
	{ 280.0f, 15.0f, 0.5f, 1.0f, 0x000fff00, },
	{ 285.0f, 10.0f, 0.5f, 1.0f, 0x0000fff0, },
	{ 290.0f, 15.0f, 0.5f, 1.0f, 0x00000fff, },
	{ 295.0f, 10.0f, 0.5f, 1.0f, 0xffff0000, },
	{ 300.0f, 15.0f, 0.5f, 1.0f, 0x0000ffff, },
	{ 305.0f, 10.0f, 0.5f, 1.0f, 0xff00ff00, },//60
	{ 310.0f, 15.0f, 0.5f, 1.0f, 0x00ff00ff, },
	{ 315.0f, 10.0f, 0.5f, 1.0f, 0xffff00ff, },
	{ 320.0f, 15.0f, 0.5f, 1.0f, 0xff00ffff, },
	{ 325.0f, 10.0f, 0.5f, 1.0f, 0x00000000, },
	{ 330.0f, 15.0f, 0.5f, 1.0f, 0xffffffff, },
	{ 335.0f, 10.0f, 0.5f, 1.0f, 0xf0000000, },
	{ 340.0f, 15.0f, 0.5f, 1.0f, 0x0f000000, },
	{ 345.0f, 10.0f, 0.5f, 1.0f, 0x00f00000, },
	{ 350.0f, 15.0f, 0.5f, 1.0f, 0x000f0000, },
	{ 355.0f, 10.0f, 0.5f, 1.0f, 0x0000f000, },//70
	{ 360.0f, 15.0f, 0.5f, 1.0f, 0x00000f00, },
	{ 375.0f, 10.0f, 0.5f, 1.0f, 0x000000f0, },
	{ 380.0f, 15.0f, 0.5f, 1.0f, 0x0000000f, },
	{ 385.0f, 10.0f, 0.5f, 1.0f, 0xff000000, },
	{ 390.0f, 15.0f, 0.5f, 1.0f, 0x0ff00000, },
	{ 395.0f, 10.0f, 0.5f, 1.0f, 0x00ff0000, },
	{ 400.0f, 15.0f, 0.5f, 1.0f, 0x000ff000, },
	{ 405.0f, 10.0f, 0.5f, 1.0f, 0x0000ff00, },
	{ 410.0f, 15.0f, 0.5f, 1.0f, 0x00000ff0, },
	{ 415.0f, 10.0f, 0.5f, 1.0f, 0x000000ff, },//80
	{ 420.0f, 15.0f, 0.5f, 1.0f, 0xfff00000, },
	{ 425.0f, 10.0f, 0.5f, 1.0f, 0x0fff0000, },
	{ 430.0f, 15.0f, 0.5f, 1.0f, 0x00fff000, },
	{ 435.0f, 10.0f, 0.5f, 1.0f, 0x000fff00, },
	{ 440.0f, 15.0f, 0.5f, 1.0f, 0x0000fff0, },
	{ 445.0f, 10.0f, 0.5f, 1.0f, 0x00000fff, },
	{ 450.0f, 15.0f, 0.5f, 1.0f, 0xffff0000, },
	{ 455.0f, 10.0f, 0.5f, 1.0f, 0x0ffff000, },
	{ 460.0f, 15.0f, 0.5f, 1.0f, 0x00ffff00, },
	{ 465.0f, 10.0f, 0.5f, 1.0f, 0x000ffff0, },//90
	{ 470.0f, 15.0f, 0.5f, 1.0f, 0x0000ffff, },
	{ 475.0f, 10.0f, 0.5f, 1.0f, 0xfffff000, },
	{ 480.0f, 15.0f, 0.5f, 1.0f, 0x0fffff00, },
	{ 485.0f, 10.0f, 0.5f, 1.0f, 0x00fffff0, },
	{ 490.0f, 15.0f, 0.5f, 1.0f, 0x000fffff, },
	{ 495.0f, 10.0f, 0.5f, 1.0f, 0xffffff00, },
	{ 500.0f, 15.0f, 0.5f, 1.0f, 0x0ffffff0, },
	{ 505.0f, 10.0f, 0.5f, 1.0f, 0x00ffffff, },
	{ 510.0f, 15.0f, 0.5f, 1.0f, 0xfffffff0, },
	{ 515.0f, 10.0f, 0.5f, 1.0f, 0x0fffffff, },//100
	{ 520.0f, 15.0f, 0.5f, 1.0f, 0xffffffff, },
	{ 525.0f, 10.0f, 0.5f, 1.0f, 0x00000000, },
	{ 530.0f, 15.0f, 0.5f, 1.0f, 0xff00ff00, },
	{ 535.0f, 10.0f, 0.5f, 1.0f, 0x00ff00ff, },
	{ 540.0f, 15.0f, 0.5f, 1.0f, 0xf0000000, },
	{ 545.0f, 10.0f, 0.5f, 1.0f, 0x0f000000, },
	{ 550.0f, 15.0f, 0.5f, 1.0f, 0x00f00000, },
	{ 555.0f, 10.0f, 0.5f, 1.0f, 0x000f0000, },
	{ 560.0f, 15.0f, 0.5f, 1.0f, 0x0000f000, },
	{ 565.0f, 10.0f, 0.5f, 1.0f, 0x00000f00, },//110
	{ 570.0f, 15.0f, 0.5f, 1.0f, 0x000000f0, },
	{ 575.0f, 10.0f, 0.5f, 1.0f, 0x0000000f, },
	{ 580.0f, 15.0f, 0.5f, 1.0f, 0xff000000, },
	{ 585.0f, 10.0f, 0.5f, 1.0f, 0x0ff00000, },
	{ 590.0f, 15.0f, 0.5f, 1.0f, 0x00ff0000, },
	{ 595.0f, 10.0f, 0.5f, 1.0f, 0x000ff000, },
	{ 600.0f, 15.0f, 0.5f, 1.0f, 0x0000ff00, },
	{ 605.0f, 10.0f, 0.5f, 1.0f, 0x00000ff0, },
	{ 610.0f, 15.0f, 0.5f, 1.0f, 0x000000ff, },
	{ 615.0f, 10.0f, 0.5f, 1.0f, 0x00000000, } //120
};

CUSTOMVERTEX TriList[] = 
{
	{   0.0f, 15.0f, 0.5f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
	{   5.0f, 10.0f, 0.5f, 1.0f, 0xff00ff00, },
	{  10.0f, 15.0f, 0.5f, 1.0f, 0xff00ffff, },
	{   5.0f, 10.0f, 0.5f, 1.0f, 0xff00ff00, },
	{  10.0f, 15.0f, 0.5f, 1.0f, 0xff00ffff, },
	{  15.0f, 10.0f, 0.5f, 1.0f, 0x00000000, },
	{  10.0f, 15.0f, 0.5f, 1.0f, 0xff00ffff, },
	{  15.0f, 10.0f, 0.5f, 1.0f, 0x00000000, },
	{  20.0f, 15.0f, 0.5f, 1.0f, 0xf00ff00f, },
	{  15.0f, 10.0f, 0.5f, 1.0f, 0x00000000, },
	{  20.0f, 15.0f, 0.5f, 1.0f, 0xf00ff00f, },
	{  25.0f, 10.0f, 0.5f, 1.0f, 0xffffffff, },
	{  20.0f, 15.0f, 0.5f, 1.0f, 0xf00ff00f, },
	{  25.0f, 10.0f, 0.5f, 1.0f, 0xffffffff, },
	{  30.0f, 15.0f, 0.5f, 1.0f, 0x000ff000, },
	{  25.0f, 10.0f, 0.5f, 1.0f, 0xffffffff, },
	{  30.0f, 15.0f, 0.5f, 1.0f, 0x000ff000, },
	{  35.0f, 10.0f, 0.5f, 1.0f, 0xff00ff00, },
	{  30.0f, 15.0f, 0.5f, 1.0f, 0x000ff000, },
	{  35.0f, 10.0f, 0.5f, 1.0f, 0xff00ff00, },
	{  40.0f, 15.0f, 0.5f, 1.0f, 0x00ff00ff, },
	{  35.0f, 10.0f, 0.5f, 1.0f, 0xff00ff00, },
	{  40.0f, 15.0f, 0.5f, 1.0f, 0x00ff00ff, },
	{  45.0f, 10.0f, 0.5f, 1.0f, 0xf0000000, },
	{  40.0f, 15.0f, 0.5f, 1.0f, 0x00ff00ff, },
	{  45.0f, 10.0f, 0.5f, 1.0f, 0xf0000000, },
	{  50.0f, 15.0f, 0.5f, 1.0f, 0x0f000000, },
	{  45.0f, 10.0f, 0.5f, 1.0f, 0xf0000000, },
	{  50.0f, 15.0f, 0.5f, 1.0f, 0x0f000000, },
	{  55.0f, 10.0f, 0.5f, 1.0f, 0x00f00000, },//10

	{  50.0f, 15.0f, 0.5f, 1.0f, 0x0f000000, },
	{  55.0f, 10.0f, 0.5f, 1.0f, 0x00f00000, },
	{  60.0f, 15.0f, 0.5f, 1.0f, 0x000f0000, },
	{  55.0f, 10.0f, 0.5f, 1.0f, 0x00f00000, },
	{  60.0f, 15.0f, 0.5f, 1.0f, 0x000f0000, },
	{  65.0f, 10.0f, 0.5f, 1.0f, 0x0000f000, },
	{  60.0f, 15.0f, 0.5f, 1.0f, 0x000f0000, },
	{  65.0f, 10.0f, 0.5f, 1.0f, 0x0000f000, },
	{  70.0f, 15.0f, 0.5f, 1.0f, 0x00000f00, },
	{  65.0f, 10.0f, 0.5f, 1.0f, 0x0000f000, },
	{  70.0f, 15.0f, 0.5f, 1.0f, 0x00000f00, },
	{  75.0f, 10.0f, 0.5f, 1.0f, 0x000000f0, },
	{  70.0f, 15.0f, 0.5f, 1.0f, 0x00000f00, },
	{  75.0f, 10.0f, 0.5f, 1.0f, 0x000000f0, },
	{  80.0f, 15.0f, 0.5f, 1.0f, 0x0000000f, },
	{  75.0f, 10.0f, 0.5f, 1.0f, 0x000000f0, },
	{  80.0f, 15.0f, 0.5f, 1.0f, 0x0000000f, },
	{  85.0f, 10.0f, 0.5f, 1.0f, 0xff000000, },
	{  80.0f, 15.0f, 0.5f, 1.0f, 0x0000000f, },
	{  85.0f, 10.0f, 0.5f, 1.0f, 0xff000000, },
	{  90.0f, 15.0f, 0.5f, 1.0f, 0x0ff00000, },
	{  85.0f, 10.0f, 0.5f, 1.0f, 0xff000000, },
	{  90.0f, 15.0f, 0.5f, 1.0f, 0x0ff00000, },
	{  95.0f, 10.0f, 0.5f, 1.0f, 0x00ff0000, },
	{  90.0f, 15.0f, 0.5f, 1.0f, 0x0ff00000, },
	{  95.0f, 10.0f, 0.5f, 1.0f, 0x00ff0000, },
	{ 100.0f, 15.0f, 0.5f, 1.0f, 0x000ff000, },
	{  95.0f, 10.0f, 0.5f, 1.0f, 0x00ff0000, },
	{ 100.0f, 15.0f, 0.5f, 1.0f, 0x000ff000, },
	{ 105.0f, 10.0f, 0.5f, 1.0f, 0x0000ff00, },//20

	{ 100.0f, 15.0f, 0.5f, 1.0f, 0x000ff000, },
	{ 105.0f, 10.0f, 0.5f, 1.0f, 0x0000ff00, },
	{ 110.0f, 15.0f, 0.5f, 1.0f, 0x00000ff0, },
	{ 105.0f, 10.0f, 0.5f, 1.0f, 0x0000ff00, },
	{ 110.0f, 15.0f, 0.5f, 1.0f, 0x00000ff0, },
	{ 115.0f, 10.0f, 0.5f, 1.0f, 0x000000ff, },
	{ 110.0f, 15.0f, 0.5f, 1.0f, 0x00000ff0, },
	{ 115.0f, 10.0f, 0.5f, 1.0f, 0x000000ff, },
	{ 120.0f, 15.0f, 0.5f, 1.0f, 0xfff00000, },
	{ 115.0f, 10.0f, 0.5f, 1.0f, 0x000000ff, },
	{ 120.0f, 15.0f, 0.5f, 1.0f, 0xfff00000, },
	{ 125.0f, 10.0f, 0.5f, 1.0f, 0x0fff0000, },
	{ 120.0f, 15.0f, 0.5f, 1.0f, 0xfff00000, },
	{ 125.0f, 10.0f, 0.5f, 1.0f, 0x0fff0000, },
	{ 130.0f, 15.0f, 0.5f, 1.0f, 0x00fff000, },
	{ 125.0f, 10.0f, 0.5f, 1.0f, 0x0fff0000, },
	{ 130.0f, 15.0f, 0.5f, 1.0f, 0x00fff000, },
	{ 135.0f, 10.0f, 0.5f, 1.0f, 0x000fff00, },
	{ 130.0f, 15.0f, 0.5f, 1.0f, 0x00fff000, },
	{ 135.0f, 10.0f, 0.5f, 1.0f, 0x000fff00, },
	{ 140.0f, 15.0f, 0.5f, 1.0f, 0x0000fff0, },
	{ 135.0f, 10.0f, 0.5f, 1.0f, 0x000fff00, },
	{ 140.0f, 15.0f, 0.5f, 1.0f, 0x0000fff0, },
	{ 145.0f, 15.0f, 0.5f, 1.0f, 0x00000fff, },
	{ 140.0f, 15.0f, 0.5f, 1.0f, 0x0000fff0, },
	{ 145.0f, 15.0f, 0.5f, 1.0f, 0x00000fff, },
	{ 150.0f, 10.0f, 0.5f, 1.0f, 0xffff0000, },
	{ 145.0f, 15.0f, 0.5f, 1.0f, 0x00000fff, },
	{ 150.0f, 10.0f, 0.5f, 1.0f, 0xffff0000, },
	{ 155.0f, 15.0f, 0.5f, 1.0f, 0xff00ff00, },//30

	{ 150.0f, 10.0f, 0.5f, 1.0f, 0xffff0000, },
	{ 155.0f, 15.0f, 0.5f, 1.0f, 0xff00ff00, },
	{ 160.0f, 15.0f, 0.5f, 1.0f, 0x0000ffff, },
	{ 155.0f, 15.0f, 0.5f, 1.0f, 0xff00ff00, },
	{ 160.0f, 15.0f, 0.5f, 1.0f, 0x0000ffff, },
	{ 165.0f, 10.0f, 0.5f, 1.0f, 0x00000000, },
	{ 160.0f, 15.0f, 0.5f, 1.0f, 0x0000ffff, },
	{ 165.0f, 10.0f, 0.5f, 1.0f, 0x00000000, },
	{ 170.0f, 15.0f, 0.5f, 1.0f, 0xffffffff, },
	{ 165.0f, 10.0f, 0.5f, 1.0f, 0x00000000, },
	{ 170.0f, 15.0f, 0.5f, 1.0f, 0xffffffff, },
	{ 175.0f, 10.0f, 0.5f, 1.0f, 0x00ff00ff, },
	{ 170.0f, 15.0f, 0.5f, 1.0f, 0xffffffff, },
	{ 175.0f, 10.0f, 0.5f, 1.0f, 0x00ff00ff, },
	{ 180.0f, 15.0f, 0.5f, 1.0f, 0xff00ffff, },
	{ 175.0f, 10.0f, 0.5f, 1.0f, 0x00ff00ff, },
	{ 180.0f, 15.0f, 0.5f, 1.0f, 0xff00ffff, },
	{ 185.0f, 10.0f, 0.5f, 1.0f, 0xffff00ff, },
	{ 180.0f, 15.0f, 0.5f, 1.0f, 0xff00ffff, },
	{ 185.0f, 10.0f, 0.5f, 1.0f, 0xffff00ff, },
	{ 190.0f, 15.0f, 0.5f, 1.0f, 0xf0000000, },
	{ 185.0f, 10.0f, 0.5f, 1.0f, 0xffff00ff, },
	{ 190.0f, 15.0f, 0.5f, 1.0f, 0xf0000000, },
	{ 195.0f, 10.0f, 0.5f, 1.0f, 0x0f000000, },
	{ 190.0f, 15.0f, 0.5f, 1.0f, 0xf0000000, },
	{ 195.0f, 10.0f, 0.5f, 1.0f, 0x0f000000, },
	{ 200.0f, 15.0f, 0.5f, 1.0f, 0x00f00000, },
	{ 195.0f, 10.0f, 0.5f, 1.0f, 0x0f000000, },
	{ 200.0f, 15.0f, 0.5f, 1.0f, 0x00f00000, },
	{ 205.0f, 10.0f, 0.5f, 1.0f, 0x000f0000, },//40

	{ 200.0f, 15.0f, 0.5f, 1.0f, 0x00f00000, },
	{ 205.0f, 10.0f, 0.5f, 1.0f, 0x000f0000, },
	{ 210.0f, 15.0f, 0.5f, 1.0f, 0x0000f000, },
	{ 205.0f, 10.0f, 0.5f, 1.0f, 0x000f0000, },
	{ 210.0f, 15.0f, 0.5f, 1.0f, 0x0000f000, },
	{ 215.0f, 10.0f, 0.5f, 1.0f, 0x00000f00, },
	{ 210.0f, 15.0f, 0.5f, 1.0f, 0x0000f000, },
	{ 215.0f, 10.0f, 0.5f, 1.0f, 0x00000f00, },
	{ 220.0f, 10.0f, 0.5f, 1.0f, 0x000000f0, },
	{ 215.0f, 10.0f, 0.5f, 1.0f, 0x00000f00, },
	{ 220.0f, 10.0f, 0.5f, 1.0f, 0x000000f0, },
	{ 225.0f, 10.0f, 0.5f, 1.0f, 0x0000000f, },
	{ 220.0f, 10.0f, 0.5f, 1.0f, 0x000000f0, },
	{ 225.0f, 10.0f, 0.5f, 1.0f, 0x0000000f, },
	{ 230.0f, 15.0f, 0.5f, 1.0f, 0xff000000, },
	{ 225.0f, 10.0f, 0.5f, 1.0f, 0x0000000f, },
	{ 230.0f, 15.0f, 0.5f, 1.0f, 0xff000000, },
	{ 235.0f, 10.0f, 0.5f, 1.0f, 0x0ff00000, },
	{ 230.0f, 15.0f, 0.5f, 1.0f, 0xff000000, },
	{ 235.0f, 10.0f, 0.5f, 1.0f, 0x0ff00000, },
	{ 240.0f, 15.0f, 0.5f, 1.0f, 0x00ff0000, },
	{ 235.0f, 10.0f, 0.5f, 1.0f, 0x0ff00000, },
	{ 240.0f, 15.0f, 0.5f, 1.0f, 0x00ff0000, },
	{ 245.0f, 10.0f, 0.5f, 1.0f, 0x000ff000, },
	{ 240.0f, 15.0f, 0.5f, 1.0f, 0x00ff0000, },
	{ 245.0f, 10.0f, 0.5f, 1.0f, 0x000ff000, },
	{ 250.0f, 15.0f, 0.5f, 1.0f, 0x0000ff00, },
	{ 245.0f, 10.0f, 0.5f, 1.0f, 0x000ff000, },
	{ 250.0f, 15.0f, 0.5f, 1.0f, 0x0000ff00, },
	{ 255.0f, 10.0f, 0.5f, 1.0f, 0x00000ff0, },//50

	{ 250.0f, 15.0f, 0.5f, 1.0f, 0x0000ff00, },
	{ 255.0f, 10.0f, 0.5f, 1.0f, 0x00000ff0, },
	{ 260.0f, 15.0f, 0.5f, 1.0f, 0x000000ff, },
	{ 255.0f, 10.0f, 0.5f, 1.0f, 0x00000ff0, },
	{ 260.0f, 15.0f, 0.5f, 1.0f, 0x000000ff, },
	{ 265.0f, 10.0f, 0.5f, 1.0f, 0xfff00000, },
	{ 260.0f, 15.0f, 0.5f, 1.0f, 0x000000ff, },
	{ 265.0f, 10.0f, 0.5f, 1.0f, 0xfff00000, },
	{ 270.0f, 15.0f, 0.5f, 1.0f, 0x0fff0000, },
	{ 265.0f, 10.0f, 0.5f, 1.0f, 0xfff00000, },
	{ 270.0f, 15.0f, 0.5f, 1.0f, 0x0fff0000, },
	{ 275.0f, 10.0f, 0.5f, 1.0f, 0x00fff000, },
	{ 270.0f, 15.0f, 0.5f, 1.0f, 0x0fff0000, },
	{ 275.0f, 10.0f, 0.5f, 1.0f, 0x00fff000, },
	{ 280.0f, 15.0f, 0.5f, 1.0f, 0x000fff00, },
	{ 275.0f, 10.0f, 0.5f, 1.0f, 0x00fff000, },
	{ 280.0f, 15.0f, 0.5f, 1.0f, 0x000fff00, },
	{ 285.0f, 10.0f, 0.5f, 1.0f, 0x0000fff0, },
	{ 280.0f, 15.0f, 0.5f, 1.0f, 0x000fff00, },
	{ 285.0f, 10.0f, 0.5f, 1.0f, 0x0000fff0, },
	{ 290.0f, 15.0f, 0.5f, 1.0f, 0x00000fff, },
	{ 285.0f, 10.0f, 0.5f, 1.0f, 0x0000fff0, },
	{ 290.0f, 15.0f, 0.5f, 1.0f, 0x00000fff, },
	{ 295.0f, 10.0f, 0.5f, 1.0f, 0xffff0000, },
	{ 290.0f, 15.0f, 0.5f, 1.0f, 0x00000fff, },
	{ 295.0f, 10.0f, 0.5f, 1.0f, 0xffff0000, },
	{ 300.0f, 15.0f, 0.5f, 1.0f, 0x0000ffff, },
	{ 295.0f, 10.0f, 0.5f, 1.0f, 0xffff0000, },
	{ 300.0f, 15.0f, 0.5f, 1.0f, 0x0000ffff, },
	{ 305.0f, 10.0f, 0.5f, 1.0f, 0xff00ff00, },//60

	{ 300.0f, 15.0f, 0.5f, 1.0f, 0x0000ffff, },
	{ 305.0f, 10.0f, 0.5f, 1.0f, 0xff00ff00, },
	{ 310.0f, 15.0f, 0.5f, 1.0f, 0x00ff00ff, },
	{ 305.0f, 10.0f, 0.5f, 1.0f, 0xff00ff00, },
	{ 310.0f, 15.0f, 0.5f, 1.0f, 0x00ff00ff, },
	{ 315.0f, 10.0f, 0.5f, 1.0f, 0xffff00ff, },
	{ 310.0f, 15.0f, 0.5f, 1.0f, 0x00ff00ff, },
	{ 315.0f, 10.0f, 0.5f, 1.0f, 0xffff00ff, },
	{ 320.0f, 15.0f, 0.5f, 1.0f, 0xff00ffff, },
	{ 315.0f, 10.0f, 0.5f, 1.0f, 0xffff00ff, },
	{ 320.0f, 15.0f, 0.5f, 1.0f, 0xff00ffff, },
	{ 325.0f, 10.0f, 0.5f, 1.0f, 0x00000000, },
	{ 320.0f, 15.0f, 0.5f, 1.0f, 0xff00ffff, },
	{ 325.0f, 10.0f, 0.5f, 1.0f, 0x00000000, },
	{ 330.0f, 15.0f, 0.5f, 1.0f, 0xffffffff, },
	{ 325.0f, 10.0f, 0.5f, 1.0f, 0x00000000, },
	{ 330.0f, 15.0f, 0.5f, 1.0f, 0xffffffff, },
	{ 335.0f, 10.0f, 0.5f, 1.0f, 0xf0000000, },
	{ 330.0f, 15.0f, 0.5f, 1.0f, 0xffffffff, },
	{ 335.0f, 10.0f, 0.5f, 1.0f, 0xf0000000, },
	{ 340.0f, 15.0f, 0.5f, 1.0f, 0x0f000000, },
	{ 335.0f, 10.0f, 0.5f, 1.0f, 0xf0000000, },
	{ 340.0f, 15.0f, 0.5f, 1.0f, 0x0f000000, },
	{ 345.0f, 10.0f, 0.5f, 1.0f, 0x00f00000, },
	{ 340.0f, 15.0f, 0.5f, 1.0f, 0x0f000000, },
	{ 345.0f, 10.0f, 0.5f, 1.0f, 0x00f00000, },
	{ 350.0f, 15.0f, 0.5f, 1.0f, 0x000f0000, },
	{ 345.0f, 10.0f, 0.5f, 1.0f, 0x00f00000, },
	{ 350.0f, 15.0f, 0.5f, 1.0f, 0x000f0000, },
	{ 355.0f, 10.0f, 0.5f, 1.0f, 0x0000f000, },//70

	{ 350.0f, 15.0f, 0.5f, 1.0f, 0x000f0000, },
	{ 355.0f, 10.0f, 0.5f, 1.0f, 0x0000f000, },
	{ 360.0f, 15.0f, 0.5f, 1.0f, 0x00000f00, },
	{ 355.0f, 10.0f, 0.5f, 1.0f, 0x0000f000, },
	{ 360.0f, 15.0f, 0.5f, 1.0f, 0x00000f00, },
	{ 375.0f, 10.0f, 0.5f, 1.0f, 0x000000f0, },
	{ 360.0f, 15.0f, 0.5f, 1.0f, 0x00000f00, },
	{ 375.0f, 10.0f, 0.5f, 1.0f, 0x000000f0, },
	{ 380.0f, 15.0f, 0.5f, 1.0f, 0x0000000f, },
	{ 375.0f, 10.0f, 0.5f, 1.0f, 0x000000f0, },
	{ 380.0f, 15.0f, 0.5f, 1.0f, 0x0000000f, },
	{ 385.0f, 10.0f, 0.5f, 1.0f, 0xff000000, },
	{ 380.0f, 15.0f, 0.5f, 1.0f, 0x0000000f, },
	{ 385.0f, 10.0f, 0.5f, 1.0f, 0xff000000, },
	{ 390.0f, 15.0f, 0.5f, 1.0f, 0x0ff00000, },
	{ 385.0f, 10.0f, 0.5f, 1.0f, 0xff000000, },
	{ 390.0f, 15.0f, 0.5f, 1.0f, 0x0ff00000, },
	{ 395.0f, 10.0f, 0.5f, 1.0f, 0x00ff0000, },
	{ 390.0f, 15.0f, 0.5f, 1.0f, 0x0ff00000, },
	{ 395.0f, 10.0f, 0.5f, 1.0f, 0x00ff0000, },
	{ 400.0f, 15.0f, 0.5f, 1.0f, 0x000ff000, },
	{ 395.0f, 10.0f, 0.5f, 1.0f, 0x00ff0000, },
	{ 400.0f, 15.0f, 0.5f, 1.0f, 0x000ff000, },
	{ 405.0f, 10.0f, 0.5f, 1.0f, 0x0000ff00, },
	{ 400.0f, 15.0f, 0.5f, 1.0f, 0x000ff000, },
	{ 405.0f, 10.0f, 0.5f, 1.0f, 0x0000ff00, },
	{ 410.0f, 15.0f, 0.5f, 1.0f, 0x00000ff0, },
	{ 405.0f, 10.0f, 0.5f, 1.0f, 0x0000ff00, },
	{ 410.0f, 15.0f, 0.5f, 1.0f, 0x00000ff0, },
	{ 415.0f, 10.0f, 0.5f, 1.0f, 0x000000ff, },//80

	{ 410.0f, 15.0f, 0.5f, 1.0f, 0x00000ff0, },
	{ 415.0f, 10.0f, 0.5f, 1.0f, 0x000000ff, },
	{ 420.0f, 15.0f, 0.5f, 1.0f, 0xfff00000, },
	{ 415.0f, 10.0f, 0.5f, 1.0f, 0x000000ff, },
	{ 420.0f, 15.0f, 0.5f, 1.0f, 0xfff00000, },
	{ 425.0f, 10.0f, 0.5f, 1.0f, 0x0fff0000, },
	{ 420.0f, 15.0f, 0.5f, 1.0f, 0xfff00000, },
	{ 425.0f, 10.0f, 0.5f, 1.0f, 0x0fff0000, },
	{ 430.0f, 15.0f, 0.5f, 1.0f, 0x00fff000, },
	{ 425.0f, 10.0f, 0.5f, 1.0f, 0x0fff0000, },
	{ 430.0f, 15.0f, 0.5f, 1.0f, 0x00fff000, },
	{ 435.0f, 10.0f, 0.5f, 1.0f, 0x000fff00, },
	{ 430.0f, 15.0f, 0.5f, 1.0f, 0x00fff000, },
	{ 435.0f, 10.0f, 0.5f, 1.0f, 0x000fff00, },
	{ 440.0f, 15.0f, 0.5f, 1.0f, 0x0000fff0, },
	{ 435.0f, 10.0f, 0.5f, 1.0f, 0x000fff00, },
	{ 440.0f, 15.0f, 0.5f, 1.0f, 0x0000fff0, },	
	{ 445.0f, 10.0f, 0.5f, 1.0f, 0x00000fff, },
	{ 440.0f, 15.0f, 0.5f, 1.0f, 0x0000fff0, },	
	{ 445.0f, 10.0f, 0.5f, 1.0f, 0x00000fff, },
	{ 450.0f, 15.0f, 0.5f, 1.0f, 0xffff0000, },
	{ 445.0f, 10.0f, 0.5f, 1.0f, 0x00000fff, },
	{ 450.0f, 15.0f, 0.5f, 1.0f, 0xffff0000, },
	{ 455.0f, 10.0f, 0.5f, 1.0f, 0x0ffff000, },
	{ 450.0f, 15.0f, 0.5f, 1.0f, 0xffff0000, },
	{ 455.0f, 10.0f, 0.5f, 1.0f, 0x0ffff000, },
	{ 460.0f, 15.0f, 0.5f, 1.0f, 0x00ffff00, },
	{ 455.0f, 10.0f, 0.5f, 1.0f, 0x0ffff000, },
	{ 460.0f, 15.0f, 0.5f, 1.0f, 0x00ffff00, },
	{ 465.0f, 10.0f, 0.5f, 1.0f, 0x000ffff0, },//90

	{ 460.0f, 15.0f, 0.5f, 1.0f, 0x00ffff00, },
	{ 465.0f, 10.0f, 0.5f, 1.0f, 0x000ffff0, },
	{ 470.0f, 15.0f, 0.5f, 1.0f, 0x0000ffff, },
	{ 465.0f, 10.0f, 0.5f, 1.0f, 0x000ffff0, },
	{ 470.0f, 15.0f, 0.5f, 1.0f, 0x0000ffff, },
	{ 475.0f, 10.0f, 0.5f, 1.0f, 0xfffff000, },
	{ 470.0f, 15.0f, 0.5f, 1.0f, 0x0000ffff, },
	{ 475.0f, 10.0f, 0.5f, 1.0f, 0xfffff000, },
	{ 480.0f, 15.0f, 0.5f, 1.0f, 0x0fffff00, },
	{ 475.0f, 10.0f, 0.5f, 1.0f, 0xfffff000, },
	{ 480.0f, 15.0f, 0.5f, 1.0f, 0x0fffff00, },
	{ 485.0f, 10.0f, 0.5f, 1.0f, 0x00fffff0, },
	{ 480.0f, 15.0f, 0.5f, 1.0f, 0x0fffff00, },
	{ 485.0f, 10.0f, 0.5f, 1.0f, 0x00fffff0, },
	{ 490.0f, 15.0f, 0.5f, 1.0f, 0x000fffff, },
	{ 485.0f, 10.0f, 0.5f, 1.0f, 0x00fffff0, },
	{ 490.0f, 15.0f, 0.5f, 1.0f, 0x000fffff, },
	{ 495.0f, 10.0f, 0.5f, 1.0f, 0xffffff00, },
	{ 490.0f, 15.0f, 0.5f, 1.0f, 0x000fffff, },
	{ 495.0f, 10.0f, 0.5f, 1.0f, 0xffffff00, },
	{ 500.0f, 15.0f, 0.5f, 1.0f, 0x0ffffff0, },
	{ 495.0f, 10.0f, 0.5f, 1.0f, 0xffffff00, },
	{ 500.0f, 15.0f, 0.5f, 1.0f, 0x0ffffff0, },
	{ 505.0f, 10.0f, 0.5f, 1.0f, 0x00ffffff, },
	{ 500.0f, 15.0f, 0.5f, 1.0f, 0x0ffffff0, },
	{ 505.0f, 10.0f, 0.5f, 1.0f, 0x00ffffff, },
	{ 510.0f, 15.0f, 0.5f, 1.0f, 0xfffffff0, },
	{ 505.0f, 10.0f, 0.5f, 1.0f, 0x00ffffff, },
	{ 510.0f, 15.0f, 0.5f, 1.0f, 0xfffffff0, },
	{ 515.0f, 10.0f, 0.5f, 1.0f, 0x0fffffff, },//100

	{ 510.0f, 15.0f, 0.5f, 1.0f, 0xfffffff0, },
	{ 515.0f, 10.0f, 0.5f, 1.0f, 0x0fffffff, },
	{ 520.0f, 15.0f, 0.5f, 1.0f, 0xffffffff, },
	{ 515.0f, 10.0f, 0.5f, 1.0f, 0x0fffffff, },
	{ 520.0f, 15.0f, 0.5f, 1.0f, 0xffffffff, },
	{ 525.0f, 10.0f, 0.5f, 1.0f, 0x00000000, },
	{ 520.0f, 15.0f, 0.5f, 1.0f, 0xffffffff, },
	{ 525.0f, 10.0f, 0.5f, 1.0f, 0x00000000, },
	{ 530.0f, 15.0f, 0.5f, 1.0f, 0xff00ff00, },
	{ 525.0f, 10.0f, 0.5f, 1.0f, 0x00000000, },
	{ 530.0f, 15.0f, 0.5f, 1.0f, 0xff00ff00, },
	{ 535.0f, 10.0f, 0.5f, 1.0f, 0x00ff00ff, },
	{ 530.0f, 15.0f, 0.5f, 1.0f, 0xff00ff00, },
	{ 535.0f, 10.0f, 0.5f, 1.0f, 0x00ff00ff, },
	{ 540.0f, 15.0f, 0.5f, 1.0f, 0xf0000000, },
	{ 535.0f, 10.0f, 0.5f, 1.0f, 0x00ff00ff, },
	{ 540.0f, 15.0f, 0.5f, 1.0f, 0xf0000000, },
	{ 545.0f, 10.0f, 0.5f, 1.0f, 0x0f000000, },
	{ 540.0f, 15.0f, 0.5f, 1.0f, 0xf0000000, },
	{ 545.0f, 10.0f, 0.5f, 1.0f, 0x0f000000, },
	{ 550.0f, 15.0f, 0.5f, 1.0f, 0x00f00000, },
	{ 545.0f, 10.0f, 0.5f, 1.0f, 0x0f000000, },
	{ 550.0f, 15.0f, 0.5f, 1.0f, 0x00f00000, },
	{ 555.0f, 10.0f, 0.5f, 1.0f, 0x000f0000, },
	{ 550.0f, 15.0f, 0.5f, 1.0f, 0x00f00000, },
	{ 555.0f, 10.0f, 0.5f, 1.0f, 0x000f0000, },
	{ 560.0f, 15.0f, 0.5f, 1.0f, 0x0000f000, },
	{ 555.0f, 10.0f, 0.5f, 1.0f, 0x000f0000, },
	{ 560.0f, 15.0f, 0.5f, 1.0f, 0x0000f000, },
	{ 565.0f, 10.0f, 0.5f, 1.0f, 0x00000f00, },//110

	{ 560.0f, 15.0f, 0.5f, 1.0f, 0x0000f000, },
	{ 565.0f, 10.0f, 0.5f, 1.0f, 0x00000f00, },
	{ 570.0f, 15.0f, 0.5f, 1.0f, 0x000000f0, },
	{ 565.0f, 10.0f, 0.5f, 1.0f, 0x00000f00, },
	{ 570.0f, 15.0f, 0.5f, 1.0f, 0x000000f0, },
	{ 575.0f, 10.0f, 0.5f, 1.0f, 0x0000000f, },
	{ 570.0f, 15.0f, 0.5f, 1.0f, 0x000000f0, },
	{ 575.0f, 10.0f, 0.5f, 1.0f, 0x0000000f, },
	{ 580.0f, 15.0f, 0.5f, 1.0f, 0xff000000, },
	{ 575.0f, 10.0f, 0.5f, 1.0f, 0x0000000f, },
	{ 580.0f, 15.0f, 0.5f, 1.0f, 0xff000000, },
	{ 585.0f, 10.0f, 0.5f, 1.0f, 0x0ff00000, },
	{ 580.0f, 15.0f, 0.5f, 1.0f, 0xff000000, },
	{ 585.0f, 10.0f, 0.5f, 1.0f, 0x0ff00000, },
	{ 590.0f, 15.0f, 0.5f, 1.0f, 0x00ff0000, },
	{ 585.0f, 10.0f, 0.5f, 1.0f, 0x0ff00000, },
	{ 590.0f, 15.0f, 0.5f, 1.0f, 0x00ff0000, },
	{ 595.0f, 10.0f, 0.5f, 1.0f, 0x000ff000, },
	{ 590.0f, 15.0f, 0.5f, 1.0f, 0x00ff0000, },
	{ 595.0f, 10.0f, 0.5f, 1.0f, 0x000ff000, },
	{ 600.0f, 15.0f, 0.5f, 1.0f, 0x0000ff00, },
	{ 595.0f, 10.0f, 0.5f, 1.0f, 0x000ff000, },
	{ 600.0f, 15.0f, 0.5f, 1.0f, 0x0000ff00, },
	{ 605.0f, 10.0f, 0.5f, 1.0f, 0x00000ff0, },
	{ 600.0f, 15.0f, 0.5f, 1.0f, 0x0000ff00, },
	{ 605.0f, 10.0f, 0.5f, 1.0f, 0x00000ff0, },
	{ 610.0f, 15.0f, 0.5f, 1.0f, 0x000000ff, },
	{ 605.0f, 10.0f, 0.5f, 1.0f, 0x00000ff0, },
	{ 610.0f, 15.0f, 0.5f, 1.0f, 0x000000ff, },
	{ 615.0f, 10.0f, 0.5f, 1.0f, 0x00000000, } //120
};

int IBuffer[] = 
{
	0, 1, 2,
	1, 2, 3,
	2, 3, 4,
	3, 4, 5,
	4, 5, 6,
	5, 6, 7,
	6, 7, 8,
	7, 8, 9,
	8, 9, 10,
	9, 10, 11, //10
	10, 11, 12,
	11, 12, 13,
	12, 13, 14,
	13, 14, 15,
	14, 15, 16,
	15, 16, 17,
	16, 17, 18,
	17, 18, 19,
	18, 19, 20,
	19, 20, 21, //20
	20, 21, 22,
	21, 22, 23,
	22, 23, 24,
	23, 24, 25,
	24, 25, 26,
	25, 26, 27,
	26, 27, 28,
	27, 28, 29,
	28, 29, 30,
	29, 39, 31, //30
	30, 31, 32,
	31, 32, 33,
	32, 33, 34,
	33, 34, 35,
	34, 35, 36,
	35, 36, 37,
	36, 37, 38,
	37, 38, 39,
	38, 39, 40,
	39, 40, 41, //40
	40, 41, 42,
	41, 42, 43,
	42, 43, 44,
	43, 44, 45,
	44, 45, 46,
	45, 46, 47,
	46, 47, 48,
	47, 48, 49,
	48, 49, 50,
	49, 50, 51, //50
	50, 51, 52,
	51, 52, 53,
	52, 53, 54,
	53, 54, 55,
	54, 55, 56,
	55, 56, 57,
	56, 57, 58,
	57, 58, 59,
	58, 59, 60,
	59, 60, 61, //60
	60, 61, 62,
	61, 62, 63,
	62, 63, 64,
	63, 64, 65,
	64, 65, 66,
	65, 66, 67,
	66, 67, 68,
	67, 68, 69,
	68, 69, 70,
	69, 70, 71, //70
	70, 71, 72,
	71, 72, 73,
	72, 73, 74,
	73, 74, 75,
	74, 75, 76,
	75, 76, 77,
	76, 77, 78,
	77, 78, 79,
	78, 79, 80,
	79, 80, 81, //80
	80, 81, 82,
	81, 82, 83,
	82, 83, 84,
	83, 84, 85,
	84, 85, 86,
	85, 86, 87,
	86, 87, 88,
	87, 88, 89,
	88, 89, 90,
	89, 90, 91,  //90
	90, 91, 92,
	91, 92, 93,
	92, 93, 94,
	93, 94, 95,
	94, 95, 96,
	95, 96, 97,
	96, 97, 98,
	97, 98, 99,
	98, 99, 100,
	99, 100, 101, //100
	100, 101, 102,
	101, 102, 103,
	102, 103, 104,
	103, 104, 105,
	104, 105, 106,
	105, 106, 107,
	106, 107, 108,
	107, 108, 109,
	108, 109, 110,
	109, 110, 111, //110
	110, 111, 112,
	111, 112, 113, 
	112, 113, 114,
	113, 114, 115,
	114, 115, 116,
	115, 116, 117,
	116, 117, 118,
	117, 118, 119,
	118, 119, 120,
	119, 120, 121 //120
};
