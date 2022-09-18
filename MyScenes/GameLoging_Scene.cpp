#include "GameLoging_Scene.h"
#include "../Scenes/Scenes.h"

bool GameLoging_Scene::init()
{
	if (!Layer::init())
		return false;
	CCLOG("GameLoging_Scene");
	
	BG = MenuItemImage::create("Logan/bg_menu.jpg", "Logan/bgmuohu_menu.jpg", 
		CC_CALLBACK_1(GameLoging_Scene::BGCALLBACK,this));

	Menu* menu = Menu::create(BG,NULL);
	addChild(menu);
	menu->setPosition(Director::getInstance()->getVisibleSize() / 2);
	BG->setPosition(Vec2::ZERO);


	Animate* myanimate_1 = CustomTools::CreateAnimate("bg/bg%d.jpg", 5, 0.4f, -1, 1, false);
	viewanimate = Sprite::create("bg/bg1.jpg");
	addChild(viewanimate,2);
	viewanimate->setPosition(_Visable / 2);
	viewanimate->setOpacity(180);
	viewanimate->runAction(myanimate_1);

	ParticleFire* fire = ParticleFire::createWithTotalParticles(500);
	fire->setEmissionRate(200);
	fire->setPosVar(Vec2(_Visable.width / 2, 2));
	fire->setPosition(_Visable.width / 2, 5);
	addChild(fire,2);

	ParticleSun* Sun = ParticleSun::createWithTotalParticles(500);
	Sun->setEmissionRate(200);
	Sun->setPosition(_Visable / 2);
	addChild(Sun,2);

	Button* GameHelp = Button::create("Logan/bangzhu2_cover.png");
	GameHelp->setPressedActionEnabled(true);
	addChild(GameHelp,5);
	GameHelp->setPosition(Vec2(100, 100));
	GameHelp->addTouchEventListener(CC_CALLBACK_2(GameLoging_Scene::GameHelpCallBack, this));

	Button* About_Me = Button::create("Logan/team2_cover.png");
	About_Me->setPressedActionEnabled(true);
	addChild(About_Me, 5);
	About_Me->setPosition(Vec2(_Visable.width - 100, 100));
	About_Me->addTouchEventListener(CC_CALLBACK_2(GameLoging_Scene::GameAboutMe, this));

	GameHelpView = ImageView::create("Logan/about.png");
	addChild(GameHelpView,5);
	GameHelpView->setVisible(false);
	GameHelpView->setPosition(_Visable / 2);

	AboutGame = ImageView::create("Logan/team_cover.png");
	addChild(AboutGame,5);
	AboutGame->setVisible(false);
	AboutGame->setPosition(_Visable / 2);

	ImageView* PleasePoint = ImageView::create("scene/xinZeng2/caiDan2/New_menu_kaiShi.png");
	addChild(PleasePoint,2);
	PleasePoint->setPosition(Size(_Visable.width / 2, 200));
	CCScaleBy* scleby = CCScaleBy::create(0.7,1.2);
	Sequence* sequence = Sequence::create(scleby->clone(), scleby->reverse()->clone(), NULL);
	RepeatForever * sclebyrepeat = RepeatForever::create(sequence);
	PleasePoint->setOpacity(180);
	PleasePoint->runAction(sclebyrepeat);

	ImageView* MyRobot = ImageView::create("scene/xinZeng2/caiDan2/New_menu_bg.jpg");
	addChild(MyRobot);
	MyRobot->setPosition(_Visable / 2);
	
	Sprite* TitleAnimate = Sprite::create("scene/xinZeng2/caiDan2/New_menu_gameName1.png");
	Animate* titleanimate = CustomTools::CreateAnimate("scene/xinZeng2/caiDan2/New_menu_gameName%d.png",
		5, 0.3f, -1, 1, false);
	addChild(TitleAnimate);
	TitleAnimate->setPosition(Size(_Visable.width / 2, _Visable.height - 100));
	TitleAnimate->runAction(titleanimate);
	ReUse = UserDefault::getInstance();
	if (!ReUse->getBoolForKey("Isfrist"))
	{
		// �Ƿ��һ�δ�
		ReUse->setBoolForKey("Isfrist", true);
		// ��ʯ
		ReUse->setIntegerForKey("Jewel", 0);
		// ����
		ReUse->setIntegerForKey("Life", 3);
		// ���ؿ�
		ReUse->setIntegerForKey("Max_GK", 12);
		// ��ǰ�ؿ�
		ReUse->setIntegerForKey("Cur_GK", 1);
		// ��ǰս��
		ReUse->setIntegerForKey("Cur_PE", 1);
		// ��������
		ReUse->setIntegerForKey("Shield", 0);
		// �˵�����
		ReUse->setIntegerForKey("N-bomb", 0);
		// ��һ̨ս���Ƿ���
		ReUse->setBoolForKey("Is_Frist", true);
		//��һ̨�Ļ����ȼ�
		ReUse->setIntegerForKey("Frist_Fire", 1);
		//��һ̨�ı��ߵȼ�
		ReUse->setIntegerForKey("Frist_go_ballistic", 1);
		//��һ̨�ı�ɱ�ȼ�
		ReUse->setIntegerForKey("Frist_Kill", 1);
		//��һ̨�ĵ��ʵȼ�
		ReUse->setIntegerForKey("Frist_Drop_rate", 1);


		// �ڶ�̨ս���Ƿ���
		ReUse->setBoolForKey("Is_Two", true);
		//�ڶ�̨�Ļ����ȼ�
		ReUse->setIntegerForKey("Two_Fire", 1);
		//�ڶ�̨�ı��ߵȼ�
		ReUse->setIntegerForKey("Two_go_ballistic", 1);
		//�ڶ�̨�ı�ɱ�ȼ�
		ReUse->setIntegerForKey("Two_Kill", 1);
		//�ڶ�̨�ĵ��ʵȼ�
		ReUse->setIntegerForKey("Two_Drop_rate", 1);

		// ����̨ս���Ƿ���
		ReUse->setBoolForKey("Is_There", true);
		//����̨�Ļ����ȼ�
		ReUse->setIntegerForKey("There_Fire", 1);
		//����̨�ı��ߵȼ�
		ReUse->setIntegerForKey("There_ballistic", 1);
		//����̨�ı�ɱ�ȼ�
		ReUse->setIntegerForKey("There_Kill", 1);
		//����̨�ĵ��ʵȼ�
		ReUse->setIntegerForKey("There_Drop_rate", 1);

		// ����̨ս���Ƿ���
		ReUse->setBoolForKey("Is_Four", true);
		//����̨�Ļ����ȼ�
		ReUse->setIntegerForKey("Four_Fire", 1);
		//����̨�ı��ߵȼ�
		ReUse->setIntegerForKey("Four_ballistic", 1);
		//����̨�ı�ɱ�ȼ�
		ReUse->setIntegerForKey("Four_Kill", 1);
		//����̨�ĵ��ʵȼ�
		ReUse->setIntegerForKey("Four_Drop_rate", 1);

	}


	return true;
}


