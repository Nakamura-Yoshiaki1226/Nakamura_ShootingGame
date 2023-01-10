#pragma once
#include "CharaBase.h"

//#define _ENEMY_BULLET_ALL_100

class Enemy : public CharaBase
{
private:
	int hp;
	int point;
	int shotNum;

public:
	Enemy(T_location location);


public:
	virtual void Update()override;
	virtual void Draw()override;
	virtual void Hit(int damage)override;
	bool HpCHeck();
	int GetPoint();
	void Move();
};

