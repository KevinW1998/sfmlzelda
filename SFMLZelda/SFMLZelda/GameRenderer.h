#pragma once
#include "StdAfx.h"
#include "DrawableObject.h"
class GameRenderer
{
public:
	GameRenderer(sf::RenderWindow* rWindow);
	~GameRenderer(void);

	void Begin();
	void End();

	sf::RenderWindow* getNative();
	
	void RenderDrawableObject(DrawableObject* dao);


private:
	sf::RenderWindow* m_nativeRenderer;
};

