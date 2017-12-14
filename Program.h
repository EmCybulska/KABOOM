#pragma once

#include <iostream>
#include <SDL.h>
#include "Window.h"
#include "ImageHolder.h"
#include "Map.h"
#include "MapGenerator.h"
#include "EventManager.h"
#include <Windows.h>

class Program {
public:
	Program();
	virtual ~Program();
	bool initialize();
	void draw();

private:
	Window * _window;
	Map *_map;
	EventManager _eventManager;
};

