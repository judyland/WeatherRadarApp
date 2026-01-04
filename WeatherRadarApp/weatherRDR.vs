
varying vec4 vtxPosition;



void main(void)
{
	gl_Position = ftransform();
	//gl_Position[1] = 0;
	//vtxPosition = gl_ModelViewProjectionMatrix * gl_Vertex;
	vtxPosition = gl_Vertex;	
	gl_FrontColor = gl_Color;
	gl_TexCoord[0] = gl_MultiTexCoord0;
	
}
