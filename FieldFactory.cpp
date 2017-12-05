#include "FieldFactory.h"



FieldFactory::FieldFactory()
{
}


FieldFactory::~FieldFactory()
{
}

BasicObject* FieldFactory::get(Block b, int x, int y)
{
	ImageHolder &holder = ImageHolder::getInstance();
	switch(b) 
	{
	case Block::GROUND :
		return new Ground(x, y, holder.getImage(Image::GROUND1));

	default: 
		return new Ground(x, y, holder.getImage(Image::GROUND1));
	
	}
}
