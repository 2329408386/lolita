#pragma once
#include "cocos2d.h"
#include "Item.h"
#include "Lolita.h"
#include "pubdata.h"
#include "gun.h"

using namespace cocos2d;
class GameScene : public Layer
{
public:

	void updateLolita(float);

	void updateItem(float);//has changed
	void removeall();

	//GameScene();
	bool init();

	static Scene *createScene();
	static GameScene* create();

	void addBackground();
	//void addMusic();


	void createLolita(LolitaType type);
	void createNormalLolita(float);
	void createHighSpeedLolita(float);
	void createHighHPLolita(float);
	void createItem(float);
/*	void createCake(float);
	void createChicken(float);
	void createBurger(float);
	void createLolly(float);
	void createDurian(float)*/;

	//void createGunCake();
	//void createGunChicken();
	//void createGunLolly();
	//void createGunHamburger();

	//void addBackground();
	//void addMusic();
	////void addScoreToCache();
	////void displayItems();
	////void displayMoney();
	//void addStoreIcon();
	void addSchedule();





	//new function
	void update(float);
	void createHit();
	void hit();
	void createDown();
	
	void createTrail();
	void createGun();
	void addListener();
	void createGunnumber();
	void initGunNum();

	Vector<Item*> m_Item;
	Vector<Lolita*> m_Lolita;
	Vector<Item*> m_vItem;
	Vector<Lolita*> m_vLolita;
	
	//new member parameters
	Vector<Gun*> m_Guns;
	Gun* m_CakeGun;
	Gun* m_ChickenGun;
	Gun* m_LollyGun;
	Gun* m_HamburgerGun;
	Gun* m_DurianGun;
	Gun* m_TempGun;
	float m_trail[4];
	float m_trailx[3];
	int m_CakeNum;
	int m_ChickenNum;
	int m_LollyNum;
	int m_HamburgerNum;
	int m_DurianNum;

public:
	void checkLolitasAndItemHit();
	void checkHeroAndItemHit();
	void checkCountLevelPoints();

	int m_score;
	int m_money;

};