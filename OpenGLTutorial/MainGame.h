#pragma once

#include <SDL\SDL.h>
#include <GL\glew.h>

#include "Sprite.h"
#include "GLSLProgram.h"
#include "GLTexture.h"

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

	void initShaders();
	void initSystems();
	void gameLoop();
	void processInput();
	void drawGame();

	SDL_Window* m_window;
	int m_screenWidth;
	int m_screenHeight;
	GameState m_gameState;
	float m_time;

	Sprite m_sprite;
	GLTexture m_playerTexture;

	GLSLProgram m_colorProgram;
};

