#pragma once
#include "afx.h"
class CBaseclass :
	public CObject
{
public:
	CBaseclass(void);
	CBaseclass(CPoint pos1);
	CBaseclass(int a,int b );
	~CBaseclass(void);
private:
	CPoint pos;
	int speed;
public:
	int getspeed();
	void setspeed(int a);
	CPoint getpos();
	void setpos(CPoint pos1);
	void setpos(int a,int b);
	void movex(int a);
	void movey(int a);

};

