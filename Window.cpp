#include "Window.h"
#include <SDL.h>
#include <iostream>
#include <cstdlib>

Window::Window(int w, int h) : _size(w, h)
{
	if (w < 0 || h < 0) {
		exit(-1);
	}

	_window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_SHOWN);
	if (_window == NULL)
	{
		std::cout << "Window could not be created! SDL_Error: " << SDL_GetError();
		system("pause");
		exit(-1);
	}

	_screenSurface = SDL_GetWindowSurface(_window);
}


Window::~Window()
{
	SDL_DestroyWindow( _window);
}

void Window::draw(SDL_Surface * image)
{

	SDL_BlitSurface(image, NULL, _screenSurface, NULL);

	SDL_UpdateWindowSurface(_window);

}


