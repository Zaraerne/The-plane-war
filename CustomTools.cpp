#include "CustomTools.h"


Animate* CustomTools::CreateAnimate(const char* Path, int num, float Time, int Loop,int DefualtFrist,bool IsDouble)
{
	Animation* animation = Animation::create();
	for (int i = DefualtFrist; i < num + DefualtFrist; ++i)
	{
		__String* strpath;
		if (IsDouble)
		strpath = __String::createWithFormat(Path, i/10,i%10);
		else
		strpath = __String::createWithFormat(Path, i % 10);
		animation->addSpriteFrameWithFile(strpath->getCString());
	}
	animation->setLoops(Loop);
	animation->setDelayPerUnit(Time);
	animation->setRestoreOriginalFrame(false);
	Animate* animate = Animate::create(animation);
	return animate;
}