#include "Checkpoint_Choese_Scene.h"
#include "../Scenes/Scenes.h"

bool Checkpoint_Choese_Scene::init()
{
	if (!Layer::init())
		return false;

	

	Lock = new ImageView*[12];
	CCMoveBy* moveby = CCMoveBy::create(3.0f, Vec2(0, -326));
	Place* move = Place::create(Vec2(_Visable.width / 2, 324));
	Sequence* MyMoveSequence = Sequence::create(moveby, move, NULL);
	MoveLine = RepeatForever::create(MyMoveSequence);

	Sprite* BG_0 = Sprite::create("scene\\xinZeng2\\chooseGuan2\\New_xuanGuanBg.jpg");
	BaoXiAbout = ImageView::create("scene/xinZeng2/libao2/New_liBao1_1.png");
	Button* liqu = Button::create("scene/xinZeng2/libao2/New_liBao_buyPlayer_lingQuBtn.png");
	AboutMe_about = ImageView::create("bg/AboutGame.png");
	AboutMe_about->setPosition(_Visable / 2);
	AboutMe_about->setVisible(false);
	addChild(AboutMe_about, 6);
	ReUse = UserDefault::getInstance();
	for (int i = 1; i < 4; ++i)
	{
		for (int j = 1; j < 3; ++j)
		{
			__String* KEY = __String::createWithFormat("Choese_Scene_BaoXi_%d_%d", i, j);
			__String* path = __String::createWithFormat
				("scene/xinZeng2/libao2/New_liBao%d_%d.png", i, j);

			if (ReUse->getStringForKey(KEY->getCString()) == "")
			{
				ReUse->setStringForKey(KEY->getCString(), path->getCString());
			}
		}
	}

	addChild(BaoXiAbout, 10);
	liqu->setPosition(Size(_Visable.width / 2 - 15, 10));
	BaoXiAbout->setAnchorPoint(Vec2::ANCHOR_MIDDLE_BOTTOM);
	liqu->setAnchorPoint(Vec2::ANCHOR_MIDDLE_BOTTOM);
	BaoXiAbout->setVisible(false);
	BaoXiAbout->setPosition(_Visable / 2 - Size(0, BaoXiAbout->getContentSize().height / 2));
	BaoXiAbout->addChild(liqu);

	BG_0->setPosition(_Visable / 2);
	addChild(BG_0, 0);
	pagelist = PageView::create();
	// 1.设置大小
	pagelist->setContentSize(Size(469, 450));
	pagelist->setAnchorPoint(Vec2::ANCHOR_MIDDLE_BOTTOM);
	pagelist->setPosition(Vec2(_Visable.width / 2, 255));
	pagelist->setDirection(PageView::Direction::HORIZONTAL);

	EaseSineIn* sinin = EaseSineIn::create(CCMoveBy::create(3.0f, Vec2(0, 20)));
	Sequence* sequencemove = Sequence::create(sinin->clone(), sinin->reverse()->clone(), NULL);
	BossMove = RepeatForever::create(sequencemove->clone());

	int pageCount = 12;
	for (int i = 0; i < pageCount; ++i)
	{
		Layout* layout = Layout::create();


		Sprite* myLine = Sprite::create("scene/xinZeng2/chooseGuan2/New_xuanGuanSaoMiao.png");
		Lock[i] = ImageView::create("scene/xinZeng2/chooseGuan2/New_suo.png");
		
		Lock[i]->setPosition(Vec2(_Visable / 2)-Vec2(0,250));
		myLine->setPosition(Vec2(_Visable.width / 2, 324));

		myLine->setOpacity(200);
		myLine->runAction(MoveLine->clone());

		layout->setContentSize(Size(469, 343));
		layout->setBackGroundColorType(Layout::BackGroundColorType::NONE);

		ImageView* xuanGuanBg = ImageView::create(__String::createWithFormat("scene/xinZeng2/chooseGuan2/New_xuanGuanBg_small%d.png", i + 1)->getCString());
		ImageView* xuanGuanBg_title = ImageView::create(__String::createWithFormat("scene/xinZeng2/chooseGuan2/New_xuanGuanName%d.png", i + 1)->getCString());

		xuanGuanBg->setAnchorPoint(Vec2::ANCHOR_MIDDLE_BOTTOM);
		xuanGuanBg_title->setAnchorPoint(Vec2::ANCHOR_MIDDLE_BOTTOM);
		xuanGuanBg->setPosition(Size(_Visable.width / 2, 0));
		xuanGuanBg_title->setPosition(Size(_Visable.width / 2, 343));

		Sprite* Boos = Sprite::create(__String::createWithFormat("npc/boss/boss%d.png", 1 + i)->getCString());
		Boos->setPosition(Vec2(_Visable.width / 2, 150));
		Boos->setScale(0.7f);
		Boos->runAction(BossMove->clone());


		
		layout->addChild(xuanGuanBg);
		layout->addChild(xuanGuanBg_title);
		layout->addChild(Boos);
		layout->addChild(myLine, 2);
		layout->addChild(Lock[i]);
		pagelist->insertPage(layout, i);
	}

	for (int i = 0; i < MyData->getIntegerForKey("Cur_GK"); ++i)
	{
		Lock[i]->setVisible(false);
	}


	ParticleFire* fire = ParticleFire::create();
	fire->setPosition(Vec2(_Visable.width / 2 + 5, 270));
	fire->setPosVar(Vec2(_Visable.width / 2 - 40, 0));
	fire->setLife(1.7f);
	addChild(fire, 7);

	BaoXi = Sprite::create("scene/xinZeng2/chooseGuan2/New_baoXiang1.png");
	BaoXi->setPosition(Vec2(135, 180));
	BaoXi->runAction(CustomTools::CreateAnimate("scene/xinZeng2/chooseGuan2/New_baoXiang%d.png", 8,
		0.2f, -1, 1, false));
	addChild(BaoXi, 6);
	Button* ClickBut = Button::create("scene/xinZeng2/chooseGuan2/BaoXi_Butoon.png");
	ClickBut->setContentSize(BaoXi->getContentSize());
	ClickBut->setPosition(BaoXi->getPosition());
	ClickBut->addTouchEventListener(CC_CALLBACK_2(Checkpoint_Choese_Scene::CALL_BACK_BAOXI, this));
	ClickBut->setOpacity(0);

	addChild(ClickBut, 6);


	// 推荐使用

	for (int i = 0; i < pageCount; ++i)
	{
		__String * ReuserPath = __String::createWithFormat("Reuse_%d", i);
		if (ReUse->getStringForKey(ReuserPath->getCString()) == "")
		{
			__String* MyReuse = __String::createWithFormat("scene/xinZeng2/chooseGuan2/New_xuanGuan_tuiJian%d.png",
				RandomHelper::random_int(1, 4));
			ReUse->setStringForKey(ReuserPath->getCString(), MyReuse->getCString());
		}
	}

	_reuse = ImageView::create(ReUse->getStringForKey("Reuse_0"));
	addChild(_reuse, 6);
	_reuse->setPosition(Vec2(_Visable.width - 135, 210));

	pagelist->addTouchEventListener(CC_CALLBACK_2(Checkpoint_Choese_Scene::PagelistCallBackCH, this));
	addChild(pagelist, 5);


	Button* Return = Button::create("scene/xinZeng2/shangdian2/New_Btn_back.png");
	addChild(Return, 6);
	Return->setPosition(Vec2(55, 50));
	Return->addTouchEventListener([&](Ref* ref, Widget::TouchEventType type)
	{
		if (type == Widget::TouchEventType::ENDED)
		{
			_director->replaceScene(Scenes::CreateScene(GameLog_Scene));
		}


	});

	Button* PlayGame = Button::create("scene/xinZeng2/chooseGuan2/New_begin.png");
	addChild(PlayGame, 6);
	PlayGame->setPosition(Vec2(_Visable.width / 2, 50));
	PlayGame->addTouchEventListener([&](Ref* ref, Widget::TouchEventType type)
	{
		if (pagelist->getCurPageIndex()<MyData->getIntegerForKey("Cur_GK"))
		if (type == Widget::TouchEventType::ENDED)
		{
			
			_director->replaceScene(Scenes::CreateScene(Plane_select));
		}
	});

	Button* About = Button::create("scene/xinZeng2/chooseGuan2/Btn_guanYu.png");
	addChild(About, 6);
	About->setPosition(Vec2(_Visable.width -60, 50));
	About->addTouchEventListener([&](Ref* ref, Widget::TouchEventType type)
	{
		if (type == Widget::TouchEventType::ENDED)
		{
			if (!AboutMe_about->isVisible())
				AboutMe_about->setVisible(true);
			else
				AboutMe_about->setVisible(false);


			BaoXiAbout->setVisible(false);

		}
	}
		);


	Button* ToRight = Button::create("scene/xinZeng2/chooseGuan2/New_xuanGuan_jianTou2.png");
	addChild(ToRight, 6);
	ToRight->setPosition(Vec2(_Visable.width - 50, _Visable.height/2));
	Button* ToLeft = Button::create("scene/xinZeng2/chooseGuan2/New_xuanGuan_jianTou.png");
	addChild(ToLeft, 6);
	ToLeft->setPosition(Vec2(60, _Visable.height / 2));
	ToRight->addTouchEventListener(CC_CALLBACK_2(Checkpoint_Choese_Scene::CALL_BACK_Right, this));
	ToLeft->addTouchEventListener(CC_CALLBACK_2(Checkpoint_Choese_Scene::CALL_BACK_Left, this));

	pagelist->setCurPageIndex(MyData->getIntegerForKey("Cur_GK") - 1);
	scheduleUpdate();
	return true;
}



