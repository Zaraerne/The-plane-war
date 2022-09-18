#pragma once
#include "cocos2d.h"

using namespace cocos2d;

enum SceneType
{
	Log_Scene,
	Load_Scens,
	GameLog_Scene,
	Checkpoint_Choese, // �ؿ�ѡ��
	Plane_select,	// ѡ��ս��
	Strthing_Scene,	// ǿ������
	PlayGameScene	// ��ʼ��Ϸ
};

class Scenes : public Layer
{
public:
	CREATE_FUNC(Scenes);
	virtual bool init() override;
	static Scene* CreateScene(SceneType);


};

