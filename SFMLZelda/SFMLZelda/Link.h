#pragma once
#include "stdafx.h"
#include "Entity.h"

#define DOTYPE_LINK 2

class Link :
	public Entity
{
public:
	Link();
	Link(int x, int y);
	~Link();

	virtual int getType();
};

