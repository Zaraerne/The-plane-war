#pragma once
#include "../../CustomTools.h"



class MyPlayer : public Sprite
{
	
public:
	virtual bool init()override;
	static MyPlayer* MyPlayer::Create(Plane_Type type);
	MyPlayer(Plane_Type type){ this->type = type; }

private:
	void UpdateUI();
	virtual void onEnter() override;
	Sprite* MyPlane;
	Sprite* Left_LJ;
	Sprite* Right_LJ;

	Plane_Type type;


private:
	std::string MyPlanePath;
	std::string ToLeft;
	std::string ToRight;
	
	void Stood(float date);
	void Stood_S(float date);


	float X;
	float Y;

	Sprite* Shan;
};

