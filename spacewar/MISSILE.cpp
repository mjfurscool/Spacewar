#include "StdAfx.h"
#include "MISSILE.h"
#include "resource.h"
#include "math.h"
CMISSILE::CMISSILE(void)
	:index(0)

{
	setspeed(60);
}
CImageList CMISSILE:: imagelist;

CMISSILE::~CMISSILE(void)
{
}
bool CMISSILE::draw(CDC* pDC)
{
    index++;
	//if(index<=5)
	{
	imagelist.Draw(pDC,index%6,getpos(),NULL);
	}

	return false;
}


bool CMISSILE::Loadimage(void)
{
	imagelist.Create(120,115,ILC_COLOR24|ILC_MASK,1,1);//CImageList::Create
	CBitmap bitmap;
	bitmap.LoadBitmapW(IDB_PIGMISS);
	imagelist.Add(&bitmap,RGB(255,255,255));//
	return false;
}
double CMISSILE::getangle(CPoint pos1)
{
	double tan_a;
	double a;
	tan_a=abs(getpos().y-pos1.y)/abs(getpos().x-pos1.x);
	a=atan(tan_a);
  return a;
}
