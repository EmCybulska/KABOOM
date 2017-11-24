#include <iostream>
#include <cstdlib>
#include "Program.h"
#include <SDL.h>
#include "Window.h"

int main(int argc, char ** argv)
{
	Program start;

	if (start.initialize())
	{
		if (start.loadMedia()) {
			start.draw();
		}
	}
	system("pause");
	return 0;
}