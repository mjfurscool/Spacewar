#include "StdAfx.h"
#include "BackGround.h"
#include"resource.h"

CBackGround::CBackGround(void)
{
}


CBackGround::~CBackGround(void)
{
}
bool CBackGround::draw(CDC* pDC)
{
	CDC memDC;
	memDC.CreateCompatibleDC(pDC);
	CBitmap bmpDraw;
	bmpDraw.LoadBitmap(IDB_BG);//load bitmap
	//pDC->BitBlt(pos.x,pos.y,6,15,&memDC,0,0,SRCCOPY);
	CBitmap* pbmpOld=memDC.SelectObject(&bmpDraw);
	pDC->TransparentBlt(pos.x,pos.y,512,927,&memDC,0,0,512,917,RGB(255,255,255));
	return false;
}

