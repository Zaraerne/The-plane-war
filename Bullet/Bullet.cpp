#include "Bullet.h"


Bullet::Bullet()
{

}


Bullet::~Bullet()
{
}

void Bullet::DefultStood(std::string path, Point ButtPos, float ButSpeed, int num)
{
	this->FilePath = path;
	this->num = num;
	this->ButtPos = ButtPos;
	this->ButSpeed = ButSpeed;
	schedule(schedule_selector(Bullet::DefultStood_SLE), 0.5f);
	schedule(schedule_selector(Bullet::Is_Out), 0.2f);
}
void Bullet::DefultStood_SLE(float date)
{
	for (int i = 0; i < num; ++i)
	{
		Sprite* But = Sprite::create(FilePath);
		But->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
		float x = 0.0f;
		float y = 0.0f;
		while (!x && !y)
		{
			x = RandomHelper::random_real<float>(-1, 1);
			y = RandomHelper::random_real<float>(-1, 1);
		}
		
		
		But->setPosition(ButtPos);
		Vec2 dd = ccpNormalize(Vec2(x, y));
		But->setRotation(90 - atan2(y, x)*180/PI);
		this->addChild(But);
		MyButs.pushBack(But); // 加入子弹到Vector中


		CCMoveBy* moveby = CCMoveBy::create(0.5f, dd*ButSpeed);
		RepeatForever* IsOut = RepeatForever::create(moveby);
		But->runAction(IsOut);

	}



}

void Bullet::Is_Shanshe(std::string path, Point ButtPos, std::vector<Vec2> Dirs, float ButSpeed)
{
	this->Dirs = Dirs;
	for (int i = 0; i < Dirs.size(); ++i)
	{
		MyAnleges.push_back(90 - atan2(Dirs.at(i).y, Dirs.at(i).x) * 180 / PI);
		this->Dirs.at(i) = ccpNormalize(Dirs.at(i));
	}


	this->ButSpeed = ButSpeed;
	this->ButtPos = ButtPos;
	FilePath = path;

	schedule(schedule_selector(Bullet::StartStood_ShanShe), 0.3f);
	schedule(schedule_selector(Bullet::Is_Out), 0.2f);
	
}

void Bullet::StartStood_ShanShe(float date)
{

	// 生成子弹
	for (int i = 0; i < Dirs.size(); ++i)
	{
		Sprite* But = Sprite::create(FilePath);
		But->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
		But->setPosition(ButtPos);
		But->setRotation(MyAnleges.at(i));
		this->addChild(But);
		MyButs.pushBack(But); // 加入子弹到Vector中


    	CCMoveBy* moveby = CCMoveBy::create(0.5f, Dirs.at(i)*ButSpeed);
   	    RepeatForever* IsOut = RepeatForever::create(moveby);
    	But->runAction(IsOut);

	}
	

}

void Bullet::SetFilePath(std::string str, Point ButtPos, Vec2 Dir, float ButSpeed)
{
	this->Dir = Dir;
	this->Anlege = 90 - atan2(Dir.y, Dir.x) * 180 / PI;
	this->ButSpeed = ButSpeed;
	this->ButtPos = ButtPos;
	FilePath = str;

	schedule(schedule_selector(Bullet::StartStood), 0.3f);  // 每0.3秒调用一次
	if (Anlege || (Dir.y!=0))
		schedule(schedule_selector(Bullet::Is_Out), 0.2f);
	CCLOG("%f", Anlege);
}

bool Bullet::init()
{
	if (!Layer::init())
		return false;
	

	return true;
}

void Bullet::Is_Out(float date)
{
	if (MyButs.size()>0)
	for (int i = 0; i < MyButs.size();++i)
	{
		if (MyButs.at(i)->getPositionX() < 0 || MyButs.at(i)->getPositionX() > _Visable.width
			|| MyButs.at(i)->getPositionY()<0 || MyButs.at(i)->getPositionY() > _Visable.height)
		{
			this->removeChild(MyButs.at(i));
			MyButs.eraseObject(MyButs.at(i));
			--i;
		}
	}
}

void Bullet::StartStood(float date)
{
	// 生成子弹
	Sprite* But = Sprite::create(FilePath);
	But->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	But->setPosition(ButtPos);
	But->setRotation(Anlege);
	this->addChild(But);
	MyButs.pushBack(But); // 加入子弹到Vector中


	if (Anlege)
	{
		CCMoveBy* moveby = CCMoveBy::create(0.5f, Dir*ButSpeed);
		
		RepeatForever* IsOut = RepeatForever::create(moveby);
		But->runAction(IsOut);	
	}
	else
	{
		CCMoveTo * To = CCMoveTo::create(1.0f - ButSpeed/100, Vec2(_Visable.width / 2, _Visable.height));
		CallFuncN* DestoryBut = CallFuncN::create(CC_CALLBACK_1( Bullet::Destory,this));
		Sequence* sequence = Sequence::create(To, DestoryBut, NULL);
		But->runAction(sequence);

	}



}

void Bullet::Destory(Ref*ref)
{
	Sprite* ptr = (Sprite*)(ref);
	// 移除
	MyButs.eraseObject(ptr);
	removeChild(ptr, true);
}

void Bullet::StopStood()
{
	this->unschedule(schedule_selector(Bullet::StartStood));  // 关闭Bullet::StartStood调度器
	this->unschedule(schedule_selector(Bullet::Is_Out));	 // 关闭Bullet::Is_Out调度器
}