#include "WelcomeScene.h"
#include "SimpleAudioEngine.h"
#include "LoadingScene.h"
#include "SettingScene.h"
#include "GamePass.h"
#include "GameOverScene.h"
#include "StoryScene.h"
#include "GameHelpScene.h"

using namespace CocosDenshion;

#define VISIBLE_SIZE Director::getInstance()->getVisibleSize()

// Set background 
//sprite->setScaleX((winSize.width / sprite->getContentSize().width) * scaleXFactor);
//sprite->setScaleY((winSize.height / sprite->getContentSize().height) * scaleYFactor);

bool WelcomeScene::init()
{
	Layer::init();
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("buttons.plist");
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("background1.plist");
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("back2.plist");
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("back3.plist");
	//SpriteFrameCache::getInstance()->addSpriteFramesWithFile("shoot_background.plist");
	//SpriteFrameCache::getInstance()->addSpriteFramesWithFile("shoot.plist");

	

	//======Ìí¼Ó¿ªÊ¼½çÃæµÄ±³¾°
	auto bg = Sprite::createWithSpriteFrameName("background1.png");
	bg->setScaleX((VISIBLE_SIZE.width/bg->getContentSize().width)*640);
	bg->setScaleY((VISIBLE_SIZE.height/bg->getContentSize().height)*480);

	this->addChild(bg, 0, 1);
	bg->setAnchorPoint(Point::ANCHOR_BOTTOM_LEFT);
	//======Ìí¼ÓÓÎÏ·Ãû
	auto nm = Sprite::createWithSpriteFrameName("logo.png");
	nm->setScale(0.5);
	nm->setPosition(VISIBLE_SIZE.width/2, VISIBLE_SIZE.height-200);
	this->addChild(nm, 2, 2);

	//======Ìí¼Ó°´Å¥

	//SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(0.3f);
	//SimpleAudioEngine::getInstance()->playBackgroundMusic("game_music.mp3", true);


	welcomeSceneButtons();


	//======Ô¤¼ÓÔØÉùÒôÎÄ¼þ
	/*SimpleAudioEngine::getInstance()->preloadBackgroundMusic("game_music.mp3");
	SimpleAudioEngine::getInstance()->preloadEffect("achievement.mp3");		
	SimpleAudioEngine::getInstance()->preloadEffect("big_spaceship_flying.mp3");
	SimpleAudioEngine::getInstance()->preloadEffect("bullet.mp3");
	SimpleAudioEngine::getInstance()->preloadEffect("button.mp3");
	SimpleAudioEngine::getInstance()->preloadEffect("enemy1_down.mp3");
	SimpleAudioEngine::getInstance()->preloadEffect("enemy2_down.mp3");
	SimpleAudioEngine::getInstance()->preloadEffect("enemy3_down.mp3");
	SimpleAudioEngine::getInstance()->preloadEffect("game_over.mp3");
	SimpleAudioEngine::getInstance()->preloadEffect("get_bomb.mp3");		
	SimpleAudioEngine::getInstance()->preloadEffect("get_double_laser.mp3");
	SimpleAudioEngine::getInstance()->preloadEffect("out_porp.mp3");
	SimpleAudioEngine::getInstance()->preloadEffect("use_bomb.mp3");*/
	//======¶¯»­»º´æ

	return true;
}



Scene* WelcomeScene::createScene()
{
	auto scene = Scene::create();
	auto layer = WelcomeScene::create();
	scene->addChild(layer);
	return scene;
}


WelcomeScene *WelcomeScene::create()
{
	auto pRet = new WelcomeScene();
	if(pRet && pRet->init())
	{
		pRet->autorelease();//½«¶ÔÏó·ÅÈë×Ô¶¯Çå¿Õ³ØÀïÃæ£¬Ëü»á×Ô¶¯Çå¿Õ£¬²»ÐèÒªÎÒÃÇÊÖ¶¯µÄdelete
		return pRet;
	}else{
		delete pRet;
		pRet = nullptr;
		return nullptr;
	}
}



