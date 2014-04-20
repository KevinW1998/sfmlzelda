#include "stdafx.h"
#include "Link.h"


void Link::init()
{
	std::string spriteSheetPath = "images/Zelda_Links_Awakening_SpriteSheet-Correction.psd";
	sf::Image spriteSheetImg;
	spriteSheetImg.loadFromFile(spriteSheetPath);

	//Link North Base Texture
	sf::Texture northBaseText;
	northBaseText.loadFromImage(spriteSheetImg, sf::IntRect(66, 6, 14, 16));

	//Link North Walk Texture
	sf::Texture northWalkText;
	northWalkText.loadFromImage(spriteSheetImg, sf::IntRect(80, 6, 14, 16));

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

	//Link East Hit Texture 1
	sf::Texture eastHitText1;
	eastHitText1.loadFromImage(spriteSheetImg, sf::IntRect(41, 107, 15, 31));

	//Link East Hit Texture 2
	sf::Texture eastHitText2;
	eastHitText2.loadFromImage(spriteSheetImg, sf::IntRect(63, 107 , 27, 31));

	//Link East Hit Texture 3
	sf::Texture eastHitText3;
	eastHitText3.loadFromImage(spriteSheetImg, sf::IntRect(94, 107, 30, 31));

	//Link West Hit Texture 1
	sf::Texture westHitText1;
	westHitText1.loadFromImage(spriteSheetImg, sf::IntRect(197, 107, 15, 31));

	//Link West Hit Texture 2
	sf::Texture westHitText2;
	westHitText2.loadFromImage(spriteSheetImg, sf::IntRect(164, 107, 27, 31));

	//Link West Hit Texture 3
	sf::Texture westHitText3;
	westHitText3.loadFromImage(spriteSheetImg, sf::IntRect(130, 107, 30, 31));

	//Link South Hit Texture 1
	sf::Texture southHitText1;
	southHitText1.loadFromImage(spriteSheetImg, sf::IntRect(31, 145, 30, 32));

	//Link South Hit Texture 2
	sf::Texture southHitText2;
	southHitText2.loadFromImage(spriteSheetImg, sf::IntRect(69, 145, 26, 32));

	//Link South Hit Texture 3
	sf::Texture southHitText3;
	southHitText3.loadFromImage(spriteSheetImg, sf::IntRect(102, 145, 15, 32));


	textureBuf.push_back(northBaseText);
	textureBuf.push_back(northWalkText);
	textureBuf.push_back(eastBaseText);
	textureBuf.push_back(eastWalkText);
	textureBuf.push_back(southBaseText);
	textureBuf.push_back(southWalkText);
	textureBuf.push_back(westBaseText);
	textureBuf.push_back(westWalkText);

	textureBuf.push_back(eastHitText1);
	textureBuf.push_back(eastHitText2);
	textureBuf.push_back(eastHitText3);

	textureBuf.push_back(westHitText1);
	textureBuf.push_back(westHitText2);
	textureBuf.push_back(westHitText3);

	textureBuf.push_back(southHitText1);
	textureBuf.push_back(southHitText2);
	textureBuf.push_back(southHitText3);

	sf::Sprite northBaseSpr(textureBuf[0]);
	sf::Sprite northWalkSpr(textureBuf[1]);
	sf::Sprite eastBaseSpr(textureBuf[2]);
	sf::Sprite eastWalkSpr(textureBuf[3]);
	sf::Sprite southBaseSpr(textureBuf[4]);
	sf::Sprite southWalkSpr(textureBuf[5]);
	sf::Sprite westBaseSpr(textureBuf[6]);
	sf::Sprite westWalkSpr(textureBuf[7]);

	sf::Sprite EastHit1Spr(textureBuf[8]);
	sf::Sprite EastHit2Spr(textureBuf[9]);
	sf::Sprite EastHit3Spr(textureBuf[10]);

	sf::Sprite westHit1Spr(textureBuf[11]);
	sf::Sprite westHit2Spr(textureBuf[12]);
	sf::Sprite westHit3Spr(textureBuf[13]);

	sf::Sprite southHit1Spr(textureBuf[14]);
	sf::Sprite southHit2Spr(textureBuf[15]);
	sf::Sprite southHit3Spr(textureBuf[16]);


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

	SpriteAnimation* eastHit = new SpriteAnimation();
	eastHit->addSprite(EastHit1Spr);
	eastHit->addSprite(EastHit2Spr);
	eastHit->addSprite(EastHit3Spr);
	extraAnim.push_back(eastHit);
	
	SpriteAnimation* westHit = new SpriteAnimation();
	westHit->addSprite(westHit1Spr);
	westHit->addSprite(westHit2Spr);
	westHit->addSprite(westHit3Spr);
	extraAnim.push_back(westHit);

	SpriteAnimation* southHit = new SpriteAnimation();
	southHit->addSprite(southHit1Spr);
	southHit->addSprite(southHit2Spr);
	southHit->addSprite(southHit3Spr);
	extraAnim.push_back(southHit);
}

