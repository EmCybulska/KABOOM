#include "Program.h"
#include <SDL.h>
#include <iostream>
#include <cstdlib>


Program::Program()
{
}

Program::~Program()
{
	SDL_Quit();
}

bool Program::initialize()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
		return false;
	}

	_window = new Window();
	
	if (_window == NULL)
	{
		std::cout << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
		return false;
	}

	return true;
}

void Program::draw()
{
	_window->draw(_image.getImage(Image::MENU));
}
