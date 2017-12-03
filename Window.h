#pragma once

#include <iostream>
#include <SDL.h>
#include "Point.h"

class Window
{

public:

	Window(int w = 640, int h = 415);
	virtual ~Window();

	void draw(SDL_Surface * image);

private:

	SDL_Window * _window;
	SDL_Surface * _screenSurface;
	
	Point _size;
};

