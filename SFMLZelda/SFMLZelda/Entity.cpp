#include "StdAfx.h"
#include "Entity.h"


void Entity::init()
{
	dirAnim = new SpriteAnimation[4];

	sf::Image magImg;
	magImg.create(16,16,sf::Color::Magenta);

	sf::Image yeImg;
	yeImg.create(16,16,sf::Color::Yellow);

	sf::Image grImg;
	grImg.create(16,16,sf::Color::Green);

	sf::Image bluImg;
	bluImg.create(16,16,sf::Color::Blue);

	sf::Image redImg;
	redImg.create(16,16,sf::Color::Red);


	sf::Texture magTxt;
	magTxt.loadFromImage(magImg);

	sf::Texture yeTxt;
	yeTxt.loadFromImage(yeImg);

	sf::Texture grTxt;
	grTxt.loadFromImage(grImg);

	sf::Texture bluTxt;
	bluTxt.loadFromImage(bluImg);

	sf::Texture redTxt;
	redTxt.loadFromImage(redImg);

	textureBuf = std::vector<sf::Texture>::vector();
	textureBuf.push_back(magTxt);
	textureBuf.push_back(yeTxt);
	textureBuf.push_back(bluTxt);
	textureBuf.push_back(grTxt);
	textureBuf.push_back(redTxt);

	sf::Sprite aniBase(textureBuf[0]);
	sf::Sprite ySpr(textureBuf[1]);
	sf::Sprite eSpr(textureBuf[2]);
	sf::Sprite sSpr(textureBuf[3]);
	sf::Sprite wSpr(textureBuf[4]);

	aniBase.setPosition((float)screenX,(float)screenY);
	ySpr.setPosition((float)screenX, (float)screenY);
	eSpr.setPosition((float)screenX, (float)screenY);
	sSpr.setPosition((float)screenX, (float)screenY);
	wSpr.setPosition((float)screenX, (float)screenY);

	dirAnim[DIR_NORTH].addSprite(aniBase);
	dirAnim[DIR_NORTH].addSprite(ySpr);
	dirAnim[DIR_EAST].addSprite(aniBase);
	dirAnim[DIR_EAST].addSprite(eSpr);
	dirAnim[DIR_SOUTH].addSprite(aniBase);
	dirAnim[DIR_SOUTH].addSprite(sSpr);
	dirAnim[DIR_WEST].addSprite(aniBase);
	dirAnim[DIR_WEST].addSprite(wSpr);
}


Entity::Entity(bool genBaseAnimationSprite) : DrawableObject(),
	dir(1),
	animActive(false),
	usageOfExtraAnimation(false),
	currentExtraAnimation(0)
{
	if (genBaseAnimationSprite){
		init();
	}else{ //Only init vars
		textureBuf = std::vector<sf::Texture>::vector();
		dirAnim = new SpriteAnimation[4];
	}
}

Entity::Entity(bool genBaseAnimationSprite, int x, int y) : DrawableObject(x, y), 
	dir(1), 
	animActive(false),
	usageOfExtraAnimation(false),
	currentExtraAnimation(0)
{
	if (genBaseAnimationSprite){
		init();
	}else{ //Only init vars
		textureBuf = std::vector<sf::Texture>::vector();
		dirAnim = new SpriteAnimation[4];
	}
}


Entity::~Entity(void)
{
}

int Entity::getType()
{
	return DOTYPE_ENTITY;
}

int Entity::getDir()
{
	return dir;
}

void Entity::setDir(int dir)
{
	if(dir < 0 || dir > 3){
		return;
	}else{
		this->dir = dir;
	}
}

void Entity::OnRender(sf::RenderWindow* renderer)
{
	renderer->draw(dirAnim[dir].getCurrentSprite());
}

void Entity::OnUpdate()
{
	if(animActive){
		dirAnim[dir].nextFrame();
	}else{
		dirAnim[dir].setCurrentFrame(0);
	}
	dirAnim[dir].getCurrentSpritePointer()->setPosition((float)screenX, (float)screenY);
}

bool Entity::isAnimActive()
{
	return animActive;
}

void Entity::setAnimActive(bool isActive)
{
	animActive = isActive;
}

void Entity::OnWalkUp()
{
	screenY--;
}

void Entity::OnWalkRight()
{
	screenX++;
}

void Entity::OnWalkDown()
{
	screenY++;
}

void Entity::OnWalkLeft()
{
	screenX--;
}


bool Entity::isExtraAnimationActive(){
	return usageOfExtraAnimation;
}

void Entity::setExtraAnimationActive(bool isActive){
	usageOfExtraAnimation = isActive;
}

int Entity::getCurrentExtraAnimation(){
	return currentExtraAnimation;
}

void Entity::setCurrentExtraAnimation(int extraAnim){
	currentExtraAnimation = extraAnim;
}