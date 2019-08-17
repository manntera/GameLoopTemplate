//==========================
//===【PlayGame.h】
//==========================
//    ゲーム本体画面の管理を行います。
//==========================
#pragma	once
//=====================//
//===【インクルード記述】 ===//
//=====================//
#include"GameScene.h"
namespace	OGL
{
	class	PlayGame :public GameScene
	{
	private:
		PlayGame(){};
		PlayGame(const PlayGame &hoge){};
		PlayGame &operator=(const PlayGame &){ return *this; }
	public:
		static	PlayGame*	GetInstance(void)
		{
			static PlayGame	instance;
			return &instance;
		}
		virtual ~PlayGame(){};
	public:
		void	Init(void);
		void	Update(void);
		void	Draw(void);
		void	Uninit(void);
	};	//EndOf__class_Title
}	//EndOf__namespace_OGL
