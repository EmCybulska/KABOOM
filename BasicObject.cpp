#include "BasicObject.h"

BasicObject::BasicObject(Point p, sf::Texture t)
{
	_pos = p;
	_t = t;
}

BasicObject::BasicObject(int x, int y, sf::Texture t)
{
	_pos = { x, y };
	_t = t;
}

sf::Texture BasicObject::getTexture()
{
	return _t;
}

Point BasicObject::getPosition()
{
	return _pos;
}
