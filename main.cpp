#include <iostream>
#include <SFML/Graphics.hpp>
#include <time.h>
#include "ImageHolder.h"
#include "Player.h"
#include "Bomb.h"

const int SCREEN_W = 800;
const int SCREEN_H = 576;
const int TILE = 32;

int **map;
bool b1 = false;
bool b2 = false;
Player *player1;
Player *player2;
Bomb *bomb1;
Bomb *bomb2;

void processEvents(sf::RenderWindow *w);
void generateMap();
void drawMap(sf::RenderWindow *w);
void movePlayer(sf::RenderWindow *w);
void explosion(sf::RenderWindow *w);
bool detectCollision(Player *p, int x, int y);

int main()
{
	sf::RenderWindow window(sf::VideoMode(SCREEN_W, SCREEN_H), "KABOOM!");
	player1 = new Player(TILE + 5, TILE + 5, *ImageHolder::getInstance().getImage(Image::ROBOT1));
	player2 = new Player(SCREEN_W - 2 * TILE, SCREEN_H - 2 * TILE, *ImageHolder::getInstance().getImage(Image::ROBOT2));
	player1->getImage()->setScale(0.4, 0.4);
	player2->getImage()->setScale(0.4, 0.4);
	bomb1 = new Bomb(player1->getX(), player1->getY());
	bomb2 = new Bomb(player2->getX(), player2->getY());
	generateMap();
	//s.setTexture(*ImageHolder::getInstance().getImage(Image::MENU));

	int counter = 0;

	while (window.isOpen()) {
		counter++;
		if(counter % 20 == 0)
			processEvents(&window);
			drawMap(&window);
	}

	return 0;
}

void generateMap()
{
	srand(time(NULL));

	int x = SCREEN_W / TILE;
	int y = SCREEN_H / TILE;

	map = new int*[y];
	for (int i = 0; i < y; i++) {
		map[i] = new int[x];
	}

	for (int i = 0; i < y; ++i) {
		for (int j = 0; j < x; ++j) {
			map[i][j] = Image::GROUND1;
		}
	}

	for (int i = 0; i < y; ++i) {
		for (int j = 0; j < x; ++j) {
			if (rand() % 4 == 0)
				map[i][j] = Image::WALL1;
			if (rand() % 3 == 0)
				map[i][j] = Image::BLOCK1;
		}
	}

	for (int i = 0; i < x; ++i) {
		map[0][i] = Image::WALL1;
		map[y-1][i] = Image::WALL1;	
	}

	for (int i = 0; i < y; ++i) {
		map[i][0] = Image::WALL1;
		map[i][x - 1] = Image::WALL1;
	}

	map[1][2] = map[2][1] = map[1][1] = Image::GROUND1;
	map[y - 3][x - 2] = map[y - 2][x - 2] = map[y - 2][x - 3] = Image::GROUND1;
}

void drawMap(sf::RenderWindow *win) {

	
	int w = SCREEN_W / TILE;
	int h = SCREEN_H / TILE;
	int x = 0;
	int y = 0;

	sf::Sprite s;
	s.setOrigin(0, 0);
	s.scale(0.5, 0.5);

	win->clear();

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			x = j * TILE;
			s.setTexture(*ImageHolder::getInstance().getImage((Image)(map[i][j])));
			s.setPosition(x, y);
			win->draw(s);
		}
		x = 0;
		y = (i + 1) * TILE;

	}

	win->draw(*player1->getImage());
	win->draw(*player2->getImage());
	if (b1)
		win->draw(*bomb1->getImage());
	if (b2)
		win->draw(*bomb2->getImage());
	win->display();
}

void processEvents(sf::RenderWindow *w)
{
	sf::Event e;
	while (w->pollEvent(e)) {
		if (e.type == sf::Event::Closed) {
			w->close();
		}
		movePlayer(w);
	}
}

void movePlayer(sf::RenderWindow *w) 
{
	//Player 1
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && player1->getY() > 0 &&
		detectCollision(player1, player1->getX(), player1->getY() - player1->getSpeed()) == false) {
		player1->getImage()->move(0, -player1->getSpeed());
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && player1->getX() > 0 
		&& detectCollision(player1, player1->getX() - player1->getSpeed(), player1->getY()) == false) {
		player1->getImage()->move(-player1->getSpeed(), 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && player1->getY() < SCREEN_H - player1->getSize()
		&& detectCollision(player1, player1->getX(), player1->getY() + player1->getSpeed()) == false) {
		player1->getImage()->move(0, player1->getSpeed());
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && player1->getX() < SCREEN_W - player1->getSize() 
		&& detectCollision(player1, player1->getX() + player1->getSpeed(), player1->getY()) == false) {
		player1->getImage()->move(player1->getSpeed(), 0);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) && player1->getBomb() > 0) {
		bomb1->setPosition(player1->getX(), player1->getY());
		b1 = true;
		player1->setBomb(-1);
	}


	//Player 2
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::I) && player2->getY() > 0 
		&& detectCollision(player2, player2->getX(), player2->getY() - player2->getSpeed()) == false) {
		player2->getImage()->move(0, -player2->getSpeed());
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::J) && player2->getX() > 0 
		&& detectCollision(player2, player2->getX() - player2->getSpeed(), player2->getY()) == false) {
		player2->getImage()->move(-player2->getSpeed(), 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::K) && player2->getY() < SCREEN_H - player2->getSize()
		&& detectCollision(player2, player2->getX(), player2->getY() + player2->getSpeed()) == false) {
		player2->getImage()->move(0, player2->getSpeed());
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::L) && player2->getX() < SCREEN_W - player2->getSize()
		&& detectCollision(player2, player2->getX() + player2->getSpeed(), player2->getY()) == false) {
		player2->getImage()->move(player2->getSpeed(), 0);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::O) && player2->getBomb() > 0) {
		bomb2->setPosition(player2->getX(), player2->getY());
		b2 = true;
		player2->setBomb(-1);
	}
}

bool detectCollision(Player *p, int x, int y)
{
	int w = SCREEN_W / TILE;
	int h = SCREEN_H / TILE;
	int tile_x = 0;
	int tile_y = 0;

	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			tile_x = j * TILE;
			if (map[i][j] == Image::BLOCK1 || map[i][j] == Image::WALL1) {
				if (x < tile_x + TILE && x + p->getSize() > tile_x &&
					y < tile_y + TILE && y + p->getSize() > tile_y) {
					return true;
				}
			}
		}
		
		tile_x = 0;
		tile_y = (i + 1) * TILE;
	}
	return false;
}

void explosion(sf::RenderWindow *win, Bomb *bomb)
{
	int w = SCREEN_W / TILE;
	int h = SCREEN_H / TILE;
	int x = 0;
	int y = 0;

	int i = 0;
	for (i = 0; i < w; i++) {
		x = i * TILE;
		if (bomb->getX() < x)
			break;	
	}

	int j;
	for (j = 0; j < h; j++) {
		y = j * TILE;
		if (bomb->getY() < y)
			break;
	}


}