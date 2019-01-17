
#include "bullet.h"
#define EBOSSBU 5
#define ENORMALBU 0
#define ELASER 1
class CEnemybullet :
	public CBullet
{
public:
	bool draw(CDC* pDC);
	CEnemybullet(void);
	virtual ~CEnemybullet(void);
	int type;
	bool removelaser();
private:
	int lasercount;//给激光计时
};
