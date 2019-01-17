#pragma once
#define ENEGYGIFT 0
#define LIFEGIFT 1
#include "baseclass.h"
#include "Plane.h"
class CGift :
	public CBaseclass
{
public:
	CGift(void);
	~CGift(void);
	public:
	bool draw(CDC* pDC);
	int type;
	void effect(CPlane&);
};

