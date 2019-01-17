#pragma once
class CGameCtrl
{
public:
	CGameCtrl(void);
	virtual ~CGameCtrl(void);	
	static bool is_continue;
	void changescore(int a);
	int getscore();
	void setscore(int a);
	void setcopylife(int a);
	int getcopylife();
	int state;
private:
	int Score;
	int copylife;
};

