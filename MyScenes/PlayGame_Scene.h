#pragma once
#include "../../Emery/EmeryFactory/EmeryFactory.h"
#include "../../MyBullets/BulletsManeger/BulletsManeger.h"
#include "MyPlayer.h"
#include "BG_Layer.h"

class PlayGame_Scene : public Layer
{
public:
	virtual bool init()override;
	CREATE_FUNC(PlayGame_Scene);

private:
	// 无敌
	bool Isinvincible;
	// UI
	ImageView* Relaxed;
	Button* Pause;
	// 信息栏
	ImageView* Infomation;
	LabelAtlas* Juew;	// 钻石
	LabelAtlas* Wake;	// 生命
	Button* Hedan;	// 核弹
	Button* Hudun;	// 护盾


	MyPlayer* plane;
	list<Emery*> EmeryLives;
	list<MyBullets*> MyBulletLives;
	list<MyBullets*> EmeryButLives;

private:
	// 宝石和生命改变
	void LifeChange();

	// 创建敌人
	void CreateEmery_1(float date);
	void CreateEmery_2(float date);
	void CreateEmery_3(float date);
	void CreateEmery_Boss_1(float date);

	virtual void onEnter()override;

	virtual void update(float date)override;
	void Consider1();
	void Consider2();
	void Consider3();
	// 无敌
	void Invincible();

	void PlaneResurgence();


	// 游戏暂停
	void GamePause();
	// 游戏继续
	void GameSume();
};

