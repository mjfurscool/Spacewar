#include "StdAfx.h"
#include "Bullet.h"
#include "resource.h"

CBullet::CBullet(void)
	: index(0)
{
	setspeed(32);
}


CBullet::~CBullet(void)
{
}


bool CBullet::draw(CDC* pDC)
{
	CDC memDC;
	memDC.CreateCompatibleDC(pDC);
	CBitmap bmpDraw;
	bmpDraw.LoadBitmap(imageid);//load bitmap
	//pDC->BitBlt(pos.x,pos.y,6,15,&memDC,0,0,SRCCOPY);
	CBitmap* pbmpOld=memDC.SelectObject(&bmpDraw);
	pDC->TransparentBlt(getpos().x+150,getpos().y+30,width,height,&memDC,0,0,width,height,RGB(255,255,255));
	return false;
}
void CBullet::setimage(int id,int w,int h)
{
	imageid=id;
	width=w;
	height=h;
}

bool CBullet::Loadimage(void)
{
	return false;
}

