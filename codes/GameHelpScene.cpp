#include"GameHelpScene.h"
#include "WelcomeScene.h"
//#include <string>
USING_NS_CC;
Scene* GameHelpScene::createScene()
{
	auto scene = Scene::create();
	auto layer = GameHelpScene::create();
	scene->addChild(layer);
	return scene;
}

GameHelpScene*  GameHelpScene::create()
{
	GameHelpScene* pRet = new  GameHelpScene();
	if (pRet && pRet->init())
	{
		pRet->autorelease();
		return pRet;
	}
	else{
		delete pRet;
		pRet = nullptr;
		return nullptr;
	}
}


bool GameHelpScene::init()
{
	if (!Layer::init())
	{
		return false;
	}
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("setting.plist");
	srand((unsigned int)time(0));
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("shoot_background.plist");
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("shoot.plist");
	//FileUtils::getInstance()->addSearchPath("font");




	//创建精灵
	auto sp = Sprite::createWithSpriteFrameName("gameHelp.png");;
	auto size = Director::getInstance()->getVisibleSize();
	sp->setPosition(0, 0);
	sp->setAnchorPoint(Point(0, 0));
	this->addChild(sp, 0, 1);




	//创建返回按钮

	auto closeItem = MenuItemImage::create(
		"dialog_close_btn_d.png",
		"dialog_close_btn_n.png",
		CC_CALLBACK_1(GameHelpScene::menuCloseCallback, this));

	closeItem->setPosition(Point(visibleSize.width-closeItem->getContentSize().width / 2,
		visibleSize.height - closeItem->getContentSize().height / 2));

	// create menu, it's an autorelease object
	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Point::ZERO);
	this->addChild(menu, 1);


	return true;
}

//场景转换
void GameHelpScene::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.", "Alert");
	return;
#endif
	auto scene = WelcomeScene::createScene();
	Director::getInstance()->replaceScene(scene);
	//Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}





