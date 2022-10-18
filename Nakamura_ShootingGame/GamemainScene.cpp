#include "GamemainScene.h"

GamemainScene::GamemainScene()
{
	T_location location = T_location{ 20,100 };
	player = new Player(location);
}
//描画以外の更新を実装する
void GamemainScene::Update() 
{
	player->Update();
}

//描画に関することを実装する
void GamemainScene::Draw() const 
{
	player->Draw();
}

//シーンの変更
AbstractScene* GamemainScene::ChangeScene() 
{
	return this;
}