Link::Link() : Entity(false)
{
	//Init
	init();
	maxFrameTime = 5;
}

Link::Link(int x, int y) : Entity(false,x,y)
{
	//Init
	init();
	maxFrameTime = 5;
}

void Link::OnRender(sf::RenderWindow* renderer){
	if (usageOfExtraAnimation){
		renderer->draw(extraAnim[currentExtraAnimation]->getCurrentSprite());
	}else{
		Entity::OnRender(renderer);
	}
}

void Link::OnUpdate(){
	if (canUpdate()){
		if (usageOfExtraAnimation){
			extraAnim[currentExtraAnimation]->nextFrame();
			OnSyncSprite();
		}else{
			Entity::OnUpdate();
		}
		std::cout << "Reset" << std::endl;
	}else{
		std::cout << "Add" << std::endl;
	}
	
}

Link::~Link()
{
}

int Link::getType()
{
	return DOTYPE_LINK;
}

void Link::OnWalkUp()
{
	if (canUpdate() && !usingNonMoveableAnimation()){
		screenY -= 3;
	}
}

void Link::OnWalkRight()
{
	if (canUpdate() && !usingNonMoveableAnimation()){
		screenX += 3;
	}
}

void Link::OnWalkDown()
{
	if (canUpdate() && !usingNonMoveableAnimation()){
		screenY += 3;
	}
}

void Link::OnWalkLeft()
{
	if (canUpdate() && !usingNonMoveableAnimation()){
		screenX -= 3;
	}
}

void Link::OnSyncSprite()
{
	if (usageOfExtraAnimation){
		if (currentExtraAnimation == ANIM_SWORDHIT_EAST){
			extraAnim[currentExtraAnimation]->getCurrentSpritePointer()->setPosition(screenX, screenY - 15);
		}else if (currentExtraAnimation == ANIM_SWORDHIT_WEST){
			extraAnim[currentExtraAnimation]->getCurrentSpritePointer()->setPosition(screenX - 15, screenY - 15);
			if (extraAnim[currentExtraAnimation]->getCurrentFrame() == 0){
				extraAnim[currentExtraAnimation]->getCurrentSpritePointer()->setPosition(screenX - 4, screenY - 15);
			}else if (extraAnim[currentExtraAnimation]->getCurrentFrame() == 2){
				extraAnim[currentExtraAnimation]->getCurrentSpritePointer()->setPosition(screenX - 18, screenY - 15);
			}else if (currentExtraAnimation == ANIM_SWORDHIT_SOUTH){
				
			}

		}
	}else{
		Entity::OnSyncSprite();
	}
	
}

bool Link::usingNonMoveableAnimation()
{
	if (usageOfExtraAnimation){
		if (currentExtraAnimation == ANIM_SWORDHIT_NORTH ||
			currentExtraAnimation == ANIM_SWORDHIT_EAST ||
			currentExtraAnimation == ANIM_SWORDHIT_SOUTH ||
			currentExtraAnimation == ANIM_SWORDHIT_WEST){
			return true;
		}
	}
	return false;
}


