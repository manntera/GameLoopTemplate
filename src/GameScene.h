//==========================
//===【GameScene.h】
//==========================
//    ゲームの本体処理を記述します。
//    このクラスを継承して使用して下さい
//==========================
#pragma	once
//=====================//
//===【インクルード記述】 ===//
//=====================//
namespace	OGL
{
	class GameScene
	{
	public:
		GameScene();
		GameScene(const GameScene &hoge){};
		GameScene &operator=(const GameScene &){ return *this; }
	public:
		virtual ~GameScene();
	protected:
	public:
		GameScene* nextScene;
		virtual	void	Init(void)=0;
		virtual	void	Update(void) = 0;
		virtual	void	Draw(void) = 0;
		virtual	void	Uninit(void) = 0;

		GameScene*	GetNextScene(void);
	};	//EndOf__class_GameLoop
}	//EndOf__namespace_OGL
