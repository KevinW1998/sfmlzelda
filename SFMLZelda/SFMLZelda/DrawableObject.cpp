#include "stdafx.h"
#include "DrawableObject.h"




DrawableObject::DrawableObject() :
	screenX(0),
	screenY(0),
	visible(true)
{
}

DrawableObject::DrawableObject(int x, int y) :
	visible(true)
{
	this->screenX = x;
	this->screenY = y;
}


DrawableObject::~DrawableObject()
{
}

void DrawableObject::OnRender(sf::RenderWindow* renderer)
{
	sf::RectangleShape sh(sf::Vector2f(16,16));
	sh.setFillColor(sf::Color::Black);
	sh.setOutlineColor(sf::Color::Red);
	sh.setOutlineThickness(1.0f);
	sh.setPosition((float)screenX,(float)screenY);
	renderer->draw(sh);
	
	sf::RectangleShape dl(sf::Vector2f(22.62f,1));
	dl.setFillColor(sf::Color::Red);
	dl.setOutlineColor(sf::Color::Red);
	dl.setPosition((float)screenX,(float)screenY);
	dl.rotate(45.0f);
	renderer->draw(dl);

}

bool DrawableObject::isVisible()
{
	return visible;
}

void DrawableObject::setVisible(bool isVisible)
{
	visible = isVisible;
}

int DrawableObject::getType()
{
	return DOTYPE_BASE;
}

