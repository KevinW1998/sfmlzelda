#include "StdAfx.h"
#include "Game.h"

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
	sampleEntity->Update();
}

void Game::Render()
{
	m_renderer->RenderDrawableObject(sampleEntity);
}

void Game::CheckKeyState()
{
	if(UP && !isUpPressed){
		//Press Up
		sampleEntity->setDir(Entity::DIR_NORTH);
		sampleEntity->setAnimActive(true);

		isUpPressed = true;
	}else if(!UP && isUpPressed){
		//Release Up
		sampleEntity->setAnimActive(false);

		isUpPressed = false;
	}

	if(DOWN && !isDownPressed){
		//Press Down
		sampleEntity->setDir(Entity::DIR_SOUTH);
		sampleEntity->setAnimActive(true);

		isDownPressed = true;
	}else if(!DOWN && isDownPressed){
		//Release Down
		sampleEntity->setAnimActive(false);

		isDownPressed = false;
	}

	if(RIGHT && !isRightPressed){
		//Press Right
		sampleEntity->setDir(Entity::DIR_EAST);
		sampleEntity->setAnimActive(true);

		isRightPressed = true;
	}else if(!RIGHT && isRightPressed){
		//Release Right
		sampleEntity->setAnimActive(false);

		isRightPressed = false;
	}

	if(LEFT && !isLeftPressed){
		//Press Left
		sampleEntity->setDir(Entity::DIR_WEST);
		sampleEntity->setAnimActive(true);

		isLeftPressed = true;
	}else if(!LEFT && isLeftPressed){
		//Release Left
		sampleEntity->setAnimActive(false);

		isLeftPressed = false;
	}
}

