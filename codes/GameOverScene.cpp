#include "GameOverScene.h"
#include "ComaData.h"
#include "commdata.h"
#include "SimpleAudioEngine.h"
#include "LoadingScene.h"
#include "WelcomeScene.h"
#include "pubdata.h"

using namespace CocosDenshion;

bool GameOverScene::init(int score) {
	do
	{
		CC_BREAK_IF(!Layer::init());

		SimpleAudioEngine::getInstance()->stopBackgroundMusic();
		SimpleAudioEngine::getInstance()->playEffect("game_over.mp3");
		SpriteFrameCache::getInstance()->addSpriteFramesWithFile("shoot_background.plist");
		SpriteFrameCache::getInstance()->addSpriteFramesWithFile("shoot.plist");


		auto bg = Sprite::createWithSpriteFrameName("background1.png");
		bg->setAnchorPoint(Point::ANCHOR_MIDDLE_TOP);

		bg->setScaleX((VISIBLE_SIZE.width/bg->getContentSize().width)*640);
		bg->setScaleY((VISIBLE_SIZE.height/bg->getContentSize().height)*480);
		//这里设置背景以顶部中央对齐屏幕
		bg->setPosition(visibleSize.width/2, visibleSize.height);
		this->addChild(bg, -1);

		auto yourScore=Sprite::createWithSpriteFrameName("yourScore.png");
		yourScore->setPosition(visibleSize.width/2-60,visibleSize.height-100);
		this->addChild(yourScore,0);

		auto lblScore = Label::createWithBMFont("font.fnt", StringUtils::format("%s", "gameover"));
		lblScore->setPosition(visibleSize.width/2+100, visibleSize.height-100);
		this->addChild(lblScore);
		lblScore->setColor(Color3B(0,0,255));
		lblScore->setString(StringUtils::format("%d", score));

		//从配置文件中读取历史最高得分，如果没有则返回默认值0
		/*auto highScore = UserDefault::getInstance()->getIntegerForKey("HIGHSCORE", 0);
		auto lblHighScore = Label::createWithBMFont("font.fnt", StringUtils::format("%d", highScore));
		lblHighScore->setAnchorPoint(Point::ANCHOR_TOP_LEFT);
		lblHighScore->setPosition(150, visibleSize.height-40);
		this->addChild(lblHighScore);
		lblHighScore->setColor(Color3B(120, 120, 120));*/

		//如果读取到的最高分没有当前的得分值高。那么，更新最高得分且写入到配置文件中
		/*if (highScore<score)
		{
			SimpleAudioEngine::getInstance()->playEffect("achievement.mp3");

			highScore = score;
			UserDefault::getInstance()->setIntegerForKey("HIGHSCORE", highScore);

			lblHighScore->setString(StringUtils::format("%d", highScore));
		}*/

		addEndMenu();


		return true;
	} while (0);
	return false;
}

GameOverScene *GameOverScene::create(int score) {
	auto gameOver = new GameOverScene();
	if (gameOver && gameOver->init(score))
	{
		gameOver->autorelease();
		return gameOver;
	}
	delete gameOver;
	gameOver = NULL;
	return NULL;
}

Scene *GameOverScene::createScene(int score) {
	auto scene = Scene::create();
	auto layer = GameOverScene::create(score);
	scene->addChild(layer);

	return scene;
}


//
void GameOverScene::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void GameOverScene::addEndMenu()
{

		//退出按钮
		auto start = Sprite::createWithSpriteFrameName("restart.png");
		auto startItem = MenuItemSprite::create(start, start, [](Ref *){
			SimpleAudioEngine::getInstance()->playEffect("button.mp3");

			auto scene = LoadingScene::createScene();
			Director::getInstance()->replaceScene(scene);
		});

		//重启开始按钮
	    auto back = Sprite::createWithSpriteFrameName("exit.png");
		auto menuItemBack = MenuItemSprite::create(back, back, [](Ref *){
			SimpleAudioEngine::getInstance()->playEffect("button.mp3");

			auto scene = WelcomeScene::createScene();
			Director::getInstance()->replaceScene(scene);
		});

		//回到开始界面按钮
		/*auto help = Sprite::create("help.png");
		auto helpItem = MenuItemSprite::create(help, help, [](Ref *){
			SimpleAudioEngine::getInstance()->playEffect("button.mp3");

			auto scene = WelcomeScene::createScene();
			Director::getInstance()->replaceScene(scene);
		});*/


		//退出按钮
		/*auto exit = Sprite::create("exit.png");
		auto exitItem = MenuItemSprite::create(exit, exit, CC_CALLBACK_1(GameOverScene::menuCloseCallback, this));*/

		//设置位置
		float x = visibleSize.width - back->getContentSize().width/2-20;
		float menuX = visibleSize.width/2;
		float menuY = visibleSize.height/2;

		startItem->setPosition(menuX, menuY);
		menuItemBack->setPosition(menuX,menuY-90);
		//helpItem->setPosition(menuX, menuY);
		//exitItem->setPosition(menuX,menuY-60);

		auto menu = Menu::create(menuItemBack,startItem,NULL);
		menu->setPosition(Point::ZERO);
		this->addChild(menu);


}
