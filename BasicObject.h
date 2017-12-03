#pragma once

#include <SDL.h>
#include "Point.h"

class BasicObject
{
public:

	virtual ~BasicObject();
	SDL_Surface * getImage();

protected:

	BasicObject(Point p, SDL_Surface * i);
	BasicObject(int x, int y, SDL_Surface * i);

private:

	Point _pos;
	SDL_Surface * _image;
};

