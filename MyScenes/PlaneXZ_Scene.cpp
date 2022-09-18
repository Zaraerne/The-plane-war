#include "PlaneXZ_Scene.h"
#include "../../Bullet/Bullet.h"
#include "../Scenes/Scenes.h"


PlaneXZ_Scene::PlaneXZ_Scene()
{
}


PlaneXZ_Scene::~PlaneXZ_Scene()
{
}


bool PlaneXZ_Scene::init()
{
	if (!Layer::init())
		return false;

	Sprite* BG = Sprite::create("scene/xinZeng2/shangdian2/New_xuanFeiJi_Bg.jpg");
	addChild(BG, 0);
	BG->setPosition(_Visable / 2);

	Plane_List = PageView::create();
	Plane_List->setContentSize(Size(480,600));
	Plane_List->setAnchorPoint(Vec2::ANCHOR_MIDDLE_BOTTOM);
	Plane_List->setPosition(Vec2(_Visable.width /2, 150));
	Plane_List->setDirection(PageView::Direction::HORIZONTAL);
	
	

	int pageCount = 4;
	for (int i = 0; i < pageCount; ++i)
	{
		Layout* layout = Layout::create();

		layout->setContentSize(Size(_Visable.width / 2, 400));
		layout->setBackGroundColorType(Layout::BackGroundColorType::NONE);

		ImageView* BG = ImageView::create(__String::createWithFormat("scene/xinZeng2/shangdian2/New_xuanFeiJi_SmallBg%d.png", i + 1)->getCString());
		ImageView* InFo = ImageView::create(__String::createWithFormat("scene/xinZeng2/shangdian2/New_xuanFeiJi_Name%d.png", i + 1)->getCString());

		BG->setAnchorPoint(Vec2::ANCHOR_MIDDLE_BOTTOM);
		InFo->setAnchorPoint(Vec2::ANCHOR_MIDDLE_BOTTOM);
		BG->setPosition(Size(_Visable.width / 2, 170));
		InFo->setPosition(Size(_Visable.width / 2, 0));

		Sprite* Plane = Sprite::create(__String::createWithFormat("player/player%d/player%d_1.png", i + 1, 1 + i)->getCString());
		Plane->setAnchorPoint(Vec2::ANCHOR_MIDDLE_BOTTOM);
		Plane->setPosition(Size(_Visable.width / 2, 170));
		Sprite* liaoji_left;
		Sprite* liaoji_Right;

		
		Bullet* MainBut;	 // 主机子弹
		Bullet* MianBut_Test;
		Bullet* But_Right;	// 右僚机子弹
		Bullet* But_Left;	// 左僚机子弹
		std::vector<Vec2> vdirs{ Vec2(RandomHelper::random_int(-1, 1), RandomHelper::random_int(-1, 1)), 
			Vec2(RandomHelper::random_int(-1, 1), RandomHelper::random_int(-1, 1)),
			Vec2(RandomHelper::random_int(-1, 1), RandomHelper::random_int(-1, 1)),
			Vec2(RandomHelper::random_int(-1, 1), RandomHelper::random_int(-1, 1)),
			Vec2(RandomHelper::random_int(-1, 1), RandomHelper::random_int(-1, 1)) };
		CCLOG("%d", vdirs.size());
		switch (i)
		{
		case 0:
			Plane->runAction(CustomTools::CreateAnimate("player/player1/player1_%d.png",8,0.1f,-1,1,false));
			liaoji_left = Sprite::create("player/LJ/LJ4baoZou1.png");
			liaoji_left->runAction(CustomTools::CreateAnimate("player/LJ/LJ4baoZou%d.png", 6, 0.1f, -1, 1, false));
			Plane->addChild(liaoji_left);
			liaoji_left->setPosition(Vec2(0, 0));
			
			

			liaoji_Right = Sprite::create("player/LJ/LJ4baoZou1.png");
			liaoji_Right->runAction(CustomTools::CreateAnimate("player/LJ/LJ4baoZou%d.png", 6, 0.1f, -1, 1, false));
			Plane->addChild(liaoji_Right);
			liaoji_Right->setPosition(Vec2(120, 0));

			MainBut = Bullet::create();
			MainBut->SetFilePath("playerBt/playerBt_dianJiangPao_Yellow_baoZou.png", Plane->getPosition()+Point(0,50), Vec2(0, 10),30);
			MainBut->setAnchorPoint(Vec2::ANCHOR_MIDDLE_BOTTOM);
			
			layout->addChild(MainBut, 10);

			But_Right = Bullet::create();
			But_Right->SetFilePath("playerBt/playerBt_huiXuan.png", Plane->getPosition() + Point(50, 0), Vec2(1, 10));
			But_Right->setAnchorPoint(Vec2::ANCHOR_MIDDLE_BOTTOM);
			
			layout->addChild(But_Right, 10);

			But_Left = Bullet::create();
			
			But_Left->setAnchorPoint(Vec2::ANCHOR_MIDDLE_BOTTOM);
			But_Left->SetFilePath("playerBt/playerBt_huiXuan.png", Plane->getPosition() + Point(-50, -0), Vec2(-1, 10));
			layout->addChild(But_Left, 10);
			

			break;
		case 1:
			Plane->runAction(CustomTools::CreateAnimate("player/player2/player2_%d.png", 8, 0.1f, -1, 1, false));
			liaoji_left = Sprite::create("player/LJ/LJ4baoZou1.png");
			liaoji_left->runAction(CustomTools::CreateAnimate("player/LJ/LJ3_baoZou%d.png", 5, 0.1f, -1, 1, false));
			Plane->addChild(liaoji_left);
			liaoji_left->setPosition(Vec2(0, 0));

			liaoji_Right = Sprite::create("player/LJ/LJ4baoZou1.png");
			liaoji_Right->runAction(CustomTools::CreateAnimate("player/LJ/LJ3_baoZou%d.png", 5, 0.1f, -1, 1, false));
			Plane->addChild(liaoji_Right);
			liaoji_Right->setPosition(Vec2(120, 0));

			
			MianBut_Test = Bullet::create();
			MianBut_Test->Is_Shanshe("player_fire2.png", Plane->getPosition() + Vec2(0, 50), vdirs);
			MianBut_Test->setAnchorPoint(Vec2::ANCHOR_MIDDLE_BOTTOM);

			layout->addChild(MianBut_Test, 10);

			break;
		case 2:
			Plane->runAction(CustomTools::CreateAnimate("player/player3/player3_%d.png", 8, 0.1f, -1, 1, false));


			MianBut_Test = Bullet::create();
			MianBut_Test->DefultStood("player_fire4.png", Plane->getPosition() + Vec2(0, 50));
			MianBut_Test->setAnchorPoint(Vec2::ANCHOR_MIDDLE_BOTTOM);
			layout->addChild(MianBut_Test,10);


			break;
		case 3:
			Plane->runAction(CustomTools::CreateAnimate("player/player4/player4_%d.png", 8, 0.1f, -1, 1, false));
			break;

		default:
			break;
		}
		
		
		layout->addChild(BG);
		layout->addChild(InFo);
		layout->addChild(Plane);
		
		Plane_List->insertPage(layout, i);
	}
	Sprite* Mask = Sprite::create("scene/xinZeng2/shangdian2/New_xuanFeiJi_Bg_ding.png");
	addChild(Mask,7);
	Mask->setPosition(Size(_Visable.width / 2, _Visable.height - Mask->getContentSize().height / 2));

	

	addChild(Plane_List, 2);
	Plane_List->addEventListener([&](Ref*ref, PageView::EventType type)
	{
		switch (type)
		{
		case cocos2d::ui::PageView::EventType::TURNING:
			CCLOG("Current : %d", Plane_List->getCurPageIndex());
			IsBuy();
			break;
		default:
			break;
		}
	});

	Button* ToRight = Button::create("scene/xinZeng2/chooseGuan2/New_xuanGuan_jianTou2.png");
	addChild(ToRight, 6);
	ToRight->setPosition(Vec2(_Visable.width - 50, _Visable.height / 2));
	Button* ToLeft = Button::create("scene/xinZeng2/chooseGuan2/New_xuanGuan_jianTou.png");
	addChild(ToLeft, 6);
	ToLeft->setPosition(Vec2(60, _Visable.height / 2));
	ToRight->addTouchEventListener([&](Ref* ref, Widget::TouchEventType type)
	{
		if (type == Widget::TouchEventType::ENDED)
		{
			Plane_List->setCurPageIndex((Plane_List->getCurPageIndex() + 1) % 4);
			IsBuy();
		}
	});
	ToLeft->addTouchEventListener([&](Ref* ref, Widget::TouchEventType type)
	{
		if (type == Widget::TouchEventType::ENDED)
		{
			Plane_List->setCurPageIndex((4 + Plane_List->getCurPageIndex() - 1) % 4);
			IsBuy();
		}
	});


	// 添加强化战机
	Fight = Button::create("scene/xinZeng2/shangdian2/New_xuanFeiJi_QiangHuaZhanJi_Btn.png");
	Fight->setPressedActionEnabled(true);
	addChild(Fight,6);
	Fight->setPosition(Vec2(_Visable.width/2,55));
	Fight->addTouchEventListener([&](Ref*, Widget::TouchEventType type)
	{
		if (type == Widget::TouchEventType::ENDED && Is_Select())
		{
			MyData->setIntegerForKey("Cur_PE", Plane_List->getCurPageIndex() + 1);
			_director->replaceScene(Scenes::CreateScene(Strthing_Scene));
		}
		if (type == Widget::TouchEventType::ENDED && !Is_Select())
		{
			switch (Plane_List->getCurPageIndex())
			{
			case 1:
				MyData->setBoolForKey("Is_Two", true);
				
				break;

			case 2:
				MyData->setBoolForKey("Is_There", true);

				break;

			case 3:
				MyData->setBoolForKey("Is_Four", true);
				break;

			default:
				break;
			}
			Fight->loadTextureNormal("scene/xinZeng2/shangdian2/New_xuanFeiJi_QiangHuaZhanJi_Btn.png");
		}
	});

	// 添加惊喜
	Button* jixi = Button::create("scene/xinZeng2/shangdian2/New_liBao_buyPlayer.png");
	jixi->setPressedActionEnabled(true);
	addChild(jixi, 6);
	jixi->setPosition(Vec2(_Visable.width - jixi->getContentSize().width/2, 253));

	// 添加礼包
	Button* libao = Button::create("scene/xinZeng2/shangdian2/New_Btn_liBao.png");
	libao->setPressedActionEnabled(true);
	addChild(libao, 6);
	libao->setPosition(Vec2(_Visable.width - jixi->getContentSize().width / 2 - 17, 50));

	// 添加返回
	Button* Return = Button::create("scene/xinZeng2/shangdian2/New_Btn_back.png");
	Return->setPressedActionEnabled(true);
	addChild(Return, 6);
	Return->setPosition(Vec2(jixi->getContentSize().width / 2 + 17 , 50));
	Return->addTouchEventListener([&](Ref * ref,Widget::TouchEventType type)
	{
		if (type == Widget::TouchEventType::ENDED)
		{
			_director->replaceScene(Scenes::CreateScene(Checkpoint_Choese));
		}
	});

	
	LabelAtlas* Life_Val = LabelAtlas::create(__String::createWithFormat("%d",MyData->getIntegerForKey("Life"))->getCString(),
		"scene/jiku/number_messageN.png",14,21,'0');
	Life_Val->setPosition(Vec2(56, 653));
	addChild(Life_Val);

	// scheduleUpdate();
	SetCurPlane();
	return true;
}

