#pragma once
#include "drawableobject.h"
#include "SpriteAnimation.h"

#define DOTYPE_ENTITY 1


class Entity :
	public DrawableObject
{
public:
	Entity();
	Entity(int x, int y);


	~Entity(void);

	virtual int getType();
	virtual void OnRender(sf::RenderWindow* renderer);
	virtual void OnUpdate();
	virtual void OnWalkUp();
	virtual void OnWalkRight();
	virtual void OnWalkDown();
	virtual void OnWalkLeft();

	enum Dir{
		DIR_NORTH = 0,
		DIR_EAST,
		DIR_SOUTH,
		DIR_WEST
	};
	int getDir();
	void setDir(int dir);
	bool isAnimActive();
	void setAnimActive(bool isActive);

protected:
	SpriteAnimation* dirAnim;
	int dir;
	bool animActive;

	std::vector<sf::Texture> textureBuf;

private:
	void init();

};

