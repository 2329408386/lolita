#pragma once
#include "cocos2d.h"
using namespace cocos2d;
#define VISIBLE_SIZE Director::getInstance()->getVisibleSize()
enum ItemType
{
	cake,
	chicken,
	burger,
	lolly,
	durian
};
//各种道具攻击力
#define CAKE_DPS 1
#define CHICKEN_DPS 2
#define BURGER_DPS 3
#define LOLLY_DPS 4
#define DURIAN_DPS 5

//各种道具价值
#define CAKE_VAL 1
#define CHICKEN_VAL 2
#define BURGER_VAL 3
#define LOLLY_VAL 4
#define DURIAN_VAL 5

//各种道具速度
#define CAKE_SP 1
#define CHICKEN_SP 2
#define BURGER_SP 3
#define LOLLY_SP 4
#define DURIAN_SP 5

#define NORMAL_LOLITA_SPEED 1
#define HIGHSPEED_LOLITA_SPEED 3
#define HIGHHP_LOLITA3_SPEED 1

typedef enum
{
	NORMAL_LOLITA,
	HIGHSPEED_LOLITA,
	HIGHHP_LOLITA
} LolitaType;
