#pragma once
#include "stdafx.h"
class ImputConfiguration
{
public:
	ImputConfiguration();
	~ImputConfiguration();

	void addKeyConfiguration(int val, int imputKey);
	int getKeyConfiguartion(int val);
	bool isKeyConfiguartion(int val, int imputKey);

private:
	std::map<int, int> keyConfig;
};

