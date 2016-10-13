#include "MainGame.h"



MainGame::MainGame() : m_window(nullptr), m_screenWidth(1024), m_screenHeight(768) {
}


MainGame::~MainGame() {
}

void MainGame::run() {
	initSystems();
}

void MainGame::initSystems() {
	SDL_Init(SDL_INIT_EVERYTHING);

	m_window = SDL_CreateWindow("Game Engine",
								SDL_WINDOWPOS_CENTERED,
								SDL_WINDOWPOS_CENTERED,
								m_screenWidth,
								m_screenHeight,
								SDL_WINDOW_OPENGL);
}
