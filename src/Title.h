//==========================
//===�yTitle.h�z
//==========================
//    �^�C�g����ʂ̊Ǘ����s���܂��B
//==========================
#pragma	once
//=====================//
//===�y�C���N���[�h�L�q�z ===//
//=====================//
#include"GameScene.h"
namespace	OGL
{
	class	Title:public GameScene
	{
	private:
		Title(){};
		Title(const Title &hoge){};
		Title &operator=(const Title &){ return *this; }
	public:
		static	Title*	GetInstance(void)
		{
			static Title	instance;
			return &instance;
		}
		virtual ~Title(){};
	public:
		void	Init(void);
		void	Update(void);
		void	Draw(void);
		void	Uninit(void);
	};	//EndOf__class_Title
}	//EndOf__namespace_OGL
