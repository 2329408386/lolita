#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "cstring"

#define visibleSize Director::getInstance()->getVisibleSize()

class SettingScene : public cocos2d::Layer
{

private:
	bool isOpenMusic;

public:
	SettingScene();
	static cocos2d::Scene* createScene();
	virtual bool init();

	void menuBackCallback(cocos2d::Ref* pSender);
	void setMusic(cocos2d::Ref* pSender);
	void selectBackground(cocos2d::Ref* pSender, int i);

	void addBackground();
	void addSettingLayer();

	const char* getChinese(const std::string);
	bool getOpenMusic();

	CREATE_FUNC(SettingScene);
};

#endif
