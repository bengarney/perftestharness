const int mathCount= 50;


void VertScene( float4 vPos : POSITION, float2 tc : TEXCOORD0,
                out float2 oTc : TEXCOORD0,
                out float4 oPos : POSITION)
{
    oPos = vPos;
    oTc = tc;
}


float4 PixScene( float4 out0 : COLOR0, float2 tc : TEXCOORD0 ) : COLOR0
{
   float4 totalColor = float4(tc.x,tc.y,tc.x*tc.x,tc.x*tc.y);

   for(int i=0; i<mathCount; i++)
   {
      totalColor.x = 2*totalColor.y + 6*totalColor.z + 2*totalColor.w;
      totalColor.y = 4*totalColor.y + 7*totalColor.z + 3*totalColor.w;
      totalColor.z = 5*totalColor.y + 8*totalColor.z + 4*totalColor.w;
      totalColor.w = 9*totalColor.y + 9*totalColor.z + 5*totalColor.w;

      totalColor.x = 2*totalColor.y + 6*totalColor.z + 2*totalColor.w;
      totalColor.y = 4*totalColor.y + 7*totalColor.z + 3*totalColor.w;
      totalColor.z = 5*totalColor.y + 8*totalColor.z + 4*totalColor.w;
      totalColor.w = 9*totalColor.y + 9*totalColor.z + 5*totalColor.w;

      totalColor.x = 2*totalColor.y + 6*totalColor.z + 2*totalColor.w;
      totalColor.y = 4*totalColor.y + 7*totalColor.z + 3*totalColor.w;
      totalColor.z = 5*totalColor.y + 8*totalColor.z + 4*totalColor.w;
      totalColor.w = 9*totalColor.y + 9*totalColor.z + 5*totalColor.w;

      totalColor.x = 2*totalColor.y + 6*totalColor.z + 2*totalColor.w;
      totalColor.y = 4*totalColor.y + 7*totalColor.z + 3*totalColor.w;
      totalColor.z = 5*totalColor.y + 8*totalColor.z + 4*totalColor.w;
      totalColor.w = 9*totalColor.y + 9*totalColor.z + 5*totalColor.w;
   }

   return totalColor;
}


//--------------------------------------------------------------------------------------
// Techniques
//--------------------------------------------------------------------------------------
technique RenderScene
{
    pass P0
    {
        VertexShader = compile vs_3_0 VertScene();
        PixelShader  = compile ps_3_0 PixScene();
    }
}
