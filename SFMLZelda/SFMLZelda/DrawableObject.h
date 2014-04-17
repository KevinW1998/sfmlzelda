#pragma once
#include "stdafx.h"
#define DOTYPE_BASE 0

class DrawableObject
{
public:

	
	DrawableObject();
	DrawableObject(int x, int y);
	~DrawableObject();

	virtual void OnRender(sf::RenderWindow* renderer);

	void setVisible(bool isVisible);
	bool isVisible();
	virtual int getType();

protected:
	int screenX;
	int screenY;
	bool visible;
};

