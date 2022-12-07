#include "DxLib.h"
#include"SceneManager.h"
#include"GamemainScene.h"

/***********************************************
 * プログラムの開始
 ***********************************************/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow) {

	// タイトルを test に変更
	SetMainWindowText("シューティングゲーム");

	ChangeWindowMode(TRUE);		// ウィンドウモードで起動

	//windowsSize
	SetGraphMode(640, 480, 16);
	int SCREEN_WIDTH = 640;
	int SCREEN_HEIGHT = 480;
	/*int SCREEN_COLOR_BIT_16;*/



	/*SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_COLOR_BIT_16);*/

	if (DxLib_Init() == -1) return -1;	// DXライブラリの初期化処理

	SetDrawScreen(DX_SCREEN_BACK);	// 描画先画面を裏にする

	SetFontSize(20);		// 文字サイズを設定

	//シーンマネージャーオブジェクトの作成
	SceneManager sceneMng( dynamic_cast<AbstractScene*>(new GamemainScene()) );

	// ゲームループ
	while (ProcessMessage() == 0) {
			
		ClearDrawScreen();		// 画面の初期化

		sceneMng.Update();      //シーンの更新処理
		sceneMng.Draw();        //シーンの描画処理
		if (sceneMng.ChangeScene() == nullptr)//シーンの変更処理
		{
			DxLib_End();	// DXライブラリ使用の終了処理
			return 0;	// ソフトの終了
		}
			
		ScreenFlip();		// 裏画面の内容を表画面に反映
	}

	DxLib_End();	// DXライブラリ使用の終了処理
	return 0;	// ソフトの終了
}