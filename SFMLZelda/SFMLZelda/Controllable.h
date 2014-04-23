#pragma once
#include "stdafx.h"
class Controllable
{
public:
	
	Controllable();
	~Controllable();

	virtual void OnKeyPressing(sf::Keyboard key);
	virtual void OnKeyDown(sf::Keyboard key);
	virtual void OnKeyUp(sf::Keyboard key);

private:
	bool keySpacePressed;
	bool keyUpPressed;
	bool keyDownPressed;
	bool keyRightPressed;
	bool keyLeftPressed;
};

