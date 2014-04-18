#include "StdAfx.h"
#include "Game.h"

//ODLBUMBM

#define KP(k) sf::Keyboard::isKeyPressed(k)
#define UP KP(sf::Keyboard::Up)
#define DOWN KP(sf::Keyboard::Down)
#define RIGHT KP(sf::Keyboard::Right)
#define LEFT KP(sf::Keyboard::Left)


Game::Game(sf::RenderWindow* rWindow) :
	isDownPressed(false),
	isLeftPressed(false),
	isRightPressed(false),
	isUpPressed(false)
{
	m_renderer = new GameRenderer(rWindow);
	sampleEntity = new Entity(100,100);
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
	CheckKeyState();
	sampleEntity->OnUpdate();
}

void Game::Render()
{
	m_renderer->RenderDrawableObject(sampleEntity);
}

void Game::CheckKeyState()
{

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
	if (isUpPressed || isRightPressed || isDownPressed || isLeftPressed){
		sampleEntity->setAnimActive(true);
	}else{
		sampleEntity->setAnimActive(false);
	}

	
	if (isUpPressed){
		sampleEntity->OnWalkUp();
	}else if (isDownPressed){
		sampleEntity->OnWalkDown();
	}

	if (isLeftPressed){
		sampleEntity->OnWalkLeft();
	}else if (isRightPressed){
		sampleEntity->OnWalkRight();
	}
	

	if (isLeftPressed){
		sampleEntity->setDir(Entity::DIR_WEST);
	}else if (isRightPressed){
		sampleEntity->setDir(Entity::DIR_EAST);
	}else if (isUpPressed){
		sampleEntity->setDir(Entity::DIR_NORTH);
	}else if (isDownPressed){
		sampleEntity->setDir(Entity::DIR_SOUTH);
	}
}

