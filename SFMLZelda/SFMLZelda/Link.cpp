#include "stdafx.h"
#include "Link.h"


Link::Link() : Entity(false)
{
	//Init
}

Link::Link(int x, int y) : Entity(false,x,y)
{
	//Init
}


Link::~Link()
{
}

int Link::getType()
{
	return DOTYPE_LINK;
}
