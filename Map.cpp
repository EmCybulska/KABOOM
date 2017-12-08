#include "Map.h"



Map::Map(int x, int y)
{
	_size = Point(x, y);
	_map = new BasicObject**[y];
	for (int i = 0; i < y; i++) {
		_map[i] = new BasicObject*[x];
	}
}

Map::~Map()
{
}

BasicObject *** Map::getMap()
{
	return _map;
}
	