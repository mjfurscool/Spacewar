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
	static int attack_speed;//�����ٶ�
	static int pro_speed;//�����ٶ�
	int imageid;
	int skill;
};

