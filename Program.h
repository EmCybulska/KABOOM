#pragma once

#include <iostream>
#include <SDL.h>
#include "Window.h"

class Program {
public:
	Program();
	virtual ~Program();
	bool initialize();
	bool loadMedia();
	void draw();


private:
	Window * _window;
	SDL_Surface * _image;
};

