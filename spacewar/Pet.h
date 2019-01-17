#pragma once
#include "baseclass.h"
class CPet :
	public CBaseclass
{
public:
	CPet(void);
	virtual ~CPet(void);
	static CImageList imagelist;
	static bool Loadimage(void);
	static int num;
	bool draw(CDC* pDC);	
	int index;
	int getattack_speed();

private:
	int attack_speed;
};


//		public CObject
//{
//public:
//	CExplode(void);
//	CExplode(int x,int y);
//	CExplode(CPoint pos1);
//	virtual ~CExplode(void);
//	CPoint pos;
//	// ±¬Õ¨Í¼±ä
//	static CImageList imagelist;
//	bool draw(CDC* pDC);
//	static bool Loadimage(void);
//	int index;
//};