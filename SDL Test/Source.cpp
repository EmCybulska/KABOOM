
#include <iostream>
#include <SDL.h>

using namespace std;

const int WIDTH = 640;
const int HEIGHT = 480;

SDL_Window* window;
SDL_Surface* winSurface;
SDL_Surface* image1;
SDL_Surface* image2;
SDL_Surface* hero;


int main(int argc, char** args) {

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		cout << "Error initializing SDL: " << SDL_GetError() << endl;
		system("pause");
		return false;
	}

	window = SDL_CreateWindow("Example", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
		WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
	if (!window) {
		cout << "Error creating window: " << SDL_GetError() << endl;
		system("pause");
		return false;
	}

	winSurface = SDL_GetWindowSurface(window);
	if (!winSurface) {
		cout << "Error getting surface: " << SDL_GetError() << endl;
		system("pause");
		return false;
	}

	image1 = SDL_LoadBMP("test1.bmp");
	image2 = SDL_LoadBMP("test2.bmp");
	hero = SDL_LoadBMP("hero.bmp");

	if (!image1 || !image2) {
		cout << "Error converting surface: " << SDL_GetError() << endl;
		system("pause");
		return false;
	}

	SDL_BlitSurface(image1, NULL, winSurface, NULL);



	SDL_Rect dest;
	dest.x = 0;
	dest.y = 0;
	dest.w = 30;
	dest.h = 30;

	SDL_BlitScaled(hero, NULL, winSurface, &dest);


	int shift = 30;

	for (int i = 0; i < HEIGHT/shift; i++) {
		for (int j = 0; j < WIDTH/shift; j++) {
			SDL_BlitScaled(image2, NULL, winSurface, &dest);
			SDL_UpdateWindowSurface(window);
			SDL_Delay(10);
			dest.x += shift ;
		}
		dest.y += shift;
		dest.x = 0;
	}

	dest.x = WIDTH/2;
	dest.y = HEIGHT/2;
	dest.w = 30;
	dest.h = 30;

	SDL_BlitScaled(hero, NULL, winSurface, &dest);
	SDL_UpdateWindowSurface(window);

	SDL_Event e;
	bool quit = false;
	int speed = 10;

	while (!quit)
	{
		//Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{
			//User requests quit
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
			//User presses a key
			else if (e.type == SDL_KEYDOWN)
			{
				//Select surfaces based on key press
				switch (e.key.keysym.sym)
				{
				case SDLK_UP:
					SDL_BlitScaled(hero, NULL, winSurface, &dest);
					dest.y -= speed;
					break;

				case SDLK_DOWN:
					SDL_BlitScaled(hero, NULL, winSurface, &dest);
					dest.y += speed;
					break;

				case SDLK_LEFT:
					SDL_BlitScaled(hero, NULL, winSurface, &dest);
					dest.x -= speed;
					break;

				case SDLK_RIGHT:
					SDL_BlitScaled(hero, NULL, winSurface, &dest);
					dest.x += speed;
					break;

				default:
				
					break;
				}
			}
		}

		//Update the surface
		SDL_UpdateWindowSurface(window);
	}

	


	system("pause");

	SDL_FreeSurface(image1);
	SDL_FreeSurface(image2);

	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}