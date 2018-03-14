#pragma once

#include "cocos2d.h"
#include "GameScene.h"
 using namespace cocos2d;

 class WelcomeScene:public Layer
 {
 public:
	// CREATE_FUNC(WelcomeScene);
	 bool init();
	 static Scene* createScene();
	 static WelcomeScene* create();

	 void welcomeSceneButtons();

	 void preloadMusic();
 };