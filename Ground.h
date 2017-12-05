#pragma once
#include "BasicObject.h"
class Ground : public BasicObject
{
public:
	Ground(int x, int y, SDL_Surface* drawable);
	~Ground();
};

