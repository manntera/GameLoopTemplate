//==========================
//===【PlayGame.cpp】
//==========================
//    ゲーム本体画面の管理を行います。
//==========================

//=====================//
//===【インクルード記述】 ===//
//=====================//
#include	"GameSceneList.h"

//■■■■■■■■■■■■■■■■■■■//
//■■■シーンの初期化を行います。■■■//
//■■■■■■■■■■■■■■■■■■■//
void	OGL::PlayGame::Init(void)
{

}

//■■■■■■■■■■■■■■■■■■//
//■■■シーンの更新を行います。■■■//
//■■■■■■■■■■■■■■■■■■//
void	OGL::PlayGame::Update(void)
{
	if (GetKeyboardTrigger(DIK_SPACE))
	{
		this->nextScene = Title::GetInstance();
	}
}

//■■■■■■■■■■■■■■■■■■//
//■■■シーンの描画を行います。■■■//
//■■■■■■■■■■■■■■■■■■//
void	OGL::PlayGame::Draw(void)
{

}

//■■■■■■■■■■■■■■■■■■■■//
//■■■シーンの終了処理を行います。■■■//
//■■■■■■■■■■■■■■■■■■■■//
void	OGL::PlayGame::Uninit(void)
{

}