#pragma once
#include "cocos2d.h"

using namespace cocos2d;

enum SceneType
{
	Log_Scene,
	Load_Scens,
	GameLog_Scene,
	Checkpoint_Choese, // 关卡选择
	Plane_select,	// 选择战机
	Strthing_Scene,	// 强化机甲
	PlayGameScene	// 开始游戏
};

class Scenes : public Layer
{
public:
	CREATE_FUNC(Scenes);
	virtual bool init() override;
	static Scene* CreateScene(SceneType);


};

