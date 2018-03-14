#include "LoadingScene.h"
#include "GameScene.h"
#include "SimpleAudioEngine.h"

using namespace CocosDenshion;

Scene* LoadingScene::createScene()
{
	auto scen = Scene::create();
	auto la = LoadingScene::create();
	scen->addChild(la);
	return scen;
}

bool LoadingScene::init()
{
	   if(!Layer::init())
	{
		return false;
	}

	//SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(0.3f);
	//SimpleAudioEngine::getInstance()->playBackgroundMusic("game_music.mp3", true);

	//添加缓存
	auto loading = Sprite::create("load0.png");
	loading->setPosition(VISIBLE_SIZE.width/2, VISIBLE_SIZE.height/2);

	// 缓存动画
	auto animation=Animation::create();
	for(int i=1;i<=5;i++)
	{
            auto png = StringUtils::format("load%d.png", i-1);
			animation->addSpriteFrameWithFileName(png);
	}
		animation->setDelayPerUnit(0.6);
		//Animation
		//animation->setLoops(2);
		auto animate = Animate::create(animation);
		auto callFunc = CallFunc::create([](){
		//跳转场景的代码
			//SimpleAudioEngine::getInstance()->stopBackgroundMusic();
		   auto scene = GameScene::createScene();
		   Director::getInstance()->replaceScene(scene);
		});
		loading->runAction(Sequence::create(animate, callFunc, NULL));
		this->addChild(loading,3);
	    return true;


}
