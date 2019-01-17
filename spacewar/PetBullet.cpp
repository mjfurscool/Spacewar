#include "StdAfx.h"
#include "PetBullet.h"
#include "resource.h"

CImageList CPetBullet:: imagelist;
CPetBullet::CPetBullet(void)
	:index(0)
{
	setspeed(16);
}

CPetBullet::~CPetBullet(void)
{
}

bool CPetBullet::draw(CDC* pDC)
{
    index++;
	{
	imagelist.Draw(pDC,index%2,getpos(),NULL);
	}

	return false;
}
bool CPetBullet::Loadimage(void)
{
	imagelist.Create(160,153,ILC_COLOR24|ILC_MASK,1,1);//CImageList::Create
	CBitmap bitmap;
	bitmap.LoadBitmapW(IDB_LIONBULLET);
	imagelist.Add(&bitmap,RGB(255,255,255));//
	return false;
}
