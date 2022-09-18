#pragma once
#include "../../CustomTools.h"
#include "../MyBullets.h"



class Bulletfactory
{
public:
	static MyBullets* CreateBulletType1(BulletTypes type);

	
private:
	Bulletfactory();
	virtual ~Bulletfactory();
};

