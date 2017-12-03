#include "ImageHolder.h"



ImageHolder::ImageHolder()
{
	_images.push_back(SDL_LoadBMP("menu.bmp"));
	_images.push_back(SDL_LoadBMP("1.bmp"));
	_images.push_back(SDL_LoadBMP("2.bmp"));
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
