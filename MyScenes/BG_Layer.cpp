#include "BG_Layer.h"


void BG_Layer::SetTeture(std::string path)
{
	bg_1 = Sprite::create(path);
	bg_2 = Sprite::create(path);
	bg_1->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	bg_2->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	addChild(bg_1);
	addChild(bg_2);
	bg_1->setPosition(_Visable / 2);
	bg_2->setPosition(_Visable.width / 2, _Visable.height*1.5);
	By = CCMoveBy::create(1.0f, Vec2(0, -10));
	repeat = RepeatForever::create(By);
	bg_1->runAction(repeat->clone());
	bg_2->runAction(repeat->clone());

	schedule(schedule_selector(BG_Layer::MoveTo), 0.2f);
}
void BG_Layer::SetSpeed(float Speed)
{
	this->Speed = Speed;
	bg_1->stopAllActions();
	bg_2->stopAllActions();
	By = CCMoveBy::create(1.0f, Vec2(0, -Speed));
	repeat = RepeatForever::create(By);
	bg_1->runAction(repeat->clone());
	bg_2->runAction(repeat->clone());
}

bool BG_Layer::init()
{
	if (!Layer::create())
		return false;


	
	return true;
}


void BG_Layer::MoveTo(float date)
{

	if (bg_1->getPositionY() < (-_Visable.height / 2+4))
	{
		bg_1->setPositionY(_Visable.height*1.5);
	}
	if (bg_2->getPositionY() < (-_Visable.height / 2+4))
	{
		bg_2->setPositionY(_Visable.height*1.5);
	}

	
}
