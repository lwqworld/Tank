#pragma once
class CGame
{
public:
	CGame();
	~CGame();
	void SetHandle(HWND hWnd);//set window hWnd

	bool EnterFram(DWORD dwTime);//������Ϸ֡

	void OnMouseMove(UINT nFlags, CPoint point);

	void OnLButtonUp(UINT nFlags, CPoint point);

private:
	HWND m_hWnd;
	//��ͼ
	void GameRunDraw();
	//fps
	void DrawFps(Graphics &gh);
	//��¼fps
	int m_fps{ 0 };
};

