#include "MyPlayer.h"
#include "../../MyBullets/MyBullets.h"
#include "../../MyBullets/Bulletfactory/Bulletfactory.h"

MyPlayer* MyPlayer::Create(Plane_Type type)
{
	MyPlayer *pRet = new(std::nothrow) MyPlayer(type);
	if (pRet && pRet->init())
	{
		pRet->autorelease();
	}
	else
	{
		delete pRet;
		pRet = nullptr;
	}
	return pRet;
}

bool MyPlayer::init()
{
	if (!Sprite::initWithFile("player/player1/player1_1.png"))
		return false;
	
	switch (type)
	{
	case Player_1:
		MyPlanePath = "player/player1/player1_%d.png";
		ToLeft = "player/player1/player1_left.png";
		ToRight = "player/player1/player1_right.png";
		break;
	case Player_2:
		this->setTexture(_director->getTextureCache()->addImage("player/player2/player2_1.png"));
		MyPlanePath = "player/player2/player2_%d.png";
		ToLeft = "player/player2/player2_left.png";
		ToRight = "player/player2/player2_right.png";
		break;
	case Player_3:
		this->setTexture(_director->getTextureCache()->addImage("player/player3/player3_1.png"));
		MyPlanePath = "player/player3/player3_%d.png";
		ToLeft = "player/player3/player3_left.png";
		ToRight = "player/player3/player3_right.png";
		break;
	case Player_4:
		this->setTexture(_director->getTextureCache()->addImage("player/player4/player4_1.png"));
		MyPlanePath = "player/player4/player4_%d.png";
		ToLeft = "player/player4/player4_left.png";
		ToRight = "player/player4/player4_right.png";
		break;
	default:
		break;
	}
	
	CCMoveBy* by = CCMoveBy::create(2.0f, Vec2(0, _Visable.height / 2));
	CCBlink* blink = CCBlink::create(4.0f, 18);
	Spawn* spwn = Spawn::create(by, blink, NULL);
	this->runAction(spwn);
	schedule(schedule_selector(MyPlayer::Stood), 0.05, -1, 5);
	schedule(schedule_selector(MyPlayer::Stood_S), 0.1, -1, 6);


	Sprite* Shan = Sprite::create("player/shan1.png");
	
	Shan->runAction(CustomTools::CreateAnimate("player/shan%d.png", 3, 0.1f, -1, 1, false));
	addChild(Shan);
	Shan->setPosition(this->getContentSize() / 2);

	return true;
}
void MyPlayer::Stood(float date)
{
	MyBullets* But = Bulletfactory::CreateBulletType1(Player_1_Main);
	this->getParent()->addChild(But);
	But->setPosition(this->getPosition() + Vec2(0, 50));
	But->StartMove();
}

void MyPlayer::Stood_S(float date)
{
	int num = 10;
	float anlege = 60.0 / 9;
	for (int i = 0; i < num; ++i)
	{
		MyBullets* But = Bulletfactory::CreateBulletType1(Player_1_Main);
		this->getParent()->addChild(But);
		But->setPosition(this->getPosition() + Vec2(-30 + anlege*i, 47 + 3 * (-(i*i) + (num-1) * i)));
		But->StartMove();
	}

}

void MyPlayer::onEnter()
{
	Sprite::onEnter();
	X = this->getPositionX();
	Y = this->getPositionY();
	EventListenerTouchOneByOne* lister = EventListenerTouchOneByOne::create();
	lister->onTouchBegan = [&](Touch* touch, Event* event)
	{
		if (this->getBoundingBox().containsPoint(touch->getLocation()))
		{
			this->stopAllActions();
			this->setVisible(true);
			return true;
		}
		return false;
	};

	lister->onTouchMoved = [&](Touch* touch, Event* event)
	{
		X = touch->getLocation().x;
		Y = touch->getLocation().y;


		if (touch->getLocation().x > getPositionX())
		{

			this->setTexture(ToRight.c_str());
		}
		if (touch->getLocation().x <  getPositionX())
		{

			this->setTexture(ToLeft.c_str());
		}

		this->setPosition(X, Y);
		if (this->getPosition().x > _Visable.width)
		{

			this->setPositionX(_Visable.width);
		}
		if (this->getPosition().x < 0)
		{
			setPositionX(0);
		}
		if (this->getPosition().y > _Visable.height)
		{
			setPositionY(_Visable.height);
		}
		if (this->getPosition().y < 0)
		{
			setPositionY(0);
		}

	};

	lister->onTouchEnded = [&](Touch* touch, Event* type)
	{
		this->stopAllActions();
		runAction(CustomTools::CreateAnimate(MyPlanePath.c_str(), 8, 0.2f, -1, 1, false));
	};


	_director->getEventDispatcher()->addEventListenerWithSceneGraphPriority(lister, this);

}


