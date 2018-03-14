#include "GameScene.h"
#include "GameOverScene.h"
#include "GamePass.h"
#include "SimpleAudioEngine.h"

using namespace CocosDenshion;

/*Create and its step methods*/
Scene *GameScene::createScene()
{
	auto layer = GameScene::create();
	auto scene = Scene::create();
	scene->addChild(layer);
	return scene;
}

GameScene* GameScene::create()
{
	auto pRet = new GameScene;
	if(pRet && pRet->init())
	{
		pRet->autorelease();//将对象放入自动清空池里面，它会自动清空，不需要我们手动的delete
		return pRet;
	}else{
		delete pRet;
		pRet = nullptr;
		return nullptr;
	}
}

void GameScene::initGunNum()
{
	m_CakeNum=10;
	m_ChickenNum=10;
	m_LollyNum=10;
	m_HamburgerNum=10;
	m_DurianNum=10;
}


/*inti() and its step methods*/
bool GameScene::init()
{
	if(!Layer::init())
	{
		return false;
	}

	SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(0.5f);
	//SimpleAudioEngine::getInstance()->playBackgroundMusic("game_music.mp3");
	SimpleAudioEngine::getInstance()->playBackgroundMusic("backgroundMusic.mp3", true);

	m_score=0;
	m_money=0;

	//addMusic();
	addBackground();
	//addStoreIcon();
	createGun();
	initGunNum();
	createGunnumber();
	createTrail();
	addListener();
	addSchedule();

	this->scheduleUpdate();
	return true;
}


//create lolitas by type
void GameScene::createLolita(LolitaType type) {
	auto lolita = Lolita::create(type);
	//float minY = lolita->getContentSize().width/2;
	//float maxY = VISIBLE_SIZE.width-minY;
	//auto distance=maxY-minY;
	float x = VISIBLE_SIZE.width+lolita->getContentSize().width/2;
	//float y=(rand()%4)*(VISIBLE_SIZE.height/4)+lolita->getContentSize().height/2;
	float y=((rand()%4)*2+1)*VISIBLE_SIZE.height/10;
	//for(int i=0;i<4;i++)
	//{
	//	m_trail[i]=(i*2+1)*VISIBLE_SIZE.height/10;
	//}
	lolita->setPosition(x, y);
	lolita->setScale(0.4);
	//lolita->setPosition(VISIBLE_SIZE.width/2,VISIBLE_SIZE.height/2);
	this->addChild(lolita, 5);
	this->m_Lolita.pushBack(lolita);
}
void GameScene::createNormalLolita(float)
{
	createLolita(NORMAL_LOLITA); 
}
void GameScene::createHighSpeedLolita(float)
{
	createLolita(HIGHSPEED_LOLITA);
}
void GameScene::createHighHPLolita(float)
{
	createLolita(HIGHHP_LOLITA);
}


void GameScene::createItem(float)
{
	//auto item =Item::create(type);
	////float minY = item->getContentSize().height/2;
	////float maxY = VISIBLE_SIZE.height-minY;
	////float y=(rand()%4)*(VISIBLE_SIZE.height/4)+item->getContentSize().height/2;
	//float y=((rand()%4)*2+1)*VISIBLE_SIZE.height/10;
	////float x = VISIBLE_SIZE.height+item->getContentSize().height/2;
	//float x =-item->getContentSize().width/2;
	////item->setPosition(VISIBLE_SIZE.width/2,VISIBLE_SIZE.height/2);
	//item->setPosition(x, y);
	//item->setScale(0.2);
	//this->addChild(item, 4);
	//this->m_Item.pushBack(item);

	for(auto gun:m_Guns)
	{
		auto type=gun->m_itemtype;
		auto item=Item::create(type);
		float x=gun->getContentSize().width/2+gun->getPositionX();
		float y=gun->getPositionY();
		item->setPosition(x,y);
		item->setScale(0.15);
		this->addChild(item,4);
		this->m_Item.pushBack(item);
	}
}

//void GameScene::createCake(float)
//{
//	createItem(cake);
//}
//void GameScene::createChicken(float)
//{
//	createItem(chicken);
//}
//void GameScene::createBurger(float)
//{
//	createItem(burger);
//}
//void GameScene::createLolly(float)
//{
//	createItem(lolly);
//}
//void GameScene::createDurian(float)
//{
//	createItem(durian);
//}
void GameScene::addSchedule()
{
	//======create lolitas
	schedule(schedule_selector(GameScene::createNormalLolita), 3);
	schedule(schedule_selector(GameScene::createHighSpeedLolita), 10);
	schedule(schedule_selector(GameScene::createHighHPLolita),15);
	//======creat items
	schedule(schedule_selector(GameScene::createItem),1);
	//schedule(schedule_selector(GameScene::createBullet),0.08f);
	//schedule(schedule_selector(GameScene::createCake), 3);
	//schedule(schedule_selector(GameScene::createChicken), 4);
	//schedule(schedule_selector(GameScene::createBurger), 5);
	//schedule(schedule_selector(GameScene::createLolly), 6);
	//schedule(schedule_selector(GameScene::createDurian), 7);
	
}

