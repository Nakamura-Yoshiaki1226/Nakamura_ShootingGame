#include "Enemy.h"
#include"DxLib.h"
#include"StraightBullets.h"
#include"CircleBullet.h"

//�����̗v�f���l����
struct MoveInfomation
{
	T_location targetlocation;
	int pattern;//�����A�����Ȃ��p�^�[��
	int next;
	int waitTimeFlame;
	int attackPattern;//�A�^�b�N
};
//�e�L�X�g�f�[�^��ς����肷�邾���œ������ς��
MoveInfomation moveInfo[10] = {
	{   640,150,0,1,  0,0},
	{1200.4,150,0,1,  0,0},
	{     0,  0,1,3,180,1},//3�b�ԗ����~�܂����܂܍U��
	{  80.2,150,0,4,  0,2},
	{     0,  0,1,5,180,1},
	{1200.4,150,0,2,  0,1},
};


T_location locations[3] = { //[���W�̐�]
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
	:CharaBase(location, 20.f, T_location{ 1,2 }), hp(10), point(10),shotNum(0)//T_location{ 0,0.5 }�X�s�[�h
{
	bullets = new BulletsBase * [30];
	for (int i = 0; i < 30; i++)
	{
		bullets[i] = nullptr;
	}
}

void Enemy::Update()
{
	//�R�����g�A�E�g�œ������~�߂Ă�
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

		//��ʊO�ɍs������e������
		if (bullets[bulletCount]->isScreenOut())
		{
			DeleteBullet(bulletCount);
			bulletCount--;
		}
	}

	//�G���e�𔭎˂��鏈��
	if (bulletCount < /*_ENEMY_BULLET_ALL_*/30 && bullets[bulletCount] == nullptr)
	{
		//�e��
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
	T_location nextLocation = GetLocation();//��������W���ꎞ�I�ɕۑ����Ă���

	if ((nextLocation.y == locations[current].y) &&
		(nextLocation.x == locations[current].x))
	{
		current = next[current];
	}
	else
	{
		//y�̈ړ������@��������
		if (nextLocation.y != locations[current].y)
		{
			if (nextLocation.y < locations[current].y)
			{
				nextLocation.y += speed.y;//�Ⴂ�Ƃ��͂ǂ�ǂ񑝂₵�Ă���
				if ((GetLocation().y <= locations[current].y) &&//���̍��W<�ړI�n
					(locations[current].y <= nextLocation.y))//�ړI�n<���̍��W
				{
					nextLocation.y = locations[current].y;
				}
			}
			else
			{
				nextLocation.y -= speed.y;
				if ((nextLocation.y <= locations[current].y) &&//�ړI�n���щz�����ꍇ
					(locations[current].y <= GetLocation().y))
				{
					nextLocation.y = locations[current].y;//�ړI�n���щz���Ȃ��悤�ɂ��Ă���(�㏑�����Ă���)
				}
			}
		}
		//�����܂�
		if (nextLocation.x != locations[current].x)
		{
			if (nextLocation.x < locations[current].x)
			{
				nextLocation.x += speed.x += speed.x;
				//�ړI�n���щz�����ꍇ
				if ((GetLocation().x <= locations[current].x) &&
					(locations[current].x <= nextLocation.x))
				{
					nextLocation.x = locations[current].x;
				}
			}
			else
			{
				nextLocation.x -= speed.x;
				//�ړI�n���щz�����璼��
				if ((nextLocation.x <= locations[current].x) &&
					(locations[current].x <= GetLocation().x))
				{
					nextLocation.x = locations[current].x;
				}
			}
		}
	}

	SetLocation(nextLocation);//��������W�̍X�V
}