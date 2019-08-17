//==========================
//===�yWindow.h�z
//==========================
//    window�̐����Ƃ���̊Ǘ��E�ێ����s���܂��B
//==========================
#pragma	once
//=====================//
//===�y�C���N���[�h�L�q�z ===//
//=====================//
#include<Windows.h>
#include<string>

namespace	OGL
{
	class	Window
	{
	private:
		Window();
		Window(const Window &hoge){};
		Window &operator=(const Window &){ return *this; }
	public:
		static	Window*	GetInstance(void)
		{
			static Window	instance;
			return &instance;
		}
		virtual ~Window();
	private:
		HINSTANCE*	mp_hInstance;
		HWND			m_hWnd;
		int					m_winWidth;
		int					m_winHeight;
		std::string		m_windowName;

	public:
		void	SetWindowMainData(HINSTANCE*	hInstance);
		void	SetWindowName(const char* windowName);
		void	SetWindowSize(int width, int height);
		void	CreateShowWindow(int nCmdShow, WNDPROC wndProc);
		HINSTANCE*	GetHinstance(void);
		HWND*			GetHwnd(void);
	};	//EndOf__class_Window
}	//EndOf__namespace_OGL
