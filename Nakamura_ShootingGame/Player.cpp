#include"DxLib.h"
#include "Player.h"

Player::Player(T_location location)
	:CharaBase(location,10.f,T_location{2,2}),score(0),life(10)
{

}

void Player::Update() 
{
	T_location newLocation = GetLocation();
	newLocation.x += 1;
	SetLocation(newLocation);
}
void Player::Draw() 
{
	DrawCircle(GetLocation().x, GetLocation().y, GetRadius(), GetColor(255, 0, 0));
}
void Player::Hit() 
{

}
bool Player::LifeCheck() 
{
	bool ret = (life <= 0);
	return ret;
}
int Player::GetScore() 
{
	return score;
}