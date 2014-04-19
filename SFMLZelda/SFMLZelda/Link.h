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

	enum extraAnimList {
		ANIM_SWORDHIT_EAST = 0
	};

	virtual int getType();
	virtual void OnRender(sf::RenderWindow* renderer);
	virtual void OnUpdate();

private:
	void init();
};

