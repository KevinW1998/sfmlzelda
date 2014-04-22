#pragma once
#include "stdafx.h"
#include "DrawableObject.h"

#define DOTYPE_FPS 3

class FPSCounter :
	public DrawableObject
{
public:
	FPSCounter();
	~FPSCounter();

	virtual void OnRender(sf::RenderWindow* renderer);
	virtual int getType();
	virtual void OnUpdate();

	int getFPS();

private:
	sf::Time lTime, diffTime;
	sf::Clock nowclock;
};

