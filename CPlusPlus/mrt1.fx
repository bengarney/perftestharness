
void VertScene( float4 vPos : POSITION,
                out float4 oPos : POSITION)
{
    oPos = vPos;
}


float4 PixScene( float4 out0 : COLOR0 ) : COLOR0
{
    // Lookup mesh texture and modulate it with diffuse and light color
    out0 = float4(0, 1, 0, 0);
    return float4(0, 1, 0, 0);
}


//--------------------------------------------------------------------------------------
// Techniques
//--------------------------------------------------------------------------------------
technique RenderScene
{
    pass P0
    {
        VertexShader = compile vs_2_0 VertScene();
        PixelShader  = compile ps_2_0 PixScene();
    }
}
