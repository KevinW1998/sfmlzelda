#include "stdafx.h"
#include "Controllable.h"


Controllable::Controllable() : ImputConfiguration()
{
	keyWatchlist = std::vector<int>::vector();
}


Controllable::~Controllable()
{
}


void Controllable::OnKeyPressing(sf::Keyboard::Key key)
{

}

void Controllable::OnKeyDown(sf::Keyboard::Key key)
{

}

void Controllable::OnKeyUp(sf::Keyboard::Key key)
{

}

void Controllable::_OnKeyPressing(sf::Keyboard::Key key)
{

}

void Controllable::_OnKeyDown(sf::Keyboard::Key key)
{

}

void Controllable::_OnKeyUp(sf::Keyboard::Key key)
{

}

std::vector<int> Controllable::getWatchlist()
{
	return keyWatchlist;
}

