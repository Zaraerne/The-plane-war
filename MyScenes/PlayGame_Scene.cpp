#include "PlayGame_Scene.h"
#include "../Scenes/Scenes.h"

bool PlayGame_Scene::init()
{
	if (!Layer::create())
		return false;
	BG_Layer* BG = BG_Layer::create();
	BG->SetTeture("bg/bg3.jpg");
	BG->SetSpeed(20);
	addChild(BG);

	EmeryLives = EmeryManege::getInstance()->getEmeryLives();
	MyBulletLives = BulletsManeger::getInstance()->getPlyerLiveBut();
	EmeryButLives = BulletsManeger::getInstance()->getEmeryLiveBut();
	
	schedule(schedule_selector(PlayGame_Scene::CreateEmery_1), 2.0f, -1, 7);
	schedule(schedule_selector(PlayGame_Scene::CreateEmery_2),2.0f ,-1, 9);
	schedule(schedule_selector(PlayGame_Scene::CreateEmery_3), 2.0f, -1, 9);
	schedule(schedule_selector(PlayGame_Scene::CreateEmery_Boss_1), 2.0f, 0, 9);
	
	scheduleUpdate();

	
	return true;

}

// 无敌
void PlayGame_Scene::Invincible()
{
	Isinvincible = true;
	CallFunc* fun = CallFunc::create([&]()
	{
		Isinvincible = false;
	});
	DelayTime* time = DelayTime::create(4.1f);
	Sequence* sec = Sequence::create(time, fun, NULL);
	this->runAction(sec);
}


void PlayGame_Scene::onEnter()
{
	Layer::onEnter();
	
	switch (MyData->getIntegerForKey("Cur_PE"))
	{
	case 1:
		plane = MyPlayer::Create(Player_1);
		
		break;
	case 2:
		plane = MyPlayer::Create(Player_2);
		break;
	case 3:
		plane = MyPlayer::Create(Player_3);
		break;
	case 4:
		plane = MyPlayer::Create(Player_4);
		break;

	default:
		break;
	}
	Invincible();
	addChild(plane);
	plane->setPosition(_Visable.width / 2, 0);


	// UI界面
	Relaxed = ImageView::create("scene/gameUI/pausing.png");
	// 重新开始
	Button* Replay = Button::create("scene/xinZeng2/shengliANDshiBai2/New_chongXinKaiShi_btn1.png",
		"scene/xinZeng2/shengliANDshiBai2/New_chongXinKaiShi_btn2.png");
	Replay->addTouchEventListener([&](Ref* ref, Widget::TouchEventType type)
	{
		if (type == Widget::TouchEventType::ENDED)
		{
			_director->replaceScene(Scenes::CreateScene(PlayGameScene));
		}
	});
	Relaxed->addChild(Replay,1);
	// 游戏继续
	Button* GoOn = Button::create("scene/gameUI/btn_jiXuZhanDou.png", "scene/gameUI/btn_jiXuZhanDou2.png");
	GoOn->addTouchEventListener([&](Ref* ref, Widget::TouchEventType type)
	{
		if (type == Widget::TouchEventType::ENDED)
		{
			Relaxed->setVisible(false);
			GameSume();
		}
	});
	Relaxed->addChild(GoOn);
	addChild(Relaxed,2);
	Relaxed->setPosition(_Visable/2 + Size(0, 100));
	Replay->setPosition(Relaxed->getContentSize() / 2 + Size(0, -130));
	GoOn->setPosition(Relaxed->getContentSize() / 2 + Size(0, -200));
	Relaxed->setVisible(false);

	// 左上角
	Infomation = ImageView::create("scene/xinZeng2/New_Ui_1.png");
	addChild(Infomation);
	Infomation->setPosition(Size(0, _Visable.height) + Size(Infomation->getContentSize().width/2,-Infomation->getContentSize().height/2));
	Juew = LabelAtlas::create(__String::createWithFormat("%d",MyData->getIntegerForKey("Jewel"))->getCString(), "scene/xinZeng2/New_Ui_NumberN.png", 19, 28, '0');
	Wake = LabelAtlas::create(__String::createWithFormat("%d", MyData->getIntegerForKey("Life"))->getCString(), "scene/xinZeng2/New_Ui_NumberN.png", 19, 28, '0');
	Infomation->addChild(Juew);
	Infomation->addChild(Wake);
	Juew->setPosition(Vec2(54, 45));
	Wake->setPosition(Vec2(54, 13));

	Pause = Button::create("scene/xinZeng2/New_Ui_PauseBtn.png");
	addChild(Pause);
	Pause->setPosition(_Visable - Pause->getContentSize() / 2);
	Pause->addTouchEventListener([&](Ref* ref, Widget::TouchEventType type)
	{
		if (type == Widget::TouchEventType::ENDED)
		{
			Relaxed->setVisible(true);
			GamePause();	
		}
	});
	Pause->setPressedActionEnabled(true);


}
// 游戏暂停
void PlayGame_Scene::GamePause()
{
	plane->pause();
	MyBulletLives = BulletsManeger::getInstance()->getPlyerLiveBut();
	EmeryLives = EmeryManege::getInstance()->getEmeryLives();
	EmeryButLives = BulletsManeger::getInstance()->getEmeryLiveBut();
	this->pause();
	for (auto mybut : MyBulletLives)
	{
		mybut->pause();
	}
	for (auto Emlive : EmeryLives)
	{
		Emlive->pause();
	}
	for (auto Embut : EmeryButLives)
	{
		Embut->pause();
	}
}
// 游戏继续
void PlayGame_Scene::GameSume()
{
	this->resume();
	plane->resume();
	for (auto mybut : MyBulletLives)
	{
		mybut->resume();
	}
	for (auto Emlive : EmeryLives)
	{
		Emlive->resume();
	}
	for (auto Embut : EmeryButLives)
	{
		Embut->resume();
	}
}


