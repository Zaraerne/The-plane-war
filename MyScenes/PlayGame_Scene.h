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
	// �޵�
	bool Isinvincible;
	// UI
	ImageView* Relaxed;
	Button* Pause;
	// ��Ϣ��
	ImageView* Infomation;
	LabelAtlas* Juew;	// ��ʯ
	LabelAtlas* Wake;	// ����
	Button* Hedan;	// �˵�
	Button* Hudun;	// ����


	MyPlayer* plane;
	list<Emery*> EmeryLives;
	list<MyBullets*> MyBulletLives;
	list<MyBullets*> EmeryButLives;

private:
	// ��ʯ�������ı�
	void LifeChange();

	// ��������
	void CreateEmery_1(float date);
	void CreateEmery_2(float date);
	void CreateEmery_3(float date);
	void CreateEmery_Boss_1(float date);

	virtual void onEnter()override;

	virtual void update(float date)override;
	void Consider1();
	void Consider2();
	void Consider3();
	// �޵�
	void Invincible();

	void PlaneResurgence();


	// ��Ϸ��ͣ
	void GamePause();
	// ��Ϸ����
	void GameSume();
};

