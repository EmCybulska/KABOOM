#pragma once

#include <iostream>
#include <SDL.h>

class Window
{
private:
	SDL_Window * _window;
	SDL_Surface * _screenSurface;

	const int SCREEN_WIDTH;
	const int SCREEN_HEIGHT;

	void createWindow();

public:
	Window(int w = 640, int h = 415);
	virtual ~Window();

	void draw(SDL_Surface * image);
};

