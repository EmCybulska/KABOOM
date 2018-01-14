#pragma once
#include <SFML/Graphics.hpp>
#include "ImageHolder.h"

class Bomb
{
private:
	int _x;
	int _y;
	int _range;
	int _damage;
	sf::Sprite *_image;
	sf::Sprite *_explosion;

public:
	Bomb(int x, int y);
	~Bomb();
	sf::Sprite* getImage();
	sf::Sprite* getExplosion();
	int getRange();
	int getX();
	int getY();
	void setPosition(int x, int y);
};

