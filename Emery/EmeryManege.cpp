#include "EmeryManege.h"

EmeryManege* EmeryManege::pInstance = nullptr;
EmeryManege::EmeryManege()
{
}


EmeryManege::~EmeryManege()
{
}

Emery* EmeryManege::FindDeathToLives(Emery_Type Type)
{
	for (Emery* pst : EmeryDeathes)
	{
		if (pst->GetType() == Type)
		{
			EmeryDeathes.remove(pst);
			return pst;
		}
	}
	return nullptr;
}
void EmeryManege::addEmery(Emery* emery)
{
	EmeryLives.push_back(emery);
}
void EmeryManege::ToDeathes(Emery* emery)
{
	emery->removeFromParent();
	EmeryDeathes.push_back(emery);
	EmeryLives.remove(emery);
	CCLOG("ToDeath");
}
