
#include"GamePass.h"
#include "WelcomeScene.h"
#include "pubdata.h"
#include "GameScene.h"
#include <string>
#include "SimpleAudioEngine.h"

using namespace CocosDenshion;
USING_NS_CC;



Scene* GamePass::createScene()
{
	auto scene = Scene::create();
	auto layer = GamePass::create();
	scene->addChild(layer);
	return scene;
}

GamePass* GamePass::create()
{
	GamePass* pRet = new GamePass();
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


bool GamePass::init()
{
	if (!Layer::init())
	{
		return false;
	}
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("shoot_background.plist");
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("shoot.plist");

	SimpleAudioEngine::getInstance()->playEffect("gamepassMusic.mp3");

	auto hero = Sprite::createWithSpriteFrameName("background3.png");
	hero->setPosition(VISIBLE_SIZE.width/2,VISIBLE_SIZE.height/2);

	this->addChild(hero, 1, 1);


	addCongratuationAnimation();
	addNextLevelButton();
	addGameOverButton();
	return true;
}


void GamePass::addCongratuationAnimation(){
	//auto hero = this->getChildByTag(1);

	Sprite* hero = Sprite::create("con1.png");
	hero->setPosition(VISIBLE_SIZE.width/2,VISIBLE_SIZE.height/2+40);
	this->addChild(hero,2);

	

	auto animation = Animation::create();

	//有哪些图片参与动画
	animation->addSpriteFrameWithFileName("con1.png");
	animation->addSpriteFrameWithFileName("con2.png");
	animation->addSpriteFrameWithFileName("con3.png");
	animation->addSpriteFrameWithFileName("con4.png");
	animation->addSpriteFrameWithFileName("con5.png");
	animation->addSpriteFrameWithFileName("con6.png");
	
	//切换的频率
	animation->setDelayPerUnit(0.3);
	//切换的周期数
	animation->setLoops(2);

	//将动画转换为动作
	auto action = Animate::create(animation);
	//执行动作
	hero->runAction(action);



}


void GamePass::addNextLevelButton()
{
	//auto sp = getChildByTag(1);
	auto back = Sprite::createWithSpriteFrameName("finish.png");
	auto menuItemBack = MenuItemSprite::create(back, back, [](Ref *){

		auto scene = WelcomeScene::createScene();
		Director::getInstance()->replaceScene(scene);
	});
	float x = visibleSize.width - back->getContentSize().width / 2 - 20;
	menuItemBack->setPosition(x, back->getContentSize().height / 2 + 20);

	auto menu = Menu::create(menuItemBack, NULL);
	menu->setPosition(Point::ZERO);
	this->addChild(menu,10,11);
}

void GamePass::addGameOverButton()
{
	auto back = Sprite::createWithSpriteFrameName("nextLevel.png");
	auto menuItemBack = MenuItemSprite::create(back, back, [](Ref *){
		//SimpleAudioEngine::getInstance()->playEffect("button.mp3");

		auto scene =GameScene ::createScene();
		Director::getInstance()->replaceScene(scene);
	});
	float x =  back->getContentSize().width / 2 + 20;
	menuItemBack->setPosition(x, back->getContentSize().height / 2 + 20);

	auto menu1 = Menu::create(menuItemBack, NULL);
	menu1->setPosition(Point::ZERO);
	this->addChild(menu1,10,12);
}