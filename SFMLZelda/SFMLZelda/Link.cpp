#include "stdafx.h"
#include "Link.h"


void Link::init()
{
	std::string spriteSheetPath = "images/Zelda_Links_Awakening_SpriteSheet.psd";
	sf::Image spriteSheetImg;
	spriteSheetImg.loadFromFile(spriteSheetPath);

	//Link North Base Texture
	sf::Texture northBaseText;
	northBaseText.loadFromImage(spriteSheetImg, sf::IntRect(66, 6, 14, 16));

	//Link North Walk Texture
	sf::Texture northWalkText;
	northWalkText.loadFromImage(spriteSheetImg, sf::IntRect(81, 6, 14, 16));

	//Link South Base Texture
	sf::Texture southBaseText;
	southBaseText.loadFromImage(spriteSheetImg, sf::IntRect(36, 6, 14, 16));

	//Link South Walk Texture
	sf::Texture southWalkText;
	southWalkText.loadFromImage(spriteSheetImg, sf::IntRect(51, 6, 14, 16));

	//Link West Base Texture
	sf::Texture westBaseText;
	westBaseText.loadFromImage(spriteSheetImg, sf::IntRect(5, 6, 14, 16));

	//Link West Walk Texture
	sf::Texture westWalkText;
	westWalkText.loadFromImage(spriteSheetImg, sf::IntRect(21, 6, 14, 16));

	//Link East Base Texture
	sf::Texture eastBaseText;
	eastBaseText.loadFromImage(spriteSheetImg, sf::IntRect(109, 6, 14, 16));

	//Link East Walk Texture
	sf::Texture eastWalkText;
	eastWalkText.loadFromImage(spriteSheetImg, sf::IntRect(94, 6, 14, 16));

	textureBuf.push_back(northBaseText);
	textureBuf.push_back(northWalkText);
	textureBuf.push_back(eastBaseText);
	textureBuf.push_back(eastWalkText);
	textureBuf.push_back(southBaseText);
	textureBuf.push_back(southWalkText);
	textureBuf.push_back(westBaseText);
	textureBuf.push_back(westWalkText);

	sf::Sprite northBaseSpr(textureBuf[0]);
	sf::Sprite northWalkSpr(textureBuf[1]);
	sf::Sprite eastBaseSpr(textureBuf[2]);
	sf::Sprite eastWalkSpr(textureBuf[3]);
	sf::Sprite southBaseSpr(textureBuf[4]);
	sf::Sprite southWalkSpr(textureBuf[5]);
	sf::Sprite westBaseSpr(textureBuf[6]);
	sf::Sprite westWalkSpr(textureBuf[7]);

	northBaseSpr.setPosition((float)screenX, (float)screenY);
	northWalkSpr.setPosition((float)screenX, (float)screenY);
	eastBaseSpr.setPosition((float)screenX, (float)screenY);
	eastWalkSpr.setPosition((float)screenX, (float)screenY);
	southBaseSpr.setPosition((float)screenX, (float)screenY);
	southWalkSpr.setPosition((float)screenX, (float)screenY);
	westBaseSpr.setPosition((float)screenX, (float)screenY);
	westWalkSpr.setPosition((float)screenX, (float)screenY);


	dirAnim[DIR_NORTH].addSprite(northBaseSpr);
	dirAnim[DIR_NORTH].addSprite(northWalkSpr);
	dirAnim[DIR_EAST].addSprite(eastBaseSpr);
	dirAnim[DIR_EAST].addSprite(eastWalkSpr);
	dirAnim[DIR_SOUTH].addSprite(southBaseSpr);
	dirAnim[DIR_SOUTH].addSprite(southWalkSpr);
	dirAnim[DIR_WEST].addSprite(westBaseSpr);
	dirAnim[DIR_WEST].addSprite(westWalkSpr);
}

Link::Link() : Entity(false)
{
	//Init
	init();
}

Link::Link(int x, int y) : Entity(false,x,y)
{
	//Init
	init();
}


Link::~Link()
{
}

int Link::getType()
{
	return DOTYPE_LINK;
}


