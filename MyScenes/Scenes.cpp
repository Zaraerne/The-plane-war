#include "Scenes.h"
#include "../Login_Scene/Login_Scene.h"
#include "../Checkpoint_Choese_Scene/Checkpoint_Choese_Scene.h"
#include "../GameLoging_Scene/GameLoging_Scene.h"
#include "../Loading_Scene/Loading_Scene.h"
#include "../Plane_Scet_Scene/PlaneXZ_Scene.h"
#include "../strengthening_Scene/Strthing.h"
#include "../PlayGame_Scene/PlayGame_Scene.h"

bool Scenes::init()
{
	if (!Layer::init())
		return false;




	return true;


}
Scene* Scenes::CreateScene(SceneType type)
{
	Scene* pScene = Scene::create();
	Layer* layer = Layer::create();
	switch (type)
	{
	case Log_Scene:
		layer = Login_Scene::create();
		pScene->addChild((Login_Scene*)layer);	
		break;
	case Load_Scens:
		layer = Loading_Scene::create();
		pScene->addChild((Loading_Scene*)layer);
		break;
	case GameLog_Scene:
		layer = GameLoging_Scene::create();
		pScene->addChild((GameLoging_Scene*)layer);
		break;
	case Checkpoint_Choese:
		layer = Checkpoint_Choese_Scene::create();
		pScene->addChild((Checkpoint_Choese_Scene*)layer);
		break;

	case Plane_select:
		layer = PlaneXZ_Scene::create();
		pScene->addChild((PlaneXZ_Scene*)layer);
		break;

	case Strthing_Scene:
		layer = Strthing::create();
		pScene->addChild((Strthing*)layer);
		break;
	case PlayGameScene:
		layer = PlayGame_Scene::create();
		pScene->addChild((PlayGame_Scene*)layer);
		break;
	default:
		break;
	}

	return pScene;
}