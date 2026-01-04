
//const int iMaxKernelSize = 25;
//const int iActKernelSize = 9;

//uniform vec2 vKernelOffsets[iActKernelSize];
//uniform float vKernelValues[iActKernelSize];

uniform sampler2D sampler0;

varying vec4 vtxPosition;

const float GreenFid = 5.0 / 255.0;
const float YellowFid = 15.0 / 255.0;
const float RedFid = 25.0 / 255.0;
const float PinkFid = 35.0 / 255.0;

vec4 getColor(vec4 samplerColor)
{
//	if (vtxPosition[0] == 0.5)
//	{
//		return vec4(1.0, 1.0, 1.0, 1.0);	
//	}

	if (samplerColor[0] > PinkFid) 
	{
		return vec4(1.0, 0.0, 1.0, 1.0);	
	}
	if (samplerColor[0] > RedFid)
	{
		return vec4(1.0, 0.0, 0.0, 1.0);	
	}
	if (samplerColor[0] > YellowFid) // red cloud
	{
		return vec4(1.0, 1.0, 0.0, 1.0);	
	}
	if (samplerColor[0] > GreenFid) // red cloud
	{
		return vec4(0.0, 1.0, 0.0, 1.0);	
	}

	return vec4(0.0, 0.0, 0.0, 1.0);
}


void main(void)
{	
//	int		i;
//	vec4	sumColor = vec4(0.0, 0.0, 0.0, 0.0);
//
//	for (i = 0; i < iActKernelSize; ++i)
//	{
//		vec4 tmp = texture2D(sampler0, gl_TexCoord[0].st + vKernelOffsets[i]);
//		sumColor += tmp * vKernelValues[i];
//	}
	vec4 tmp = texture2D(sampler0, gl_TexCoord[0].st);
	gl_FragColor = getColor(tmp);
}
