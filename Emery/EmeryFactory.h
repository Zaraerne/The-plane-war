#pragma once
#include "../EmeryManege/EmeryManege.h"

class EmeryFactory
{
public:
	static Emery* CreateEmery(Emery_Type Type);
};

