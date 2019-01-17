#pragma once
#include "afx.h"
#include "atltypes.h"
#include"Baseclass.h"
class CBullet :
	public CBaseclass
{
private:
	int imageid;
public:
	CBullet(void);
	virtual ~CBullet(void);
	bool draw(CDC* pDC);
	void setimage(int id,int w,int h);
	bool Loadimage(void);//可做变幻的子弹
	int index;//可做变幻的子弹
	int width;
	int height;


};

