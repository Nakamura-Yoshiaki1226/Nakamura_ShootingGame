#pragma once
#include "SphereCollider.h"
#include"BulletsBase.h"

class CharaBase :public SphereCollider
{
protected:
	BulletsBase** bullets;
	int* image;
	T_location speed;

public:
	CharaBase(T_location location, float radius, T_location speed);

public:
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void Hit(int damage) = 0;
	BulletsBase** GetBullets();
	void DeleteBullet(int bulletNum);
};

