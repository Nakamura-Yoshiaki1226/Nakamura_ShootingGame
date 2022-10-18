#pragma once
#include "SphereCollider.h"

class CharaBase :public SphereCollider
{
private:
	//bullets(ポイント配列)
	T_location speed;

protected:
	int* image;

public:
	CharaBase(T_location location, float radius, T_location speed);

public:
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void Hit() = 0;
	//GetBullets();
};

