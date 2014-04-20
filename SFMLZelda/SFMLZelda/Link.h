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
		ANIM_SWORDHIT_EAST = 0,
		ANIM_SWORDHIT_WEST,
		ANIM_SWORDHIT_NORTH,
		ANIM_SWORDHIT_SOUTH
	};

	virtual int getType();
	virtual void OnRender(sf::RenderWindow* renderer);
	virtual void OnUpdate();
	virtual void OnWalkUp();
	virtual void OnWalkRight();
	virtual void OnWalkDown();
	virtual void OnWalkLeft();
	virtual void OnSyncSprite();

private:
	void init();

	bool usingNonMoveableAnimation();
};