void GameLoging_Scene::BGCALLBACK(Ref*ref)
{
	CallFunc* fun = CallFunc::create([&]()
	{
		this->removeChild(BG, this);
		Scene* scene = Scenes::CreateScene(Checkpoint_Choese);
		Director::getInstance()->replaceScene(scene);
		CCLOG("Checkpoint_Choese");
	}
	);
	CCLOG("Checkpoint_Choese");
	viewanimate->runAction(CCFadeOut::create(1.5f));

	Sequence* sequence = Sequence::create(CCFadeOut::create(3.0f), fun,NULL);
	BG->runAction(sequence->clone());
}

void GameLoging_Scene::GameHelpCallBack(Ref*ref, Widget::TouchEventType type)
{
	if (Widget::TouchEventType::ENDED == type)
	{
		if (AboutGame->isVisible())
			AboutGame->setVisible(false);
		if (GameHelpView->isVisible())
			GameHelpView->setVisible(false);
		else
			GameHelpView->setVisible(true);

	}

}

void GameLoging_Scene::GameAboutMe(Ref* ref, Widget::TouchEventType type)
{
	if (Widget::TouchEventType::ENDED == type)
	{
		if (GameHelpView->isVisible())
			GameHelpView->setVisible(false);
		if (AboutGame->isVisible())
			AboutGame->setVisible(false);
		else
			AboutGame->setVisible(true);

			



	}

}