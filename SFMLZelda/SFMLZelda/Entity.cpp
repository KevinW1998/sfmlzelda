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
	currentExtraAnimation(0),
	maxFrameTime(1),
	frameTimer(0),
	speed(1)
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
	currentExtraAnimation(0),
	maxFrameTime(1),
	frameTimer(0),
	speed(1)
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
	if (dir < 0 || dir > 3){
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
	if (canUpdate()){
		if (animActive){
			dirAnim[dir].nextFrame();
		}
		else{
			dirAnim[dir].setCurrentFrame(0);
		}
		OnSyncSprite();
	}
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
	if (canUpdate()){
		screenY -= speed;
	}
}

void Entity::OnWalkRight()
{
	if (canUpdate()){
		screenX += speed;
	}
}

void Entity::OnWalkDown()
{
	if (canUpdate()){
		screenY += speed;
	}
}

void Entity::OnWalkLeft()
{
	if (canUpdate()){
		screenX -= speed;
	}
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
	if (currentExtraAnimation != extraAnim || !usageOfExtraAnimation){
		resetCurrentExtraAnimation();
	}
	currentExtraAnimation = extraAnim;
}

int Entity::getMaxFrameTime()
{
	return maxFrameTime;
}

void Entity::setMaxFrameTime(int framesUntilSwitch)
{
	maxFrameTime = framesUntilSwitch;
}

void Entity::beginUpdate()
{
	frameTimer++;
}

void Entity::endUpdate()
{
	if (frameTimer == maxFrameTime){
		frameTimer = 0;
	}
}

bool Entity::canUpdate()
{
	return frameTimer == maxFrameTime;
}

void Entity::OnSyncSprite()
{
	if (usageOfExtraAnimation){
		extraAnim[currentExtraAnimation]->getCurrentSpritePointer()->setPosition(screenX, screenY);
	}else{
		dirAnim[dir].getCurrentSpritePointer()->setPosition((float)screenX, (float)screenY);
	}
}

sf::Vector2i Entity::getPlayerPosition()
{
	return sf::Vector2i(mapPos.x, mapPos.y);
}

void Entity::resetCurrentExtraAnimation()
{
	extraAnim[currentExtraAnimation]->setCurrentFrame(0);
}

int Entity::getSpeed()
{
	return speed;
}

void Entity::setSpeed(int speed)
{
	this->speed = speed;
}
