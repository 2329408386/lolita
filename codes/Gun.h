#pragma once
#include "cocos2d.h"
#include "Item.h"
#include "pubdata.h"
using namespace cocos2d;

class Gun:public Sprite
{
public:
	ItemType m_itemtype;

	static Gun* create(ItemType g);
	bool init(ItemType g);
};