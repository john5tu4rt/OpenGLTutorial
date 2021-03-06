#include "MainGame.h"
#include "Errors.h"
#include "ImageLoader.h"

#include <string>
#include <iostream>


MainGame::MainGame() : m_window(nullptr),
					m_screenWidth(1024),
					m_screenHeight(768),
					m_gameState(GameState::PLAY),
					m_time(0.0f){
}


MainGame::~MainGame() {

}

void MainGame::run() {
	initSystems();

	//Temp sprite init
	m_sprite.init(-1.f, -1.f, 2.f, 2.f); // full window sprite

	//Temp PNG Load
	m_playerTexture = ImageLoader::loadPNG("Textures/PNG/CharacterLeft_Walk2.png");

	gameLoop();
}

void MainGame::initShaders() {
	m_colorProgram.compileShaders("Shaders/colorShader.vert", "Shaders/colorShader.frag");
	m_colorProgram.addAttribute("vertexPosition");
	m_colorProgram.addAttribute("vertexColor");
	m_colorProgram.addAttribute("vertexUV");
	m_colorProgram.linkShaders();
}

void MainGame::initSystems() {

	// Initialize SDL

	SDL_Init(SDL_INIT_EVERYTHING);

	m_window = SDL_CreateWindow("Game Engine",
								SDL_WINDOWPOS_CENTERED,
								SDL_WINDOWPOS_CENTERED,
								m_screenWidth,
								m_screenHeight,
								SDL_WINDOW_OPENGL);
	if (m_window == nullptr) {
		fatalError("SDL Window could not be created");
	}

	// If successful create Open GL context

	SDL_GLContext glContext = SDL_GL_CreateContext(m_window);
	if (glContext == nullptr) {
		fatalError("SDL_GLContext could not be created");
	}

	// If successful initialize glew (useful for hardware compatibility)
	GLenum error = glewInit();
	if (error != GLEW_OK) {
		fatalError("Could not initialize glew");
	}

	// If successful initialize buffer to have 2 window buffers, 1 to draw to and 1 to clear
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	// Set background color
	glClearColor(0.f, 0.f, 0.f, 0.f);

	//Initialise Shaders
	initShaders();
}

void MainGame::gameLoop() {
	while (m_gameState != GameState::EXIT) {
		m_time += 0.01f; // timestep
		processInput();
		drawGame();
	}
}

void MainGame::processInput() {
	SDL_Event evnt;
	while (SDL_PollEvent(&evnt)) {
		switch (evnt.type) {
		case SDL_QUIT:
			m_gameState = GameState::EXIT;
			break;
		case SDL_MOUSEMOTION:
			std::cout << evnt.motion.x << " " << evnt.motion.y << '\n';
			break;
		}
	}
}

void MainGame::drawGame() {
	glClearDepth(1.f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clear both color and depth buffers	

	m_colorProgram.use();
	glActiveTexture(GL_TEXTURE0); //can do mutiple textures for same object
	glBindTexture(GL_TEXTURE_2D, m_playerTexture.id);

	//send uniform texture location to GPU
	GLint textureLocation = m_colorProgram.getUniformLocation("mySampler");
	glUniform1i(textureLocation, 0);

	//send uniform time variable to GPU, commented out as time is no longer used in gpu compilation
	//GLuint timeLocation = m_colorProgram.getUniformLocation("time");	
	//glUniform1f(timeLocation, m_time);

	m_sprite.draw();

	glBindTexture(GL_TEXTURE_2D, 0);
	m_colorProgram.unuse();

	// after complete swap buffers
	SDL_GL_SwapWindow(m_window);
}
