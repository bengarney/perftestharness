
void VertScene( float4 vPos : POSITION,
                out float4 oPos : POSITION)
{
    oPos = vPos;
}


float4 PixScene( float4 out0 : COLOR0, float4 out1 : COLOR1, float4 out2 : COLOR2, float4 out3 : COLOR3 ) : COLOR0
{
    // Lookup mesh texture and modulate it with diffuse and light color
    out0 = float4(0, 1, 0, 0);
    out1 = float4(0, 0, 1, 0);
    out2 = float4(1, 0, 1, 0);
    out3 = float4(1, 0, 1, 0);
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
