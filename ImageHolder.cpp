#include "ImageHolder.h"



ImageHolder::ImageHolder()
{
	_images.push_back(SDL_LoadBMP("resources/images/menu.bmp"));
	_images.push_back(SDL_LoadBMP("resources/images/ground1.bmp"));
	_images.push_back(SDL_LoadBMP("resources/images/background.bmp"));
	_images.push_back(SDL_LoadBMP("resources/images/ground3.bmp"));
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
