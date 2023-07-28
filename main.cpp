#include<Windows.h>
#include"WinApp.h"
#include"DirectXCommon.h"
#include"MyEngine.h"
#include"Triangle.h"

//Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	WinApp* winApp = new WinApp;
	DirectXCommon* directXCommon = new DirectXCommon;
	MyEngine* engine = new MyEngine;

	//アプリケーションの開始
	winApp->StartApp();
	directXCommon->Initialize(winApp->GetHwnd());
	engine->Initialize();

	Vector4 triangleVertexData[10][3];
	Triangle* triangle[10];
	Vector4 material[10];

	for (int i = 0; i < 10; i++)
	{
		triangleVertexData[i][0] = { -0.2f,-1.8f + (i * 0.3f),0.0f,2.0f };
		triangleVertexData[i][1] = { 0.0f,-1.4f + (i * 0.3f),0.0f,2.0f };
		triangleVertexData[i][2] = { 0.2f,-1.8f + (i * 0.3f),0.0f,2.0f };
		material[i] = { 0.0f + (i * 0.1f),1.0f,0.0f,1.0f };
		triangle[i] = new Triangle;
		triangle[i]->Initialize(directXCommon, triangleVertexData[i][0], triangleVertexData[i][1], triangleVertexData[i][2], material[i]);
	}
	MSG msg{};

	while (msg.message != WM_QUIT)
	{
		//Windowsにメッセージが来てたら最優先で処理させる
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			engine->Update();

			for (int i = 0; i < 10; i++)
			{
				//三角形描画
				triangle[i]->Draw();
			}

			engine->UpdateEnd();
		}
	}

	for (int i = 0; i < 10; i++)
	{
		triangle[i]->Finalize();
	}

	winApp->EndApp();
	engine->Finalize();
	directXCommon->PostDraw();

	return 0;
}