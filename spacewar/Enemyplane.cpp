#include "StdAfx.h"
#include "Enemyplane.h"
#include "resource.h"

CEnemyplane::CEnemyplane(void):skill(rand()%100)
{
	setspeed(8);
}

int  CEnemyplane::attack_speed=2001;
int  CEnemyplane::pro_speed=2001;
CEnemyplane::~CEnemyplane(void)
{
}
bool CEnemyplane::draw(CDC* pDC)
{
	CDC memDC;
	memDC.CreateCompatibleDC(pDC);
	CBitmap bmpDraw;
	bmpDraw.LoadBitmap(imageid);//load bitmap
	//pDC->BitBlt(pos.x,pos.y,6,15,&memDC,0,0,SRCCOPY);
	CBitmap* pbmpOld=memDC.SelectObject(&bmpDraw);
	pDC->TransparentBlt(getpos().x,getpos().y,width,hight,&memDC,0,0,width,hight,RGB(255,255,255));
	return false;
}
void CEnemyplane::setimage(int id,int w,int h)
{
	imageid=id;
	width=w;
	hight=h;
}
int CEnemyplane::getskill()
{
	return skill;
}
int CEnemyplane:: getattack_speed()
{
	return attack_speed;
}
int CEnemyplane:: getpro_speed()
{
	return pro_speed;
}