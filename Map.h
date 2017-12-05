#pragma once

#include "Point.h"
#include "BasicObject.h"

class Map
{
	friend class MapGenerator;

public:
	Map(int x, int y);
	virtual ~Map();

private:
	Point _size;
	BasicObject **_map;
};

