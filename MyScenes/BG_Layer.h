#pragma once
#include "../../CustomTools.h"

class BG_Layer:public Layer
{
public:
	virtual bool init()override;
	CREATE_FUNC(BG_Layer);

	void SetTeture(std::string path);
	void SetSpeed(float Speed);
private:
	void MoveTo(float date);
	Sprite*bg_1;
	Sprite*bg_2;
	float Speed;

	CCMoveBy* By;
	RepeatForever* repeat;
};

