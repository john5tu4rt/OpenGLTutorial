#version 130

//The vertex shader operates on each vertex

//input data from the VBO. Each vertex is 2 floats
in vec2 vertexPosition;
//4 color bytes
in vec4 vertexColor;

out vec4 fragmentColor;

void main() {
	//set the xy position on screen
	gl_Position.xy = vertexPosition;  //xy together is known as swizzeling, compiler knows to use x first and then y from vertexPosition
	//set z = 0 as we are 2D	
	gl_Position.z = 0.0;
	//Indicate that the coordinates are normalised
	gl_Position.w = 1.0;

	//set the fragment color from the passed vertexcolor data
	fragmentColor = vertexColor;
}