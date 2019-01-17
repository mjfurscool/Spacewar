#include "StdAfx.h"
#include "AirBus.h"
#include"resource.h"

CAirBus::CAirBus(void):pasnum(rand()%10+1),is_drop(0),is_landing(0)
{
	setspeed(20);
}


CAirBus::~CAirBus(void)
{
}
bool CAirBus::draw(CDC* pDC)
{
	CDC memDC;
	memDC.CreateCompatibleDC(pDC);
	CBitmap bmpDraw;
	if(is_forced==0)
	{
    
	bmpDraw.LoadBitmap(IDB_AIRBUS);//load bitmap
	//pDC->BitBlt(pos.x,pos.y,6,15,&memDC,0,0,SRCCOPY);
	CBitmap* pbmpOld=memDC.SelectObject(&bmpDraw);
	pDC->TransparentBlt(getpos().x,getpos().y,1500,500,&memDC,0,0,1500,500,RGB(255,255,255));
	}
	else
	{
	bmpDraw.LoadBitmap(IDB_FAIRBUS);//load bitmap
	//pDC->BitBlt(pos.x,pos.y,6,15,&memDC,0,0,SRCCOPY);
	CBitmap* pbmpOld=memDC.SelectObject(&bmpDraw);
	pDC->TransparentBlt(getpos().x,getpos().y,1729,512,&memDC,0,0,1500,500,RGB(255,255,255));
	}
	return false;
}