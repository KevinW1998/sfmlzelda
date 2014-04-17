
#include "StdAfx.h"
#include "GameRenderer.h"


GameRenderer::GameRenderer(sf::RenderWindow* rWindow)
{
	m_nativeRenderer = rWindow;
}


GameRenderer::~GameRenderer(void)
{

}

void GameRenderer::Begin()
{
	m_nativeRenderer->clear();
}

void GameRenderer::End()
{
	m_nativeRenderer->display();
}

sf::RenderWindow* GameRenderer::getNative()
{
	return m_nativeRenderer;
}

void GameRenderer::RenderDrawableObject(DrawableObject* dao)
{
	if(dao->isVisible()){
		dao->OnRender(m_nativeRenderer);
	}
}
