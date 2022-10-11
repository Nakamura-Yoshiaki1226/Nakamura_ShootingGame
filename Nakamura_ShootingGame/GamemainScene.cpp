#include "GamemainScene.h"

//描画以外の更新を実装する
void GamemainScene::Update() 
{

}

//描画に関することを実装する
void GamemainScene::Draw() const 
{

}

//シーンの変更
AbstractScene* GamemainScene::ChangeScene() 
{
	return this;
}