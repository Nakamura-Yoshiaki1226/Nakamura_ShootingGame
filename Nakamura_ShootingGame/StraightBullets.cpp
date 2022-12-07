#include "StraightBullets.h"
#include"DxLib.h"

StraightBullets::StraightBullets(T_location location,T_location speed)
	:BulletsBase(location, 5.f, 1, speed)
{
}

void StraightBullets::Update()
{
	T_location newLocation = GetLocation();
	newLocation.y += speed.y;
	SetLocation(newLocation);
}

void StraightBullets::Draw()
{
	DrawCircle(GetLocation().x, GetLocation().y, GetRadius(), GetColor(255, 255, 0));
}

bool StraightBullets::isScreenOut()
{
	bool ret = ((GetLocation().y +GetRadius())<= 0);
	if (ret) 
	{
		return ret;
	}

	/*ret = (SCREEN_HEIGHT <= (GetLocation().y - GetRadius()));*/
	return ret;
}