#include "MapGenerator.h"

void MapGenerator::generate(Map & map)
{
	for (int i = 0; i < map._size.getY(); ++i) {
		for (int j = 0; j < map._size.getX(); ++j) {
			map._map[i][j] = FieldFactory::get(Block::GROUND, 30*j, 30*i);
		}
	}
}