//==========================
//===【main.cpp】
//==========================
//    ゲームのエントリーポイントです。
//==========================

//=====================//
//===【インクルード記述】 ===//
//=====================//
#include<Windows.h>
#include<thread>
#include"Window.h"
#include"GameLoopManager.h"

using namespace std;
#define _CRTDBG_MAP_ALLOC

//■■■■■■■■■■■■■■■■//
//■■■【プロトタイプ宣言】■■■//
//■■■■■■■■■■■■■■■■//
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

//■■■■■■■■■■■■■■■■//
//■■■【エントリポイント】■■■//
//■■■■■■■■■■■■■■■■//
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	MSG msg;

	OGL::Window* hWindow =OGL::Window::GetInstance();

	hWindow->SetWindowMainData(&hInstance);
	hWindow->SetWindowName("キャラっと♪スタジオ");
	hWindow->SetWindowSize(1280, 720);
	hWindow->CreateShowWindow(nCmdShow, (WNDPROC)WndProc);

	OGL::GameLoopManager*	gameLoopMng = OGL::GameLoopManager::GetInstance();
	gameLoopMng->BeginGameLoopManager(60);

	while (1)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE))
		{
			if (GetMessage(&msg, NULL, 0, 0) == 0)
			{
				gameLoopMng->EndGameLoopManager();
				break;
			}
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
	return (int)msg.wParam;
}

//■■■■■■■■■■■■■■■■■■■//
//■■■【ウィンドウプロシージャ】■■■//
//■■■■■■■■■■■■■■■■■■■//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message){
	case	WM_DESTROY:
		PostQuitMessage(0);
		break;
	case	WM_KEYDOWN:
		switch (wParam)
		{
		case VK_ESCAPE:
			PostQuitMessage(0);
			break;
		}
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}
#if 0
//■■■■■■■■■■■■■■//
//■■■【ゲームループ】■■■//
//■■■■■■■■■■■■■■//
void	GameLoop(void)
{

	OGL::GameLoop	gameLoop;
	OGL::Timer			timer;

	gameLoop.Init();

	timer.StartLapTime();
	while (g_loopFlg)
	{
		if (timer.GetLapTime() < 1000 / 60)
		{
			continue;	//無限ループって怖いよね
		}
		timer.StartLapTime();

		UpdateInput();

		gameLoop.Update();

		//▼▼▼頂点情報の送出を開始▼▼▼//
		gp_device->GetDevice()->BeginScene();
		gameLoop.Draw();
		//▼▼▼頂点情報の送出を終了▼▼▼//
		gp_device->GetDevice()->EndScene();
		//▼▼▼送出した頂点情報を元に実際に画面にポリゴンを書き込む▼▼▼//
		gp_device->GetDevice()->Present(NULL, NULL, NULL, NULL);
	}
	gameLoop.Uninit();
}
#endif