#include "Window.h"
#include <SDL.h>
#include <iostream>
#include <cstdlib>

Window::Window(int w, int h) : SCREEN_WIDTH(w), SCREEN_HEIGHT(h)
{
	if (w < 0 || h < 0) {
		exit(-1);
	}

	createWindow();
}


Window::~Window()
{
	delete _window;
	delete _screenSurface;
}

void Window::draw(SDL_Surface * image)
{

	SDL_BlitSurface(image, NULL, _screenSurface, NULL);

	SDL_UpdateWindowSurface(_window);

}

void Window::createWindow()
{
	_window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	_screenSurface = SDL_GetWindowSurface(_window);
}


