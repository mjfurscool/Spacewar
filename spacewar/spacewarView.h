
// spacewarView.h : CspacewarView ��Ľӿ�
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
protected: // �������л�����
	CspacewarView();
	DECLARE_DYNCREATE(CspacewarView)

// ����
public:
	CspacewarDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CspacewarView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
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
	CDC MemDC; //���ȶ���һ����ʾ�豸����
    CBitmap MemBitmap;//����һ��λͼ����
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

#ifndef _DEBUG  // spacewarView.cpp �еĵ��԰汾
inline CspacewarDoc* CspacewarView::GetDocument() const
   { return reinterpret_cast<CspacewarDoc*>(m_pDocument); }
#endif

