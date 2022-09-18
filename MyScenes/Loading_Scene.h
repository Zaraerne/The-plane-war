#pragma once
#include "../../CustomTools.h"

class Loading_Scene : public Layer
{
private:
	Size Visable;
	LoadingBar* loadingbar;
	float per;
	Text* percent;
	Sprite* Bg;
	ImageView* view;

	void _CallFunc();
public:

	CREATE_FUNC(Loading_Scene);
	virtual bool init() override;
	virtual void update(float date) override;
};

