
#include "Gun.h"
Gun* Gun::create(ItemType g)
{
	//创建一个新对象
	auto ite = new Gun;
	//如果对象创建成功，并且初始化成功
	if(ite&&ite->init(g))
	{
		ite->autorelease();
		return ite;
	}
	//删除分配空间
	delete ite;
	ite = NULL;
	return NULL;
}

bool Gun::init(ItemType g)
{
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("guns.plist");

	bool flag=false;
	this->m_itemtype=g;
	switch(g)
	{
	case cake:
		flag=Sprite::initWithSpriteFrameName("cakegun.png");
		break;
	case chicken:
		flag=Sprite::initWithSpriteFrameName("chickengun.png");
		break;
	case lolly:
		flag=Sprite::initWithSpriteFrameName("lollygun.png");
			break;
	case durian:
		flag=Sprite::initWithSpriteFrameName("duriangun.png");
		break;
	case burger:
		flag=Sprite::initWithSpriteFrameName("hamburgergun.png");
		break;
	}
	return flag;
}