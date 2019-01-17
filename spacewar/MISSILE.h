#pragma once
#include "Enemyplane.h"
class CMISSILE :
	public CBaseclass
{
public:
	CMISSILE(void);
	~CMISSILE(void);
	bool draw(CDC* pDC);
	double getangle(CPoint);
	static CImageList imagelist;
	static bool Loadimage(void);
	int index;
private:	
	double angle;
};

