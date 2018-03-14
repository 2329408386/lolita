#include "Item.h"
using namespace cocos2d;

Item *Item::create(ItemType i)
{
	//创建一个新对象
	auto ite = new Item;
	//如果对象创建成功，并且初始化成功
	if(ite&&ite->init(i))
	{
		ite->autorelease();
		return ite;
	}
	//删除分配空间
	delete ite;
	ite = NULL;
	return NULL;
}

bool Item::init(ItemType i)
{
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("item.plist");

	this->m_itemtype=i;
	bool flag=false;
	switch(this->m_itemtype)
	{
	case cake:
		flag=Sprite::initWithSpriteFrameName("cake1.png");
		//flag=Sprite::init("cake1.png");
		//flag=Sprite::initWithFile("cake1.png");
		this->m_dps=CAKE_DPS;
		this->m_speed=CAKE_SP;
		this->m_value=CAKE_VAL;
		break;
	case chicken:
		flag=Sprite::initWithSpriteFrameName("chicken.png");
		//flag=Sprite::initWithFile("chicken.png");
		this->m_dps=CHICKEN_DPS;
		this->m_speed=CHICKEN_SP;
		this->m_value=CHICKEN_VAL;
		break;
	case burger:
		flag=Sprite::initWithSpriteFrameName("hambergur2.png");
		//flag=Sprite::initWithFile("hambergur2.png");
		this->m_dps=BURGER_DPS;
		this->m_speed=BURGER_SP;
		this->m_value=BURGER_VAL;
		break;
	case durian:
		flag=Sprite::initWithSpriteFrameName("durian1.png");
		//flag=Sprite::initWithFile("durian1.png");
		this->m_dps=DURIAN_DPS;
		this->m_speed=DURIAN_SP;
		this->m_value=DURIAN_VAL;
		break;
	case lolly:
		flag=Sprite::initWithSpriteFrameName("lolly1.png");
		//flag=Sprite::initWithFile("lolly1.png");
		this->m_dps=LOLLY_DPS;
		this->m_speed=LOLLY_SP;
		this->m_value=LOLLY_VAL;
		break;
	}
	return flag;
}