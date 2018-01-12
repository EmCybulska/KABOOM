#include "Player.h"



Player::Player(int x, int y, sf::Texture t) : _x(x), _y(y), _texture(t) 
{
	_speed = 1;
	_size = 25;
	_image = new sf::Sprite;
	_image->setTexture(_texture);
	_image->setPosition(_x, _y);
}


Player::~Player()
{
	delete _image;
}

void Player::setImage(sf::Texture t)
{
	_texture = t;
}

sf::Sprite* Player::getImage()
{
	return _image;
}

void Player::setSpeed(int n)
{
	_speed = n;
}

int Player::getSpeed()
{
	return _speed;
}

void Player::setPosition(int x, int y)
{
	_x = x;
	_y = y;
	_image->setPosition(_x, _y);
	
}

int Player::getX()
{
	_x = _image->getPosition().x;	
	return _x;

}

int Player::getY()
{
	_y = _image->getPosition().y;
	return _y;
}

int Player::getSize()
{
	return _size;
}
