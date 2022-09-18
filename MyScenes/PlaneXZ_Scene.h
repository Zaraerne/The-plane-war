#pragma once
#include "../../CustomTools.h"


class PlaneXZ_Scene : public Layer
{
public:
	PlaneXZ_Scene();
	~PlaneXZ_Scene();
	CREATE_FUNC(PlaneXZ_Scene);
	virtual bool init()override;


private:
	PageView* Plane_List;
	Button* Fight;

	virtual void update(float date)override;

	void IsBuy();
	void SetCurPlane();
	bool Is_Select();

	RepeatForever* ToFroward;
	RepeatForever* But_Left;
	RepeatForever* But_Right;

public:
};

