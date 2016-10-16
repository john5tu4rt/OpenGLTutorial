#version 130
//The fragment shader operates on each pixel in a given polygon

in vec4 fragmentColor;

//This is the 4 component (rgba) float vector that gets drawn to screen for each pixel
out vec4 color;

uniform float time;

void main(){
	color = fragmentColor + vec4((cos(time)+1.0)*0.5, (cos(time + 2.0) + 1.0) * 0.5, (sin(time + 1.0) + 1.0) * 0.5, 0.0);
}