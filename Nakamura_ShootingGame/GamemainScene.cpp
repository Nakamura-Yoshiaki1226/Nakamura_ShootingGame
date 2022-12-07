#include "GamemainScene.h"
#include"Recovery.h"

GamemainScene::GamemainScene()
{
	T_location location = T_location{ 20,100 };
	player = new Player(location);

	enemy = new Enemy * [10];
	for (int i = 0; i < 10; i++)
	{
		enemy[i] = nullptr;
	}
	enemy[0] = new Enemy(T_location{ 250,250 });
	/*enemy[0] = new Enemy(T_location{ SCREEN_WIDTH/2,SCREEN_HEIGHT/2});*/


	items = new ItemBase * [10];
	for (int i = 0; i < 10; i++)
	{
		items[i] = nullptr;
	}

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

	for (int i = 0; i < 10; i++)
	{
		if (items[i] == nullptr)
		{
			break;
		}
		items[i]->Update();
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
				for (int i = 0; i < 10; i++)
				{
					if (items[i] == nullptr)
					{
						items[i] = new Recovery(enemy[enemyCount]->GetLocation());
						break;
					}
				}

				//スコアの加算
				player->AddScore(enemy[enemyCount]->GetPoint());

				//エネミーの削除
				delete enemy[enemyCount];
				enemy[enemyCount] = nullptr;

				for (int i = enemyCount + 1; i < 10; i++)
				{
					if (enemy[i] == nullptr)
					{
						break;
					}
					enemy[i - 1] = enemy[i];
					enemy[i] = nullptr;
				}

				enemyCount--;
				break;//バレットカウントを終了しますよというbreak
			}
		}

	}
  }


	for (enemyCount = 0; enemyCount < 10; enemyCount++) 
	{
		if (enemy[enemyCount] == nullptr)
		{
			break;
		}
		bullet = enemy[enemyCount]->GetBullets();

		//弾のループ判定
		for (int i = 0; i < 30; i++)
		{
			if (bullet[i] == nullptr)
			{
				break;
			}
			//当たり判定(ダメージを与える)
			if (player->HitSphere(bullet[i]))
			{
				player->Hit(bullet[i]->GetDamage());

				enemy[enemyCount]->DeleteBullet(i);
				i--;
			}

		}
	}
	
	//回復アイテムが出て、playerに当たると消える処理
	for (int itemCount = 0; itemCount < 10; itemCount++)
	{
		if (items[itemCount] == nullptr)
		{
			break;
		}
		if (items[itemCount]->HitSphere(player) == true)
		{

			//回復処理
			player->Hit(items[itemCount]);

			delete items[itemCount];
			items[itemCount] = nullptr;

			for (int i = itemCount + 1; i < 10; i++)
			{
				if (items[i] == nullptr)
				{
					break;
				}
				items[i - 1] = items[i];
				items[i] = nullptr;
			}
			itemCount--;
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

	for (int i = 0; i < 10; i++)
	{
		if (items[i] == nullptr)
		{
			break;
		}
		items[i]->Draw();
	}
}

//シーンの変更
AbstractScene* GamemainScene::ChangeScene() 
{
	return this;
}