void GameScene::addBackground()
{
	//background of level 1

	auto bg=StringUtils::format("level%d.png", rand()%4+1);

	auto bg1 = Sprite::createWithSpriteFrameName(bg);
	bg1->setPosition(VISIBLE_SIZE.width/2,VISIBLE_SIZE.height/2);
	
	//bg1->setScaleX((VISIBLE_SIZE.width / bg1->getContentSize().width) * 640);
	//bg1->setScaleY((VISIBLE_SIZE.height / bg1->getContentSize().height) * 480);
	
	//bg1->setScale(2);
	this->addChild(bg1, -1, 1);
	//bg1->setAnchorPoint(Point::ANCHOR_BOTTOM_LEFT);
	
}

void GameScene::createTrail()
{
	for(int i=0;i<4;i++)
	{
		m_trail[i]=(i*2+1)*VISIBLE_SIZE.height/10;
	}
	for(int i=0;i<3;i++)
	{
		m_trailx[i]=m_CakeGun->getContentSize().width/2+80*i;
	}
}

void GameScene::createGun()
{
	/*m_CakeGun=Sprite::create("cakegun.png");
	m_ChickenGun=Sprite::create("chickengun.png");
	m_LollyGun=Sprite::create("lollygun.png");
	m_DurianGun=Sprite::create("duriangun.png");
	m_HamburgerGun=Sprite::create("hamburgergun.png");*/
	auto gun1=Gun::create(cake);
	auto gun2=Gun::create(chicken);
	auto gun3=Gun::create(lolly);
	auto gun4=Gun::create(burger);
	auto gun5=Gun::create(durian);

	m_CakeGun=gun1;m_CakeGun->setScale(0.7);
	m_ChickenGun=gun2;m_ChickenGun->setScale(0.7);
	m_LollyGun=gun3;m_LollyGun->setScale(0.7);
	m_HamburgerGun=gun4;m_HamburgerGun->setScale(0.7);
	m_DurianGun=gun5;m_DurianGun->setScale(0.7);
	m_TempGun=gun1;m_TempGun->setScale(0.7);

	float d=m_CakeGun->getContentSize().width;
	float y=VISIBLE_SIZE.height- m_CakeGun->getContentSize().height/2;
	float x[5];
	x[0]=d;
	for(int i=1;i<5;i++)
	{
		x[i]=x[i-1]+d;
	}
	//投手初始位置
	m_CakeGun->setPosition(x[0],y);
	m_ChickenGun->setPosition(x[1],y);
	m_LollyGun->setPosition(x[2],y);
	m_HamburgerGun->setPosition(x[3],y);
	m_DurianGun->setPosition(x[4],y);



	this->addChild(m_CakeGun,4,1);
	this->addChild(m_ChickenGun,4);
	this->addChild(m_LollyGun,4);
	this->addChild(m_HamburgerGun,4);
	this->addChild(m_DurianGun,4);
}

