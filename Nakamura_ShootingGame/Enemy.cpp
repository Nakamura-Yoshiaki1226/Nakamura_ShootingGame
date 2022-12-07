#include "Enemy.h"
#include"DxLib.h"
#include"StraightBullets.h"
#include"CircleBullet.h"


Enemy::Enemy(T_location location)
	:CharaBase(location, 20.f, T_location{ 0,0.5 }), hp(10), point(10),shotNum(0)
{
	bullets = new BulletsBase * [30];
	for (int i = 0; i < 30; i++)
	{
		bullets[i] = nullptr;
	}
}

void Enemy::Update()
{
	//コメントアウトで動きを止めてる
	/*T_location newLocation = GetLocation();
	newLocation.y += speed.y;
	SetLocation(newLocation);*/

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

	//敵が弾を発射する処理
	if (bulletCount < /*_ENEMY_BULLET_ALL_*/30 && bullets[bulletCount] == nullptr)
	{
		//弾幕
		bullets[bulletCount] = new CircleBullet(GetLocation(), 2.0f, (20 * shotNum));
		shotNum++;
		/*bullets[bulletCount] = new StraightBullets(GetLocation(),T_location {0,2});*/
	}
}

void Enemy::Draw()
{
		DrawCircle(GetLocation().x, GetLocation().y, GetRadius(), GetColor(255, 0, 255));

		for (int bulletCount = 0; bulletCount < 30; bulletCount++)
		{
			if (bullets[bulletCount] == nullptr)
			{
				break;
			}
			bullets[bulletCount]->Draw();
		}
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