void Checkpoint_Choese_Scene::CALL_BACK_Left(Ref* ref, Widget::TouchEventType type)
{
	
	if (type == Widget::TouchEventType::ENDED)
	{
		pagelist->setCurPageIndex((12 + pagelist->getCurPageIndex() - 1) % 12);

	}
}
void Checkpoint_Choese_Scene::CALL_BACK_Right(Ref* ref, Widget::TouchEventType type)
{
	if (type == Widget::TouchEventType::ENDED)
	{
		pagelist->setCurPageIndex((pagelist->getCurPageIndex() + 1) % 12);

	}
}

void Checkpoint_Choese_Scene::update(float date)
{
	_reuse->loadTexture(ReUse->getStringForKey(
		__String::createWithFormat("Reuse_%d", pagelist->getCurPageIndex())->getCString()
		));
}

void Checkpoint_Choese_Scene::CALL_BACK_BAOXI(Ref* ref, Widget::TouchEventType type)
{
	switch (type)
	{
	case cocos2d::ui::Widget::TouchEventType::BEGAN:
		

		BaoXi->setScale(1.2f);

		break;
	case cocos2d::ui::Widget::TouchEventType::MOVED:
		break;
	case cocos2d::ui::Widget::TouchEventType::ENDED:
	
		BaoXiAbout->loadTexture(ReUse->getStringForKey(
			__String::createWithFormat(
			"Choese_Scene_BaoXi_%d_%d",
			RandomHelper::random_int(1, 3),
			RandomHelper::random_int(1, 2))->getCString()
			));
		BaoXi->setScale(1.0f);

		AboutMe_about->setVisible(false);

		if (BaoXiAbout->isVisible())
		{
			BaoXiAbout->setVisible(false);
		}
		else
		{
			BaoXiAbout->setVisible(true);
		}
		

		break;
	case cocos2d::ui::Widget::TouchEventType::CANCELED:
		BaoXi->setScale(1.0f);
		break;
	default:
		break;
	}

}


void Checkpoint_Choese_Scene::PagelistCallBackCH(Ref *sender, Widget::TouchEventType type)
{


	if (type == Widget::TouchEventType::ENDED)
	{
		// CCLOG("%d",pagelist->getCurPageIndex());
	}

}