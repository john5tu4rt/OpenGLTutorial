#pragma once

#include <SDL\SDL.h>
#include <GL\glew.h>

class MainGame {
public:
	MainGame();
	~MainGame();

	void run();

	void initSystems();

private:
	SDL_Window* m_window;
	int m_screenWidth;
	int m_screenHeight;
};

