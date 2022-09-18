#include "Emery.h"
#include "EmeryManege\EmeryManege.h"
#include "../MyBullets/Bulletfactory/Bulletfactory.h"

Emery::Emery(Emery_Type Type, Vec2 dir)
{
	this->Type = Type;
	SetDir(dir);
}


Emery::~Emery()
{
}

Emery* Emery::CreateEmery(Emery_Type Type, Vec2 dir)
{
	Emery* psd = new (std::nothrow) Emery(Type,dir);
	if (psd && psd->init())
	{
		psd->autorelease();
	}
	else
	{
		delete psd;
		psd = nullptr;
	}
	return psd;
	
}
bool Emery::init()
{
	if (!Sprite::initWithFile("npc/npc_coin.png"))
		return false;

	

	return true;
}

void Emery::update(float date)
{
	Dir = ccpNormalize(Dir);	// ·½Ïò
	float Anlege = 90 - atan2(Dir.y, Dir.x) * 180 / PI;
	this->setRotation(Anlege);
	this->setPosition(this->getPosition() + date* Speed* Dir);

	if (getPositionY() < (-getContentSize().height / 2))
	{
		EmeryManege::getInstance()->ToDeathes(this);
	}

}

void Emery::onEnter()
{
	Sprite::onEnter();
	switch (Type)
	{
	case Emery_1:
		Hp = 100;
		Speed = 100.0f;
		break;
	case Emery_2:
		Hp = 500;
		Speed = 80.0f;
		this->setTexture("npc/npc_coin_3.png");
		break;
	case Emery_3:
		Hp = 400;
		Speed = 400.0f;
		this->setTexture("npc/npc_coin_4.png");
		break;
	case Boss_1:
		Hp = 400000;
		Speed = 1.0f;
		this->setTexture("npc/boss/boss1.png");
		break;
	default:
		break;
	}
	scheduleUpdate();
}

void Emery::TakeDamege(float damege)
{
	Hp -= damege;
	CCLOG("%d", Hp);
	if (Hp <= 0)
	{
		switch (Type)
		{
		case Emery_1:
			Hp = 100;
			break;
		case Emery_2:
			Hp = 500;
			break;
		case Emery_3:
			Hp = 400;
			break;
		case Boss_1:
			Hp = 400000;
			break;
		default:
			break;
		}



		EmeryManege::getInstance()->ToDeathes(this);
	}
}

void Emery::StoodType_1()
{
	schedule(schedule_selector(Emery::StoodType_1_SCH), 0.5,-1,1);
}
void Emery::StoodType_1_SCH(float date)
{
	MyBullets* But = Bulletfactory::CreateBulletType1(Emery_1_1Main);
	getParent()->addChild(But);
	But->SetDir(Vec2(0, -1));
	But->StartMove();
	But->setPosition(this->getPosition()-Vec2(0,50));
}
