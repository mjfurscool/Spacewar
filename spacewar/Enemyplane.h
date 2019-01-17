#pragma once
#include "Baseclass.h"
class CEnemyplane :
	public CBaseclass
{
public:
	bool draw(CDC* pDC);
	CEnemyplane(void);
	virtual ~CEnemyplane(void);
	static int getattack_speed();
	static int getpro_speed();
	int width;
	int hight;
	void setimage(int id,int w,int h);
	int getskill();
private:
	static int attack_speed;//攻击速度
	static int pro_speed;//产生速度
	int imageid;
	int skill;
};

