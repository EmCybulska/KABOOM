#include <iostream>
#include <cstdlib>
#include "Program.h"
#include <SDL.h>

int main(int argc, char ** argv)
{
	Program p;

	if (p.initialize())
	{
		p.draw();		
	}
	system("pause");
	return 0;
}