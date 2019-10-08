﻿
// MainFrm.h: CMainFrame 类的接口
//

#pragma once
#include"CGame.h"

class CMainFrame : public CFrameWnd
{

public:
	CMainFrame();
protected:
	DECLARE_DYNAMIC(CMainFrame)

	// 特性
public:

	// 操作
public:

	// 重写
public:

	// 实现
public:
	virtual ~CMainFrame();


	// 生成的消息映射函数
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);

	DECLARE_MESSAGE_MAP()

	int m_iWidth{ 800 };//Client Width
	int m_iHeight{ 600 };// Client Height
// 定时器
	enum ETimerId { ETimerIdGameLoop = 1 };//定时器ID

	CGame m_game;
public:
	afx_msg void OnTimer(UINT_PTR nIDEEvent);

};