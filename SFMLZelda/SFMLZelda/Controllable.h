#pragma once
#include "stdafx.h"
#include "ImputConfiguration.h"
class Controllable : public ImputConfiguration
{
public:
	
	Controllable();
	~Controllable();

	//non virutal functions
	void _OnKeyPressing(sf::Keyboard::Key key);
	void _OnKeyDown(sf::Keyboard::Key key);
	void _OnKeyUp(sf::Keyboard::Key key);

	virtual void OnKeyPressing(sf::Keyboard::Key key);
	virtual void OnKeyDown(sf::Keyboard::Key key);
	virtual void OnKeyUp(sf::Keyboard::Key key);

	bool isKeyPressed(sf::Keyboard::Key key);

	//common key functions here
	std::vector<int> getWatchlist();

protected:
	std::vector<int> keyWatchlist;
};

