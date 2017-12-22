#pragma once

#include <SFML/Graphics.hpp>

class Window
{
public:
	Window(int w = 800, int h = 600);
	virtual ~Window();
	bool isOpen();
	void display();

private:
	sf::RenderWindow* _window;

};

