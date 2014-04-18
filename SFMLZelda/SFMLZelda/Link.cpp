#include "stdafx.h"
#include "Link.h"


Link::Link() : Entity(false)
{
	//Init
	std::string spriteSheetPath = "images/Zelda_Links_Awakening_SpriteSheet.psd";
	sf::Image someImg;
	someImg.loadFromFile(spriteSheetPath);
}

Link::Link(int x, int y) : Entity(false,x,y)
{
	//Init
	std::string spriteSheetPath = "images/Zelda_Links_Awakening_SpriteSheet.psd";
	sf::Image someImg;
	someImg.loadFromFile(spriteSheetPath);
}


Link::~Link()
{
}

int Link::getType()
{
	return DOTYPE_LINK;
}
