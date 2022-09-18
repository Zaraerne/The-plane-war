#pragma once
#include "../CustomTools.h"




class MyBullets:public Sprite
{
public:
	MyBullets(BulletTypes type, Vec2 Dir){ this->type = type; this->Dir = Dir; }
	static MyBullets* Create(BulletTypes type, Vec2 Dir = Vec2(0, 1));
	
public:
	BulletTypes getType()
	{
		return type;
	}

	// 一定要调用StartMove();
	void StartMove();
	void SetDir(Vec2 Dir);

	float TakeDamage()
	{
		return Daname;
	}

private:
	virtual void update(float date)override;
	virtual bool init()override;
	void ChangeAnlege();
	void BulletCreate();

private:
	BulletTypes type;
	float Speed;
	int Daname;
	Vec2 Dir;

};

