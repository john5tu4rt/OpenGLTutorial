#version 130
//The fragment shader operates on each pixel in a given polygon

in vec4 fragmentColor;
in vec2 fragmentPosition;
in vec2 fragmentUV;

//This is the 4 component (rgba) float vector that gets drawn to screen for each pixel
out vec4 color;

//passing time to the shader
uniform float time;
//passing texture to the shader
uniform sampler2D mySampler; //shitty name for learning purposes
//passing uv data


void main(){
	
	//texture uses UV coords. "lookup my texture by these coords"
	vec4 textureColor = texture(mySampler, fragmentUV);

	//Makes colors vary with time and position
	//color = vec4(fragmentColor.r * (cos(fragmentPosition.x * 4.0 + time) + 1.0) * 0.5,
	//			 fragmentColor.g * (cos(fragmentPosition.y * 8.0 + time) + 1.0) * 0.5,
	//			 fragmentColor.b * (cos(fragmentPosition.x * 2.0 + time) + 1.0) * 0.5,
	//			 fragmentColor.a);

	color = textureColor * fragmentColor; //color blending (one of many ways)
}