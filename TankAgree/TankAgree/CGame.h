#pragma once
class CGame
{
public:
	CGame();
	~CGame();
	void SetHandle(HWND hWnd);//set window hWnd

	bool EnterFram(DWORD dwTime);//进入游戏帧

	void OnMouseMove(UINT nFlags, CPoint point);

	void OnLButtonUp(UINT nFlags, CPoint point);

private:
	HWND m_hWnd;
	//绘图
	void GameRunDraw();
	//fps
	void DrawFps(Graphics &gh);
	//记录fps
	int m_fps{ 0 };
};

