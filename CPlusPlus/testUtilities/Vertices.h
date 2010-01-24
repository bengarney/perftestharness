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

extern CUSTOMVERTEX VerticesF[];
extern CUSTOMVERTEX TriStrip[];
extern CUSTOMVERTEX TriList[];
extern int IBuffer[];
