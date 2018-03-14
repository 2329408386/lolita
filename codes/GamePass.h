#pragma once
#include "cocos2d.h"
#include "SettingScene.h"
using namespace cocos2d;
#define visibleSize Director::getInstance()->getVisibleSize()
class GamePass :public Layer{
public:
	static GamePass* create();
	static Scene* createScene();
	bool init();
	void addCongratuationAnimation();
	void addNextLevelButton();
	void addGameOverButton();
private:

};