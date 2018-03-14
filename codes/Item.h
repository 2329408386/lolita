#pragma once
#include "cocos2d.h"
#include "pubdata.h"
using namespace cocos2d;
class Item:public Sprite
{
public:
	ItemType m_itemtype;
	float m_dps;//每种道具攻击力
	float m_speed;
	float m_value;

	static Item* create(ItemType i);
	bool init(ItemType i);



};
