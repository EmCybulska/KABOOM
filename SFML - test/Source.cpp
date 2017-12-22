#include <SFML/Graphics.hpp>
#include <time.h>

const int SCREEN_W = 1024;
const int SCREEN_H = 512;
const int TILE = 32;

class TileMap : public sf::Drawable, public sf::Transformable
{
public:

	bool load(const std::string& tileset, sf::Vector2u tileSize, int* tiles, unsigned int width, unsigned int height)
	{
		// load the tileset texture
		if (!m_tileset.loadFromFile(tileset))
			return false;

		// resize the vertex array to fit the level size
		m_vertices.setPrimitiveType(sf::Quads);
		m_vertices.resize(width * height * 4);

		// populate the vertex array, with one quad per tile
		for (unsigned int i = 0; i < width; ++i)
			for (unsigned int j = 0; j < height; ++j)
			{
				// get the current tile number
				int tileNumber = tiles[i + j * width];

				// find its position in the tileset texture
				int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
				int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);

				// get a pointer to the current tile's quad
				sf::Vertex* quad = &m_vertices[(i + j * width) * 4];

				// define its 4 corners
				quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
				quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
				quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
				quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

				// define its 4 texture coordinates
				quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
				quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
				quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
				quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
			}

		return true;
	}

private:

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		// apply the transform
		states.transform *= getTransform();

		// apply the tileset texture
		states.texture = &m_tileset;

		// draw the vertex array
		target.draw(m_vertices, states);
	}

	sf::VertexArray m_vertices;
	sf::Texture m_tileset;
};

int main()
{
	// create the window
	sf::RenderWindow window(sf::VideoMode(SCREEN_W, SCREEN_H), "Tilemap");

	//// define the level with an array of tile indices
	//const int level[] =
	//{
	//	0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	//	0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0,
	//	1, 1, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3,
	//	0, 1, 0, 0, 2, 0, 3, 3, 3, 0, 1, 1, 1, 0, 0, 0,
	//	0, 1, 1, 0, 3, 3, 3, 0, 0, 0, 1, 1, 1, 2, 0, 0,
	//	0, 0, 1, 0, 3, 0, 2, 2, 0, 0, 1, 1, 1, 1, 2, 0,
	//	2, 0, 1, 0, 3, 0, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1,
	//	0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1,
	//};

	//rand tiles
	srand(time(NULL));

	int* level = new int[((SCREEN_W / TILE)*(SCREEN_H / TILE))];

	for (int i = 0; i < ((SCREEN_W / TILE)*(SCREEN_H / TILE)); i++)
		level[i] = rand() % 3;


	// create the tilemap from the level definition
	TileMap map;
	if (!map.load("tileset1.png", sf::Vector2u(TILE, TILE), level, (SCREEN_W / TILE), (SCREEN_H / TILE)))
		return -1;
	//hero
	sf::Texture image;
	image.loadFromFile("robo3.png");
	sf::Sprite hero;
	hero.setTexture(image);
	hero.setOrigin(16, 20);
	hero.setPosition((SCREEN_W / 2), (SCREEN_H / 2));


	//bomb
	sf::Texture image2;
	sf::Sprite bomb;
	image2.loadFromFile("bomb.png");
	bomb.setTexture(image2);
	bomb.setScale(0.0625, 0.0625);
	bomb.setOrigin(16, 16);


	int speed = 10;

	// run the main loop
	while (window.isOpen())
	{
		// handle events
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up)
			{
				hero.move(0, -speed);
			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down)
			{
				hero.move(0, speed);
			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right)
			{
				hero.move(speed, 0);
			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left)
			{
				hero.move(-speed, 0);
			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
			{
				sf::Vector2f pos = hero.getPosition() - bomb.getOrigin();
				bomb.setPosition(pos);
			}
		}

		// draw the map
		window.clear();
		window.draw(map);
		window.draw(hero);
		window.draw(bomb);
		window.display();
	}

	return 0;
}