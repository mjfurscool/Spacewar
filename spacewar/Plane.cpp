#include "StdAfx.h"
#include "Plane.h"
#include "resource.h"

CPlane::CPlane(void)
	: life(10),enegy(10),trcbuspeed(1500),procount(0)
{
}


CPlane::~CPlane(void)
{
}
bool CPlane::is_invincible=0;
bool CPlane::is_protected=0;
	int CPlane::getlife()
	{return life;}
	int CPlane::getenegy()
	{return enegy;}
	int CPlane::gettrcbuspeed()
	{return trcbuspeed;}
	void CPlane::setlife(int a)
	{life=a;}
	void CPlane::setenegy(int a)
	{enegy=a;}
	void CPlane::changelife(int a)
	{
		if(a>0)//无条件加血
		life+=a;
		else
		{
			if(is_invincible==0&&is_protected==0)//不无敌减血
			{
				life+=a;
				
			}
				
		}		
	}
	void CPlane::changeenegy(int a)
	{
		if(getenegy()+a>=0)
		enegy+=a;
	}
bool CPlane::draw(CDC* pDC)
{
	CDC memDC;
	memDC.CreateCompatibleDC(pDC);
	CBitmap bmpDraw;
	if(is_protected==0)
	{
		bmpDraw.LoadBitmap(IDB_BITMAP1);//load bitmap
	CBitmap* pbmpOld=memDC.SelectObject(&bmpDraw);
	pDC->TransparentBlt(getpos().x,getpos().y,368,293,&memDC,0,0,368,293,RGB(255,255,255));
	}
	else
	{  
		
	   bmpDraw.LoadBitmap(IDB_PRO);//load bitmap
CBitmap* pbmpOld=memDC.SelectObject(&bmpDraw);	
	pDC->TransparentBlt(getpos().x,getpos().y,368,293,&memDC,0,0,368,293,RGB(255,255,255));
	procount++;//保护膜计时
	if(procount==200)
	{is_protected=0;
	procount=0;
	}
    
	}
	
	return false;
}
