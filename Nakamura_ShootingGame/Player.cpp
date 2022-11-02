#include"DxLib.h"
#include "Player.h"
#include"StraightBullets.h"
#include"KeyManager.h"

Player::Player(T_location location)
	:CharaBase(location,10.f,T_location{2,2}),score(0),life(10)
{
	bullets = new BulletsBase * [30];
	for (int i = 0; i < 30; i++)
	{
		bullets[i] = nullptr;
	}
}

void Player::Update() 
{
	//キーボードで移動
	T_location newLocation = GetLocation();
	if (KeyManager::OnKeyPressed(KEY_INPUT_W))
	{
		newLocation.y -= speed.y;
	}

	if (KeyManager::OnKeyPressed(KEY_INPUT_A))
	{
		newLocation.x -= speed.x;
	}

	if (KeyManager::OnKeyPressed(KEY_INPUT_S))
	{
		newLocation.y += speed.y;
	}

	if (KeyManager::OnKeyPressed(KEY_INPUT_D))
	{
		newLocation.x += speed.x;
	}

	SetLocation(newLocation);

	int bulletCount;
	for (bulletCount = 0; bulletCount < 30; bulletCount++)
	{
		if (bullets[bulletCount] == nullptr)
		{
			break;
		}
		bullets[bulletCount]->Update();

		//画面外に行ったら弾を消す
		if (bullets[bulletCount]->isScreenOut())
		{
			DeleteBullet(bulletCount);
			bulletCount--;
		}
	}

	if (KeyManager::OnMousePressed(MOUSE_INPUT_LEFT))//クリックするごとに玉が発射される
	{
			if (bulletCount<30 && bullets[bulletCount] == nullptr)
			{
				bullets[bulletCount] = new StraightBullets(GetLocation());
		}
	}
}
void Player::Draw() 
{
	DrawCircle(GetLocation().x, GetLocation().y, GetRadius(), GetColor(255, 0, 0));

	for (int bulletCount = 0; bulletCount < 30; bulletCount++)
	{
		if (bullets[bulletCount] == nullptr)
		{
			break;
		}
		bullets[bulletCount]->Draw();
	}
}
void Player::Hit(int damage)
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