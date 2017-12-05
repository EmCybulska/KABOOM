#include "ImageHolder.h"



ImageHolder::ImageHolder()
{
	_images.push_back(SDL_LoadBMP("Resources/Images/menu.bmp"));
	_images.push_back(SDL_LoadBMP("Resources/Images/ground1.bmp"));
	_images.push_back(SDL_LoadBMP("Resources/Images/ground2.bmp"));
	_images.push_back(SDL_LoadBMP("Resources/Images/ground3.bmp"));
}


ImageHolder::~ImageHolder()
{
	for (SDL_Surface * i : _images) {
		SDL_FreeSurface(i);
	}
}

SDL_Surface * ImageHolder::getImage(Image i)
{
	return _images[i];
}

ImageHolder & ImageHolder::getInstance()
{
	static ImageHolder instance;
	return instance;
}
