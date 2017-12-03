#pragma once

#include <vector>
#include <SDL.h>

enum Image {
	MENU,
	IMG1,
	IMG2
};

class ImageHolder
{
public:
	ImageHolder();
	virtual ~ImageHolder();

	SDL_Surface * getImage(Image i);

private:
	std::vector<SDL_Surface*> _images;
};

