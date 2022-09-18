#include "Loading_Scene.h"
#include "../Scenes/Scenes.h"

bool Loading_Scene::init()
{
	if (!Layer::init())
		return false;
	CCLOG("Loading_Scene");
	Visable = Director::getInstance()->getVisibleSize();
	loadingbar = LoadingBar::create("Logan/loginRect1.png");
	percent = Text::create("0.0 %","fonts/Marker Felt.ttf",20);
	per = 0.0f;
	loadingbar->setPercent(per);
	loadingbar->setDirection(LoadingBar::Direction::LEFT);
	loadingbar->addChild(percent);
	percent->setPosition(loadingbar->getContentSize() / 2);
	addChild(loadingbar, 4);
	loadingbar->setPosition(Vec2(Director::getInstance()->getVisibleSize().width / 2, 80));
	
	ImageView* LoadingBG = ImageView::create("Logan/loginRect0.png");
	LoadingBG->setPosition(Vec2(Director::getInstance()->getVisibleSize().width / 2, 80));
	addChild(LoadingBG, 1);

	Animate* animate = CustomTools::CreateAnimate("Logan/guang/eff_cj2_000%d%d.png", 30, 0.2f, -1);
	Sprite* mybg = Sprite::create("Logan/guang/eff_cj2_00000.png");
	mybg->runAction(animate);
	addChild(mybg);
	mybg->setPosition(Vec2(_Visable.width/2 + 20,_Visable.height));

	view = ImageView::create("bg/bg4.jpg");
	addChild(view,0);
	view->setPosition(_Visable / 2);

	Bg = Sprite::create("bg/bg4_0.png");
	addChild(Bg,1);
	Bg->setPosition(Visable / 2);
	Bg->setOpacity(0);


	scheduleUpdate();

	

	return true;
}

void Loading_Scene::update(float date)
{
	Bg->setOpacity(per/100.f * 255);
	per += date*15;
	__String* Text_Percent = __String::createWithFormat("%.1f %", per);
	percent->setText(Text_Percent->getCString());
	loadingbar->setPercent(per);
	if (per > 99.7)
	{
		unscheduleUpdate();
		loadingbar->setPercent(100.0f);
		percent->setText("100.0 %");
		CCScaleBy* scale = CCScaleBy::create(3.0f, 4.0f);
		Bg->runAction(CCRotateBy::create(4.0f,360.0f));
		CallFunc* fun = CallFunc::create(CC_CALLBACK_0(Loading_Scene::_CallFunc,this));
		
		Sequence* sequence = Sequence::create(scale, fun, NULL);

		
		Bg->runAction(EaseSineIn::create(sequence));
	}
}


void Loading_Scene::_CallFunc()
{
	Scene* scene = Scenes::CreateScene(GameLog_Scene);
	Director::getInstance()->replaceScene(scene);

}