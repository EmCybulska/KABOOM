#pragma once

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Bomb.h"

class Player
{
private:
	int _x;
	int _y;
	int _speed;
	int _size;
	int _bomb;
	int _hp;
	sf::Texture _texture;
	sf::Sprite *_image;
	//std::vector<Bomb> *vec;
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
	void setBomb(int n);
	int getBomb();
	void newBomb();
};

