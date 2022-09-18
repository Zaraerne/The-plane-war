#include "MyBullets.h"
#include "BulletsManeger\BulletsManeger.h"

MyBullets* MyBullets::Create(BulletTypes type, Vec2 Dir)
{
	MyBullets *pRet = new(std::nothrow) MyBullets(type,Dir);
	if (pRet && pRet->init())
	{
		pRet->autorelease();
		return pRet;
	}
	else
	{
		delete pRet;
		pRet = nullptr;
		return nullptr;
	}
}

bool MyBullets::init()
{
	if (!Sprite::initWithFile("player_fire.png"))
		return false;

	
	BulletCreate();
	return true;
}
void MyBullets::update(float date)
{
	ChangeAnlege();
	this->setPosition(this->getPosition() + Speed * date * Dir);
	if (this->getPositionY() > (_Visable.height - getContentSize().height / 2)||
		this->getPositionY() < getContentSize().height / 2					  ||
		this->getPositionX()< getContentSize().width / 2					  ||
		this->getPositionX() > _Visable.width - getContentSize().width/2)
	{
		switch (type)
		{
		case Player_1_Main:
		case Player_2_Main:
		case Player_3_Main:
		case Player_4_Main:
			BulletsManeger::getInstance()->ToDeath(this);
			break;
		case Emery_1_1Main:
		case Emery_1_2Main:
		case Emery_1_3Main:
		case Emery_1_Boos_1Main:
		case Emery_1_Boos_2Main:
			BulletsManeger::getInstance()->EmeryButToDeath(this);
			break;
		default:
			break;
		}
		
	}
}

void MyBullets::BulletCreate()
{
	
	switch (type)
	{
	case Player_1_Main:
		Speed = 800.0f;
		Daname = 50;
		break;
	case Player_2_Main:
		this->setTexture("player_fire2.png");
		Speed = 800.0f;
		Daname = 100;
		break;
	case Player_3_Main:
		this->setTexture("player_fire3.png");
		Speed = 800.0f;
		Daname = 150;
		break;
	case Player_4_Main:
		this->setTexture("player_fire4.png");
		Speed = 800.0f;
		Daname = 200;
		break;
	case Emery_1_1Main:
		this->setTexture("enemy_bullet.png");
		Speed = 500.0f;
		Daname = 99999;
		break;
	case Emery_1_2Main:
		break;
	case Emery_1_3Main:
		break;
	case Emery_1_Boos_1Main:
		break;
	case Emery_1_Boos_2Main:
		break;
	default:
		break;
	}

	ChangeAnlege();
}

void MyBullets::StartMove()
{
	scheduleUpdate();

}

void MyBullets::SetDir(Vec2 Dir)
{
	this->Dir = Dir;
}


void MyBullets::ChangeAnlege()
{
	float anlege = 90 - atan2(Dir.y, Dir.x)*180 / PI;
	Dir = ccpNormalize(Dir);
	this->setRotation(anlege);

}