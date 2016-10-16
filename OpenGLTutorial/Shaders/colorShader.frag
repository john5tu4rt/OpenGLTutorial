#version 130
//The fragment shader operates on each pixel in a given polygon

in vec4 fragmentColor;
in vec2 fragmentPosition;

//This is the 4 component (rgba) float vector that gets drawn to screen for each pixel
out vec4 color;

uniform float time;

void main(){
	color = vec4(fragmentColor.r * (cos(fragmentPosition.x * 4.0 + time) + 1.0) * 0.5,
				 fragmentColor.g * (cos(fragmentPosition.y * 8.0 + time) + 1.0) * 0.5,
				 fragmentColor.b * (cos(fragmentPosition.x * 2.0 + time) + 1.0) * 0.5,
				 fragmentColor.a);
}