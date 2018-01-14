#include "Bomb.h"



Bomb::Bomb(int x, int y) : _x(x), _y(y)
{
	_image = new sf::Sprite;
	_image->setTexture(*ImageHolder::getInstance().getImage(Image::BOMB));
	_image->setScale(0.3, 0.3);
	_image->setPosition(_x, _y);
	_explosion = new sf::Sprite;
	_explosion->setTexture(*ImageHolder::getInstance().getImage(Image::EXPLOSION));
	_range = 3;
	_damage = 10;
}


Bomb::~Bomb()
{
	delete _image;
	delete _explosion;
}

sf::Sprite * Bomb::getImage()
{
	return _image;
}

sf::Sprite * Bomb::getExplosion()
{
	return _explosion;
}

int Bomb::getRange()
{
	return _range;
}

int Bomb::getX()
{
	_x = _image->getPosition().x;
	return _x;

}

int Bomb::getY()
{
	_y = _image->getPosition().y;
	return _y;
}

void Bomb::setPosition(int x, int y)
{
	_x = x;
	_y = y;
	_image->setPosition(_x, _y);

}
