#include "StdAfx.h"
#include "Explode.h"
#include "resource.h"
CImageList CExplode:: imagelist;
CExplode::CExplode(void)
	: pos(20,20)
	, index(0)
{
}
CExplode::CExplode(int x,int y)
	: pos(x,y)
	, index(0)
{
}
CExplode::CExplode(CPoint pos1)
	: pos(pos1)
	, index(0)
{
}

CExplode::~CExplode(void)
{
}


bool CExplode::draw(CDC* pDC)
{
    index++;
	//if(index<=5)
	{
	imagelist.Draw(pDC,index%6,pos,NULL);
	}

	return false;
}


bool CExplode::Loadimage(void)
{
	imagelist.Create(130,105,ILC_COLOR24|ILC_MASK,1,1);//CImageList::Create
	CBitmap bitmap;
	bitmap.LoadBitmapW(IDB_EXP);
	imagelist.Add(&bitmap,RGB(255,255,255));//
	return false;
}
