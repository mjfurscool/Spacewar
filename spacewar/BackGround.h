#pragma once
#include "afx.h"
class CBackGround :
	public CObject
{
public:
	CBackGround(void);
	virtual ~CBackGround(void);
	CPoint pos;
	int speed;
	bool draw(CDC* pDC);
};

