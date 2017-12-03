#pragma once

#include <iostream>
#include <SDL.h>
#include "Window.h"
#include "ImageHolder.h"

class Program {
public:
	Program();
	virtual ~Program();
	bool initialize();
	void draw();


private:
	Window * _window;
	ImageHolder _image;
};

