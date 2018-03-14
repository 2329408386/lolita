#include "SettingScene.h"
#include "WelcomeScene.h"

USING_NS_CC;

SettingScene::SettingScene()
{
	//get the value of isOpenMusic from config file
	auto openMusic = UserDefault::getInstance()->getIntegerForKey("ISOPENMUSIC", true);
	this->isOpenMusic = openMusic;
}

Scene* SettingScene::createScene()
{
	auto scene = Scene::create();
	auto layer = SettingScene::create();
	scene->addChild(layer);

	return scene;
}

bool SettingScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("setting.plist");
	//add Background
	addBackground();

	//add setting items
	addSettingLayer();

	return true;
}

void SettingScene::addBackground()
{
	auto bg = Sprite::createWithSpriteFrameName("level1.png");
	bg->setScaleX((VISIBLE_SIZE.width/bg->getContentSize().width)*640);
	bg->setScaleY((VISIBLE_SIZE.height/bg->getContentSize().height)*480);
	bg->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	this->addChild(bg);
}

void SettingScene::addSettingLayer()
{
	// Layer
	auto dialogLayer = LayerColor::create(Color4B(255, 255, 204, 220));
	dialogLayer->setContentSize(Size(550, 400));
	dialogLayer->ignoreAnchorPointForPosition(false);
	dialogLayer->setAnchorPoint(ccp(0.5,0.5));
	dialogLayer->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	this->addChild(dialogLayer, 2,1);

	auto dialogLayerWidth = dialogLayer->getContentSize().width;
	auto dialogLayerHeight = dialogLayer->getContentSize().height;
	auto dialogLayerPositionX = dialogLayer->getPositionX();
	auto dialogLayerPositionY = dialogLayer->getPositionY();

	//Back Menu
	auto back_no = Sprite::create("dialog_close_btn_n.png");
	auto back_pr = Sprite::create("dialog_close_btn_d.png");
	auto menuItemBack = MenuItemSprite::create(back_no, back_pr, CC_CALLBACK_1(SettingScene::menuBackCallback, this));
	auto menu = Menu::create(menuItemBack, NULL);
	menu->setPosition(Point::ZERO);
	dialogLayer->addChild(menu, 3);
	menuItemBack->setPosition(dialogLayerPositionX - menuItemBack->getContentSize().width + dialogLayerWidth / 2, dialogLayerPositionY - menuItemBack->getContentSize().height + dialogLayerHeight/2);

	//SettingLayer title
	auto txtTitle = Sprite::create("settingTitle.png");
	dialogLayer->addChild(txtTitle,3);
	txtTitle->setPosition(visibleSize.width/2-txtTitle->getContentSize().width/6,visibleSize.height/2+dialogLayerHeight/3);

	//Music Label
	auto labelMusic = LabelTTF::create(getChinese("music"), "fonts/FZMWFont.ttf", 28);
	labelMusic->setAnchorPoint(Point::ANCHOR_MIDDLE_LEFT);
	labelMusic->setColor(Color3B::BLACK);
	labelMusic->setPosition(txtTitle->getPositionX()-txtTitle->getContentSize().width/2,txtTitle->getPositionY()-100);
	dialogLayer->addChild(labelMusic, 3);

	//Music select Button
	auto music_on = Sprite::create("sound_on.png");
	auto menuItemMusicOn = MenuItemSprite::create(music_on, music_on, CC_CALLBACK_1(SettingScene::setMusic, this));
	menuItemMusicOn->setPosition(txtTitle->getPositionX() + txtTitle->getContentSize().width / 2 - menuItemMusicOn->getContentSize().width/2, txtTitle->getPositionY() - 101);
	menuItemMusicOn->setTag(111);

	auto music_off = Sprite::create("sound_off.png");
	auto menuItemMusicOff = MenuItemSprite::create(music_off, music_off, CC_CALLBACK_1(SettingScene::setMusic, this));
	menuItemMusicOff->setPosition(txtTitle->getPositionX() + txtTitle->getContentSize().width / 2 - menuItemMusicOn->getContentSize().width / 2, txtTitle->getPositionY() - 101);
	menuItemMusicOff->setTag(112);

	if (this->isOpenMusic)
	{
		menuItemMusicOff->setVisible(false);
	}
	else{
		menuItemMusicOff->setVisible(true);
		menuItemMusicOn->setVisible(false);
	}

	auto menu1 = Menu::create(menuItemMusicOn, menuItemMusicOff, NULL);
	menu1->setPosition(Point::ZERO);
	dialogLayer->addChild(menu1, 3, 110);

	//Background label
	auto labelBackgroung = LabelTTF::create(getChinese("background"), "fonts/FZMWFont.ttf", 28);
	labelBackgroung->setAnchorPoint(Point::ANCHOR_MIDDLE_LEFT);
	labelBackgroung->setColor(Color3B::BLACK);
	labelBackgroung->setPosition(txtTitle->getPositionX() - txtTitle->getContentSize().width / 2, txtTitle->getPositionY() - 170);
	dialogLayer->addChild(labelBackgroung, 2);

	//Background items
	for (int i = 0; i < 4; i++)
	{
		auto png =StringUtils::format("settingLevel%d.jpg", i+1);
		
		auto bkItem = MenuItemImage::create(png, png, CC_CALLBACK_1(SettingScene::selectBackground, this, i));
		bkItem->setAnchorPoint(Point::ANCHOR_MIDDLE_LEFT);
		auto menu = Menu::create(bkItem, NULL);
		menu->setPosition(Point::ZERO);
		dialogLayer->addChild(menu);
		if (i < 2)
		{
			bkItem->setPosition(txtTitle->getPositionX() - txtTitle->getContentSize().width / 2 + i*(txtTitle->getContentSize().width-2*bkItem->getContentSize().width), labelBackgroung->getPositionY() - 70);
		}
		else{
			bkItem->setPosition(txtTitle->getPositionX() - txtTitle->getContentSize().width / 2 + (i - 2) * (txtTitle->getContentSize().width - 2 * bkItem->getContentSize().width), labelBackgroung->getPositionY() - 150);
		}
	}

	auto lolita = Sprite::createWithSpriteFrameName("s_hurt.png");
	lolita->setScale(0.5);
	lolita->setPosition(dialogLayerPositionX - menuItemBack->getContentSize().width + dialogLayerWidth / 2 - lolita->getContentSize().width / 4, dialogLayerPositionY - menuItemBack->getContentSize().height - dialogLayerHeight / 2 + lolita->getContentSize().height / 4);
	dialogLayer->addChild(lolita);

	
}


