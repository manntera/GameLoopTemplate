//==========================
//===�ymain.cpp�z
//==========================
//    �Q�[���̃G���g���[�|�C���g�ł��B
//==========================

//=====================//
//===�y�C���N���[�h�L�q�z ===//
//=====================//
#include<Windows.h>
#include<thread>
#include"Window.h"
#include"GameLoopManager.h"

using namespace std;
#define _CRTDBG_MAP_ALLOC

//��������������������������������//
//�������y�v���g�^�C�v�錾�z������//
//��������������������������������//
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

//��������������������������������//
//�������y�G���g���|�C���g�z������//
//��������������������������������//
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	MSG msg;

	OGL::Window* hWindow =OGL::Window::GetInstance();

	hWindow->SetWindowMainData(&hInstance);
	hWindow->SetWindowName("�L�������Ɓ�X�^�W�I");
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

//��������������������������������������//
//�������y�E�B���h�E�v���V�[�W���z������//
//��������������������������������������//
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
//����������������������������//
//�������y�Q�[�����[�v�z������//
//����������������������������//
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
			continue;	//�������[�v���ĕ|�����
		}
		timer.StartLapTime();

		UpdateInput();

		gameLoop.Update();

		//���������_���̑��o���J�n������//
		gp_device->GetDevice()->BeginScene();
		gameLoop.Draw();
		//���������_���̑��o���I��������//
		gp_device->GetDevice()->EndScene();
		//���������o�������_�������Ɏ��ۂɉ�ʂɃ|���S�����������ށ�����//
		gp_device->GetDevice()->Present(NULL, NULL, NULL, NULL);
	}
	gameLoop.Uninit();
}
#endif