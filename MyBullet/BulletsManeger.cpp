#include "BulletsManeger.h"

BulletsManeger* BulletsManeger::pInstance = nullptr;
BulletsManeger::BulletsManeger()
{
	
}


BulletsManeger::~BulletsManeger()
{
}

void BulletsManeger::addBullet(MyBullets* bullet)
{
	Lives.push_back(bullet);
}
void BulletsManeger::ToDeath(MyBullets* bullet)
{
	Lives.remove(bullet);
	bullet->removeFromParent();
	Death.push_back(bullet);
	
}
MyBullets* BulletsManeger::FinddeathToLives(BulletTypes type)
{
	for (auto but : Death)
	{
		if (type == but->getType())
		{
			Death.remove(but);
			return but;
		}
	}
	return nullptr;
}


void BulletsManeger::addEmeryBullet(MyBullets* bullet)
{
	EmeryButLives.push_back(bullet);
}
void BulletsManeger::EmeryButToDeath(MyBullets* bullet)
{
	EmeryButLives.remove(bullet);
	bullet->removeFromParent();
	EmeryButDeath.push_back(bullet);
}
MyBullets* BulletsManeger::FindEmeryButdeathToLives(BulletTypes type)
{
	for (auto but : EmeryButDeath)
	{
		if (type == but->getType())
		{
			EmeryButDeath.remove(but);
			CCLOG("Find");
			return but;
		}
	}
	return nullptr;
}