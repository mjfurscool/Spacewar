#pragma once
#include "afx.h"
#include "atltypes.h"
#include "afxwin.h"
#include"Baseclass.h"
class CExplode :
	public CBaseclass
{
public:
	CExplode(void);
	CExplode(int x,int y);
	CExplode(CPoint pos1);
	virtual ~CExplode(void);
	CPoint pos;
	// ±¬Õ¨Í¼±ä
	static CImageList imagelist;
	bool draw(CDC* pDC);
	static bool Loadimage(void);
	int index;
};