void GameScene::addListener()
{
	auto listener=EventListenerTouchOneByOne::create();
	//bool flag=true;
	listener->onTouchBegan=[=](Touch* t,Event* e)
	{
		//bool flag=true;
		log("====touch began====");
		auto pos=t->getLocation();
		//this->m_vec=hero->getPosition()-pos;
		bool isContain=true;
		if(m_CakeGun->getBoundingBox().containsPoint(pos)&&m_CakeNum>0)
		{
				m_TempGun=Gun::create(cake);
		}

		else if(m_ChickenGun->getBoundingBox().containsPoint(pos)&&m_ChickenNum>0)
			m_TempGun=Gun::create(chicken);

		else if(m_LollyGun->getBoundingBox().containsPoint(pos)&&m_LollyNum>0)
			m_TempGun=Gun::create(lolly);
		else if(m_HamburgerGun->getBoundingBox().containsPoint(pos)&&m_HamburgerNum>0)
			m_TempGun=Gun::create(burger);
		else if(m_DurianGun->getBoundingBox().containsPoint(pos)&&m_DurianNum>0)
			m_TempGun=Gun::create(durian);
		else 
			isContain=false;
		//bool isContain=hero->getBoundingBox().containsPoint(pos);
		if(isContain==true)
		{
			this->addChild(m_TempGun,4);

		}
		     //this->addChild(m_TempGun,4);
		return isContain;
	};

	listener->onTouchMoved=[=](Touch* t,Event* e)
	{
		auto pos=t->getLocation();
		m_TempGun->setPosition(pos);
		//Point nextPos = t->getLocation()+this->m_vec;
		//边界拦截
	/*	auto visibleSize= Director::getInstance()->getVisibleSize();
		float minX = m_TempGun->getContentSize().width/2;
		float maxX = visibleSize.width-minX;
		float minY = m_TempGun->getContentSize().height/2;
		float maxY = visibleSize.height-minY;

		float x = MAX(minX, MIN(nextPos.x, maxX));
	    float y = MAX(minY, MIN(nextPos.y, maxY));
*/
		//hero->setPosition(x, y);

		log("====touch moved===");
	};
	listener->onTouchEnded=[=](Touch* t,Event* e)
	{
		log("====touch ended======");
		//this->addChild(m_TempGun);
		auto pos=t->getLocation();
		auto x=pos.x;
		auto y=pos.y;
		bool flag=false;
		for(int i=0;i<4;i++)
		{
			if(y>=m_trail[i]-20 && y <= m_trail[i]+20)
			{
				for(int j=0;j<3;j++)
				{
					if(x>=m_trailx[j]-20 && x<= m_trail[j]+20)
					{

						m_TempGun->setPosition(m_trailx[j],m_trail[i]);
				               auto type=m_TempGun->m_itemtype;
				               Label* lb;
				            switch(type)
			             	{
			                  	case cake:
				             	    m_CakeNum--;
					                lb = (Label *)this->getChildByTag(91);
					                lb->setString(StringUtils::format("X%d", this->m_CakeNum));
			                  		break;
			                	case chicken:
					                m_ChickenNum--;
					                lb = (Label *)this->getChildByTag(92);
					                lb->setString(StringUtils::format("X%d", this->m_ChickenNum));
					                break;
				                case lolly:
					                m_LollyNum--;
					                lb = (Label *)this->getChildByTag(93);
				                	lb->setString(StringUtils::format("X%d", this->m_LollyNum));
					                break;
				               case burger:
					                m_HamburgerNum--;
				                	lb = (Label *)this->getChildByTag(94);
				                 	lb->setString(StringUtils::format("X%d", this->m_HamburgerNum));
					                break;
				              case durian:
					               m_DurianNum--;
					               lb = (Label *)this->getChildByTag(95);
					               lb->setString(StringUtils::format("X%d", this->m_DurianNum));
				                	break;
			            	}
				    flag=true;
				    break;

					}
				}
			}
		}
		if(flag)
		{
			m_Guns.pushBack(m_TempGun);
		}
		else
		{
			this->removeChild(m_TempGun);
		}
			//this->removeChild(m_TempGun);
		//m_vec=Point::ZERO;

	};

	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this->m_TempGun);
}

void GameScene::createGunnumber()
{
	//lb->setString(StringUtils::format("X%d", this->m_ChickenNum));

	auto CakeCount=Label::createWithBMFont("font.fnt","No");
	CakeCount->setString(StringUtils::format("X%d", this->m_CakeNum));
	float x=m_CakeGun->getPositionX();
	float y=m_CakeGun->getPositionY()-m_CakeGun->getContentSize().height/2;
	CakeCount->setPosition(x,y);
	CakeCount->setColor(Color3B::WHITE);
	CakeCount->setAnchorPoint(Point::ANCHOR_BOTTOM_LEFT);
	this->addChild(CakeCount,13,91);

	auto ChickenCount=Label::createWithBMFont("font.fnt","No");
	ChickenCount->setString(StringUtils::format("X%d", this->m_ChickenNum));
	 x=m_ChickenGun->getPositionX();
	y=m_ChickenGun->getPositionY()-m_ChickenGun->getContentSize().height/2;
	ChickenCount->setPosition(x,y);
	ChickenCount->setColor(Color3B::WHITE);
	ChickenCount->setAnchorPoint(Point::ANCHOR_BOTTOM_LEFT);

	this->addChild(ChickenCount,13,92);

	auto LollyCount=Label::createWithBMFont("font.fnt","No");
	LollyCount->setString(StringUtils::format("X%d", this->m_LollyNum));
	x=m_LollyGun->getPositionX();
	y=m_LollyGun->getPositionY()-m_LollyGun->getContentSize().height/2;
	LollyCount->setPosition(x,y);
	LollyCount->setColor(Color3B::WHITE);
	LollyCount->setAnchorPoint(Point::ANCHOR_BOTTOM_LEFT);
	this->addChild(LollyCount,13,93);

	auto BurgerCount=Label::createWithBMFont("font.fnt","No");
	BurgerCount->setString(StringUtils::format("X%d", this->m_HamburgerNum));
	x=m_HamburgerGun->getPositionX();
	y=m_HamburgerGun->getPositionY()-m_HamburgerGun->getContentSize().height/2;
	BurgerCount->setPosition(x,y);
	BurgerCount->setColor(Color3B::WHITE);
	BurgerCount->setAnchorPoint(Point::ANCHOR_BOTTOM_LEFT);
	this->addChild(BurgerCount,13,94);

	auto DurianCount=Label::createWithBMFont("font.fnt","No");
	DurianCount->setString(StringUtils::format("X%d", this->m_DurianNum));
	x=m_DurianGun->getPositionX();
	y=m_DurianGun->getPositionY()-m_DurianGun->getContentSize().height/2;
	DurianCount->setPosition(x,y);
	DurianCount->setColor(Color3B::WHITE);
	DurianCount->setAnchorPoint(Point::ANCHOR_BOTTOM_LEFT);
	this->addChild(DurianCount,13,95);
}

