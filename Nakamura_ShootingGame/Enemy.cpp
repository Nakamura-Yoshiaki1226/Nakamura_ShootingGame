#include "Enemy.h"
#include"DxLib.h"


Enemy::Enemy(T_location location)
	:CharaBase(location, 20.f, T_location{ 0,0.5 }), hp(10), point(10)
{
}

void Enemy::Update()
{
	T_location newLocation = GetLocation();
	newLocation.y += 0.5;
	SetLocation(newLocation);
}

void Enemy::Draw()
{
		DrawCircle(GetLocation().x, GetLocation().y, GetRadius(), GetColor(255, 0, 255));
}

void Enemy::Hit(int damage)
{
	if (0 < damage)
	{
		hp -= damage;
		if (hp < 0)
		{
			hp = 0;
		}
	}
}

bool Enemy::HpCHeck()
{
	bool ret = (hp <= 0);
	return ret;
}

int Enemy::GetPoint()
{
	return point;
}