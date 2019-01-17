#pragma once
#include "afx.h"
#include "atltypes.h"
#include"Baseclass.h"
class CPlane :
	public CBaseclass
{
public:
	CPlane(void);
	virtual ~CPlane(void);
	bool draw(CDC* pDC);
	int getlife();
	int getenegy();
	void setlife(int a);
	void setenegy(int a);
    void changelife(int a);
	void changeenegy(int a);
	int gettrcbuspeed();
	static bool is_invincible;
	static bool is_protected;
	int procount;
private:
	int life;
	int enegy;
	int trcbuspeed;
};

