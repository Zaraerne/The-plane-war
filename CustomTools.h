#pragma once
#include "cocos2d.h"
#include <list>
using namespace std;
using namespace cocos2d;
#include "math\CCMath.h"
#include "ui\CocosGUI.h"
#include "Particle3D\CCParticleSystem3D.h"
using namespace cocos2d::ui;

#define PI 3.14
#define _director Director::getInstance()
#define _Visable Director::getInstance()->getVisibleSize()
#define MyData UserDefault::getInstance()

enum Emery_Type
{
	Emery_1,
	Emery_2,
	Emery_3,


	Boss_1
};

enum Plane_Type
{
	Player_1,
	Player_2,
	Player_3,
	Player_4
};

enum BulletTypes
{
	Player_1_Main,
	Player_2_Main,
	Player_3_Main,
	Player_4_Main,


	Emery_1_1Main,
	Emery_1_2Main,
	Emery_1_3Main,
	Emery_1_Boos_1Main,
	Emery_1_Boos_2Main
};


class CustomTools : public Layer
{
public :
	static Animate* CreateAnimate(const char* Path, int num, float Time, int Loop, int DefualtFrist = 0, bool IsDouble = true);
	

	
};

