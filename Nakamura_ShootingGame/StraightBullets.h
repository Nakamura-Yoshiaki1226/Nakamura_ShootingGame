#pragma once
#include "BulletsBase.h"

class StraightBullets : public BulletsBase
{
public:
	StraightBullets(T_location location, T_location speed = T_location{ 0,-2 });

public:
	virtual void Update() override;
	virtual void Draw() override;
	virtual bool isScreenOut() override;
};

