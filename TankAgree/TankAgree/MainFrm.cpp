
// MainFrm.cpp: CMainFrame 类的实现
//

#include "stdafx.h"
#include "TankAgree.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

/***********************************************************************************/
//gloabl variable
#define GAME_WIN_W (800)
#define GAME_WIN_H (600)
// CMainFrame

IMPLEMENT_DYNAMIC(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CMainFrame 构造/析构

CMainFrame::CMainFrame()
{
	#define MY_STYLE (WS_OVERLAPPED|WS_CAPTION|WS_SYSMENU|WS_MINIMIZEBOX|FWS_ADDTOTITLE)
	//create window
	Create(NULL, _T("坦克大战"), MY_STYLE, CRect(0, 0, GAME_WIN_W, GAME_WIN_H));
	{
		CRect rcCli;
		GetClientRect(rcCli);//get Client size
		//set frame size
		RECT rcFrame = { 0,0,m_iWidth * 2 - rcCli.right,m_iHeight * 2 - rcCli.bottom };

		MoveWindow(&rcFrame, TRUE);
	}
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1) {
		return -1;
	}
	SetTimer(ETimerIdGameLoop, 0, NULL);
	m_game.SetHandle(GetSafeHwnd());//设置游戏主窗口句柄

	return 0;
}
void CMainFrame::OnTimer(UINT_PTR nIDEvent) 
{
	switch (nIDEvent) 
	{
		case ETimerIdGameLoop: 
		{
			static DWORD dwLastUpdate = GetTickCount();//记录本次时刻
			if (GetTickCount() - dwLastUpdate >= 20) {
				m_game.EnterFram(GetTickCount());
				dwLastUpdate = GetTickCount();
			}
		}
		default:
			break;
	}
	CFrameWnd::OnTimer(nIDEvent);
}



