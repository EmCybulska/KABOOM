#include "EventManager.h"



EventManager::EventManager()
{
}


EventManager::~EventManager()
{
}

void EventManager::processEvents()
{
	//sf::Event event;

	//_window.pollEvent(event);

	/*while (true) {
		for (const auto& e : _eventMap[event.type]) {
			e->notifyEvent();
		}
	}*/
}

void EventManager::registerEvent(sf::Event e, EventNotification * handler) 
{
	//_eventMap[e].push_back(handler);
}
