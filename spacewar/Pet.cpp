#include "StdAfx.h"
#include "Pet.h"
#include "resource.h"
CImageList CPet:: imagelist;
int CPet::num=0;
CPet::CPet(void)
	:index(0),attack_speed(1500)
{
}

CPet::~CPet(void)
{
}
bool CPet::draw(CDC* pDC)
{
    index++;
	if (num==1)
	{
	imagelist.Draw(pDC,index%10,getpos(),NULL);
	}

	return false;
}
int CPet::getattack_speed()
{
	return attack_speed; 
}

bool CPet::Loadimage(void)
{
	imagelist.Create(241,360,ILC_COLOR24|ILC_MASK,1,1);//CImageList::Create
	CBitmap bitmap;
	bitmap.LoadBitmapW(IDB_LION);
	imagelist.Add(&bitmap,RGB(255,255,255));//
	return false;
}
