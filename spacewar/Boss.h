#pragma once
#include "enemyplane.h"
class CBoss :
	public CEnemyplane
{
public:
	CBoss(void);
	~CBoss(void);
	int getlife();
	void setlife(int a);
	void changelife(int a);
	bool is_left;
		void turn();
		void automove();
	static	bool is_exist;
private:
	int life;
};

