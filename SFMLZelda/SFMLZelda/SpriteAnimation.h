#pragma once
#include <vector>
class SpriteAnimation
{
public:
	SpriteAnimation();
	SpriteAnimation(std::vector<sf::Sprite> list);
	~SpriteAnimation();

	//Loop Management
	int getCurrentFrame();
	sf::Sprite getCurrentSprite();
	sf::Sprite* getCurrentSpritePointer();
	void setCurrentFrame(int curFrame);
	void nextFrame();

	//Sprite Data Management
	void addSprite(sf::Sprite spriteFrame);
	void deleteSprite(int pos);
	void clearSpriteList();
	

private:
	std::vector<sf::Sprite> spriteList;
	int currentFrame;

};

