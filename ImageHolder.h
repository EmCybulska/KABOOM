#pragma once

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <vector>
#include <iostream>

enum Image {
	MENU,
	LEVEL1,
	GROUND1,
	BACKGROUND,
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
	sf::Texture* addImage(std::string path);
};
