#pragma once
#include "stdafx.h"
#include <vector>
#include "Controllable.h"
class ImputController
{
public:
	ImputController();
	~ImputController();

	void checkKeyState();

private:
	bool keyPressed[101];
	std::vector<Controllable> controllables;

};

