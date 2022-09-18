#include "EmeryFactory.h"

Emery* EmeryFactory::CreateEmery(Emery_Type Type)
{
	Emery* emery = nullptr;
	switch (Type)
	{
	case Emery_1:
	case Emery_2:
	case Emery_3:
	case Boss_1:
		emery = EmeryManege::getInstance()->FindDeathToLives(Type);
		if (emery == nullptr)
		{
			emery = Emery::CreateEmery(Type);
			emery->retain();
		}
		EmeryManege::getInstance()->addEmery(emery);
		break;
	default:
		break;
	}
	


	return emery;
}
