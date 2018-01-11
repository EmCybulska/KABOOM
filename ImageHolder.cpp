#include "ImageHolder.h"



ImageHolder::ImageHolder()
{
	_imagesMap[Image::MENU] = addImage("menu.png");
	_imagesMap[Image::BOMB] = addImage("bomb.png");
	_imagesMap[Image::ROBOT1] = addImage("robot1.png");
	_imagesMap[Image::ROBOT2] = addImage("robot2.png");
	_imagesMap[Image::GROUND1] = addImage("ground1.png");
	_imagesMap[Image::WALL1] = addImage("wall1.png");
	_imagesMap[Image::BLOCK1] = addImage("block1.png");
}

sf::Texture * ImageHolder::addImage(std::string fileName)
{
	sf::Texture * t = new sf::Texture;
	std::string s = "resources/images/" + fileName;
	t->loadFromFile(s);
	return t;
}


ImageHolder::~ImageHolder()
{
}

sf::Texture * ImageHolder::getImage(Image i)
{
	return _imagesMap[i];
}

ImageHolder & ImageHolder::getInstance()
{
	static ImageHolder instance;
	return instance;
}