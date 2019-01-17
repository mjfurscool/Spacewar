#include "StdAfx.h"
#include "Baseclass.h"


CBaseclass::CBaseclass(void)
{
}
CBaseclass::CBaseclass(CPoint pos1):speed(0),pos(pos1)
{

}
CBaseclass::CBaseclass(int a,int b):speed(0)
{
	pos.x=a;pos.y=b;
}
int CBaseclass::getspeed()
{
	return speed;
}
void CBaseclass::setspeed(int a)
{
	speed=a;
}
void CBaseclass::setpos(CPoint pos1)
{
	pos=pos1;
}
void CBaseclass::setpos(int a,int b)
{
	pos.x=a;
	pos.y=b;
}
	void CBaseclass:: movex(int a)
	{
		pos.x+=a;
	}
	void CBaseclass:: movey(int a)
	{
		pos.y+=a;
	}
CPoint CBaseclass::getpos()
{
	return pos;
}

CBaseclass::~CBaseclass(void)
{
}
