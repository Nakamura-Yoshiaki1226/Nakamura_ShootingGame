#pragma once
#include "AbstractScene.h"
class GamemainScene : public AbstractScene
{
public:
	virtual ~GamemainScene() {};//�f�X�g���N�^
	
	virtual void Update() override;//�`��ȊO�̍X�V����������
	
	virtual void Draw() const override;//�`��Ɋւ��邱�Ƃ���������
	
	virtual AbstractScene* ChangeScene() override;//�V�[���̕ύX
};