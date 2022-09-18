#pragma once
#include "../CustomTools.h"

class Emery : public Sprite
{
public:
	
	Emery(Emery_Type Type, Vec2 dir);
	~Emery();
	
	static Emery* CreateEmery(Emery_Type Type, Vec2 dir = Vec2(0, -1));
	virtual bool init()override;

	float GetSpeed(){ return Speed; }
	int GetHp(){ return Hp; }
	void SetDir(Vec2 dir){ Dir = dir; }
	Emery_Type GetType(){ return Type; }

	//  ‹µΩ…À∫¶
	void TakeDamege(float damege);

	// …‰ª˜
	void StoodType_1();
	void StoodType_1_SCH(float date);

private:
	Emery_Type Type;

	int Hp;
	float Speed;
	Vec2 Dir;

private:
	virtual void onEnter()override;

	virtual void update(float date)override;

	

};

