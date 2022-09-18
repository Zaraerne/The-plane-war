#include "Strthing.h"
#include "../Scenes/Scenes.h"
#include "../../Bullet/Bullet.h"
bool Strthing::init()
{
	if (!Layer::init())
		return false;

	Sprite* BG = Sprite::create("scene/xinZeng2/shuXing2/New_shuXing_bg.jpg");
	addChild(BG);
	BG->setPosition(_Visable / 2);

	Button* StartGame = Button::create("scene/xinZeng2/shuXing2/New_xuanGuan_chuJiZhanDouBtn.png");
	addChild(StartGame);
	StartGame->setPosition(Size(_Visable.width / 2, 50));
	StartGame->addTouchEventListener([&](Ref* ref, Widget::TouchEventType type)
	{
		_director->replaceScene(Scenes::CreateScene(PlayGameScene));
	});

	Button* Return = Button::create("scene/xinZeng2/shangdian2/New_Btn_back.png");
	addChild(Return);
	Return->setPosition(Vec2(60, 50));
	Return->addTouchEventListener([&](Ref*, Widget::TouchEventType type)
	{
		if (type == Widget::TouchEventType::ENDED)
		_director->replaceScene(Scenes::CreateScene(Plane_select));
	});

	Button* ADDJUE = Button::create("scene/xinZeng2/shuXing2/New_Btn_jinBiLiBao.png");
	addChild(ADDJUE);
	ADDJUE->setPosition(Vec2(_Visable.width - 62, 50));

	// Ç¿»¯
	Button* IMV_1 = Button::create("scene/xinZeng2/shuXing2/New_shuXing_Btn_qiangHua.png");
	addChild(IMV_1);
	IMV_1->setPosition(Vec2(370, 305 - 56 * 0));
	IMV_1->addTouchEventListener([&](Ref*, Widget::TouchEventType type)
	{
		if (type == Widget::TouchEventType::ENDED)
		switch (MyData->getIntegerForKey("Cur_PE"))
		{
		case 1:
			MyData->setIntegerForKey("Frist_Fire", MyData->getIntegerForKey("Frist_Fire") + 1);
			for (int i = MyData->getIntegerForKey("Frist_Fire") - 1; i < MyData->getIntegerForKey("Frist_Fire"); ++i)
			{
				ImageView* IMV = ImageView::create("scene/xinZeng2/shuXing2/New_LvTiao.png");
				addChild(IMV);
				IMV->setPosition(Vec2(165, 305) + Vec2(14, 0)*i);
			}


			break;

		case 2:
			MyData->setIntegerForKey("Two_Fire", MyData->getIntegerForKey("Two_Fire") + 1);
			for (int i = MyData->getIntegerForKey("Two_Fire") - 1; i < MyData->getIntegerForKey("Two_Fire"); ++i)
			{
				ImageView* IMV = ImageView::create("scene/xinZeng2/shuXing2/New_LvTiao.png");
				addChild(IMV);
				IMV->setPosition(Vec2(165, 305) + Vec2(14, 0)*i);
			}


			break;
		case 3:
			MyData->setIntegerForKey("There_Fire", MyData->getIntegerForKey("There_Fire") + 1);
			for (int i = MyData->getIntegerForKey("There_Fire") - 1; i < MyData->getIntegerForKey("There_Fire"); ++i)
			{
				ImageView* IMV = ImageView::create("scene/xinZeng2/shuXing2/New_LvTiao.png");
				addChild(IMV);
				IMV->setPosition(Vec2(165, 305) + Vec2(14, 0)*i);
			}


			break;
		case 4:
			MyData->setIntegerForKey("Four_Fire", MyData->getIntegerForKey("Four_Fire") + 1);
			for (int i = MyData->getIntegerForKey("Four_Fire") - 1; i < MyData->getIntegerForKey("Four_Fire"); ++i)
			{
				ImageView* IMV = ImageView::create("scene/xinZeng2/shuXing2/New_LvTiao.png");
				addChild(IMV);
				IMV->setPosition(Vec2(165, 305) + Vec2(14, 0)*i);
			}


			break;

		default:
			break;
		}

	});
	Button* IMV_2 = Button::create("scene/xinZeng2/shuXing2/New_shuXing_Btn_qiangHua.png");
	addChild(IMV_2);
	IMV_2->setPosition(Vec2(370, 305 - 56 * 1));
	IMV_2->addTouchEventListener([&](Ref*, Widget::TouchEventType type)
	{
		if (type == Widget::TouchEventType::ENDED)
			switch (MyData->getIntegerForKey("Cur_PE"))
		{
			case 1:
				MyData->setIntegerForKey("Frist_go_ballistic", MyData->getIntegerForKey("Frist_go_ballistic") + 1);
				for (int i = MyData->getIntegerForKey("Frist_go_ballistic") - 1; i < MyData->getIntegerForKey("Frist_go_ballistic"); ++i)
				{
					ImageView* IMV = ImageView::create("scene/xinZeng2/shuXing2/New_LvTiao.png");
					addChild(IMV);
					IMV->setPosition(Vec2(165, 305 - 56*1) + Vec2(14, 0)*i);
				}


				break;

			case 2:
				MyData->setIntegerForKey("Two_go_ballistic", MyData->getIntegerForKey("Two_go_ballistic") + 1);
				for (int i = MyData->getIntegerForKey("Two_go_ballistic") - 1; i < MyData->getIntegerForKey("Two_go_ballistic"); ++i)
				{
					ImageView* IMV = ImageView::create("scene/xinZeng2/shuXing2/New_LvTiao.png");
					addChild(IMV);
					IMV->setPosition(Vec2(165, 305 - 56 * 1) + Vec2(14, 0)*i);
				}


				break;
			case 3:
				MyData->setIntegerForKey("There_go_ballistic", MyData->getIntegerForKey("There_Fire") + 1);
				for (int i = MyData->getIntegerForKey("Frist_go_ballistic") - 1; i < MyData->getIntegerForKey("Frist_go_ballistic"); ++i)
				{
					ImageView* IMV = ImageView::create("scene/xinZeng2/shuXing2/New_LvTiao.png");
					addChild(IMV);
					IMV->setPosition(Vec2(165, 305 - 56 * 1) + Vec2(14, 0)*i);
				}


				break;
			case 4:
				MyData->setIntegerForKey("Four_go_ballistic", MyData->getIntegerForKey("Four_go_ballistic") + 1);
				for (int i = MyData->getIntegerForKey("Four_go_ballistic") - 1; i < MyData->getIntegerForKey("Four_go_ballistic"); ++i)
				{
					ImageView* IMV = ImageView::create("scene/xinZeng2/shuXing2/New_LvTiao.png");
					addChild(IMV);
					IMV->setPosition(Vec2(165, 305 - 56 * 1) + Vec2(14, 0)*i);
				}


				break;

			default:
				break;
		}

	});
	Button* IMV_3 = Button::create("scene/xinZeng2/shuXing2/New_shuXing_Btn_qiangHua.png");
	addChild(IMV_3);
	IMV_3->setPosition(Vec2(370, 305 - 56 * 2));
	IMV_3->addTouchEventListener([&](Ref*, Widget::TouchEventType type)
	{
		if (type == Widget::TouchEventType::ENDED)
			switch (MyData->getIntegerForKey("Cur_PE"))
		{
			case 1:
				MyData->setIntegerForKey("Frist_Kill", MyData->getIntegerForKey("Frist_Kill") + 1);
				for (int i = MyData->getIntegerForKey("Frist_Kill") - 1; i < MyData->getIntegerForKey("Frist_Kill"); ++i)
				{
					ImageView* IMV = ImageView::create("scene/xinZeng2/shuXing2/New_LvTiao.png");
					addChild(IMV);
					IMV->setPosition(Vec2(165, 305 - 56 * 2) + Vec2(14, 0)*i);
				}


				break;

			case 2:
				MyData->setIntegerForKey("Two_Kill", MyData->getIntegerForKey("Two_Kill") + 1);
				for (int i = MyData->getIntegerForKey("Two_Kill") - 1; i < MyData->getIntegerForKey("Two_Kill"); ++i)
				{
					ImageView* IMV = ImageView::create("scene/xinZeng2/shuXing2/New_LvTiao.png");
					addChild(IMV);
					IMV->setPosition(Vec2(165, 305 - 56 * 2) + Vec2(14, 0)*i);
				}


				break;
			case 3:
				MyData->setIntegerForKey("There_Kill", MyData->getIntegerForKey("There_Kill") + 1);
				for (int i = MyData->getIntegerForKey("There_Kill") - 1; i < MyData->getIntegerForKey("There_Kill"); ++i)
				{
					ImageView* IMV = ImageView::create("scene/xinZeng2/shuXing2/New_LvTiao.png");
					addChild(IMV);
					IMV->setPosition(Vec2(165, 305 - 56 * 2) + Vec2(14, 0)*i);
				}


				break;
			case 4:
				MyData->setIntegerForKey("Four_Kill", MyData->getIntegerForKey("Four_Kill") + 1);
				for (int i = MyData->getIntegerForKey("Four_Kill") - 1; i < MyData->getIntegerForKey("Four_Kill"); ++i)
				{
					ImageView* IMV = ImageView::create("scene/xinZeng2/shuXing2/New_LvTiao.png");
					addChild(IMV);
					IMV->setPosition(Vec2(165, 305 - 56 * 2) + Vec2(14, 0)*i);
				}


				break;

			default:
				break;
		}

	});
	Button* IMV_4 = Button::create("scene/xinZeng2/shuXing2/New_shuXing_Btn_qiangHua.png");
	addChild(IMV_4);
	IMV_4->setPosition(Vec2(370, 305 - 56 * 3));
	IMV_4->addTouchEventListener([&](Ref*, Widget::TouchEventType type)
	{
		if (type == Widget::TouchEventType::ENDED)
			switch (MyData->getIntegerForKey("Cur_PE"))
		{
			case 1:
				MyData->setIntegerForKey("Frist_Drop_rate", MyData->getIntegerForKey("Frist_Drop_rate") + 1);
				for (int i = MyData->getIntegerForKey("Frist_Drop_rate") - 1; i < MyData->getIntegerForKey("Frist_Drop_rate"); ++i)
				{
					ImageView* IMV = ImageView::create("scene/xinZeng2/shuXing2/New_LvTiao.png");
					addChild(IMV);
					IMV->setPosition(Vec2(165, 305 - 56 * 3) + Vec2(14, 0)*i);
				}


				break;

			case 2:
				MyData->setIntegerForKey("Two_Drop_rate", MyData->getIntegerForKey("Two_Drop_rate") + 1);
				for (int i = MyData->getIntegerForKey("Two_Drop_rate") - 1; i < MyData->getIntegerForKey("Two_Drop_rate"); ++i)
				{
					ImageView* IMV = ImageView::create("scene/xinZeng2/shuXing2/New_LvTiao.png");
					addChild(IMV);
					IMV->setPosition(Vec2(165, 305 - 56 * 3) + Vec2(14, 0)*i);
				}


				break;
			case 3:
				MyData->setIntegerForKey("There_Drop_rate", MyData->getIntegerForKey("There_Drop_rate") + 1);
				for (int i = MyData->getIntegerForKey("There_Drop_rate") - 1; i < MyData->getIntegerForKey("There_Drop_rate"); ++i)
				{
					ImageView* IMV = ImageView::create("scene/xinZeng2/shuXing2/New_LvTiao.png");
					addChild(IMV);
					IMV->setPosition(Vec2(165, 305 - 56 * 3) + Vec2(14, 0)*i);
				}


				break;
			case 4:
				MyData->setIntegerForKey("Four_Drop_rate", MyData->getIntegerForKey("Four_Drop_rate") + 1);
				for (int i = MyData->getIntegerForKey("Four_Drop_rate") - 1; i < MyData->getIntegerForKey("Four_Drop_rate"); ++i)
				{
					ImageView* IMV = ImageView::create("scene/xinZeng2/shuXing2/New_LvTiao.png");
					addChild(IMV);
					IMV->setPosition(Vec2(165, 305 - 56 * 3) + Vec2(14, 0)*i);
				}


				break;

			default:
				break;
		}

	});

	ImageView* Log = ImageView::create("scene/xinZeng2/shuXing2/New_shuXing_bg_ding.png");
	addChild(Log,10);
	Log->setPosition(Vec2(_Visable.width / 2, _Visable.height - Log->getContentSize().height / 2));

	


	AddUI_Up();

	return true;
}
void Strthing::AddUI_Up()
{
	Sprite* Plane = nullptr;
	switch (MyData->getIntegerForKey("Cur_PE"))
	{
	case 1:
		Plane = Sprite::create("player/player1/player1_1.png");
		Plane->runAction(CustomTools::CreateAnimate("player/player1/player1_%d.png", 8, 0.2f, -1, 1, false));
		for (int i = 0; i < MyData->getIntegerForKey("Frist_Fire"); ++i)
		{
			ImageView* IMV = ImageView::create("scene/xinZeng2/shuXing2/New_LvTiao.png");
			addChild(IMV);
			IMV->setPosition(Vec2(165, 305) + Vec2(14, 0)*i);
		}

		for (int i = 0; i < MyData->getIntegerForKey("Frist_go_ballistic"); ++i)
		{
			ImageView* IMV = ImageView::create("scene/xinZeng2/shuXing2/New_LvTiao.png");
			addChild(IMV);
			IMV->setPosition(Vec2(165, 305 - 56) + Vec2(14, 0)*i);

		}
		for (int i = 0; i < MyData->getIntegerForKey("Frist_Kill"); ++i)
		{
			ImageView* IMV = ImageView::create("scene/xinZeng2/shuXing2/New_LvTiao.png");
			addChild(IMV);
			IMV->setPosition(Vec2(165, 305 - 56*2) + Vec2(14, 0)*i);

		}
		for (int i = 0; i < MyData->getIntegerForKey("Frist_Drop_rate"); ++i)
		{
			ImageView* IMV = ImageView::create("scene/xinZeng2/shuXing2/New_LvTiao.png");
			addChild(IMV);
			IMV->setPosition(Vec2(165, 305 - 56*3) + Vec2(14, 0)*i);

		}
		break;

	case 2:
		Plane = Sprite::create("player/player2/player2_1.png");
		Plane->runAction(CustomTools::CreateAnimate("player/player2/player2_%d.png", 8, 0.2f, -1, 1, false));
		for (int i = 0; i < MyData->getIntegerForKey("Two_Fire"); ++i)
		{
			ImageView* IMV = ImageView::create("scene/xinZeng2/shuXing2/New_LvTiao.png");
			addChild(IMV);
			IMV->setPosition(Vec2(165, 305) + Vec2(14, 0)*i);
		}

		for (int i = 0; i < MyData->getIntegerForKey("Two_go_ballistic"); ++i)
		{
			ImageView* IMV = ImageView::create("scene/xinZeng2/shuXing2/New_LvTiao.png");
			addChild(IMV);
			IMV->setPosition(Vec2(165, 305 - 56) + Vec2(14, 0)*i);

		}
		for (int i = 0; i < MyData->getIntegerForKey("Two_Kill"); ++i)
		{
			ImageView* IMV = ImageView::create("scene/xinZeng2/shuXing2/New_LvTiao.png");
			addChild(IMV);
			IMV->setPosition(Vec2(165, 305 - 56 * 2) + Vec2(14, 0)*i);

		}
		for (int i = 0; i < MyData->getIntegerForKey("Two_Drop_rate"); ++i)
		{
			ImageView* IMV = ImageView::create("scene/xinZeng2/shuXing2/New_LvTiao.png");
			addChild(IMV);
			IMV->setPosition(Vec2(165, 305 - 56 * 3) + Vec2(14, 0)*i);

		}
		break;
	case 3:
		Plane = Sprite::create("player/player3/player3_1.png");
		Plane->runAction(CustomTools::CreateAnimate("player/player3/player3_%d.png", 8, 0.2f, -1, 1, false));
		for (int i = 0; i < MyData->getIntegerForKey("There_Fire"); ++i)
		{
			ImageView* IMV = ImageView::create("scene/xinZeng2/shuXing2/New_LvTiao.png");
			addChild(IMV);
			IMV->setPosition(Vec2(165, 305) + Vec2(14, 0)*i);
		}

		for (int i = 0; i < MyData->getIntegerForKey("There_go_ballistic"); ++i)
		{
			ImageView* IMV = ImageView::create("scene/xinZeng2/shuXing2/New_LvTiao.png");
			addChild(IMV);
			IMV->setPosition(Vec2(165, 305 - 56) + Vec2(14, 0)*i);

		}
		for (int i = 0; i < MyData->getIntegerForKey("There_Kill"); ++i)
		{
			ImageView* IMV = ImageView::create("scene/xinZeng2/shuXing2/New_LvTiao.png");
			addChild(IMV);
			IMV->setPosition(Vec2(165, 305 - 56 * 2) + Vec2(14, 0)*i);

		}
		for (int i = 0; i < MyData->getIntegerForKey("There_Drop_rate"); ++i)
		{
			ImageView* IMV = ImageView::create("scene/xinZeng2/shuXing2/New_LvTiao.png");
			addChild(IMV);
			IMV->setPosition(Vec2(165, 305 - 56 * 3) + Vec2(14, 0)*i);

		}
		break;
	case 4:
		Plane = Sprite::create("player/player4/player4_1.png");
		Plane->runAction(CustomTools::CreateAnimate("player/player4/player4_%d.png", 8, 0.2f, -1, 1, false));
		for (int i = 0; i < MyData->getIntegerForKey("Four_Fire"); ++i)
		{
			ImageView* IMV = ImageView::create("scene/xinZeng2/shuXing2/New_LvTiao.png");
			addChild(IMV);
			IMV->setPosition(Vec2(165, 305) + Vec2(14, 0)*i);
		}

		for (int i = 0; i < MyData->getIntegerForKey("Four_go_ballistic"); ++i)
		{
			ImageView* IMV = ImageView::create("scene/xinZeng2/shuXing2/New_LvTiao.png");
			addChild(IMV);
			IMV->setPosition(Vec2(165, 305 - 56) + Vec2(14, 0)*i);

		}
		for (int i = 0; i < MyData->getIntegerForKey("Four_Kill"); ++i)
		{
			ImageView* IMV = ImageView::create("scene/xinZeng2/shuXing2/New_LvTiao.png");
			addChild(IMV);
			IMV->setPosition(Vec2(165, 305 - 56 * 2) + Vec2(14, 0)*i);

		}
		for (int i = 0; i < MyData->getIntegerForKey("Four_Drop_rate"); ++i)
		{
			ImageView* IMV = ImageView::create("scene/xinZeng2/shuXing2/New_LvTiao.png");
			addChild(IMV);
			IMV->setPosition(Vec2(165, 305 - 56 * 3) + Vec2(14, 0)*i);

		}
		break;

	default:
		break;
	}

	addChild(Plane);
	Plane->setPosition(Vec2(_Visable / 2) + Vec2(0,100));
	
	Bullet* But = Bullet::create();
	// But->DefultStood("player_fire.png",Plane->getPosition()+Vec2(0,50));
	But->Is_Shanshe("player_fire.png", Plane->getPosition() + Vec2(0, 50),
		std::vector<Vec2>{Vec2(1, 10), Vec2(-1, 10), Vec2(1, 9), Vec2(-1, 9),
		Vec2(1, 7), Vec2(-1, 7), Vec2(1, 6), Vec2(-1, 6), Vec2(1, 5), Vec2(-1, 5),
		Vec2(1, 4), Vec2(-1, 4), Vec2(1, 3), Vec2(-1, 3), Vec2(1, 2), Vec2(-1, 2),
		Vec2(1, 1), Vec2(-1, 1), Vec2(0, 1)});
	addChild(But);

}

