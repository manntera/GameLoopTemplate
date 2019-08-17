//==========================
//===【Window.cpp】
//==========================
//    windowの生成とそれの管理・保持を行います。
//==========================

//=====================//
//===【インクルード記述】 ===//
//=====================//
#include	"Window.h"

OGL::Window::Window()
{
}

OGL::Window::~Window()
{
}

void	OGL::Window::SetWindowMainData(HINSTANCE*	hInstance)
{
	mp_hInstance = hInstance;
}

void	OGL::Window::SetWindowName(const char* windowName)
{
	m_windowName = windowName;
}

void	OGL::Window::SetWindowSize(int width, int height)
{
	m_winWidth = width;
	m_winHeight = height;
}

void	OGL::Window::CreateShowWindow(int nCmdShow, WNDPROC wndProc)
{
	WNDCLASSEX wc;

	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.hInstance = *mp_hInstance;
	wc.lpszClassName = m_windowName.c_str();
	wc.lpfnWndProc = wndProc;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wc.lpszMenuName = NULL;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;

	if (!RegisterClassEx(&wc))
	{
		MessageBox(NULL, "ウィンドウクラスの構造体の初期化エラー", "", MB_OK);
	}
	m_hWnd = CreateWindow(wc.lpszClassName,
		m_windowName.c_str(),
		WS_CAPTION | WS_SYSMENU,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		m_winWidth,
		m_winHeight,
		NULL,
		NULL,
		*mp_hInstance,
		NULL);
	ShowWindow(m_hWnd, nCmdShow);
	UpdateWindow(m_hWnd);
}
HINSTANCE*	OGL::Window::GetHinstance(void)
{
	return this->mp_hInstance;
}
HWND*			OGL::Window::GetHwnd(void)
{
	return &m_hWnd;
}