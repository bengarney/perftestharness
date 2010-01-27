const int numSamples = 4;
const int numDependent = 4;
sampler2D RandomTexture;


void VertScene( float4 vPos : POSITION, float2 tc : TEXCOORD0,
                out float2 oTc : TEXCOORD0,
                out float4 oPos : POSITION)
{
    oPos = vPos;
    oTc = tc;
}


float4 PixScene( float4 out0 : COLOR0, float2 tc : TEXCOORD0 ) : COLOR0
{
   float4 totalColor = float4(0,0,0,0);

   for(int i=0; i<numSamples; i++)
   {
      float4 tmp = float4(tc.x + float(i)/256.0,tc.y + float(i)/256.0,0,0);
      for(int j=0; j<numDependent; j++)
         tmp = tex2D(RandomTexture, tmp.xy);
      totalColor += tmp;
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
