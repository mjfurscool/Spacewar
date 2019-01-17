#include "StdAfx.h"
#include "EnemyBullet.h"
#include "resource.h"

CEnemybullet::CEnemybullet(void):type(0),lasercount(0)
{
	setspeed(10);
}


CEnemybullet::~CEnemybullet(void)
{
}
bool CEnemybullet::draw(CDC* pDC)
{
	CDC memDC;
	memDC.CreateCompatibleDC(pDC);
	CBitmap bmpDraw;
	if(type==ENORMALBU||type==EBOSSBU)
	{
bmpDraw.LoadBitmap(IDB_ENEBULLET1);//load bitmap
	CBitmap* pbmpOld=memDC.SelectObject(&bmpDraw);
	pDC->TransparentBlt(getpos().x+85,getpos().y+100,32,32,&memDC,0,0,32,32,RGB(255,255,255));
	}
	else if(type==ELASER)
	{
		lasercount++;
		bmpDraw.LoadBitmap(IDB_LASER);//load bitmap
	CBitmap* pbmpOld=memDC.SelectObject(&bmpDraw);
	pDC->TransparentBlt(getpos().x+90,getpos().y+100,49,2000,&memDC,0,0,49,2000,RGB(255,255,255));
	}
	
	return false;
}
bool CEnemybullet::removelaser()
{
	if(lasercount>=5)
		return true;
	else
		return false;
}