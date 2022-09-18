#pragma once
#include "../../CustomTools.h"
#include "../Emery.h"

class EmeryManege
{
public:
	static EmeryManege* getInstance()
	{
		if (pInstance == nullptr)
		{
			pInstance = new EmeryManege;
		}
		return pInstance;
	}

	list<Emery*> getEmeryLives(){ return EmeryLives; }

	Emery* FindDeathToLives(Emery_Type Type);
	void addEmery(Emery* emery);
	void ToDeathes(Emery* emery);


private:
	static EmeryManege* pInstance;
	EmeryManege();
	virtual ~EmeryManege();

	list<Emery*> EmeryLives;
	list<Emery*> EmeryDeathes;
};

