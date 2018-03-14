#pragma once

#include "cocos2d.h"
#include "SettingScene.h"

using namespace cocos2d;

class StoryScene : public cocos2d::Layer
{
public:
	bool init();
	static Scene* createScene();
	static StoryScene* create();
	void menuCloseCallback(Ref* pSender);
private:
	void addStoryBackgroudButton();
};