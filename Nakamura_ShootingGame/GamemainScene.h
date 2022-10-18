#pragma once
#include "AbstractScene.h"
#include"Player.h"

class GamemainScene : public AbstractScene
{
private:
	Player* player;

public:
	GamemainScene();
	virtual ~GamemainScene() //�f�X�g���N�^
	{}

public:
	virtual void Update() override;//�`��ȊO�̍X�V����������
	virtual void Draw() const override;//�`��Ɋւ��邱�Ƃ���������
	virtual AbstractScene* ChangeScene() override;//�V�[���̕ύX
};