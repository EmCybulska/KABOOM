#include "ImageHolder.h"



ImageHolder::ImageHolder()
{
	_imagesMap[Image::MENU] = addImage("menu.png");
}

sf::Texture * ImageHolder::addImage(std::string fileName)
{
	sf::Texture * t;
	std::string s = "resources/" + fileName;
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
