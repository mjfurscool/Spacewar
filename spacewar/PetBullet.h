#pragma once
#include "Bullet.h"
class CPetBullet :
	 public CBullet
{
public:
	CPetBullet(void);
	~CPetBullet(void);
	static CImageList imagelist;
	static bool Loadimage(void);
	bool draw(CDC* pDC);
	int index;
};