void PlayGame_Scene::CreateEmery_1(float date)
{
	Emery* emery = EmeryFactory::CreateEmery(Emery_1);
	addChild(emery);
	emery->setPosition(RandomHelper::random_real<float>(20, 380),
		_Visable.height - emery->getContentSize().height / 2);
	emery->StoodType_1();


}
void PlayGame_Scene::CreateEmery_2(float date)
{
	Emery* emery = EmeryFactory::CreateEmery(Emery_2);
	addChild(emery);
	emery->setPosition(_Visable.width / 2, _Visable.height - emery->getContentSize().height / 2);
	emery->runAction(CCMoveBy::create(2.0f,Vec2(0, -50)));
	emery->StoodType_1();
}
void PlayGame_Scene::CreateEmery_3(float date)
{
	Emery* emery = EmeryFactory::CreateEmery(Emery_3);
	addChild(emery);
	emery->setPosition(RandomHelper::random_real<float>(20, 380),
		_Visable.height - emery->getContentSize().height / 2);
	emery->StoodType_1();
}
void PlayGame_Scene::CreateEmery_Boss_1(float date)
{
	Emery* emery = EmeryFactory::CreateEmery(Boss_1);
	addChild(emery);
	emery->setPosition(_Visable.width/2,
		_Visable.height + emery->getContentSize().height/2);
	emery->runAction(CCMoveBy::create(3.0f, Vec2(0, -emery->getContentSize().height)));
	emery->StoodType_1();
}
void PlayGame_Scene::update(float date)
{
	if (!Isinvincible)
	{
		Consider1();
		Consider3();
	}
	Consider2();
	




}
// 宝石和生命改变
void PlayGame_Scene::LifeChange()
{
	
	if (MyData->getIntegerForKey("Life") <= 0)
	{
		MyData->setIntegerForKey("Life", MyData->getIntegerForKey("Life") - 1);
		Wake->setString(__String::createWithFormat("%d", MyData->getIntegerForKey("Life"))->getCString());
	}
	else
	{
		CCLOG("没命了!");
	}
}


void PlayGame_Scene::PlaneResurgence()
{
	removeChild(plane);
	plane = nullptr;

	switch (MyData->getIntegerForKey("Cur_PE"))
	{
	case 1:
		plane = MyPlayer::Create(Player_1);

		break;
	case 2:
		plane = MyPlayer::Create(Player_2);
		break;
	case 3:
		plane = MyPlayer::Create(Player_3);
		break;
	case 4:
		plane = MyPlayer::Create(Player_4);
		break;

	default:
		break;
	}

	addChild(plane);
	plane->setPosition(_Visable.width / 2, 0);
	Invincible();
}

// 敌方子弹与我机
void PlayGame_Scene::Consider1()
{
	for (MyBullets* pst : BulletsManeger::getInstance()->getEmeryLiveBut())
	{
		if (pst->getBoundingBox().containsPoint(plane->getPosition()))
		{
			PlaneResurgence();

			BulletsManeger::getInstance()->EmeryButToDeath(pst);
			return;
		}
	}

}
// 我方子弹和敌机
void PlayGame_Scene::Consider2()
{
	
	// 迭代器
	list<Emery*>::iterator emit;
	list<MyBullets*>::iterator myit;
	MyBulletLives = BulletsManeger::getInstance()->getPlyerLiveBut();
	EmeryLives = EmeryManege::getInstance()->getEmeryLives();
	for (myit = MyBulletLives.begin(); myit != MyBulletLives.end(); ++myit)
	{
		for (emit = EmeryLives.begin(); emit != EmeryLives.end(); ++emit)
		{		
			if ((*emit)->getBoundingBox().containsPoint((*myit)->getPosition()))
			{
				BulletsManeger::getInstance()->ToDeath((*myit));
				(*emit)->TakeDamege((*myit)->TakeDamage());
			}
		}
	}

	

	
	//// 序列for循环
	//for (auto myit : BulletsManeger::getInstance()->getPlyerLiveBut())
	//{
	//	for (auto emit : EmeryManege::getInstance()->getEmeryLives())
	//	{
	//		if (emit->getBoundingBox().containsPoint(myit->getPosition()))
	//		{
	//			EmeryManege::getInstance()->ToDeathes(emit);
	//			BulletsManeger::getInstance()->ToDeath(myit);
	//		}
	//	}
	//}

}
// 敌机和我方
void PlayGame_Scene::Consider3()
{
	for (Emery* emery : EmeryManege::getInstance()->getEmeryLives())
	{
		if (emery->getBoundingBox().containsPoint(plane->getPosition()))
		{
			PlaneResurgence();			// 复活
			emery->TakeDamege(1000.0f);


		}

	}
}