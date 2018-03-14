#pragma once
#include "cocos2d.h"
#include "Comadata.h"
using namespace cocos2d;

class LoadingScene:public Layer
{
public:
	bool init();
	static Scene* createScene();
	//static LoadingScene* creat();
	CREATE_FUNC(LoadingScene);
};