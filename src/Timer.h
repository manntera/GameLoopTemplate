//=========================================================================//
//======ÅyTimer.hÅz
//======		éûä‘Çä«óùÇµÇ‹Ç∑ÅB
//=========================================================================//
#pragma once
#include<Windows.h>
#pragma comment(lib, "winmm.lib")
namespace OGL
{
	class Timer
	{
	private:
		DWORD	m_startLapTime;
		bool		m_stopFlg;
		DWORD	m_StartStopTime;
	public:
		Timer();
		~Timer();
		void		StartLapTime(void);
		float		GetLapFrameTime(float fps);
		void		StopTime(void);
		void		StartTime(void);
		DWORD	GetTime(void);
		DWORD	GetLapTime(void);
		DWORD	GetLapMin(void);
		DWORD	GetLapSec(void);
		DWORD	GetLapMSec(void);
	};
}
