#include "MyEngine.h"
#include "GameScene.h"

const wchar_t kWindowTitle[] = { L"CG2_LE2B_04_ウエキレオ" };

//Windowsアプリでのエントリーポイント
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) 
{
	//COMの初期化
	CoInitializeEx(0, COINIT_MULTITHREADED);

	//初期化
	WinApp* win_ = nullptr;
	MyEngine* engine = new MyEngine;
	engine->Initialize(win_, kWindowTitle, 1280, 720);

	GameScene* gameScene = new GameScene();
	gameScene->Initialize(engine, engine->GetDirectXCommon());

	while (true) 
	{
		//windowのメッセージを最優先で処理させる
		if (win_->Procesmessage()) 
		{
			break;
		}

		//ゲームの処理
		engine->BeginFrame();

		gameScene->Update();

		gameScene->Draw();

		engine->EndFrame();
	}


	//解放処理
	engine->Finalize();
	gameScene->Finalize();
	CoUninitialize();

	return 0;
}