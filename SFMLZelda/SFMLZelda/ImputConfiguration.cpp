#include "stdafx.h"
#include "ImputConfiguration.h"


ImputConfiguration::ImputConfiguration()
{
	keyConfig = std::map<int, int>::map();
}


ImputConfiguration::~ImputConfiguration()
{
}

void ImputConfiguration::addKeyConfiguration(int val, int imputKey)
{
	keyConfig.insert(std::pair<int, int>(val, imputKey));
}

int ImputConfiguration::getKeyConfiguartion(int val)
{
	if (keyConfig.count(val)){
		return keyConfig.find(val)->second;
	}
	return -1;
}

bool ImputConfiguration::isKeyConfiguartion(int val, int imputKey)
{
	if (keyConfig.count(val)){
		int cKey = keyConfig.find(val)->second;
		return cKey == imputKey;
	}
	return false;
}


