#include <iostream>
#include <thread>
#include <chrono>
#include <SFML/Graphics.hpp>
#include "ImageHolder.h"
#include "Player.h"
#include "Bomb.h"

enum GameState { MENU, GAME, GAME_OVER, END };
GameState state;

const int SCREEN_W = 1280;
const int SCREEN_H = 720;
const int TILE = 32;

int **map;
bool b1 = false;
bool b2 = false;
bool game = true;

Player *player1;
Player *player2;
Bomb *bomb1;
Bomb *bomb2;

sf::Clock timer1;
sf::Clock timer2;
sf::Font font;


void drawMenu(sf::RenderWindow *w);
void processEvents(sf::RenderWindow *w);
void generateMap();
void drawMap(sf::RenderWindow *w);
void movePlayer(sf::RenderWindow *w);
void explosion(sf::RenderWindow *w, Bomb *bomb);
void explosionEffects(Bomb *bomb);
void makeDamage(Player *p, int explosion_x, int explosion_y);
void gameOver(sf::RenderWindow *w);
void reset();
bool detectCollision(Player *p, int x, int y);



int main()
{

	sf::RenderWindow window(sf::VideoMode(SCREEN_W, SCREEN_H), "KABOOM!", sf::Style::Fullscreen);

	if (!font.loadFromFile("resources/Mecha.ttf"))
	{
		std::cout << "Font not found! ERROR\n";
		return -1;
	}

	while (window.isOpen()) {

		player1 = new Player(TILE + 5, TILE + 5, *ImageHolder::getInstance().getImage(Image::ROBOT1));
		player2 = new Player(SCREEN_W - 2 * TILE, SCREEN_H - 2 * TILE - 10, *ImageHolder::getInstance().getImage(Image::ROBOT2));
		player1->getImage()->setScale(0.4, 0.4);
		player2->getImage()->setScale(0.4, 0.4);
		bomb1 = new Bomb(player1->getX(), player1->getY());
		bomb2 = new Bomb(player2->getX(), player2->getY());

		generateMap();
		game = true;

		while (game)
		{
			switch (state)
			{
			case MENU: drawMenu(&window);
				break;
			case GAME: processEvents(&window);
				drawMap(&window);
				break;
			case GAME_OVER:
				gameOver(&window);
				break;
			case END: window.close();
				game = false;
				break;
			}
		}
		reset();

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
		map[y - 1][i] = Image::WALL1;
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

	//*player1->drawBombs(Window* window);
	/*
	for(...) {
	window->draw(bomby[i].draw()

	*/
	if (b1) {
		if (timer1.getElapsedTime().asSeconds() > 5) {
			explosion(win, bomb1);
			if (timer1.getElapsedTime().asSeconds() > 6) {
				explosionEffects(bomb1);
				player1->setBomb(1);
				b1 = false;
			}
		}
		else
			win->draw(*bomb1->getImage());
	}

	if (b2) {
		if (timer2.getElapsedTime().asSeconds() > 5) {
			explosion(win, bomb2);
			if (timer2.getElapsedTime().asSeconds() > 6) {
				explosionEffects(bomb2);
				player2->setBomb(1);
				b2 = false;
			}
		}
		else
			win->draw(*bomb2->getImage());
	}

	win->display();
}

void drawMenu(sf::RenderWindow * w)
{
	sf::Text title("KABOOM!", font, 80);
	title.setStyle(sf::Text::Bold);

	title.setPosition(SCREEN_W / 2 - title.getGlobalBounds().width / 2, 20);

	const int ile = 2;

	sf::Text tekst[ile];

	std::string str[] = { "Play","Exit" };

	for (int i = 0; i<ile; i++)
	{
		tekst[i].setFont(font);
		tekst[i].setCharacterSize(65);

		tekst[i].setString(str[i]);
		tekst[i].setPosition(SCREEN_W / 2 - tekst[i].getGlobalBounds().width / 2, 250 + i * 120);
	}

	while (state == MENU)
	{
		sf::Vector2f mouse(sf::Mouse::getPosition());
		sf::Event event;

		while (w->pollEvent(event))
		{
			//Wciœniêcie ESC lub przycisk X
			if (event.type == sf::Event::Closed)
				state = END;

			//klikniêcie EXIT
			if (tekst[1].getGlobalBounds().contains(mouse) &&
				event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
			{
				state = END;
			}

			if (tekst[0].getGlobalBounds().contains(mouse) &&
				event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
			{
				state = GAME;
			}
		}


		for (int i = 0; i<ile; i++)
			if (tekst[i].getGlobalBounds().contains(mouse))
				tekst[i].setFillColor(sf::Color::Cyan);
			else tekst[i].setFillColor(sf::Color::White);

			w->clear();

			w->draw(title);
			for (int i = 0; i<ile; i++)
				w->draw(tekst[i]);

			w->display();
	}
}

void processEvents(sf::RenderWindow *w)
{
	sf::Event e;
	while (w->pollEvent(e)) {
		if (e.type == sf::Event::Closed) {
			w->close();
		}
		if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Escape) {
			state = MENU;
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

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && player1->getBomb() > 0) {
		bomb1->setPosition(player1->getX(), player1->getY());
		b1 = true;
		player1->setBomb(-1);
		timer1.restart();
	}


	//Player 2
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && player2->getY() > 0
		&& detectCollision(player2, player2->getX(), player2->getY() - player2->getSpeed()) == false) {
		player2->getImage()->move(0, -player2->getSpeed());
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && player2->getX() > 0
		&& detectCollision(player2, player2->getX() - player2->getSpeed(), player2->getY()) == false) {
		player2->getImage()->move(-player2->getSpeed(), 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && player2->getY() < SCREEN_H - player2->getSize()
		&& detectCollision(player2, player2->getX(), player2->getY() + player2->getSpeed()) == false) {
		player2->getImage()->move(0, player2->getSpeed());
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && player2->getX() < SCREEN_W - player2->getSize()
		&& detectCollision(player2, player2->getX() + player2->getSpeed(), player2->getY()) == false) {
		player2->getImage()->move(player2->getSpeed(), 0);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return) && player2->getBomb() > 0) {
		bomb2->setPosition(player2->getX(), player2->getY());
		b2 = true;
		player2->setBomb(-1);
		timer2.restart();
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
	int x = ((bomb->getX() + TILE / 2) / TILE) * TILE; //pozycja na planszy
	int y = ((bomb->getY() + TILE / 2) / TILE) * TILE;

	//explosion animation
	bomb->setExplosionPos(x, y);
	win->draw(*bomb->getExplosion());

	makeDamage(player1, x, y);
	makeDamage(player2, x, y);

	int n = x / TILE;
	int tmp = x;
	for (int k = 0; k < bomb->getRange(); k++) //eksplozja na lewo od bomby
	{
		tmp -= TILE;
		n--;
		if (map[y / TILE][n] == Image::WALL1)
			break;

		bomb->setExplosionPos(tmp, y);
		makeDamage(player1, tmp, y);
		makeDamage(player2, tmp, y);
		win->draw(*bomb->getExplosion());
	}

	n = x / TILE;
	tmp = x;
	for (int k = 0; k < bomb->getRange(); k++) //eksplozja na prawo od bomby
	{
		tmp += TILE;
		n++;
		if (map[y / TILE][n] == Image::WALL1)
			break;

		bomb->setExplosionPos(tmp, y);
		makeDamage(player1, tmp, y);
		makeDamage(player2, tmp, y);
		win->draw(*bomb->getExplosion());
	}

	n = y / TILE;
	tmp = y;
	for (int k = 0; k < bomb->getRange(); k++) //eksplozja w górê od bomby
	{
		tmp -= TILE;
		n--;
		if (map[n][x / TILE] == Image::WALL1)
			break;

		bomb->setExplosionPos(x, tmp);
		makeDamage(player1, x, tmp);
		makeDamage(player2, x, tmp);
		win->draw(*bomb->getExplosion());
	}

	n = y / TILE;
	tmp = y;
	for (int k = 0; k < bomb->getRange(); k++) //eksplozja w dó³ od bomby
	{
		tmp += TILE;
		n++;
		if (map[n][x / TILE] == Image::WALL1)
			break;

		bomb->setExplosionPos(x, tmp);
		makeDamage(player1, x, tmp);
		makeDamage(player2, x, tmp);
		win->draw(*bomb->getExplosion());
	}

}

void explosionEffects(Bomb *bomb)
{
	int x = ((bomb->getX() + TILE / 2) / TILE) * TILE;
	int y = ((bomb->getY() + TILE / 2) / TILE) * TILE;

	int n = x / TILE;
	for (int k = 0; k < bomb->getRange(); k++) //eksplozja na lewo od bomby
	{
		n--;
		if (map[y / TILE][n] == Image::WALL1)
			break;
		map[y / TILE][n] = Image::GROUND1;
	}

	n = x / TILE;
	for (int k = 0; k < bomb->getRange(); k++) //eksplozja na prawo od bomby
	{
		n++;
		if (map[y / TILE][n] == Image::WALL1)
			break;
		map[y / TILE][n] = Image::GROUND1;
	}

	n = y / TILE;
	for (int k = 0; k < bomb->getRange(); k++) //eksplozja w górê od bomby
	{
		n--;
		if (map[n][x / TILE] == Image::WALL1)
			break;

		map[n][x / TILE] = Image::GROUND1;
	}

	n = y / TILE;
	for (int k = 0; k < bomb->getRange(); k++) //eksplozja w dó³ od bomby
	{
		n++;
		if (map[n][x / TILE] == Image::WALL1)
			break;

		map[n][x / TILE] = Image::GROUND1;
	}
}

void makeDamage(Player *p, int explosion_x, int explosion_y)
{
	int x = ((p->getX() + TILE / 2) / TILE) * TILE;
	int y = ((p->getY() + TILE / 2) / TILE) * TILE;

	if (x == explosion_x && y == explosion_y) {
		p->setLife(-1);
		state = GameState::GAME_OVER;
	}
}

void gameOver(sf::RenderWindow *w)
{
	std::string str;
	if (player1->getLife() == 0)
		str = "The Winner is Player 2!";
	else if (player2->getLife() == 0)
		str = "The Winner is Player 1!";


	sf::Text text(str, font, 80);
	text.setStyle(sf::Text::Bold);
	text.setPosition(SCREEN_W / 2 - text.getGlobalBounds().width / 2, 50);
	text.setFillColor(sf::Color::Red);

	sf::Text text2("Press ESC to return to the menu", font, 65);
	text2.setPosition(SCREEN_W / 2 - text.getGlobalBounds().width / 2, 500);
	text2.setFillColor(sf::Color::White);
	
	w->clear();
	w->draw(text);
	w->draw(text2);
	w->display();

	while (state == GAME_OVER) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			game = false;
			return;
		}
	}
}

void reset()
{
	delete player1;
	delete player2;
	delete bomb1;
	delete bomb2;

	int x = SCREEN_W / TILE;
	int y = SCREEN_H / TILE;

	timer1.restart();
	timer2.restart();

	for (int i = 0; i < y; i++) {
		delete[] map[i];
	}

	delete[] map;

	b1 = false;
	b2 = false;

	state = GameState::MENU;

}