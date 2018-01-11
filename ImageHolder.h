#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <vector>
#include <iostream>

enum Image {
	MENU,
	BOMB,
	ROBOT1,
	ROBOT2,
	GROUND1,
	WALL1,
	BLOCK1
	
};

class ImageHolder
{
public:

	virtual ~ImageHolder();
	sf::Texture * getImage(Image i);
	static ImageHolder & getInstance();

private:
	ImageHolder();
	ImageHolder(const ImageHolder& copy) = delete;
	std::unordered_map<Image, sf::Texture*> _imagesMap;
	sf::Texture* addImage(std::string fileName);
};
