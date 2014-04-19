#pragma once
#include "drawableobject.h"
#include "SpriteAnimation.h"

#define DOTYPE_ENTITY 1


class Entity :
	public DrawableObject
{
public:
	Entity(bool genBaseAnimationSprite);
	Entity(bool genBaseAnimationSprite, int x, int y);


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

	bool isExtraAnimationActive();
	void setExtraAnimationActive(bool isActive);

	int getCurrentExtraAnimation();
	void setCurrentExtraAnimation(int extraAnim);

	int getMaxFrameTime();
	void setMaxFrameTime(int framesUntilSwitch);

	void beginUpdate();
	void endUpdate();

	//If a methode want to check before sending a update call....
	bool canUpdate();
	void forceToUpdate();

protected:
	SpriteAnimation* dirAnim;
	std::vector<SpriteAnimation*> extraAnim;
	bool usageOfExtraAnimation;
	int currentExtraAnimation;

	//Frame Options
	int maxFrameTime;
	int frameTimer;
	bool forceUpdate;

	int dir;
	bool animActive;

	std::vector<sf::Texture> textureBuf;

private:
	void init();

};

