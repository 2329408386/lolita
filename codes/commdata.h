#pragma once
#include "cocos2d.h"

using namespace cocos2d;

#define visibleSize Director::getInstance()->getVisibleSize()

#define SMALL_ENEMY_STEP 6
#define MIDDLE_ENEMY_STEP 3
#define BIG_ENEMY_STEP 1

#define SMALL_ENEMY_POINTS 1
#define MIDDLE_ENEMY_POINTS 5
#define BIG_ENEMY_POINTS 10

enum EnemyType{
	SMALL,
	MID,
	BIG,
};

enum BulletType{
	RED,
	BLUE,
};

enum UfoType{
	UFO1,
	UFO2,
};