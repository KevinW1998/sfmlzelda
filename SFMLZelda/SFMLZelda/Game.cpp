#include "StdAfx.h"
#include "Game.h"

//ODLBUMBM

#define KP(k) sf::Keyboard::isKeyPressed(k)
#define UP KP(sf::Keyboard::Up)
#define DOWN KP(sf::Keyboard::Down)
#define RIGHT KP(sf::Keyboard::Right)
#define LEFT KP(sf::Keyboard::Left)
#define SPACE KP(sf::Keyboard::Space)


Game::Game(sf::RenderWindow* rWindow) :
	isDownPressed(false),
	isLeftPressed(false),
	isRightPressed(false),
	isUpPressed(false)
{
	m_renderer = new GameRenderer(rWindow);
	sampleEntity = new Entity(true,100,100);
	sampleLink = new Link(200, 200);
	m_fpscounter = new FPSCounter();
	controller = new ImputController();
	controller->addControllable(sampleLink);
}


Game::~Game(void)
{

}

void Game::RunLoop()
{
	Update();
	m_renderer->Begin();
	Render();
	m_renderer->End();
}

void Game::Update()
{
	m_fpscounter->OnUpdate();
	sampleLink->beginUpdate();
	CheckKeyState();
	controller->checkKeyState();
	sampleEntity->OnUpdate();
	sampleLink->OnUpdate();
	sampleLink->endUpdate();
}

void Game::Render()
{
	//m_renderer->RenderDrawableObject(sampleEntity);
	m_renderer->RenderDrawableObject(sampleLink);
#if SFML_FPSCOUNTER == 1
	m_renderer->RenderDrawableObject(m_fpscounter);
#endif
}

void Game::CheckKeyState()
{	
	if (SPACE && !isSpacePressed){
		//Press Space
		isSpacePressed = true;
	}else if(!SPACE && isSpacePressed){
		//Release Space
		isSpacePressed = false;
	}

	if (!(RIGHT && LEFT)){
		if (RIGHT && !isRightPressed){
			//Press Right
			isRightPressed = true;
		}else if (!RIGHT && isRightPressed){
			//Release Right
			isRightPressed = false;
		}
		if (LEFT && !isLeftPressed){
			//Press Left			
			isLeftPressed = true;
		}
		else if (!LEFT && isLeftPressed){
			//Release Left
			isLeftPressed = false;
		}
	}else{
		isRightPressed = false;
		isLeftPressed = false;
	}

	if (!(UP && DOWN)){
		if (UP && !isUpPressed){
			//Press Up			
			isUpPressed = true;
		}
		else if (!UP && isUpPressed){
			//Release Up
			isUpPressed = false;
		}

		if (DOWN && !isDownPressed){
			//Press Down			
			isDownPressed = true;
		}
		else if (!DOWN && isDownPressed){
			//Release Down
			isDownPressed = false;
		}
	}else{
		isUpPressed = false;
		isDownPressed = false;
	}

	//Key Pressing Check Loop
	if (isUpPressed || isRightPressed || isDownPressed || isLeftPressed || isSpacePressed){
		//sampleEntity->setAnimActive(true);
		sampleLink->setAnimActive(true);
	}else{
		//sampleEntity->setAnimActive(false);
		sampleLink->setAnimActive(false);
	}

	//Movment Change
	if (isUpPressed){
		//sampleEntity->OnWalkUp();
		sampleLink->OnWalkUp();
	}
	else if (isDownPressed){
		//sampleEntity->OnWalkDown();
		sampleLink->OnWalkDown();
	}

	if (isLeftPressed){
		//sampleEntity->OnWalkLeft();
		sampleLink->OnWalkLeft();
	}
	else if (isRightPressed){
		//sampleEntity->OnWalkRight();
		sampleLink->OnWalkRight();
	}

	//Animation Changes
	if (isUpPressed){
		if (!isLeftPressed && !isRightPressed){
			//Animation change
			//sampleEntity->setDir(Entity::DIR_NORTH);
			sampleLink->setDir(Entity::DIR_NORTH);
		}
	}
	if (isLeftPressed){
		if (!isUpPressed && !isDownPressed){
			//Animation change
			//sampleEntity->setDir(Entity::DIR_WEST);
			sampleLink->setDir(Entity::DIR_WEST);
		}
	}
	if (isDownPressed){
		if (!isRightPressed && !isLeftPressed){
			//Animation change
			//sampleEntity->setDir(Entity::DIR_SOUTH);
			sampleLink->setDir(Entity::DIR_SOUTH);
		}
	}
	if (isRightPressed){
		if (!isUpPressed && !isDownPressed){
			//Animation change
			//sampleEntity->setDir(Entity::DIR_EAST);
			sampleLink->setDir(Entity::DIR_EAST);
		}
	}
	if (isSpacePressed){
		if (sampleLink->getDir() == Link::DIR_EAST){
			sampleLink->setCurrentExtraAnimation(Link::ANIM_SWORDHIT_EAST);
			sampleLink->setExtraAnimationActive(true);
		}else if (sampleLink->getDir() == Link::DIR_WEST){
			sampleLink->setCurrentExtraAnimation(Link::ANIM_SWORDHIT_WEST);
			sampleLink->setExtraAnimationActive(true);
		}else if (sampleLink->getDir() == Link::DIR_SOUTH){
			sampleLink->setCurrentExtraAnimation(Link::ANIM_SWORDHIT_SOUTH);
			sampleLink->setExtraAnimationActive(true);
		}else if (sampleLink->getDir() == Link::DIR_NORTH){
			sampleLink->setCurrentExtraAnimation(Link::ANIM_SWORDHIT_NORTH);
			sampleLink->setExtraAnimationActive(true);
		}
	}else{
		sampleLink->setExtraAnimationActive(false);
	}

	sampleLink->OnSyncSprite();
}

