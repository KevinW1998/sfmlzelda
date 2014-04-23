#pragma once
#include "stdafx.h"
class Controllable
{
public:
	
	Controllable();
	~Controllable();

	//non virutal functions
	void _OnKeyPressing(sf::Keyboard key);
	void _OnKeyDown(sf::Keyboard key);
	void _OnKeyUp(sf::Keyboard key);

	virtual void OnKeyPressing(sf::Keyboard key);
	virtual void OnKeyDown(sf::Keyboard key);
	virtual void OnKeyUp(sf::Keyboard key);

	//common key functions here

};

