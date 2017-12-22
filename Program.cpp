#include "Program.h"



Program::Program()
{
}


Program::~Program()
{
}

void Program::init()
{
	_window = new Window();
	
}

void Program::run()
{
	while(_window->isOpen())
	{
		_window->display();
	}

}
