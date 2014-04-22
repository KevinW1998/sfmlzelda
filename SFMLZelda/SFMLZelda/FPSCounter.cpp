#include "stdafx.h"
#include "FPSCounter.h"


FPSCounter::FPSCounter() : DrawableObject(5,1)
{
	nowclock.restart();
}


FPSCounter::~FPSCounter()
{
}

void FPSCounter::OnRender(sf::RenderWindow* renderer)
{
	sf::Text fpsTxt;
	sf::Font fpsFont;
	fpsFont.loadFromFile("fonts/hobo.ttf");
	fpsTxt.setFont(fpsFont);
	fpsTxt.setString(std::to_string(getFPS()));
	fpsTxt.setPosition(sf::Vector2f((float)screenX, (float)screenY));
	fpsTxt.setScale(sf::Vector2f(0.5f, 0.5f));
	renderer->draw(fpsTxt);
}

int FPSCounter::getType()
{
	return DOTYPE_FPS;
}

void FPSCounter::OnUpdate()
{
	diffTime = nowclock.getElapsedTime() - lTime;
	lTime = nowclock.getElapsedTime();
}

int FPSCounter::getFPS()
{
	return (int)std::ceil(1 / diffTime.asSeconds());
}
