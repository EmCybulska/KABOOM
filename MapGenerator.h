#pragma once

#include <cstdint>

class MapGenerator
{
public:
	MapGenerator(uint8_t x = 12, uint8_t y = 12);
	virtual ~MapGenerator();
	void generate();

private:
	uint8_t _mapSize_x;
	uint8_t _mapSize_y;
};

