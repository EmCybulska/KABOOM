#include "Program.h"
#include <SDL.h>
#include <iostream>
#include <cstdlib>


Program::Program()
{
}

Program::~Program()
{
	SDL_Quit();
}

bool Program::initialize()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
		return false;
	}

	_window = new Window();
	
	if (_window == NULL)
	{
		std::cout << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
		return false;
	}

	_map = new Map(15, 15);
	MapGenerator::generate(*_map);

	_eventManager.registerEvent(SDL_QUIT, _window);
	_eventManager.registerEvent(SDL_KEYDOWN, _window);

	return true;
}

void Program::draw()

{
	BasicObject*** m = _map->getMap();

	_window->draw(ImageHolder::getInstance().getImage(Image::BACKGROUND), SDL_Rect());
	
	for (int i = 0; i < 15; ++i) {
		for (int j = 0; j < 15; ++j) {
			BasicObject* b = m[i][j];
			_window->draw(b->getImage(), {b->getPosition().getX(), b->getPosition().getY(), 30, 30});
			SDL_Delay(10);
			_window->update();
		}
	}
	_window->update();

	while (true) {
		_eventManager.processEvents();
		Sleep(100);
	}
}