/*update() and its step methods*/
void GameScene::update(float s)
{
	updateItem(s);
	updateLolita(s);

	checkLolitasAndItemHit();

	checkHeroAndItemHit();

	checkCountLevelPoints();

	removeall();

}

void GameScene::updateLolita(float)
{
	//auto lol=this->getChildByTag(1);
	for(auto lol:m_Lolita)
	{
		lol->setPositionX(lol->getPositionX()-lol->getLolitaSpeed());
		//lol->hit();
		if(lol->getPositionX()<=lol->getContentSize().width/2)
		{
			m_vLolita.pushBack(lol);
			this->removeChild(lol);
			//lol->down();
		}
	}
}

void GameScene::updateItem(float)
{
	//auto ite=this->getChildByTag(2);
	for(auto ite:m_Item)
	{
		ite->setPositionX(ite->getPositionX()+ite->m_speed);
		if(ite->getPositionX()>(VISIBLE_SIZE.width+ite->getContentSize().width/2))
		{
			m_vItem.pushBack(ite);
			this->removeChild(ite);
		}
	}

}

void GameScene::removeall()
{
	for(auto lol:m_vLolita)
	{
		this->m_Lolita.eraseObject(lol);
	}
	for(auto ite:m_vItem)
	{
		this->m_Item.eraseObject(ite);
	}
}

void GameScene::checkLolitasAndItemHit()
{
	//萝莉和道具的碰撞
	for(auto loli : m_Lolita)
	{
		for(auto item : m_Item)
		{
			if(loli->getBoundingBox().intersectsRect(item->getBoundingBox()))
			{
					
				m_vItem.pushBack(item);		
				this->removeChild(item);

				loli->setHP(loli->getHP()-item->m_dps);

				if(loli->getHP()>0)
				{
					//产生萝莉背打击的效果
					loli->hit();
				}else
				{
					this->m_score+=loli->getScore();
					//加金币

					this->m_money=loli->money;
		//			addMoney();
					//加道具
		//			addItem();
					//萝莉倒下的效果
					loli->down();
					//获得写有分数的label
		//			auto lable = (Label *) this->getChildByTag(6);
		//			lable->setString(StringUtils::format("%d", this->score));
					m_vLolita.pushBack(loli);

				}
				//测试可以输出
			log("score%d",m_score);

						
			}
		}
	}
}

void GameScene::checkHeroAndItemHit()
{
	for (auto lol : this->m_Lolita)
	{
		if (lol->getPositionX() <= 240)
		{
			SimpleAudioEngine::getInstance()->stopBackgroundMusic();
			auto gameoverScene = GameOverScene::createScene(this->m_score);
			Director::getInstance()->replaceScene(gameoverScene);
		}
	}
}

void GameScene::checkCountLevelPoints()
{
	//auto hero =this-> getChildByTag();
	auto ratio = UserDefault::getInstance()->getFloatForKey("SCORE_RATIO", 1.2);
	//if (20.0 >= this->carrentLevelPoints*ratio)
	if (m_score>10000)//need score to judge if pass this scene,but now we don't know the score and the total socre we need.
	{
		SimpleAudioEngine::getInstance()->stopBackgroundMusic();
		auto scene =GamePass ::createScene();
		Director::getInstance()->replaceScene(scene);
	}
}