void SettingScene::menuBackCallback(Ref* pSender)
{
	//Go to welcomeScene
	auto scene = WelcomeScene::createScene();
		Director::getInstance()->replaceScene(scene);
}

void SettingScene::setMusic(Ref* pSender)
{
	auto layer = this->getChildByTag(1);
	auto menuMusic = layer->getChildByTag(110);
	auto menuItemMusicOn = menuMusic->getChildByTag(111);
	auto menuItemMusicOff = menuMusic->getChildByTag(112);
	if (this->isOpenMusic)
	{
		isOpenMusic = false;
		menuItemMusicOff->setVisible(true);
		menuItemMusicOn->setVisible(false);
		UserDefault::getInstance()->setIntegerForKey("ISOPENMUSIC", false);
	}
	else{
		isOpenMusic = true;
		menuItemMusicOff->setVisible(false);
		menuItemMusicOn->setVisible(true);
		UserDefault::getInstance()->setIntegerForKey("ISOPENMUSIC", true);
	}
}


void SettingScene::selectBackground(Ref* pSender, int i)
{
	log(i+4);
	switch (i)
	{
	case 0:
		UserDefault::getInstance()->setStringForKey("BACKGROUND_IMAGE", "background_1.png");
		break;
	case 1:
		UserDefault::getInstance()->setStringForKey("BACKGROUND_IMAGE", "background_2.png");
		break;
	case 2:
		UserDefault::getInstance()->setStringForKey("BACKGROUND_IMAGE", "background_3.png");
		break;
	case 3:
		UserDefault::getInstance()->setStringForKey("BACKGROUND_IMAGE", "background_4.png");
		break;
	default:
		break;
	}
}

const char* SettingScene::getChinese(const std::string en_name)
{
	auto *chnStrings = Dictionary::createWithContentsOfFile("fonts/Chinese.xml");
	auto str1 = ((String*)chnStrings->objectForKey(en_name))->getCString();

	return str1;
}

bool SettingScene::getOpenMusic()
{
	return this->isOpenMusic;
}