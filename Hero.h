#pragma once
#include "BasicObject.h"
#include "EventNotification.h"

class Hero
	: public BasicObject, public EventNotification
{
public:
	Hero(int x, int y, SDL_Surface* drawable);
	~Hero();
	void notifyEvent() override;

private:

};

