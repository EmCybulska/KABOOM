#pragma once

#include <vector>
#include <SDL.h>

enum Image {
	MENU,
	GROUND1,
	GROUND2
};

class ImageHolder
{
public:
	
	virtual ~ImageHolder();
	SDL_Surface * getImage(Image i);
	static ImageHolder & getInstance();

private:
	ImageHolder();
	ImageHolder(const ImageHolder& copy) = delete;
	std::vector<SDL_Surface*> _images;

};

