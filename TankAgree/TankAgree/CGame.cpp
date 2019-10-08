#include "stdafx.h"
#include "CGame.h"


CGame::CGame()
{
}


CGame::~CGame()
{
}

void CGame::SetHandle(HWND hWnd)
{
	m_hWnd = hWnd;
}

bool CGame::EnterFram(DWORD dwTime)
{
	GameRunDraw();
	return false;
}

void CGame::OnMouseMove(UINT nFlags, CPoint point)
{
}

void CGame::OnLButtonUp(UINT nFlags, CPoint point)
{
}

void CGame::GameRunDraw()
{
	HDC hdc = ::GetDC(m_hWnd);
	CRect rc;
	GetClientRect(m_hWnd, &rc);

	CDC *dc = CClientDC::FromHandle(hdc);

	CDC m_dcMemory;
	CBitmap bmp;//双缓冲绘图用
	bmp.CreateCompatibleBitmap(dc, rc.Width(), rc.Height());
	m_dcMemory.CreateCompatibleDC(dc);
	CBitmap *pOldBitmap = m_dcMemory.SelectObject(&bmp);

	Graphics gh(m_dcMemory.GetSafeHdc());//构造对象
	gh.Clear(Color::White);//清除背景
	gh.ResetClip();
	DrawFps(gh);
	//background image
	Gdiplus::Image *img = Image::FromFile(_T("./res/fox.jpeg"));
	gh.DrawImage(img, rc.left, rc.top, rc.Width(), rc.Height());

	::BitBlt(hdc, 0, 0, rc.Width(), rc.Height(), m_dcMemory.GetSafeHdc(), 0, 0, SRCCOPY);
	dc->DeleteDC();
	return;
}

void CGame::DrawFps(Graphics & gh)
{
	static int fps = 0;
	m_fps++;
	static DWORD dwLast = GetTickCount();
	//记录帧数
	if (GetTickCount() - dwLast >= 1000) {
		fps = m_fps;
		m_fps = 0;
		dwLast = GetTickCount();

	}
	//输出fps
	{
		CString s;
		s.Format(_T("FPS:%d"), fps);
		SolidBrush brush(Color::Red);
		Gdiplus::Font font(_T("宋体"), 10.0);
		CRect rc;
		::GetClientRect(m_hWnd, &rc);
		PointF origin(static_cast<float>(rc.right - 50), static_cast<float>(rc.top + 2));
		gh.DrawString(s.GetString(), -1, &font, origin, &brush);
	}

}

