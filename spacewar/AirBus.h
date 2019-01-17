#pragma once
#include "baseclass.h"
#include "passenger.h"
class CAirBus :
	public CBaseclass
{
public:
	CAirBus(void);
	~CAirBus(void);
	CPassenger pas;
	int pasnum;
	bool draw(CDC* pDC);
    bool is_drop;
	bool is_landing;
	bool is_forced;
};

