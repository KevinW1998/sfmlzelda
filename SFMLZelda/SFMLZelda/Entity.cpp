#include "StdAfx.h"
#include "Entity.h"


void Entity::init()
{
	dirAnim = new SpriteAnimation[4];

	sf::Image blImg;
	blImg.create(16,16,sf::Color::Black);

	sf::Image yeImg;
	yeImg.create(16,16,sf::Color::Yellow);

	sf::Image grImg;
	grImg.create(16,16,sf::Color::Green);

	sf::Image bluImg;
	bluImg.create(16,16,sf::Color::Blue);

	sf::Image redImg;
	redImg.create(16,16,sf::Color::Red);


	sf::Texture blTxt;
	blTxt.loadFromImage(blImg);

	sf::Texture yeTxt;
	yeTxt.loadFromImage(yeImg);

	sf::Texture grTxt;
	grTxt.loadFromImage(grImg);

	sf::Texture bluTxt;
	bluTxt.loadFromImage(bluImg);

	sf::Texture redTxt;
	redTxt.loadFromImage(redImg);

	textureBuf = std::vector<sf::Texture>::vector();
	textureBuf.push_back(blTxt);
	textureBuf.push_back(yeTxt);
	textureBuf.push_back(bluTxt);
	textureBuf.push_back(grTxt);
	textureBuf.push_back(redTxt);

	sf::Sprite aniBase(textureBuf[0]);
	sf::Sprite ySpr(textureBuf[1]);
	sf::Sprite eSpr(textureBuf[2]);
	sf::Sprite sSpr(textureBuf[3]);
	sf::Sprite wSpr(textureBuf[4]);

	aniBase.setPosition(screenX,screenY);
	ySpr.setPosition(screenX,screenY);
	eSpr.setPosition(screenX,screenY);
	sSpr.setPosition(screenX,screenY);
	wSpr.setPosition(screenX,screenY);

	dirAnim[DIR_NORTH].addSprite(aniBase);
	dirAnim[DIR_NORTH].addSprite(ySpr);
	dirAnim[DIR_EAST].addSprite(aniBase);
	dirAnim[DIR_EAST].addSprite(eSpr);
	dirAnim[DIR_SOUTH].addSprite(aniBase);
	dirAnim[DIR_SOUTH].addSprite(sSpr);
	dirAnim[DIR_WEST].addSprite(aniBase);
	dirAnim[DIR_WEST].addSprite(wSpr);
}


Entity::Entity() : DrawableObject(), dir(1), animActive(false)
{
	init();
}

Entity::Entity(int x, int y) : DrawableObject(x,y), dir(1), animActive(false)
{
	init();
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

void Entity::Render(sf::RenderWindow* renderer)
{
	renderer->draw(dirAnim[dir].getCurrentSprite());
}

void Entity::Update()
{
	if(animActive){
		dirAnim[dir].nextFrame();
		if(dir == DIR_NORTH){
			screenY--;
		}else if(dir == DIR_EAST){
			screenX++;
		}else if(dir == DIR_SOUTH){
			screenY++;
		}else if(dir == DIR_WEST){
			screenX--;
		}
	}else{
		dirAnim[dir].setCurrentFrame(0);
	}
	dirAnim[dir].getCurrentSpritePointer()->setPosition(screenX,screenY);
}

bool Entity::isAnimActive()
{
	return animActive;
}

void Entity::setAnimActive(bool isActive)
{
	animActive = isActive;
}
