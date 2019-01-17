#include "StdAfx.h"
#include "Gift.h"
#include "resource.h"

CGift::CGift(void):type(0)
{
}
bool CGift::draw(CDC* pDC)
{
CDC memDC;
	memDC.CreateCompatibleDC(pDC);
	CBitmap bmpDraw;
	if(type==LIFEGIFT)
	{
     bmpDraw.LoadBitmap(IDB_LIFEGIFT);//load bitmap
	CBitmap* pbmpOld=memDC.SelectObject(&bmpDraw);
	pDC->TransparentBlt(getpos().x,getpos().y+100,106,92,&memDC,0,0,106,92,RGB(255,255,255));
	}
	else if(type==ENEGYGIFT)
	{
		bmpDraw.LoadBitmap(IDB_ENEGYGIFT);//load bitmap
	CBitmap* pbmpOld=memDC.SelectObject(&bmpDraw);
	pDC->TransparentBlt(getpos().x,getpos().y+100,123,106,&memDC,0,0,123,106,RGB(255,255,255));
	}
	
	return false;
}
void CGift::effect(CPlane &a)
{
	if(type==LIFEGIFT)
		a.changelife(5);
	else
		a.changeenegy(7);

}

CGift::~CGift(void)
{
}

