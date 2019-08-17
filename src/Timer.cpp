//=========================================================================//
//======�yTimer.cpp�z
//======		���Ԃ��Ǘ����܂��B
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

//������������������������������������������������������������//
//�������v���O�����̎��s���Ԃ��~���b�P�ʂŎ擾���܂�	�B	������//
//������	return	-	���s����(�~���b)						������//
//������������������������������������������������������������//
DWORD	OGL::Timer::GetTime(void)
{
	return timeGetTime();
}

//������������������������������������//
//���������b�v�^�C���J�n���܂��B������//
//������������������������������������//
void		OGL::Timer::StartLapTime(void)
{
	m_startLapTime = GetTime();
	m_StartStopTime = m_startLapTime;
}

//��������������������������������������//
//���������b�v�^�C�����擾���܂��B������//
//��������������������������������������//
DWORD	OGL::Timer::GetLapTime(void)
{
	if (m_stopFlg == true)
	{
		return m_StartStopTime - m_startLapTime;
	}
	return GetTime() - m_startLapTime;
}

//��������������������������������������������������������������//
//�������w�肵��FPS�̃t���[�����̃��b�v�^�C�����擾���܂�	������//
//������	param1	-	FPS											������//
//������	return	-	�t���[����									������//
//������������������������������������������������������������//
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