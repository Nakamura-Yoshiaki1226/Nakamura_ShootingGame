#pragma once
#include "AbstractScene.h"
#include"Player.h"

class GamemainScene : public AbstractScene
{
private:
	Player* player;

public:
	GamemainScene();
	virtual ~GamemainScene() //デストラクタ
	{}

public:
	virtual void Update() override;//描画以外の更新を実装する
	virtual void Draw() const override;//描画に関することを実装する
	virtual AbstractScene* ChangeScene() override;//シーンの変更
};