bool PlaneXZ_Scene::Is_Select()
{
	switch (Plane_List->getCurPageIndex())
	{
	case 0:
		return MyData->getBoolForKey("Is_Frist");
		break;
	case 1:
		return MyData->getBoolForKey("Is_Two");
		break;
	case 2:
		return MyData->getBoolForKey("Is_There");
		break;
	case 3:
		return MyData->getBoolForKey("Is_Four");
		break;

	default:
		break;
	}

	return false;
}

void PlaneXZ_Scene::update(float date)
{



}
void PlaneXZ_Scene::IsBuy()
{
	
	switch (Plane_List->getCurPageIndex())
	{
	case 0:
		
		if (MyData->getBoolForKey("Is_Frist"))
		{
			CCLOG("Yes");
			Fight->loadTextureNormal("scene/xinZeng2/shangdian2/New_xuanFeiJi_QiangHuaZhanJi_Btn.png");
		}
		else
		{
			CCLOG("No");
			Fight->loadTextureNormal("scene/xinZeng2/shangdian2/New_gouMaiZhanJi_Btn.png");
		}
		break;
	case 1:
		if (MyData->getBoolForKey("Is_Two"))
		{
			CCLOG("Yes");
			Fight->loadTextureNormal("scene/xinZeng2/shangdian2/New_xuanFeiJi_QiangHuaZhanJi_Btn.png");
		}
		else
		{
			CCLOG("No");
			Fight->loadTextureNormal("scene/xinZeng2/shangdian2/New_gouMaiZhanJi_Btn.png");
		}
		break;

	case 2:
		if (MyData->getBoolForKey("Is_There"))
		{
			Fight->loadTextureNormal("scene/xinZeng2/shangdian2/New_xuanFeiJi_QiangHuaZhanJi_Btn.png");
		}
		else
		{
			Fight->loadTextureNormal("scene/xinZeng2/shangdian2/New_gouMaiZhanJi_Btn.png");
		}
		break;

	case 3:
		if (MyData->getBoolForKey("Is_Four"))
		{
			Fight->loadTextureNormal("scene/xinZeng2/shangdian2/New_xuanFeiJi_QiangHuaZhanJi_Btn.png");
		}
		else
		{
			Fight->loadTextureNormal("scene/xinZeng2/shangdian2/New_gouMaiZhanJi_Btn.png");
		}
		break;
	default:
		break;
	}
}

void PlaneXZ_Scene::SetCurPlane()
{
	Plane_List->setCurPageIndex(MyData->getIntegerForKey("Cur_PE")-1);
}