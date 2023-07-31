#include "MyEngine.h"
#include "Triangle.h"

const wchar_t kWindowTitle[] = { L"CG2_LE2B_04_ウエキレオ" };

//Windowsアプリでのエントリーポイント
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) 
{
	//初期化
	WinApp* win_ = nullptr;
	MyEngine* Engine = new MyEngine;
	Engine->Initialization(win_, kWindowTitle, 1280, 720);

	Engine->Initialize();
	Vector4 triangleVertexData[10][3];
	Vector4 material[10] = {};
	float materialColor[3] = { material[10].x,material[10].y,material[10].z};

	for (int i = 0; i < 10; i++)
	{
		triangleVertexData[i][0] = { -0.2f,-1.8f + (i * 0.3f),0.0f,2.0f };
		triangleVertexData[i][1] = { 0.0f,-1.4f + (i * 0.3f),0.0f,2.0f };
		triangleVertexData[i][2] = { 0.2f,-1.8f + (i * 0.3f),0.0f,2.0f };
		material[i] = { material[i].x,material[i].y,material[i].z};
	}

	while (true) 
	{
		//windowのメッセージを最優先で処理させる
		if (win_->Procesmessage()) {
			break;
		}

		//ゲームの処理
		Engine->BeginFrame();

		Engine->Update();

		ImGui::Begin("Triangle");
		ImGui::ColorEdit3("Color", materialColor);
		ImGui::End();

		for (int i = 0; i < 10; i++)
		{
			material[i].x = materialColor[0];
			material[i].y = materialColor[1];
			material[i].z = materialColor[2];
		}

		//三角形描画
		for (int i = 0; i < 10; i++)
		{
			Engine->DrawTriangle(triangleVertexData[i][0], triangleVertexData[i][1], triangleVertexData[i][2], material[i]);
		}

		Engine->EndFrame();
	}

	//解放処理
	Engine->Finalize();

	return 0;
}