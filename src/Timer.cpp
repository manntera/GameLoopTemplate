//=========================================================================//
//======【Timer.cpp】
//======		時間を管理します。
//=========================================================================//
#include "Timer.h"

OGL::Timer::Timer()
{
	m_startLapTime = 0;
	m_StartStopTime = 0;
	m_stopFlg = false;
}

OGL::Timer::~Timer()
{
}

//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■//
//■■■プログラムの実行時間をミリ秒単位で取得します	。	■■■//
//■■■	return	-	実行時間(ミリ秒)						■■■//
//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■//
DWORD	OGL::Timer::GetTime(void)
{
	return timeGetTime();
}

//■■■■■■■■■■■■■■■■■■//
//■■■ラップタイム開始します。■■■//
//■■■■■■■■■■■■■■■■■■//
void		OGL::Timer::StartLapTime(void)
{
	m_startLapTime = GetTime();
	m_StartStopTime = m_startLapTime;
}

//■■■■■■■■■■■■■■■■■■■//
//■■■ラップタイムを取得します。■■■//
//■■■■■■■■■■■■■■■■■■■//
DWORD	OGL::Timer::GetLapTime(void)
{
	if (m_stopFlg == true)
	{
		return m_StartStopTime - m_startLapTime;
	}
	return GetTime() - m_startLapTime;
}

//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■//
//■■■指定したFPSのフレーム数のラップタイムを取得します	■■■//
//■■■	param1	-	FPS											■■■//
//■■■	return	-	フレーム数									■■■//
//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■//
float	OGL::Timer::GetLapFrameTime(float fps)
{
	return float(GetLapTime()) / (1000 / fps);
}

void		OGL::Timer::StopTime(void)
{
	if (m_stopFlg == false)
	{
		m_stopFlg = true;
		m_StartStopTime = GetTime();
	}
}

void		OGL::Timer::StartTime(void)
{
	if (m_stopFlg == true)
	{
		m_stopFlg = false;
		m_startLapTime = m_startLapTime+(GetTime() - m_StartStopTime);
	}
}

DWORD	OGL::Timer::GetLapMin(void)
{
	return GetLapTime() / 60000;
}

DWORD	OGL::Timer::GetLapSec(void)
{
	return (GetLapTime() / 1000)%60;
}

DWORD	OGL::Timer::GetLapMSec(void)
{
	return GetLapTime() % 1000;
}