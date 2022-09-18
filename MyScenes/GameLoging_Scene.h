#pragma once
#include "../../CustomTools.h"



class GameLoging_Scene:public Layer
{
public:
	CREATE_FUNC(GameLoging_Scene);
	virtual bool init()override;

private:
	MenuItemImage* BG;
	ImageView* GameHelpView;
	ImageView* AboutGame;
	Sprite* viewanimate;
	UserDefault* ReUse;
	

	void BGCALLBACK(Ref*);
	void GameHelpCallBack(Ref*, Widget::TouchEventType);
	void GameAboutMe(Ref*, Widget::TouchEventType);
	
};

