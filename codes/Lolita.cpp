#include "Lolita.h"
#include "SimpleAudioEngine.h"

using namespace CocosDenshion;

Lolita::Lolita() {
	this->m_speed = 0;
	this->m_HP = 0;
	this->m_type = NORMAL_LOLITA;
	this->m_Score = 0;
}

Lolita *Lolita::create(LolitaType type) {
	auto lolita = new Lolita();
	if (lolita && lolita->init(type))
	{
		lolita->autorelease();
		return lolita;
	}
	delete lolita;
	lolita = NULL;
	return NULL;
}

bool Lolita::init(LolitaType type) {
	/*if(!Sprite::init())
		return false;*/
	
	//SpriteFrameCache::getInstance()->addSpriteFramesWithFile("lolita.plist");

	this->m_type = type;
	bool flag=false;
	createDown();
	createHit();
	switch (this->m_type)
	{
	case NORMAL_LOLITA:
		{
			//SimpleAudioEngine::getInstance()->playEffect("big_spaceship_flying.mp3");

			//���õ���init������create
			flag=Sprite::initWithFile("l_1.png");
			//flag=Sprite::initWithSpriteFrameName("l_2.png");
			this->m_speed = NORMAL_LOLITA_SPEED;
			this->m_HP = 1;
			this->m_Score = 500;

			//������ƶ�����
			auto moveAnim = Animation::create();
			//moveAnim->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("l_1.png"));
			moveAnim->addSpriteFrameWithFileName("l_2.png");
			moveAnim->addSpriteFrameWithFileName("l_3.png");
			moveAnim->addSpriteFrameWithFileName("l_4.png");
			moveAnim->addSpriteFrameWithFileName("l_5.png");
			moveAnim->addSpriteFrameWithFileName("l_6.png");
			moveAnim->setDelayPerUnit(0.3f);
			moveAnim->setLoops(-1);
			this->runAction(Animate::create(moveAnim));
		}
		break;
	case HIGHSPEED_LOLITA:
		{
			//SimpleAudioEngine::getInstance()->playEffect("big_spaceship_flying.mp3");

			//���õ���init������create
			flag=Sprite::initWithFile("l_2_1.png");
			this->m_speed = NORMAL_LOLITA_SPEED;
			this->m_HP = 1;
			this->m_Score = 1000;

			//������ƶ�����
			auto moveAnim = Animation::create();
			moveAnim->addSpriteFrameWithFileName("l_2_1.png");
			moveAnim->addSpriteFrameWithFileName("l_2_2.png");
			moveAnim->addSpriteFrameWithFileName("l_2_3.png");
			moveAnim->addSpriteFrameWithFileName("l_2_4.png");
			moveAnim->addSpriteFrameWithFileName("l_2_5.png");
			moveAnim->addSpriteFrameWithFileName("l_2_6.png");
			moveAnim->setDelayPerUnit(0.2f);
			moveAnim->setLoops(-1);
			this->runAction(Animate::create(moveAnim));
		}
		break;
	case HIGHHP_LOLITA:
		{
			//SimpleAudioEngine::getInstance()->playEffect("big_spaceship_flying.mp3");

			//���õ���init������create
			flag=Sprite::initWithFile("l_3_1.png");
			this->m_speed = NORMAL_LOLITA_SPEED;
			this->m_HP = 8;
			this->m_Score = 2000;

			//������ƶ�����
			auto moveAnim = Animation::create();
			moveAnim->addSpriteFrameWithFileName("l_3_1.png");
			moveAnim->addSpriteFrameWithFileName("l_3_2.png");
			moveAnim->addSpriteFrameWithFileName("l_3_3.png");
			moveAnim->addSpriteFrameWithFileName("l_3_4.png");
			moveAnim->addSpriteFrameWithFileName("l_3_5.png");
			moveAnim->addSpriteFrameWithFileName("l_3_6.png");
			moveAnim->setDelayPerUnit(0.2f);
			moveAnim->setLoops(-1);
			this->runAction(Animate::create(moveAnim));
		}
		break;
	default:
		break;
	}
	return flag;

	//return true;
}
//Item* Lolita::rewardItem(LolitaType type)
//{
//	this->m_type = type;
//	switch (type)
//	{
//	case NORMAL_LOLITA:
//		return NULL;
//	case HIGHSPEED_LOLITA:
//		return CAKE;
//	case HIGHHP_LOLITA:
//		return HAMBURGER;
//	default:
//		break;
//	}
//
//}
float Lolita::getLolitaSpeed()
{
	return this->m_speed;
}

void Lolita::createHit()
{
	auto animation=Animation::create();
	switch(this->m_type)
	{
	case NORMAL_LOLITA:
		animation->addSpriteFrameWithFileName("loli1_hit.png");
		animation->addSpriteFrameWithFileName("l_1.png");
		animation->setDelayPerUnit(0.2f);
		AnimationCache::getInstance()->addAnimation(animation,"Normal_hit");
		break;
	case HIGHSPEED_LOLITA:
		animation->addSpriteFrameWithFileName("loli2_hit.png");
		animation->addSpriteFrameWithFileName("l_2_1.png");
		animation->setDelayPerUnit(0.2f);
		AnimationCache::getInstance()->addAnimation(animation,"HighSpeed_hit");
		break;
	case HIGHHP_LOLITA:
		animation->addSpriteFrameWithFileName("loli3_hit.png");
		animation->addSpriteFrameWithFileName("l_3_1.png");
		animation->setDelayPerUnit(0.2f);
		AnimationCache::getInstance()->addAnimation(animation,"HighHP_hit");
		break;
	}

}


