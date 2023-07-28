#include<Windows.h>
#include"WinApp.h"
#include"DirectXCommon.h"
#include"MyEngine.h"
#include"Triangle.h"

//Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	WinApp* window = new WinApp;
	DirectXCommon* directXCommon = new DirectXCommon;
	MyEngine* engine = new MyEngine;

	//アプリケーションの開始
	window->StartApp();
	directXCommon->Initialize(window->GetHwnd());
	engine->Initialize();

	Vector4 data1[4];
	Vector4 data2[4];
	Vector4 data3[4];

	for (int i = 0; i < 4; i++)
	{

		data1[i] = { -0.2f,-0.2f + (i * 0.5f),0.0f,1.5f };
		data2[i] = { 0.0f,0.2f + (i * 0.4f),0.0f,1.5f };
		data3[i] = { 0.2f,-0.2f + (i * 0.5f),0.0f,1.5f };
	}

	Vector4 data4[3];
	Vector4 data5[3];
	Vector4 data6[3];

	for (int i = 0; i < 3; i++)
	{

		data4[i] = { 0.4f,-0.2f + (i * -0.5f),0.0f,2.0f };
		data5[i] = { 0.6f,0.2f + (i * -0.5f),0.0f,2.0f };
		data6[i] = { 0.8f,-0.2f + (i * -0.5f),0.0f,2.0f };
	}

	Vector4 data7[3];
	Vector4 data8[3];
	Vector4 data9[3];

	for (int i = 0; i < 3; i++)
	{

		data7[i] = { -0.8f,-0.2f + (i * -0.5f),0.0f,2.0f };
		data8[i] = { -0.6f,0.2f + (i * -0.5f),0.0f,2.0f };
		data9[i] = { -0.4f,-0.2f + (i * -0.5f),0.0f,2.0f };
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

			for (int i = 0; i < 4; i++)
			{
				//三角形描画
				engine->Draw(data1[i], data2[i], data3[i]);
			}

			for (int i = 0; i < 3; i++)
			{
				//三角形描画
				engine->Draw(data4[i], data5[i], data6[i]);
			}

			for (int i = 0; i < 3; i++)
			{
				//三角形描画
				engine->Draw(data7[i], data8[i], data9[i]);
			}

			engine->UpdateEnd();

		}
	}

	window->EndApp();
	engine->End();
	directXCommon->PostDraw();
	return 0;
}