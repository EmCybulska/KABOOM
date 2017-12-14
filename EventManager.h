#pragma once

#include <SDL.h>
#include <unordered_map>
#include <vector>
#include "EventNotification.h"

class EventManager {
public:
	EventManager();
	virtual ~EventManager();
	void processEvents();
	void registerEvent(SDL_EventType e, EventNotification *handler);

private:
	std::unordered_map<SDL_EventType, std::vector<EventNotification*>> _eventMap;

};
