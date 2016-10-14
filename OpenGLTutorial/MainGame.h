#pragma once

#include "Sprite.h"

#include <SDL\SDL.h>
#include <GL\glew.h>

enum class GameState {
	PLAY,
	EXIT,
};

class MainGame {
public:
	MainGame();
	~MainGame();

	void run();	

private:

	void initSystems();
	void gameLoop();
	void processInput();
	void drawGame();

	SDL_Window* m_window;
	int m_screenWidth;
	int m_screenHeight;
	GameState m_gameState;

	Sprite m_sprite;
};

