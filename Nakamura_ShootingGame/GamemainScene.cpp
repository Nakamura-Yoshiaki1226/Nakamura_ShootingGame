#include "GamemainScene.h"

GamemainScene::GamemainScene()
{
	T_location location = T_location{ 20,100 };
	player = new Player(location);
}
//�`��ȊO�̍X�V����������
void GamemainScene::Update() 
{
	player->Update();
}

//�`��Ɋւ��邱�Ƃ���������
void GamemainScene::Draw() const 
{
	player->Draw();
}

//�V�[���̕ύX
AbstractScene* GamemainScene::ChangeScene() 
{
	return this;
}