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
//�`��ȊO�̍X�V����������
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
			//�������Ă����if���ɓ���@�G�l�~�[�Ƀv���C���[�̒e���q�b�g

			//�G�l�~�[�Ƀ_���[�W��^����
			enemy[enemyCount]->Hit(bullet[bulletCount]->GetDamage());

			//�e���폜����
			player->DeleteBullet(bulletCount);
			bulletCount--;

			//�G�l�~�[��HP��0�ɂȂ�����A�G�l�~�[���폜����
			if (enemy[enemyCount]->HpCHeck())
			{
				//�G�l�~�[�̍폜

			}
		}

	}
  }
}

//�`��Ɋւ��邱�Ƃ���������
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

//�V�[���̕ύX
AbstractScene* GamemainScene::ChangeScene() 
{
	return this;
}