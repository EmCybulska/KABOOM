#pragma once

#include <iostream>
#include <SDL.h>
#include "Point.h"
#include "EventNotification.h"

class Window : public EventNotification
{

public:

	Window(int w = 640, int h = 480);
	virtual ~Window();

	void draw(SDL_Surface * image, SDL_Rect dest);
	void update();
	void notifyEvent() override;

private:

	SDL_Window * _window;
	SDL_Surface * _screenSurface;
	
	Point _size;
};

