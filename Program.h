#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Window.h"

class Program
{
public:
	Program();
	virtual ~Program();
	void init();
	void run();
private:
	Window * _window;
};

