#pragma once

#include <iostream>
#include <SDL.h>
#include "Point.h"

class Window
{

public:

	Window(int w = 640, int h = 480);
	virtual ~Window();

	void draw(SDL_Surface * image, SDL_Rect dest);
	void update();
	void scaleImage(SDL_Surface *image, int w, int h, int x, int y);

private:

	SDL_Window * _window;
	SDL_Surface * _screenSurface;
	
	Point _size;
};

