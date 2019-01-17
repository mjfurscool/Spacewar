#include "StdAfx.h"
#include "Passenger.h"
#include "resource.h"
CPassenger::CPassenger(void)
{
	setspeed(10);
}
bool CPassenger::draw(CDC* pDC)
{
	CDC memDC;
	memDC.CreateCompatibleDC(pDC);
	CBitmap bmpDraw;
	bmpDraw.LoadBitmap(IDB_PAS);//load bitmap
	//pDC->BitBlt(pos.x,pos.y,6,15,&memDC,0,0,SRCCOPY);
	CBitmap* pbmpOld=memDC.SelectObject(&bmpDraw);
	pDC->TransparentBlt(getpos().x,getpos().y,200,200,&memDC,0,0,200,200,RGB(255,255,255));
	return false;
}

CPassenger::~CPassenger(void)
{
}
