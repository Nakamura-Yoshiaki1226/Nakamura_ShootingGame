#include "Enemy.h"
#include"DxLib.h"
#include"StraightBullets.h"
#include"CircleBullet.h"

//動きの要素を考える
struct MoveInfomation
{
	T_location targetlocation;
	int pattern;//動く、動かないパターン
	int next;
	int waitTimeFlame;
	int attackPattern;//アタック
};
//テキストデータを変えたりするだけで動きが変わる
MoveInfomation moveInfo[10] = {
	{   640,150,0,1,  0,0},
	{1200.4,150,0,1,  0,0},
	{     0,  0,1,3,180,1},//3秒間立ち止まったまま攻撃
	{  80.2,150,0,4,  0,2},
	{     0,  0,1,5,180,1},
	{1200.4,150,0,2,  0,1},
};


T_location locations[3] = { //[座標の数]
	{640,150},
	{1200.4,150},
	{80.2,150},
};

int next[3] = {
	1,
	2,
	1
};

int current = 0;

Enemy::Enemy(T_location location)
	:CharaBase(location, 20.f, T_location{ 1,2 }), hp(10), point(10),shotNum(0)//T_location{ 0,0.5 }スピード
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

	Move();

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

void Enemy::Move()
{
	T_location nextLocation = GetLocation();//今いる座標を一時的に保存している

	if ((nextLocation.y == locations[current].y) &&
		(nextLocation.x == locations[current].x))
	{
		current = next[current];
	}
	else
	{
		//yの移動処理　ここから
		if (nextLocation.y != locations[current].y)
		{
			if (nextLocation.y < locations[current].y)
			{
				nextLocation.y += speed.y;//低いときはどんどん増やしていく
				if ((GetLocation().y <= locations[current].y) &&//今の座標<目的地
					(locations[current].y <= nextLocation.y))//目的地<次の座標
				{
					nextLocation.y = locations[current].y;
				}
			}
			else
			{
				nextLocation.y -= speed.y;
				if ((nextLocation.y <= locations[current].y) &&//目的地を飛び越えた場合
					(locations[current].y <= GetLocation().y))
				{
					nextLocation.y = locations[current].y;//目的地を飛び越えないようにしている(上書きしている)
				}
			}
		}
		//ここまで
		if (nextLocation.x != locations[current].x)
		{
			if (nextLocation.x < locations[current].x)
			{
				nextLocation.x += speed.x += speed.x;
				//目的地を飛び越えた場合
				if ((GetLocation().x <= locations[current].x) &&
					(locations[current].x <= nextLocation.x))
				{
					nextLocation.x = locations[current].x;
				}
			}
			else
			{
				nextLocation.x -= speed.x;
				//目的地を飛び越えたら直す
				if ((nextLocation.x <= locations[current].x) &&
					(locations[current].x <= GetLocation().x))
				{
					nextLocation.x = locations[current].x;
				}
			}
		}
	}

	SetLocation(nextLocation);//今いる座標の更新
}