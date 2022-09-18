#include "Login_Scene.h"
#include "../Scenes/Scenes.h"




bool Login_Scene::init()
{
    
    if ( !Layer::init() )
    {
        return false;
    }
	CCLOG("Login_Scene");
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	Sprite* BG = Sprite::create("bg/MyLog.png");
	addChild(BG, 0);
	BG->setPosition(visibleSize / 2);
	BG->setOpacity(0);
	CCFadeIn* fadein = CCFadeIn::create(1.0f);
	CCFadeOut* fadeout = CCFadeOut::create(1.0f);
	DelayTime* delaytime = DelayTime::create(0.5);
	CallFunc* myfun = CallFunc::create([&]()
	{
		Scene* scene = Scenes::CreateScene(Load_Scens);
		Director::getInstance()->replaceScene(scene);
	});
	Sequence* sequence = Sequence::create(fadein, delaytime, fadeout, myfun, NULL);
	BG->runAction(sequence);
    return true;
}



