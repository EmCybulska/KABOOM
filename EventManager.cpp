#include "EventManager.h"

EventManager::EventManager()
{
}

EventManager::~EventManager()
{
}

void EventManager::processEvents()
{
	SDL_Event event;
	
	while (SDL_PollEvent(&event) != 0) {		
		for (const auto& e : _eventMap[(SDL_EventType) event.type]) {
			e->notifyEvent();
		}
		//User presses a key
		//else if (e.type == SDL_KEYDOWN)
		//{
			//Select surfaces based on key press
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
}

void EventManager::registerEvent(SDL_EventType e, EventNotification * handler)
{
	_eventMap[e].push_back(handler);
}
