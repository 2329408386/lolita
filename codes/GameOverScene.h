#pragma once

#include "cocos2d.h"
USING_NS_CC;

class GameOverScene : public Layer
{
public:
	bool init(int score);
	static GameOverScene *create(int score);
	static Scene *createScene(int score);
	//有重新开始 退出 回到开始界面的三个按钮的菜单
	void addEndMenu();
	//退出的回调函数
	void menuCloseCallback(cocos2d::Ref* pSender);

};