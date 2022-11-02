#include "GamemainScene.h"

GamemainScene::GamemainScene()
{
	T_location location = T_location{ 20,100 };
	player = new Player(location);

	enemy = new Enemy * [10];
	for (int i = 0; i < 10; i++)
	{
		enemy[i] = nullptr;
	}
	enemy[0] = new Enemy(T_location{ 200,0 });
}
//描画以外の更新を実装する
void GamemainScene::Update() 
{
	player->Update();
	
	int enemyCount;
	for (enemyCount = 0; enemyCount < 10; enemyCount++)
	{
		if (enemy[enemyCount] == nullptr)
		{
			break;
		}
		enemy[enemyCount]->Update();
	}

	BulletsBase** bullet = player->GetBullets();
	for (enemyCount = 0; enemyCount < 10; enemyCount++)
	{
		if (enemy[enemyCount] == nullptr)
		{
			break;
		}
	for (int bulletCount = 0; bulletCount < 30; bulletCount++)
	{
		if (bullet[bulletCount] == nullptr)
		{
			break;
		}

		if (enemy[enemyCount]->HitSphere(bullet[bulletCount]))
		{
			//当たっていればif文に入る　エネミーにプレイヤーの弾がヒット

			//エネミーにダメージを与える
			enemy[enemyCount]->Hit(bullet[bulletCount]->GetDamage());

			//弾を削除する
			player->DeleteBullet(bulletCount);
			bulletCount--;

			//エネミーのHPが0になったら、エネミーを削除する
			if (enemy[enemyCount]->HpCHeck())
			{
				//エネミーの削除

			}
		}

	}
  }
}

//描画に関することを実装する
void GamemainScene::Draw() const 
{
	player->Draw();

	for (int enemyCount = 0; enemyCount < 10; enemyCount++)
	{
		if (enemy[enemyCount] == nullptr)
		{
			break;
		}
		enemy[enemyCount]->Draw();
	}
}

//シーンの変更
AbstractScene* GamemainScene::ChangeScene() 
{
	return this;
}