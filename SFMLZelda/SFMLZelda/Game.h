
#pragma once
#include "stdafx.h"
#include "GameRenderer.h"
#include "Link.h"

class Game
{
public:
	Game(sf::RenderWindow *rWindow);
	~Game(void);

	void RunLoop();

private:
	
	void CheckKeyState();
	void Update();
	void Render();

	GameRenderer* m_renderer;

	bool isUpPressed;
	bool isDownPressed;
	bool isRightPressed;
	bool isLeftPressed;

	Entity* sampleEntity;
	Link* sampleLink;

};

