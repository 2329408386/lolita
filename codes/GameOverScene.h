#pragma once

#include "cocos2d.h"
USING_NS_CC;

class GameOverScene : public Layer
{
public:
	bool init(int score);
	static GameOverScene *create(int score);
	static Scene *createScene(int score);
	//�����¿�ʼ �˳� �ص���ʼ�����������ť�Ĳ˵�
	void addEndMenu();
	//�˳��Ļص�����
	void menuCloseCallback(cocos2d::Ref* pSender);

};