#pragma once

#include <unordered_map>
#include <vector>
#include <SFML/Window.hpp>
#include "EventNotification.h"
#include "Window.h"

class EventManager
{
public:
	EventManager();
	virtual ~EventManager();
	void processEvents();
	void registerEvent(sf::Event e, EventNotification * handler);
private:
	//std::unordered_map<sf::Event, std::vector<EventNotification*>> _eventMap;
};

