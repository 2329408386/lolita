#pragma once
#include "cocos2d.h"
#include "pubdata.h"
//#include "Item.h"
USING_NS_CC;

class Lolita : public Sprite
{
public:
	Lolita();

	static Lolita *create(LolitaType type);
	bool init(LolitaType type);
	//������ը�ĺ���
	void createHit();
	void createDown();
	void down();
	//���˵ĺ���
	void hit();
	//Ѫ��
	CC_SYNTHESIZE(int, m_HP, HP);
	//������ֵ
	CC_SYNTHESIZE_READONLY(int, m_Score, Score);
	
	//�������򵥲��ƶ����루��������������Ѷȵ��Ӿ��룩
	float getLolitaSpeed();
public:
	LolitaType m_type;
	//�����򵥲��ƶ�����(��������, �������, get����set�����ĺ���)
	float m_speed;

	int money;

//	Item* rewardItem(LolitaType type); 
	

};
