#include "Bulletfactory.h"
#include "../BulletsManeger/BulletsManeger.h"


Bulletfactory::Bulletfactory()
{
	
}


Bulletfactory::~Bulletfactory()
{
}

MyBullets* Bulletfactory::CreateBulletType1(BulletTypes type)
{
	
	MyBullets* but = nullptr;
	switch (type)
	{
	case Player_1_Main:
	case Player_2_Main:
	case Player_3_Main:
	case Player_4_Main:
		but = BulletsManeger::getInstance()->FinddeathToLives(type);
		if (but == nullptr)
		{
			but = MyBullets::Create(type);
			but->retain();
		}
		BulletsManeger::getInstance()->addBullet(but);
		
		break;
	case Emery_1_1Main:
	case Emery_1_2Main:
	case Emery_1_3Main:
	case Emery_1_Boos_1Main:
	case Emery_1_Boos_2Main:
		but = BulletsManeger::getInstance()->FindEmeryButdeathToLives(type);
		if (but == nullptr)
		{
			but = MyBullets::Create(type,Vec2(0,-1));
			but->retain();
		}
		BulletsManeger::getInstance()->addEmeryBullet(but);
		break;
	default:
		break;
	}
	return but;
}


