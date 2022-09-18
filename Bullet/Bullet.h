#pragma once
#include "../CustomTools.h"




class Bullet:public Layer
{
public:
	Bullet();
	~Bullet();
	CREATE_FUNC(Bullet);
	

	void SetFilePath(std::string, Point ButtPos, Vec2 Dir, float ButSpeed = 70);  // µ•…‰
	void Is_Shanshe(std::string, Point, std::vector<Vec2>, float Speed = 70);
	void StopStood();
	void DefultStood(std::string path, Point ButtPos,float ButSpeed = 40,int num = 20);
	
private:
	virtual bool init()override;

	void StartStood(float date);
	
	void Destory(Ref*ref);
	void Is_Out(float date);
	void StartStood_ShanShe(float date);
	void DefultStood_SLE(float date);

	cocos2d::Vector<Sprite*> MyButs;
	std::vector<float> MyAnleges;
	std::vector<Vec2> Dirs;
	Vec2 Dir;
	float Anlege;
	Point Plane;
	float ButSpeed;
	std::string FilePath;
	Point ButtPos;
	int num;

	bool Is_Sche_Out;
};

