#include "Errors.h"
#include <iostream>
#include <SDL\SDL.h>


void fatalError(std::string errorString) {
	std::cout << errorString << '\n' << "Enter any key to quit" << '\n';
	int tmp;
	std::cin >> tmp;
	SDL_Quit(); //cleanup SDL
	exit(1);
}