void WelcomeScene::welcomeSceneButtons()
{
		//ÖØÐÂÓÎÏ·
		auto story = Sprite::createWithSpriteFrameName("storyBackground.png");
		auto menuItemBack = MenuItemSprite::create(story, story, [](Ref *){
			SimpleAudioEngine::getInstance()->setEffectsVolume(0.8f);
		SimpleAudioEngine::getInstance()->playEffect("button.mp3");

		auto scene = StoryScene::createScene();
		Director::getInstance()->replaceScene(scene);
		});

		//¿ªÊ¼°´Å¥
		auto start = Sprite::createWithSpriteFrameName("start.png");
		auto startItem = MenuItemSprite::create(start, start, [](Ref *){

		SimpleAudioEngine::getInstance()->setEffectsVolume(0.8f);
		SimpleAudioEngine::getInstance()->playEffect("button.mp3");

		auto scene = LoadingScene::createScene();
		Director::getInstance()->replaceScene(scene);
		});

		//°ïÖú°´Å¥
		auto help = Sprite::createWithSpriteFrameName("help.png");
		auto helpItem = MenuItemSprite::create(help, help, [](Ref *){
			SimpleAudioEngine::getInstance()->setEffectsVolume(0.8f);
		SimpleAudioEngine::getInstance()->playEffect("button.mp3");

		auto scene=GameHelpScene::createScene();
		Director::getInstance()->replaceScene(scene);
		});

		//ÉèÖÃ°´Å¥
		auto set = Sprite::createWithSpriteFrameName("setting.png");
		auto setItem = MenuItemSprite::create(set, set, [](Ref *){
			SimpleAudioEngine::getInstance()->setEffectsVolume(0.8f);
		SimpleAudioEngine::getInstance()->playEffect("button.mp3");

		auto scene = SettingScene::createScene();
		Director::getInstance()->replaceScene(scene);
		});

		//ÍË³ö°´Å¥
		auto exit = Sprite::createWithSpriteFrameName("exit.png");
		auto exitItem = MenuItemSprite::create(exit, exit, [](Ref *){
			SimpleAudioEngine::getInstance()->setEffectsVolume(0.8f);
		SimpleAudioEngine::getInstance()->playEffect("button.mp3");
		Director::getInstance()->end();
		});


		float x = VISIBLE_SIZE.width - story->getContentSize().width/2-20;
		float menuX = VISIBLE_SIZE.width/2-100;
		float menuY = VISIBLE_SIZE.height/2-80;


		setItem->setPosition(x+story->getContentSize().width/2-set->getContentSize().width/2, set->getContentSize().height/2+20);
		startItem->setPosition(menuX, menuY);	
		helpItem->setPosition(menuX, menuY-80);
		menuItemBack->setPosition(menuX+200, menuY);
		exitItem->setPosition(menuX+200,menuY-80);

		auto menu = Menu::create(menuItemBack,startItem,helpItem,setItem,exitItem,NULL);
		menu->setPosition(Point::ZERO);
		this->addChild(menu, 2, 3);

}

void WelcomeScene::preloadMusic()
{
	SimpleAudioEngine::getInstance()->preloadBackgroundMusic("backgroundMusic.mp3");
	SimpleAudioEngine::getInstance()->preloadBackgroundMusic("game_music.mp3");
	SimpleAudioEngine::getInstance()->preloadEffect("button.mp3");
	SimpleAudioEngine::getInstance()->preloadEffect("getScore.mp3");
	SimpleAudioEngine::getInstance()->preloadEffect("getMoney.mp3");
	SimpleAudioEngine::getInstance()->preloadEffect("hitLolita.mp3");
	SimpleAudioEngine::getInstance()->preloadEffect("gamepassMusic.mp3");
}