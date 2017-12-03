#include <iostream>
#include <cstdlib>
#include "Program.h"
#include <SDL.h>

int main(int argc, char ** argv)
{
	Program start;

	if (start.initialize())
	{
		start.draw();		
	}
	system("pause");
	return 0;
}