#pragma once

#include <cstdint>

class Map
{
public:
	Map(uint8_t w, uint8_t h);
	virtual ~Map();
	void draw();
private:
	std::uint8_t _x;
	std::uint8_t _y;
};