void Lolita::createDown()
{
	auto animation=Animation::create();
	switch(this->m_type)
	{
	case NORMAL_LOLITA:
		animation->addSpriteFrameWithFileName("l_1.png");
		animation->addSpriteFrameWithFileName("loli_down.png");
		animation->setDelayPerUnit(0.2);
		animation->setLoops(2);
		AnimationCache::getInstance()->addAnimation(animation,"Normal_down");
		break;
	case HIGHSPEED_LOLITA:
		animation->addSpriteFrameWithFileName("l_2_1.png");
		animation->addSpriteFrameWithFileName("loli_down.png");
		animation->setDelayPerUnit(0.2);
		animation->setLoops(2);
		AnimationCache::getInstance()->addAnimation(animation,"HighSpeed_down");
		break;
	case HIGHHP_LOLITA:
		animation->addSpriteFrameWithFileName("l_3_1.png");
		animation->addSpriteFrameWithFileName("loli_down.png");
		animation->setDelayPerUnit(0.2);
		animation->setLoops(2);
		AnimationCache::getInstance()->addAnimation(animation,"HighHP_down");
		break;
	}
	//animation->addSpriteFrameWithFileName("down.png");
}

void Lolita::down()
{
	Animation *animation;
	switch(this->m_type)
	{
	case NORMAL_LOLITA:
		animation=AnimationCache::getInstance()->getAnimation("Normal_down");
		break;
	case HIGHSPEED_LOLITA:
		animation=AnimationCache::getInstance()->getAnimation("HighSpeed_down");
		break;
	case HIGHHP_LOLITA:
		animation=AnimationCache::getInstance()->getAnimation("HighHP_down");
		break;
	}
	auto animate=Animate::create(animation);
	//CallFuncN���������ڶ��������в�����룬����N����ִ�����������Ԫ������
	auto callFunc = CallFuncN::create([](Node *node){
		//���Լ��Ӹ��������Ƴ�
		node->removeFromParentAndCleanup(true);
	});
	//Sequen��֤�˶���ִ�е��Ⱥ�˳��ĩβ��NULL��ʾ�������е���ֹ������ʡ��
	this->runAction(Sequence::create(animate, callFunc, NULL));
}

void Lolita::hit()
{
	Animation *animation=NULL;
	switch(this->m_type)
	{
	case NORMAL_LOLITA:
		animation=AnimationCache::getInstance()->getAnimation("Normal_hit");
		break;
	case HIGHSPEED_LOLITA:
		animation=AnimationCache::getInstance()->getAnimation("HighSpeed_hit");
		break;
	case HIGHHP_LOLITA:
		animation=AnimationCache::getInstance()->getAnimation("HighHP_hit");
		break;
	}
	this->runAction(Animate::create(animation));

}
//
////���򱻻���ʱ���õĺ���
//void Lolita::bomb() {
//	//�������ƴӶ����������һض���
//	Animation *animation;
//	switch (this->m_type)
//	{
//	case NORMAL_LOLITA:
//		SimpleAudioEngine::getInstance()->playEffect("lolita1_bomb.mp3");
//		animation = AnimationCache::getInstance()->getAnimation("NormalLolitaBomb");
//		break;
//	case HIGHSPEED_LOLITA:
//		SimpleAudioEngine::getInstance()->playEffect("lolita2_bomb.mp3");
//		animation = AnimationCache::getInstance()->getAnimation("HighSpeedLolitaBomb");
//		break;
//	case HIGHHP_LOLITA:
//		SimpleAudioEngine::getInstance()->playEffect("lolita3_bomb.mp3");
//		animation = AnimationCache::getInstance()->getAnimation("HighHPLolitaBomb");
//		break;
//	default:
//		break;
//	}
//	auto animate = Animate::create(animation);
//	auto callFunc = CallFuncN::create([](Node *node){
//		node->removeFromParentAndCleanup(true);
//	});
//	this->stopAllActions();
//	this->runAction(Sequence::create(animate, callFunc, NULL));
//}
//
////���򱻵��߻���֮�����˶���
//void Lolita::hit() {
//	//Ѫ��һ���½�
//	this->m_HP--;
//	//���û��Ѫ���ˣ�����ñ�ը���������˳��˺���
//	if (this->m_HP <= 0)
//	{
//		this->bomb();
//		return;
//	}
//
//	//��ȡ���˶�����ִ��
//	Animation *animation;
//	switch (this->m_type)
//	{
//	case HIGHSPEED_LOLITA:
//		animation = AnimationCache::getInstance()->getAnimation("HighSpeedLolitaHit");//name need to change
//		break;
//	case HIGHHP_LOLITA:
//		animation = AnimationCache::getInstance()->getAnimation("HighHPLolitaHit");//name
//		break;
//	default:
//		break;
//	}
//
//	this->runAction(Animate::create(animation));
//}
