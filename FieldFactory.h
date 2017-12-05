#pragma once

#include "Ground.h"
#include "ImageHolder.h"
#include <iostream>

enum Block {
	GROUND,

};

class FieldFactory
{
public:
	FieldFactory();
	virtual ~FieldFactory();
	static BasicObject* get(Block b, int x, int y);

};

