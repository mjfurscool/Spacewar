
// spacewarView.h : CspacewarView 类的接口
//

#pragma once
#include "afxcoll.h"
#include "plane.h"
#include "atltypes.h"
#include "background.h"
#include "explode.h"
#include "gamectrl.h"
#include "pet.h"
#define SHOW_AIRBUS 1
#define SHOW_LEVEL 2
#define SHOW_PASSENGER 3
#define ARMYUPDATE 4
#define SHOW_BOSS 5
#define SHOW_FAIRBUS 6

class CspacewarView : public CView
{
protected: // 仅从序列化创建
	CspacewarView();
	DECLARE_DYNCREATE(CspacewarView)

// 特性
public:
	CspacewarDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CspacewarView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
//	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
//	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	virtual void OnInitialUpdate();
	CObList plist;
	CObList plist2;
	afx_msg void OnDestroy();
	afx_msg void Onsetlevel();
	CObList plist_bullet;
	CObList plist_enebullet;
	CObList plist_airbus;
	CPlane My_plane;
	CRect rect;
	CDC MemDC; //首先定义一个显示设备对象
    CBitmap MemBitmap;//定义一个位图对象
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	CBackGround bg;
	afx_msg void OnSize(UINT nType, int cx, int cy);
	CGameCtrl gamectrl;
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	CObList plist_exp;
	void UpDateWin(CDC* pDC);
	CPet lion;
	CObList plist_petbu;
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
	CObList plist_missile;
	int level;
	CObList plist_pas;
	CObList plist_bullet2;
	CObList plist_bos;
	CObList plist_gft;
	 BITMAP bitmap;
	// CRect rctClient;
};

#ifndef _DEBUG  // spacewarView.cpp 中的调试版本
inline CspacewarDoc* CspacewarView::GetDocument() const
   { return reinterpret_cast<CspacewarDoc*>(m_pDocument); }
#endif

