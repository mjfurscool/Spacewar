#include "StdAfx.h"
#include "GameCtrl.h"

bool CGameCtrl :: is_continue=1;
CGameCtrl::CGameCtrl(void):Score(0),state(1000)
{
}
void CGameCtrl :: changescore(int a)
{
	if(Score+a>=0)
	{
		Score+=a;
	}
	else
		Score=0;
}
int CGameCtrl ::  getscore()
{
	return Score;
}
void CGameCtrl :: setscore(int a)
{
	Score=a;
}
void CGameCtrl ::  setcopylife(int a)
{
	copylife=a;
}
int CGameCtrl ::  getcopylife()
{
	return copylife;
}

CGameCtrl::~CGameCtrl(void)
{
}
