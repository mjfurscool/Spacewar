#pragma once
#include "baseclass.h"
class CPassenger :
	public CBaseclass
{
public:
	CPassenger(void);
	virtual ~CPassenger(void);
	bool draw(CDC* pDC);
};

