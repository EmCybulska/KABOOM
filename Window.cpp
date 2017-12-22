#include "Window.h"



Window::Window(int w, int h)
{
	_window = new sf::RenderWindow();
	_window->create(sf::VideoMode(w, h), "KABOOM!");
}


Window::~Window()
{
}

bool Window::isOpen()
{
	if (!_window) {
		return false;
	}

	return _window->isOpen();
}

void Window::display()
{
	_window->display();
}


