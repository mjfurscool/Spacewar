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
	bool Loadimage(void);//������õ��ӵ�
	int index;//������õ��ӵ�
	int width;
	int height;


};

