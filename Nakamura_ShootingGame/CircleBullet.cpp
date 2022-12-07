#include "CircleBullet.h"
#include"DxLib.h"

#define _USE_MATH_DEFINES
#include <math.h>

CircleBullet::CircleBullet(T_location location, float speed, int degAngle)
	:BulletsBase(location, 5.f, 1, T_location{ 0,0 })
{
	int deg = degAngle % 360;//360�̒l��艺�ɂ��Ă�(0�ƕς��Ȃ�)
	double rad = (M_PI / 180) * deg;//���~���̊p�x�A1���̊p�x�̎����l���o���Ă���
	float x = (abs(deg) == 90 || deg == 270) ? 0 : cos(rad);//�O�����Z�q�A1�s�ŕ`����if���������܂�I�X�X�����Ȃ�(������)?TRUE:FALSE
	float y = sin(rad);

	this->speed = T_location{ (speed * x),(speed * y) };
}

void CircleBullet::Update()
{
	T_location newLocation = GetLocation();
	newLocation.y += speed.y;
	newLocation.x += speed.x;
	SetLocation(newLocation);
}

void CircleBullet::Draw()
{
	DrawCircle(GetLocation().x, GetLocation().y, GetRadius(), GetColor(0, 255, 0));
}


bool CircleBullet::isScreenOut()
{
	bool ret = ((GetLocation().y + GetRadius()) <= 0);
	if (ret)
	{
		return ret;
	}

	/*ret = (SCREEN_HEIGHT <= (GetLocation().y - GetRadius()));*/
	if (ret)
	{
		return ret;
	}
	ret = ((GetLocation().x + GetRadius()) <= 0);
	if (ret)
	{
		return ret;
	}

	/*ret(SCREEN_WIDTH <= (GetLocation().y - GetRadius()));
	return ret;*/
}