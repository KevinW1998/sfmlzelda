#include "StdAfx.h"
#include "SpriteAnimation.h"


SpriteAnimation::SpriteAnimation() : 
	currentFrame( 0 )
{
	spriteList = std::vector<sf::Sprite>::vector();
}

SpriteAnimation::SpriteAnimation(std::vector<sf::Sprite> list) :
	currentFrame( 0 )
{
	spriteList = list;
}


SpriteAnimation::~SpriteAnimation()
{
	
}

int SpriteAnimation::getCurrentFrame()
{
	return currentFrame;
}

sf::Sprite SpriteAnimation::getCurrentSprite()
{
	return spriteList[currentFrame];
}

sf::Sprite* SpriteAnimation::getCurrentSpritePointer()
{
	return &spriteList[currentFrame];
}


void SpriteAnimation::setCurrentFrame(int curFrame)
{
	currentFrame = curFrame;
}

void SpriteAnimation::addSprite(sf::Sprite spriteFrame)
{
	spriteList.push_back(spriteFrame);
}



void SpriteAnimation::clearSpriteList()
{
	spriteList.clear();
}

void SpriteAnimation::nextFrame()
{
	int s = spriteList.size();
	if(s-1 <= currentFrame){
		currentFrame = 0;
	}else{
		currentFrame++;
	}
}

void SpriteAnimation::deleteSprite(int pos)
{
	if(pos >= (int)spriteList.size() || pos < 0){
		return;
	}else{
		spriteList.erase(spriteList.begin()+pos);
	}
}
