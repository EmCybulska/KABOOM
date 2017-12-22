#pragma once

#include <SFML/Graphics.hpp>
#include "Point.h"


class BasicObject
{
public:
	virtual ~BasicObject() = default;
	sf::Texture getTexture(); //zamiast textury pewnie tu bêd¹ sprajty
	Point getPosition();
protected:
	BasicObject(Point p, sf::Texture t);
	BasicObject(int x, int y, sf::Texture t);
private:
	Point _pos;
	sf::Texture _t;
};

