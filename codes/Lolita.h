#pragma once
#include "cocos2d.h"
#include "pubdata.h"
//#include "Item.h"
USING_NS_CC;

class Lolita : public Sprite
{
public:
	Lolita();

	static Lolita *create(LolitaType type);
	bool init(LolitaType type);
	//死亡爆炸的函数
	void createHit();
	void createDown();
	void down();
	//受伤的函数
	void hit();
	//血量
	CC_SYNTHESIZE(int, m_HP, HP);
	//奖励分值
	CC_SYNTHESIZE_READONLY(int, m_Score, Score);
	
	//返回萝莉单步移动距离（包括基础距离和难度叠加距离）
	float getLolitaSpeed();
public:
	LolitaType m_type;
	//该萝莉单步移动距离(变量类型, 类变量名, get或者set函数的后部门)
	float m_speed;

	int money;

//	Item* rewardItem(LolitaType type); 
	

};
