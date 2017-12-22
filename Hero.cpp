#include "Hero.h"



Hero::Hero(int x, int y, SDL_Surface* drawable) : BasicObject(x, y, drawable)
{
}


Hero::~Hero()
{
}

void Hero::notifyEvent()
{
	//switch (e.key.keysym.sym)
	//{
	//case SDLK_UP:
	//	SDL_BlitScaled(image2, NULL, winSurface, &dest);
	//	dest.y -= speed;
	//	SDL_BlitScaled(hero, NULL, winSurface, &dest);
	//	break;
	//
	//case SDLK_DOWN:
	//	SDL_BlitScaled(image2, NULL, winSurface, &dest);
	//	dest.y += speed;
	//	SDL_BlitScaled(hero, NULL, winSurface, &dest);
	//	break;
	//
	//case SDLK_LEFT:
	//	SDL_BlitScaled(image2, NULL, winSurface, &dest);
	//	dest.x -= speed;
	//	SDL_BlitScaled(hero, NULL, winSurface, &dest);
	//	break;
	//
	//case SDLK_RIGHT:
	//	SDL_BlitScaled(image2, NULL, winSurface, &dest);
	//	dest.x += speed;
	//	SDL_BlitScaled(hero, NULL, winSurface, &dest);
	//	break;
	//
	//default:
	//	break;
	//}
}
