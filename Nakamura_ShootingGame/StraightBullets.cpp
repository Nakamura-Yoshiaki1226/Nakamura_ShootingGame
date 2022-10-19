#include "StraightBullets.h"
#include"DxLib.h"

StraightBullets::StraightBullets(T_location location)
	:BulletsBase(location, 5.f, 1, T_location{ 0,2 })
{
}

void StraightBullets::Update()
{
	T_location newLocation = GetLocation();
	newLocation.y -= speed.y;
	SetLocation(newLocation);
}

void StraightBullets::Draw()
{
	DrawCircle(GetLocation().x, GetLocation().y, GetRadius(), GetColor(255, 255, 0));
}