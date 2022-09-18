#pragma once

#include "../../CustomTools.h"


class Checkpoint_Choese_Scene : public Layer
{
public:
	CREATE_FUNC(Checkpoint_Choese_Scene);
	virtual bool init()override;



private:
	PageView* pagelist;
	Sprite* BaoXi;
	UserDefault* ReUse;
	ImageView* _reuse;
	RepeatForever* BossMove;
	ImageView* BaoXiAbout;
	ImageView* AboutMe_about;
	RepeatForever* MoveLine;
	ImageView** Lock;


	void PagelistCallBackCH(Ref *sender, Widget::TouchEventType type);
	void CALL_BACK_BAOXI(Ref*, Widget::TouchEventType);
	void CALL_BACK_Left(Ref*, Widget::TouchEventType);
	void CALL_BACK_Right(Ref*, Widget::TouchEventType);

	virtual void update(float date)override;
};

