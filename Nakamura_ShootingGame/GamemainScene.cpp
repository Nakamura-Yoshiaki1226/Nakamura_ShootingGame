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
			//�������Ă����if���ɓ���@�G�l�~�[�Ƀv���C���[�̒e���q�b�g

			//�G�l�~�[�Ƀ_���[�W��^����
			enemy[enemyCount]->Hit(bullet[bulletCount]->GetDamage());

			//�e���폜����
			player->DeleteBullet(bulletCount);
			bulletCount--;

			//�G�l�~�[��HP��0�ɂȂ�����A�G�l�~�[���폜����
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

				//�X�R�A�̉��Z
				player->AddScore(enemy[enemyCount]->GetPoint());

				//�G�l�~�[�̍폜
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
				break;//�o���b�g�J�E���g���I�����܂���Ƃ���break
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

		//�e�̃��[�v����
		for (int i = 0; i < 30; i++)
		{
			if (bullet[i] == nullptr)
			{
				break;
			}
			//�����蔻��(�_���[�W��^����)
			if (player->HitSphere(bullet[i]))
			{
				player->Hit(bullet[i]->GetDamage());

				enemy[enemyCount]->DeleteBullet(i);
				i--;
			}

		}
	}
	
	//�񕜃A�C�e�����o�āAplayer�ɓ�����Ə����鏈��
	for (int itemCount = 0; itemCount < 10; itemCount++)
	{
		if (items[itemCount] == nullptr)
		{
			break;
		}
		if (items[itemCount]->HitSphere(player) == true)
		{

			//�񕜏���
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

	for (int i = 0; i < 10; i++)
	{
		if (items[i] == nullptr)
		{
			break;
		}
		items[i]->Draw();
	}
}

//�V�[���̕ύX
AbstractScene* GamemainScene::ChangeScene() 
{
	return this;
}