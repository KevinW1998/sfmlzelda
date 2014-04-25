#include "stdafx.h"
#include "ImputController.h"


ImputController::ImputController()
{
	std::fill_n(keyPressed, (int)sf::Keyboard::KeyCount, false);
}


ImputController::~ImputController()
{
}

void ImputController::checkKeyState()
{
	bool keyPressedTemp[sf::Keyboard::KeyCount];
	std::copy(std::begin(keyPressed), std::end(keyPressed), std::begin(keyPressedTemp));
	for (Controllable* keyCtrl : controllables){
		for (int keylist : keyCtrl->getWatchlist()){
			if (sf::Keyboard::isKeyPressed((sf::Keyboard::Key)keylist) && !keyPressed[keylist]){
				keyCtrl->_OnKeyDown((sf::Keyboard::Key)keylist);
				keyPressedTemp[keylist] = true;
			}else if (!sf::Keyboard::isKeyPressed((sf::Keyboard::Key)keylist) && keyPressed[keylist]){
				keyCtrl->_OnKeyUp((sf::Keyboard::Key)keylist);
				keyPressedTemp[keylist] = false;
			}
			if (sf::Keyboard::isKeyPressed((sf::Keyboard::Key)keylist)){
				keyCtrl->_OnKeyPressing((sf::Keyboard::Key)keylist);
			}
		}
	}
	std::copy(std::begin(keyPressedTemp), std::end(keyPressedTemp), std::begin(keyPressed));
}

void ImputController::addControllable(Controllable* ctrla)
{
	controllables.push_back(ctrla);
}
