#include "StdAfx.h"
#include "Boss.h"


CBoss::CBoss(void):life(500),is_left(0)
{
	setspeed(1);
}
bool CBoss:: is_exist=0;
int CBoss::getlife()
{
	return life;
}
void CBoss::setlife(int a)
{
	life=a;
}
void CBoss::changelife(int a)
{
	life+=a;
}
void CBoss::turn()
{
	if(is_left==0)
		is_left=1;
	else
		is_left=0;

}
void CBoss::automove()
{
	if(is_left==1)
	{
	movex(-getspeed());
	movey(-getspeed()/3);
	}
	else
	
		{movex(getspeed());
	movey(getspeed()/4);
	}
}
CBoss::~CBoss(void)
{
}
