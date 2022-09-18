#pragma once
#include "../../CustomTools.h"



class Strthing :public Layer
{
public:
	CREATE_FUNC(Strthing);
	virtual bool init()override;



private:
	void AddUI_Up();



};

