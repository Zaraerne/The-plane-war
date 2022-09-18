#pragma once

#include "../../CustomTools.h"
#include "../MyBullets.h"


class BulletsManeger
{
private:
	BulletsManeger();
	virtual ~BulletsManeger();
public:
	static BulletsManeger* getInstance()
	{
		if (pInstance == nullptr)
		{
			pInstance = new BulletsManeger;
		}
		return pInstance;
	}

	void addBullet(MyBullets* bullet);
	void ToDeath(MyBullets* bullet);
	MyBullets* FinddeathToLives(BulletTypes type);

	void addEmeryBullet(MyBullets* bullet);
	void EmeryButToDeath(MyBullets* bullet);
	MyBullets* FindEmeryButdeathToLives(BulletTypes type);

	std::list<MyBullets*> getPlyerLiveBut(){ return Lives; }
	std::list<MyBullets*> getPlyerDeathBut(){ return Death; }
	std::list<MyBullets*> getEmeryLiveBut(){ return EmeryButLives; }
	std::list<MyBullets*> getEmeryDeathBut(){ return EmeryButDeath; }

private:
	static BulletsManeger* pInstance;


	std::list<MyBullets*> Lives;
	std::list<MyBullets*> Death;

	std::list<MyBullets*> EmeryButLives;
	std::list<MyBullets*> EmeryButDeath;


};

