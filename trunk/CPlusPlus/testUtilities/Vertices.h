#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZRHW|D3DFVF_DIFFUSE)
#define D3DFVF_VERT2 (D3DFVF_XYZRHW | D3DFVF_TEX1)
#define D3DFVF_VERT3 (D3DFVF_XYZRHW | D3DFVF_TEX2)
#define D3DFVF_VERT4 (D3DFVF_XYZRHW | D3DFVF_TEX8)
#define D3DFVF_VERT5 (D3DFVF_XYZRHW | D3DFVF_TEX8 | D3DFVF_DIFFUSE | D3DFVF_NORMAL)

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

struct CUSTOMVERT3
{
   FLOAT x, y, z, rhw;
   FLOAT tu, tv;
   FLOAT tu2, tv2;
};

struct CUSTOMVERT4
{
   FLOAT x, y, z, rhw;
   FLOAT tu, tv;
   FLOAT tu2, tv2;
   FLOAT tu3, tv3;
   FLOAT tu4, tv4;
   FLOAT tu5, tv5;
   FLOAT tu6, tv6;
   FLOAT tu7, tv7;
   FLOAT tu8, tv8;
};

struct CUSTOMVERT5
{
   FLOAT x, y, z, rhw;
   FLOAT nx, ny, nz;
   DWORD diffuse;
   FLOAT tu, tv;
   FLOAT tu2, tv2;
   FLOAT tu3, tv3;
   FLOAT tu4, tv4;
   FLOAT tu5, tv5;
   FLOAT tu6, tv6;
   FLOAT tu7, tv7;
   FLOAT tu8, tv8;
};

extern CUSTOMVERTEX VerticesF[];
extern CUSTOMVERTEX TriStrip[];
extern CUSTOMVERTEX TriList[];
extern int IBuffer[];
