//==========================
//===【GameLoopManager.cpp】
//==========================
//    ゲームループの管理を行います。
//==========================

//=====================//
//===【インクルード記述】 ===//
//=====================//
#include	"GameLoopManager.h"
#include"Window.h"

OGL::GameLoopManager::GameLoopManager()
{
	m_loopFlg = false;
	mp_gameScene = Title::GetInstance();
}

OGL::GameLoopManager::~GameLoopManager()
{
}

void	OGL::GameLoopManager::LoopMain(void)
{
	mp_gameScene->Init();
	mp_gameScene->nextScene = mp_gameScene;
	InitInput(*Window::GetInstance()->GetHinstance(), *Window::GetInstance()->GetHwnd());
	m_loopTimer.StartLapTime();

	while (m_loopFlg)
	{
		if (m_loopTimer.GetLapTime() < 1000 / m_frameRate)
		{
			continue;
		}
		m_loopTimer.StartLapTime();
		UpdateInput();
		mp_gameScene->Update();
		mp_gameScene->Draw();
		if (mp_gameScene != mp_gameScene->GetNextScene())
		{
			mp_gameScene->Uninit();
			mp_gameScene = mp_gameScene->nextScene;
			mp_gameScene->nextScene = mp_gameScene;
			mp_gameScene->Init();
		}
	}
	mp_gameScene->Uninit();
	UninitInput();
}

void	OGL::GameLoopManager::BeginGameLoopManager(float frameRate)
{
	m_frameRate = frameRate;
	m_loopFlg = true;
	std::thread	tempThread(&OGL::GameLoopManager::LoopMain, this);
	std::swap(m_loopThread, tempThread);
}

void	OGL::GameLoopManager::EndGameLoopManager(void)
{
	m_loopFlg = false;
	if (m_loopThread.joinable())
	{
		m_loopThread.join();
	}
}
