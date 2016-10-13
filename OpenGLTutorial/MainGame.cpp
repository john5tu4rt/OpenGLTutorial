#include "MainGame.h"

#include <string>
#include <iostream>

void fatalError(std::string errorString) {
	std::cout << errorString << '\n' << "Enter any key to quit" << '\n';
	int tmp;
	std::cin >> tmp;
	SDL_Quit();
	exit(1);
}

MainGame::MainGame() : m_window(nullptr),
					m_screenWidth(1024),
					m_screenHeight(768),
					m_gameState(GameState::PLAY){
}


MainGame::~MainGame() {
}

void MainGame::run() {
	initSystems();
	gameLoop();
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

}

void MainGame::gameLoop() {
	while (m_gameState != GameState::EXIT) {
		processInput();
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
