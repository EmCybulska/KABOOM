#include "BasicObject.h"

BasicObject::BasicObject(Point p, SDL_Surface * i)
{
	_pos = p;
	_image = i;
}

BasicObject::BasicObject(int x, int y, SDL_Surface * i) 
{
	_pos = { x, y };
	_image = i;
}

SDL_Surface * BasicObject::getImage()
{
	return _image;
}

Point BasicObject::getPosition()
{
	return _pos;
}

