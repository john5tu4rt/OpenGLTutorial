#version 130
//The fragment shader operates on each pixel in a given polygon

in vec4 fragmentColor;

//This is the 4 component (rgba) float vector that gets drawn to screen for each pixel
out vec4 color;

void main(){
	color = fragmentColor;
}