#pragma once
#include "AbstractScene.h"
#include"Player.h"
#include"Enemy.h"
#include"ItemBase.h"

class GamemainScene : public AbstractScene
{
private:
	Player* player;
	Enemy** enemy;
	ItemBase** items;

public:
	GamemainScene();
	virtual ~GamemainScene() //�f�X�g���N�^
	{}

public:
	virtual void Update() override;//�`��ȊO�̍X�V����������
	virtual void Draw() const override;//�`��Ɋւ��邱�Ƃ���������
	virtual AbstractScene* ChangeScene() override;//�V�[���̕ύX
};