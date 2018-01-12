#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class Player
{
private:
	int _x;
	int _y;
	int _speed;
	int _size;
	sf::Texture _texture;
	sf::Sprite *_image;
public:
	Player(int x, int y, sf::Texture t);
	~Player();
	void setImage(sf::Texture);
	sf::Sprite* getImage();
	void setSpeed(int n);
	int getSpeed();
	void setPosition(int x, int y);
	int getX();
	int getY();
	int getSize();
};

