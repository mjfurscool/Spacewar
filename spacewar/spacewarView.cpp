
// spacewarView.cpp : CspacewarView 类的实现
//
#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "spacewar.h"
#endif
#include "math.h"
#include "spacewarDoc.h"
#include "spacewarView.h"
#include "Plane.h"
#include "Enemyplane.h"
#include "resource.h"
#include "Explode.h"
#include "Bullet.h"
#include "Enemybullet.h"
#include "sethardlevel.h"
#include "Pet.h"
#include "PetBullet.h"
#include "Baseclass.h"
#include "MISSILE.h"
#include "AirBus.h"
#include "Passenger.h"
#include"Boss.h"
#include "Gift.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CspacewarView
IMPLEMENT_DYNCREATE(CspacewarView, CView)

BEGIN_MESSAGE_MAP(CspacewarView, CView)
	ON_WM_CONTEXTMENU()
//	ON_WM_RBUTTONUP()
//	ON_WM_LBUTTONDOWN()
//	ON_WM_KEYDOWN()
	ON_WM_TIMER()
	ON_WM_DESTROY()
	ON_COMMAND(ID_32771, &CspacewarView::Onsetlevel)
	ON_WM_ERASEBKGND()
	ON_WM_SIZE()
	ON_WM_CREATE()
	ON_WM_KEYUP()
END_MESSAGE_MAP()
    
// CspacewarView 构造/析构
CspacewarView::CspacewarView()
: level(0)
{
	// TODO: 在此处添加构造代码
	CExplode::Loadimage();
	CPet::Loadimage();
	CPetBullet::Loadimage();
	CMISSILE::Loadimage();
	MemDC.CreateCompatibleDC(NULL);
	//这时还不能绘图，因为没有地方画
	//下面建立一个与屏幕显示兼容的位图，至于位图的大小嘛，可以用窗口的大小
}

CspacewarView::~CspacewarView()
{
}

BOOL CspacewarView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CspacewarView 绘制

void CspacewarView::OnDraw(CDC* pDC)
{
	CspacewarDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;


	/////////////////添加开始///////////////////////////
	//////////////////////
 GetClientRect(rect);
 CDC dcMem;
 dcMem.CreateCompatibleDC(pDC);
 CBitmap m_bmp;
 //if(level%2==0)
 m_bmp.LoadBitmap(IDB_BG);
// else
//m_bmp.LoadBitmap(IDB_BG2);
dcMem.SelectObject(&m_bmp); 
 MemDC.StretchBlt(0,0,rect.Width(),rect.Height(),&dcMem,0,0,512,927,SRCCOPY);
		///////////////背景绘制结束////////////////
           MemDC.SetBkMode(TRANSPARENT);
		   MemDC.SetTextAlign(TA_CENTER);
		HFONT font;
		font=CreateFont(20,10,0,0,0,0,0,0,0,0,0,100,10,0);
		MemDC.SelectObject(font);
		CString str;
		MemDC.SetTextColor(RGB(255,0,0));
		str.Format(_T("当前关卡:%d"),level+1);
		MemDC.TextOutW(70,20,str);
		str.Format(_T("当前得分:%d"),gamectrl.getscore());
		MemDC.TextOutW(70,40,str);
		str.Format(_T("剩余生命:%d"),My_plane.getlife());
		MemDC.TextOutW(70,60,str);	
		str.Format(_T("能量值:%d"),My_plane.getenegy());
		MemDC.TextOutW(70,80,str);
		str.Format(_T("“P”键暂停"));
		MemDC.TextOutW(2000,20,str);
		//==========================================================提示条绘制======================================================================================
		font=CreateFont(60,30,0,0,0,0,0,0,0,0,0,100,10,0);
		MemDC.SelectObject(font);
		switch (gamectrl.state)
		{
			case SHOW_FAIRBUS:
				{
		   CString str1 = _T("客机被劫持，请攻击机尾！");
		   
		   MemDC.SetTextColor(RGB(255, 0, 0));
		   MemDC.TextOut(1200, 400 , str1);
		   break;
				}
			case SHOW_AIRBUS:
				{
		   CString str1 = _T("客机出现！");
		   
		   MemDC.SetTextColor(RGB(255, 0, 0));
		   MemDC.TextOut(1200, 400 , str1);
		   break;
				}
			case SHOW_PASSENGER :
				{
		   CString str1 = _T("客机坠落！注意保护乘客");
		   
		   MemDC.SetTextColor(RGB(255, 0, 0));
		   MemDC.TextOut(1200, 200 , str1);
		   break;
				}
				case ARMYUPDATE :
				{
		   CString str1 = _T("武器升级！");
		   
		 MemDC.SetTextColor(RGB(255, 0, 0));
		 MemDC.TextOut(1200, 200 , str1);
		   break;
				}
				case SHOW_BOSS:
				{
		   CString str1 = _T("BOSS出现！");
		   
		   MemDC.SetTextColor(RGB(255, 0, 0));
		   MemDC.TextOut(1200, 400 , str1);
		   break;
				}
	   }
		
		//===========================================================================================================================================================
 //////////////游戏属性绘制结束///////////////////
	POSITION pos;
	
		CEnemyplane *temp;
		for( pos = plist.GetHeadPosition(); pos != NULL; )
{
	temp=(CEnemyplane *) plist.GetNext(pos);
	temp->setimage(IDB_ENEMY1,197,134);
	temp->draw(&MemDC);
}//==============================敌机1绘制结束====================================
		CEnemyplane *temp2;
		for( pos = plist2.GetHeadPosition(); pos != NULL; )
{
	temp2=(CEnemyplane *) plist2.GetNext(pos);
	temp2->setimage(IDB_UFO,205,147);
	temp2->draw(&MemDC);
}//==============================UFO绘制结束====================================
	////////敌机绘制结束///////////		
		CBoss *tbos;
		for( pos = plist_bos.GetHeadPosition(); pos != NULL; )
{
	tbos=(CBoss *) plist_bos.GetNext(pos);
	tbos->setimage(IDB_BOSS,1000,747);
	tbos->draw(&MemDC);
}
		////////////////////////BOSS绘制结束//////////////////////////////////
   CAirBus *tair;
		for( pos = plist_airbus.GetHeadPosition(); pos != NULL; )
{
	tair=(CAirBus *) plist_airbus.GetNext(pos);
	tair->draw(&MemDC);
}
	////////客机绘制结束///////////
		   
		CPassenger *tpas;
		for( pos = plist_pas.GetHeadPosition(); pos != NULL; )
{
	tpas=(CPassenger *) plist_pas.GetNext(pos);
	tpas->draw(&MemDC);
}
	////////乘客绘制结束///////////
CEnemybullet *tenebullet;
		for( pos = plist_enebullet.GetHeadPosition(); pos != NULL; )
{
	tenebullet=(CEnemybullet *) plist_enebullet.GetNext(pos);
	tenebullet->draw(&MemDC);
}
		//////////敌机子弹绘制结束//////////////
CBullet *tbullet;
		for( pos = plist_bullet.GetHeadPosition(); pos != NULL; )
{
	tbullet=(CBullet *) plist_bullet.GetNext(pos);
	tbullet->setimage(IDB_BULLET,64,64);
	tbullet->draw(&MemDC);
}
		//===================子弹1绘制结束================================
		CBullet *tbullet2;
		for( pos = plist_bullet2.GetHeadPosition(); pos != NULL; )
{
	tbullet2=(CBullet *) plist_bullet2.GetNext(pos);
	tbullet2->setimage(IDB_BULLET2,39,96);
	tbullet2->draw(&MemDC);
}
		//===================子弹2绘制结束================================
		////////////我方子弹绘制结束//////////////////		
		CExplode *texp;
		for( pos = plist_exp.GetHeadPosition();pos != NULL; )
{
	texp=(CExplode *) plist_exp.GetNext(pos);
	texp->draw(&MemDC);
}
		//////////////爆炸绘制结束//////////////////	
			
		CMISSILE *tmis;
		for( pos = plist_missile.GetHeadPosition();pos != NULL; )
{
	tmis=(CMISSILE *) plist_missile.GetNext(pos);
	tmis->draw(&MemDC);
}
        ////////////导弹绘制结束//////////////////	
		if(lion.num==1)
		{
		CPetBullet *tpetbu;
		for( pos = plist_petbu.GetHeadPosition();pos != NULL; )
{
	tpetbu=(CPetBullet *) plist_petbu.GetNext(pos);
	tpetbu->draw(&MemDC);
}
		}
      //////////宠物子弹绘制结束////////////////
		if(lion.num==1)
		lion.draw(&MemDC);
     //////////////狮鹫绘制结束//////////////////
				
		My_plane.draw(&MemDC);
//////////////我的飞机绘制结束//////////////
		CGift *tgft;
		for( pos = plist_gft.GetHeadPosition(); pos != NULL; )
{
	tgft=(CGift *) plist_gft.GetNext(pos);
	tgft->draw(&MemDC);
}
	////////补给架绘制结束///////////
	pDC->BitBlt(0,0,rect.Width(),rect.Height(),&MemDC,0,0,SRCCOPY);;//双缓冲,将缓存区图形画到屏幕	
///////////////////添加代码结束/////////////////////
	
}

//void CspacewarView::OnRButtonUp(UINT /* nFlags */, CPoint point)
//{
//	ClientToScreen(&point);
//	OnContextMenu(this, point);
//}

void CspacewarView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CspacewarView 诊断

#ifdef _DEBUG
void CspacewarView::AssertValid() const
{
	CView::AssertValid();
}

void CspacewarView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CspacewarDoc* CspacewarView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CspacewarDoc)));
	return (CspacewarDoc*)m_pDocument;
}
#endif //_DEBUG


// CspacewarView 消息处理程序


//void CspacewarView::OnLButtonDown(UINT nFlags, CPoint point)
//{
//
//	CView::OnLButtonDown(nFlags, point);
//}




void CspacewarView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if(gamectrl.is_continue==1&&nIDEvent==1)
	{
		
		POSITION pos,pos_enebullet,pos_bullet;
		CEnemyplane *temp,*temp2,*temp_;
		CEnemybullet *tenebullet;
		CMISSILE *tmis;
		CAirBus *tair;
		CBoss *tbos;
		CGift *tgft;
		for( pos = plist_bos.GetHeadPosition(); pos != NULL; )
{
	tbos=(CBoss *) plist_bos.GetNext(pos);
	tbos->automove();	
	if(tbos->getpos().x>=2000||tbos->getpos().x<=100)
		{
			tbos->turn();
			
		}		
	if(level<=20)
	{
			
		tbos->setspeed(level*2+10);
		
					
	}	
	else
	tbos->setspeed(level+30);
}
//BOSS移动

		for( pos = plist.GetHeadPosition(); pos != NULL; )
{
	temp=(CEnemyplane *) plist.GetNext(pos);
	if(level<=20)
	temp->movey(temp->getspeed()+level*2);
	else
	temp->movey(temp->getspeed()+50+level);
	
}
//敌机1移动
		for( pos = plist2.GetHeadPosition(); pos != NULL; )
{
	temp_=(CEnemyplane *) plist2.GetNext(pos);
temp_->movey(temp_->getspeed()+level*2);
if(temp_->getpos().x>=1000)
{
temp_->movex(-temp_->getspeed());
}
else if(temp_->getpos().x<=800)
{temp_->movex(temp_->getspeed());}
else
{
	temp_->movey(temp_->getspeed()+level*2);
}

	
}
//UFO移动
		for( pos = plist_airbus.GetHeadPosition(); pos != NULL; )
{
	tair=(CAirBus *) plist_airbus.GetNext(pos);
		
	if(tair->is_drop==1&&tair->is_landing==0)
	{   tair->movex(-(tair->getspeed()));
		tair->movey(tair->getspeed());
	}
	if(tair->is_drop==0&&tair->is_landing==0)
	{   
		tair->movex(-(tair->getspeed()));
	}
	if(tair->is_drop==1&&tair->is_landing==1)
	{
		tair->movey(2*tair->getspeed());
	}
	if(tair->is_drop==0&&tair->is_landing==1)
	{
		tair->movey(tair->getspeed());
	}
}
//客机移动

for( pos_enebullet = plist_enebullet.GetHeadPosition(); pos_enebullet != NULL; )
	{
		tenebullet=(CEnemybullet *) plist_enebullet.GetNext(pos_enebullet);
		if(tenebullet->type==ENORMALBU)//敌机1子弹
		tenebullet->movey(tenebullet->getspeed()*level+10);
		else if(tenebullet->type==EBOSSBU)//boss子弹
		{ 
			tenebullet->movex(sin(3.14*tenebullet->getpos().y*tenebullet->getpos().y)*tenebullet->getspeed()/8);
			tenebullet->movey(tenebullet->getspeed()*level+100);
		}
		else if(tenebullet->type==ELASER)//UFO激光
		{ 
			for( pos = plist2.GetHeadPosition(); pos != NULL; )
{
	temp_=(CEnemyplane *) plist2.GetNext(pos);
	tenebullet->setpos(temp_->getpos());
}
		}
       
	}
//敌机子弹移动

		CBullet *tbullet;
		for( pos_bullet = plist_bullet.GetHeadPosition(); pos_bullet != NULL; )
{
	tbullet=(CBullet *) plist_bullet.GetNext(pos_bullet);
	tbullet->movey(-(tbullet->getspeed()+10));
}//子弹1移动
		CBullet *tbullet2;
		for( pos_bullet = plist_bullet2.GetHeadPosition(); pos_bullet != NULL; )
{
	tbullet2=(CBullet *) plist_bullet2.GetNext(pos_bullet);
	tbullet2->setspeed(32);
	tbullet2->movey(-(tbullet2->getspeed()+1));
	tbullet2->movex(sin(3.14*(tbullet2->getspeed()+1)));
}//子弹2移动
		if(plist.GetCount()!=0)//导弹移动
		{
			temp2=(CEnemyplane *) plist.GetTail();
			
		for( pos_bullet = plist_missile.GetHeadPosition(); pos_bullet != NULL; )
{
	
	tmis=(CMISSILE *) plist_missile.GetNext(pos_bullet);
	if(tmis->getpos().y>temp2->getpos().y&&tmis->getpos().x>temp2->getpos().x)
	{
if(tmis->getpos().y>-10)
	{
		tmis->movey(-sin(tmis->getangle(temp2->getpos()))*tmis->getspeed());
	tmis->movex(-cos(tmis->getangle(temp2->getpos()))*tmis->getspeed());
	}
	else
		tmis->movey(-tmis->getspeed());//防止移除导弹时angle异常
	}
	else if(tmis->getpos().y<temp2->getpos().y&&tmis->getpos().x>temp2->getpos().x)
	{
if(tmis->getpos().y>-10)
	{
	tmis->movey(sin(tmis->getangle(temp2->getpos()))*tmis->getspeed());
	tmis->movex(-cos(tmis->getangle(temp2->getpos()))*tmis->getspeed());
	}
	else
		tmis->movey(-tmis->getspeed());
	}
	else	if(tmis->getpos().y>temp2->getpos().y&&tmis->getpos().x<temp2->getpos().x)
	{
if(tmis->getpos().y>-10)
	{
	tmis->movey(-sin(tmis->getangle(temp2->getpos()))*tmis->getspeed());
	tmis->movex(cos(tmis->getangle(temp2->getpos()))*tmis->getspeed());
	}
	else
		tmis->movey(-tmis->getspeed());
	}
	else	if(tmis->getpos().y<temp2->getpos().y&&tmis->getpos().x<temp2->getpos().x)
	{
if(tmis->getpos().y>-10)
	{
	tmis->movey(sin(tmis->getangle(temp2->getpos()))*tmis->getspeed());
	tmis->movex(cos(tmis->getangle(temp2->getpos()))*tmis->getspeed());
	}
	else
		tmis->movey(-tmis->getspeed());
	}
	
}
		}
		else
		{
for( pos_bullet = plist_missile.GetHeadPosition(); pos_bullet != NULL; )
{
	tmis=(CMISSILE *) plist_missile.GetNext(pos_bullet);
	tmis->movey(-tmis->getspeed());
}
		}
			
		CPetBullet *tpetbullet;
		for( pos_bullet = plist_petbu.GetHeadPosition(); pos_bullet != NULL; )
{
	tpetbullet=(CPetBullet *) plist_petbu.GetNext(pos_bullet);
	tpetbullet->movey(-(tpetbullet->getspeed()));
}//宠物子弹移动
			CPassenger *tpas;
		for( pos_bullet = plist_pas.GetHeadPosition(); pos_bullet != NULL; )
{
	tpas=(CPassenger *) plist_pas.GetNext(pos_bullet);
	tpas->movey(tpas->getspeed());
}//乘客移动
		this->Invalidate();
	}
	if(gamectrl.is_continue==1&&nIDEvent==2)
	{
		CEnemyplane *temp_=new CEnemyplane();//产生UFO
	temp_->setpos(rand()%2200+100,1);
	plist2.AddHead(temp_);

		for(int i=0;i<2+level/20;i++)
		{
	CEnemyplane *temp=new CEnemyplane();//产生敌机1
	temp->setpos(rand()%2200,1);
	plist.AddHead(temp);
	
		
	/////////////敌机产生完毕下面产生敌机子弹1/////////////////
	CEnemybullet * tenebullet=new CEnemybullet();
	tenebullet->setpos(temp->getpos()); 
	plist_enebullet.AddHead(tenebullet);
	/////////////////////////////////
	this->Invalidate();
		}
	}
	
	if (gamectrl.is_continue==1&&nIDEvent == 3)//敌机产生子弹2
	{
		POSITION pos;
		CEnemyplane *temp;
		CEnemyplane *temp2;
		CBoss *tbos;
for (pos = plist.GetHeadPosition(); pos != NULL;)
		{
			temp = (CEnemyplane*) plist.GetNext(pos);
			CEnemybullet * tenebullet=new CEnemybullet();
	         tenebullet->setpos(temp->getpos()); 
	           plist_enebullet.AddHead(tenebullet);
		}
for (pos = plist2.GetHeadPosition(); pos != NULL;)
		{
			temp2 = (CEnemyplane*) plist2.GetNext(pos);
			CEnemybullet * tenebullet=new CEnemybullet();
			tenebullet->type=ELASER;
	         tenebullet->setpos(temp2->getpos()); 
	           plist_enebullet.AddHead(tenebullet);
		}
for (pos = plist_bos.GetHeadPosition(); pos != NULL;)//boss产生子弹
		{
			tbos = (CBoss*) plist_bos.GetNext(pos);
			for(int i=0;i<5;i++)
			{
				CEnemybullet * tenebullet=new CEnemybullet();
				tenebullet->setpos(tbos->getpos().x+200+rand()%20*i,tbos->getpos().y+500);
			 tenebullet->type=EBOSSBU; 
	           plist_enebullet.AddHead(tenebullet);
			}
			for(int i=0;i<5;i++)
			{
				CEnemybullet * tenebullet=new CEnemybullet();
				tenebullet->setpos(tbos->getpos().x+500+rand()%20*i,tbos->getpos().y+500);
			 tenebullet->type=5; 
	           plist_enebullet.AddHead(tenebullet);
			}
			
		}
          gamectrl.state=1000;//以计时器3来更新提示条
		this->Invalidate();
	}
	if (gamectrl.is_continue==1&&nIDEvent == 4)
	{
		level+=1;
		My_plane.changeenegy(5);
		////////////过关///////////////
		if(level<=10)
		{	
			this->SetTimer(2,CEnemyplane::getpro_speed()-level*10,0);//产生敌机+发射子弹
	this->SetTimer(3,CEnemyplane::getattack_speed()-level*10,0);//敌机二次发射子弹
		}
		else//支持上万关
	    {	
			this->SetTimer(2,CEnemyplane::getpro_speed()-level/100-100,0);//产生敌机+发射子弹
	this->SetTimer(3,CEnemyplane::getattack_speed()-level/100-1000,0);//敌机二次发射子弹
		}

	//================重设与level有关的计时器==========================
		if(level%2==0&&CBoss::is_exist==0)
		{
		gamectrl.state=SHOW_BOSS;
		CBoss *tbos=new CBoss();//产生BOSS
		tbos->is_exist=1;
	tbos->setpos(500,0);
	tbos->setlife(level*10+500);
	plist_bos.AddHead(tbos);
		}



		int x=rand()%6;
			if(x==2)
			{
CAirBus *tair=new CAirBus();//概率产生客机
tair->is_forced=0;
	tair->setpos(2200,400);
	plist_airbus.AddHead(tair);
	gamectrl.state=SHOW_AIRBUS;
			}
			else if(x==3)
			{
CAirBus *tair=new CAirBus();//概率产生劫持客机
tair->is_forced=1;
	tair->setpos(2200,400);
	plist_airbus.AddHead(tair);
	gamectrl.state=SHOW_FAIRBUS;
			}
			
		
	}

	if (gamectrl.is_continue==1&&nIDEvent == 5)
	{
		if(lion.num==1)
	{
   CPetBullet * tpetbullet=new CPetBullet(); tpetbullet->setpos(lion.getpos()); plist_petbu.AddHead(tpetbullet);//宠物产生子弹 
	}
		for(int i=1;i<=3;i++)
		{
			CBullet * tbullet2=new CBullet(); tbullet2->setpos(My_plane.getpos().x-i*100,My_plane.getpos().y+i*50); plist_bullet2.AddHead(tbullet2); 
		CBullet * tbullet2_=new CBullet(); tbullet2_->setpos(My_plane.getpos().x+i*100,My_plane.getpos().y+i*50); plist_bullet2.AddHead(tbullet2_);
		}
		
	}
	
	    
	//=================================================================================================================================================================================
if (gamectrl.is_continue==1 )//多按键处理
{
	this->GetClientRect(rect);
	
	if(GetKeyState(VK_RIGHT)<0&&My_plane.getpos().x+200<rect.Width())
	{
		//My_plane.pos.x+=My_plane.speed;
		My_plane.movex(My_plane.getspeed());
	}
	if(GetKeyState(VK_LEFT)<0&&My_plane.getpos().x>0)
	{
		My_plane.movex(-My_plane.getspeed());
	}
	if(GetKeyState(VK_UP)<0&&My_plane.getpos().y>-200)
	{
		My_plane.movey(-My_plane.getspeed());
	}
	if(GetKeyState(VK_DOWN)<0&&My_plane.getpos().y+100<rect.Height())
	{
		My_plane.movey(My_plane.getspeed());
	}
	if(GetKeyState(VK_SPACE)<0)
	{
			CBullet * tbullet=new CBullet();
			tbullet->setpos(My_plane.getpos().x,My_plane.getpos().y);
			plist_bullet.AddHead(tbullet);
		
		
		
	}
	
	if(GetKeyState(VK_SHIFT)<0&&lion.num==0)//
	{
		if(My_plane.getenegy()>=5)
		{
        lion.num=1; 	
		My_plane.changeenegy(-5);
		}	
		
	}
	
	 
}
//=====================================================================================================================================================================
if (gamectrl.is_continue==1 )//敌机碰撞检测、越界检测
	{
		POSITION pos,pos_;
		CEnemyplane *temp;
		CEnemyplane *temp2;
		POSITION bu_pos;
		POSITION pos_enebullet;
		CEnemybullet *tenebullet;
		CMISSILE *tmis;
		CBullet *tbullet;
		CBullet *tbullet2;
		CPassenger * tpas;
		CPassenger * tpas1;
		CPetBullet *tpetbu;
		CBoss* tbos;
		CAirBus *tair;
		CGift *tgft;
		CObject *tob;
	
		for (pos = plist_bos.GetHeadPosition(); (pos_ = pos) != NULL;)
		{
			tbos = (CBoss*) plist_bos.GetNext(pos);
			if (tbos->getpos().y > 1200||tbos->getpos().y < -100)
			{
				tob = plist_bos.GetAt(pos_);
				plist_bos.RemoveAt(pos_);
				delete tob;
			}//BOSS出界
		}
		for (pos = plist_gft.GetHeadPosition(); (pos_ = pos) != NULL;)
		{
			tgft = (CGift*) plist_gft.GetNext(pos);
			if (tgft->getpos().y > 1500)
			{
				tob = plist_gft.GetAt(pos_);
				plist_gft.RemoveAt(pos_);
				delete tob;
			}//补给架出界
		}
		for (pos = plist.GetHeadPosition(); (pos_ = pos) != NULL;)
		{
			temp = (CEnemyplane*) plist.GetNext(pos);
			if (temp->getpos().y > 1200||temp->getpos().y< -100)
			{
				tob = plist.GetAt(pos_);
				plist.RemoveAt(pos_);
				delete tob;
			}//敌机1出界
		}
		for (pos = plist2.GetHeadPosition(); (pos_ = pos) != NULL;)
		{
			temp2 = (CEnemyplane*) plist2.GetNext(pos);
			if (temp2->getpos().y > 1200||temp2->getpos().y < -100)
			{
				tob = plist2.GetAt(pos_);
				plist2.RemoveAt(pos_);
				delete tob;
			}//UFO出界
		}
		for (pos = plist_airbus.GetHeadPosition(); (pos_ = pos) != NULL;)
		{
			tair = (CAirBus*) plist_airbus.GetNext(pos);
			if (tair->getpos().x < -1600||tair->getpos().y>1200)
			{
				tob = plist_airbus.GetAt(pos_);
				plist_airbus.RemoveAt(pos_);
				delete tob;
			}//客机出界
	    }
		CExplode *texp;
	for (pos = plist_exp.GetHeadPosition(); (pos_ = pos) != NULL;)
		{
			texp = (CExplode*) plist_exp.GetNext(pos);
			if (texp->index>6)
			{
				tob = plist_exp.GetAt(pos_);
				plist_exp.RemoveAt(pos_);
				delete tob;
			}//爆炸删除
		}
		for (bu_pos = plist_bullet.GetHeadPosition(); (pos_ = bu_pos) != NULL;)
		{
			tbullet = (CBullet*)plist_bullet.GetNext(bu_pos);
			if (tbullet->getpos().y <= -200)
			{
				tob = plist_bullet.GetAt(pos_);
				plist_bullet.RemoveAt(pos_);
				delete tob;
			}//子弹1出界
		}
		for (bu_pos = plist_bullet2.GetHeadPosition(); (pos_ = bu_pos) != NULL;)
		{
			tbullet2 = (CBullet*)plist_bullet2.GetNext(bu_pos);
			if (tbullet2->getpos().y <= -200)
			{
				tob = plist_bullet2.GetAt(pos_);
				plist_bullet2.RemoveAt(pos_);
				delete tob;
			}//子弹2出界
		}
		for (bu_pos = plist_missile.GetHeadPosition(); (pos_ = bu_pos) != NULL;)
		{
			tmis = (CMISSILE*)plist_missile.GetNext(bu_pos);
			if (tmis->getpos().y <= -200||tmis->getpos().y >1200 ){
				tob = plist_missile.GetAt(pos_);
				plist_missile.RemoveAt(pos_);
				delete tob;
			}//导弹出界
		}
		for (bu_pos = plist_petbu.GetHeadPosition(); (pos_ = bu_pos) != NULL;)
		{
			tpetbu = (CPetBullet*)plist_petbu.GetNext(bu_pos);
			if (tpetbu->getpos().y <= 0){
				tob = plist_petbu.GetAt(pos_);
				plist_petbu.RemoveAt(pos_);
				delete tob;
			}//宠物子弹出界
		}
		for (bu_pos = plist_pas.GetHeadPosition(); (pos_ = bu_pos) != NULL;)
		{
			tpas = (CPassenger*)plist_pas.GetNext(bu_pos);
			if (tpas->getpos().y >= 1200){
				tob = plist_pas.GetAt(pos_);
				plist_pas.RemoveAt(pos_);
				delete tob;
			}//乘客出界
		}
		for (pos_enebullet = plist_enebullet.GetHeadPosition(); (pos_ =pos_enebullet) != NULL;)
		{
			tenebullet = (CEnemybullet*)plist_enebullet.GetNext(pos_enebullet);
			if (tenebullet->getpos().y > 1200||tenebullet->removelaser())
			{
				tob = plist_enebullet.GetAt(pos_);
				plist_enebullet.RemoveAt(pos_);
				delete tob;
			}//敌机子弹出界
		}
		//==========================================================================================================BOSS碰撞===============================================================
		for (pos = plist_bos.GetHeadPosition(); pos != NULL;)
		{
			tbos = (CBoss*)plist_bos.GetNext(pos);
			for (bu_pos = plist_bullet.GetHeadPosition(); bu_pos != NULL;)
			{
				tbullet = (CBullet*)plist_bullet.GetNext(bu_pos);
			
				if (tbullet->getpos().x < tbos->getpos().x + 1000 && tbullet->getpos().x > tbos->getpos().x - 85 &&  tbullet->getpos().y >= tbos->getpos().y - 100 && tbullet->getpos().y <= tbos->getpos().y + 500)//敌机被击中
				{
					
					CExplode *texp=new CExplode(tbullet->getpos().x+25,tbullet->getpos().y);//我的子弹1爆炸
	                 plist_exp.AddHead(texp);					
					tbos->changelife(-1);
					if(tbos->getlife()<=0)
					{
						tbos->setpos(0,2000);
						gamectrl.changescore(200);
					}
				
					tbullet->setpos(0,-2000);
				}

			}
			for (bu_pos = plist_bullet2.GetHeadPosition(); bu_pos != NULL;)
			{
				tbullet2 = (CBullet*)plist_bullet2.GetNext(bu_pos);
			
				if (tbullet2->getpos().x < tbos->getpos().x + 1000 && tbullet2->getpos().x > tbos->getpos().x - 85 &&  tbullet2->getpos().y >= tbos->getpos().y - 100 && tbullet2->getpos().y <= tbos->getpos().y + 500)//敌机被击中
				{
					
					CExplode *texp=new CExplode(tbullet2->getpos().x+25,tbullet2->getpos().y);//我的子弹2爆炸
	                 plist_exp.AddHead(texp);					
					tbos->changelife(-1);
					if(tbos->getlife()<=0)
					{
						tbos->setpos(0,2000);
						gamectrl.changescore(200);
					}
					tbullet2->setpos(0,-2000);
				}

			}
			for (bu_pos = plist_missile.GetHeadPosition(); bu_pos != NULL;)
			{
				
			tmis = (CMISSILE*)plist_missile.GetNext(bu_pos);
				if (tmis->getpos().x < tbos->getpos().x + 1000 && tmis->getpos().x > tbos->getpos().x - 155 &&  tmis->getpos().y >= tbos->getpos().y - 100 && tmis->getpos().y <= tbos->getpos().y + 500)//敌机被击中
				{			
					CExplode *texp=new CExplode(tmis->getpos().x+25,tmis->getpos().y);//导弹爆炸
	                 plist_exp.AddHead(texp);
					 tbos->changelife(-1);
					if(tbos->getlife()<=0)
					{
						tbos->setpos(0,2000);
						gamectrl.changescore(200);
					}
					// tmis->setpos(0,-2000);
				}
			}
			for (bu_pos = plist_petbu.GetHeadPosition(); bu_pos != NULL;)
			{
				
			tpetbu = (CPetBullet*)plist_petbu.GetNext(bu_pos);
				if (tpetbu->getpos().x < tbos->getpos().x + 1000 && tpetbu->getpos().x > tbos->getpos().x - 155 &&  tpetbu->getpos().y >= tbos->getpos().y - 100 && tpetbu->getpos().y <= tbos->getpos().y + 500)//敌机被击中
				{			
					CExplode *texp=new CExplode(tpetbu->getpos().x+25,tpetbu->getpos().y);//宠物子弹爆炸
	                 plist_exp.AddHead(texp);
				
					tbos->changelife(-1);
					if(tbos->getlife()<=0)
					{
						tbos->setpos(0,2000);
						gamectrl.changescore(2000);
					}
				}
			}
			
		}
		//==========================================================================================================敌机1碰撞===============================================================
		for (pos = plist.GetHeadPosition(); pos != NULL;)
		{
			temp = (CEnemyplane*)plist.GetNext(pos);
			for (bu_pos = plist_bullet.GetHeadPosition(); bu_pos != NULL;)
			{
				tbullet = (CBullet*)plist_bullet.GetNext(bu_pos);
			
				if (tbullet->getpos().x < temp->getpos().x + 130 && tbullet->getpos().x > temp->getpos().x - 85 &&  tbullet->getpos().y >= temp->getpos().y - 100 && tbullet->getpos().y <= temp->getpos().y + 100)//敌机被击中
				{
					int x=rand()%120;
					CExplode *texp=new CExplode(tbullet->getpos().x+25,tbullet->getpos().y);//我的子弹1爆炸
	                 plist_exp.AddHead(texp);					
					gamectrl.changescore(10);
					if(temp->getskill()<x)//未躲避
					{
						if(x%20==1)
						{
CGift *tgft=new CGift();//产生gift
tgft->setpos(temp->getpos());
	plist_gft.AddHead(tgft);
						}
						if(x%20==2)
						{
CGift *tgft=new CGift();//产生gift
tgft->type=LIFEGIFT;
tgft->setpos(temp->getpos());
	plist_gft.AddHead(tgft);
						}
		
						temp->setpos(0,2000);
					}
					tbullet->setpos(0,-2000);
				}

			}
			for (bu_pos = plist_bullet2.GetHeadPosition(); bu_pos != NULL;)
			{
				tbullet2 = (CBullet*)plist_bullet2.GetNext(bu_pos);
			
				if (tbullet2->getpos().x < temp->getpos().x + 130 && tbullet2->getpos().x > temp->getpos().x - 85 &&  tbullet2->getpos().y >= temp->getpos().y - 100 && tbullet2->getpos().y <= temp->getpos().y + 100)//敌机被击中
				{
					int x=rand()%120;
					CExplode *texp=new CExplode(tbullet2->getpos().x+25,tbullet2->getpos().y);//我的子弹2爆炸
	                 plist_exp.AddHead(texp);					
					gamectrl.changescore(10);
					if(temp->getskill()<x)//未躲避
					{
						if(x%20==1)
						{
CGift *tgft=new CGift();//产生gift
tgft->setpos(temp->getpos());
	plist_gft.AddHead(tgft);
						}
						if(x%20==2)
						{
CGift *tgft=new CGift();//产生gift
tgft->type=LIFEGIFT;
tgft->setpos(temp->getpos());
	plist_gft.AddHead(tgft);
						}
						temp->setpos(0,2000);			
					}
					tbullet2->setpos(0,-2000);
				}

			}
			for (bu_pos = plist_missile.GetHeadPosition(); bu_pos != NULL;)
			{
				
			tmis = (CMISSILE*)plist_missile.GetNext(bu_pos);
				if (tmis->getpos().x < temp->getpos().x + 180 && tmis->getpos().x > temp->getpos().x - 155 &&  tmis->getpos().y >= temp->getpos().y - 100 && tmis->getpos().y <= temp->getpos().y + 70)//敌机被击中
				{			
					CExplode *texp=new CExplode(tmis->getpos().x+25,tmis->getpos().y);//导弹爆炸
	                 plist_exp.AddHead(texp);
					 temp->setpos(0,2000);
					// tmis->setpos(0,-2000);
					gamectrl.changescore(10);
				}
			}
			for (bu_pos = plist_petbu.GetHeadPosition(); bu_pos != NULL;)
			{
				
			tpetbu = (CPetBullet*)plist_petbu.GetNext(bu_pos);
				if (tpetbu->getpos().x < temp->getpos().x + 180 && tpetbu->getpos().x > temp->getpos().x - 155 &&  tpetbu->getpos().y >= temp->getpos().y - 100 && tpetbu->getpos().y <= temp->getpos().y + 70)//敌机被击中
				{			
					CExplode *texp=new CExplode(tpetbu->getpos().x+25,tpetbu->getpos().y);//宠物子弹爆炸
	                 plist_exp.AddHead(texp);
					 temp->setpos(0,2000);
					gamectrl.changescore(10);
				}
			}
			
		}
		//==========================================================================================================UFO碰撞===============================================================
		for (pos = plist2.GetHeadPosition(); pos != NULL;)
		{
			temp2 = (CEnemyplane*)plist2.GetNext(pos);
			for (bu_pos = plist_bullet.GetHeadPosition(); bu_pos != NULL;)
			{
				tbullet = (CBullet*)plist_bullet.GetNext(bu_pos);
			
				if (tbullet->getpos().x < temp2->getpos().x + 130 && tbullet->getpos().x > temp2->getpos().x - 85 &&  tbullet->getpos().y >= temp2->getpos().y - 100 && tbullet->getpos().y <= temp2->getpos().y + 100)//敌机被击中
				{
					
					CExplode *texp=new CExplode(tbullet->getpos().x+25,tbullet->getpos().y);//我的子弹1爆炸
	                 plist_exp.AddHead(texp);					
					gamectrl.changescore(10);
					temp2->setpos(0,2000);
					tbullet->setpos(0,-2000);
				}

			}
			for (bu_pos = plist_bullet2.GetHeadPosition(); bu_pos != NULL;)
			{
				tbullet2 = (CBullet*)plist_bullet2.GetNext(bu_pos);
			
				if (tbullet2->getpos().x < temp2->getpos().x + 130 && tbullet2->getpos().x > temp2->getpos().x - 85 &&  tbullet2->getpos().y >= temp2->getpos().y - 100 && tbullet2->getpos().y <= temp2->getpos().y + 100)//敌机被击中
				{
					
					CExplode *texp=new CExplode(tbullet2->getpos().x+25,tbullet2->getpos().y);//我的子弹2爆炸
	                 plist_exp.AddHead(texp);					
					gamectrl.changescore(10);
					temp2->setpos(0,2000);
					tbullet2->setpos(0,-2000);
				}

			}
			for (bu_pos = plist_missile.GetHeadPosition(); bu_pos != NULL;)
			{
				
			tmis = (CMISSILE*)plist_missile.GetNext(bu_pos);
				if (tmis->getpos().x < temp2->getpos().x + 180 && tmis->getpos().x > temp2->getpos().x - 155 &&  tmis->getpos().y >= temp2->getpos().y - 100 && tmis->getpos().y <= temp2->getpos().y + 70)//敌机被击中
				{			
					CExplode *texp=new CExplode(tmis->getpos().x+25,tmis->getpos().y);//导弹爆炸
	                 plist_exp.AddHead(texp);
					 temp2->setpos(0,2000);
					// tmis->setpos(0,-2000);
					gamectrl.changescore(10);
				}
			}
			for (bu_pos = plist_petbu.GetHeadPosition(); bu_pos != NULL;)
			{
				
			tpetbu = (CPetBullet*)plist_petbu.GetNext(bu_pos);
				if (tpetbu->getpos().x < temp2->getpos().x + 180 && tpetbu->getpos().x > temp2->getpos().x - 155 &&  tpetbu->getpos().y >= temp2->getpos().y - 100 && tpetbu->getpos().y <= temp2->getpos().y + 70)//敌机被击中
				{			
					CExplode *texp=new CExplode(tpetbu->getpos().x+25,tpetbu->getpos().y);//宠物子弹爆炸
	                 plist_exp.AddHead(texp);
					 temp2->setpos(0,2000);
					gamectrl.changescore(10);
				}
			}
			
		}
		//================================================================客机碰撞===============================================================================================
		for (pos = plist_airbus.GetHeadPosition(); pos != NULL;)
		{
			tair = (CAirBus*)plist_airbus.GetNext(pos);
			for (bu_pos = plist_bullet.GetHeadPosition(); bu_pos != NULL;)
			{
				tbullet = (CBullet*)plist_bullet.GetNext(bu_pos);
			
				if (tbullet->getpos().x < tair->getpos().x + 350 && tbullet->getpos().x > tair->getpos().x &&  tbullet->getpos().y >= tair->getpos().y - 100 && tbullet->getpos().y <= tair->getpos().y + 300)//敌机被击中
				{
					
					CExplode *texp=new CExplode(tbullet->getpos().x+25,tbullet->getpos().y);//我的子弹1爆炸
	                 plist_exp.AddHead(texp);					
					
					int x=rand()%10;
					if(x==9)
					{
						for(int i=0;i<tair->pasnum;i++)//------------------------------------!!!!!!!
						{
							
							CPassenger *tpas=new CPassenger();//产生乘客
						
							tpas->setpos(tair->getpos().x+10*(rand()%10),tair->getpos().y+10*(rand()%10));
	                       plist_pas.AddHead(tpas);
						   gamectrl.changescore(-20);
						}
						gamectrl.state=SHOW_PASSENGER;
						tair->setpos(-2000,0);
					}
					
					tbullet->setpos(0,-2000);
				}//头
				if (tbullet->getpos().x < tair->getpos().x + 1000 && tbullet->getpos().x > tair->getpos().x+350 &&  tbullet->getpos().y >= tair->getpos().y - 100 && tbullet->getpos().y <= tair->getpos().y + 300)//敌机被击中
				{
					
					CExplode *texp=new CExplode(tbullet->getpos().x+25,tbullet->getpos().y);//我的子弹1爆炸
	                 plist_exp.AddHead(texp);
					 if(tair->is_drop==0)
					gamectrl.changescore(-20);//防止多次扣分
					tair->is_drop=1;
					tbullet->setpos(0,-2000);
				}//机翅
				if (tbullet->getpos().x < tair->getpos().x + 1200 && tbullet->getpos().x > tair->getpos().x+1000 &&  tbullet->getpos().y >= tair->getpos().y - 100 && tbullet->getpos().y <= tair->getpos().y + 300)//敌机被击中
				{
					
					CExplode *texp=new CExplode(tbullet->getpos().x+25,tbullet->getpos().y);//我的子弹1爆炸
	                 plist_exp.AddHead(texp);
					 if(tair->is_forced==0)
					gamectrl.changescore(-20-tair->pasnum*2);//乘客全部遇难
					 else if(tair->is_forced==1)
					 {
						 if(tair->is_landing==0)//未迫降
							 gamectrl.changescore(-20-tair->pasnum*2);//乘客全部遇难
						 else
							  gamectrl.changescore(-10-tair->pasnum);//乘客全部遇难但扣分减半
					 }
					tair->setpos(-2000,0);
					tbullet->setpos(0,-2000);
				}//油箱
				if (tbullet->getpos().x < tair->getpos().x + 1500 && tbullet->getpos().x > tair->getpos().x+1200 &&  tbullet->getpos().y >= tair->getpos().y - 100 && tbullet->getpos().y <= tair->getpos().y + 300)//敌机被击中
				{
					
					CExplode *texp=new CExplode(tbullet->getpos().x+25,tbullet->getpos().y);//我的子弹1爆炸
	                 plist_exp.AddHead(texp); 
					 if(tair->is_landing==0)
					gamectrl.changescore(-20);//防止多次扣分
					 tair->is_landing=1;		
					tbullet->setpos(0,-2000);
					if(tair->is_forced==1)
					{
						gamectrl.changescore(50+tair->pasnum*2);
					}

				}//尾部

			}
		}
		//=============================================================乘客碰撞==========================================================================

		for (pos = plist_pas.GetHeadPosition(); pos != NULL;)
		{
			tpas1 = (CPassenger*)plist_pas.GetNext(pos);
			for (bu_pos = plist_bullet.GetHeadPosition(); bu_pos != NULL;)
			{
				tbullet = (CBullet*)plist_bullet.GetNext(bu_pos);
			
				if (tbullet->getpos().x < tpas1->getpos().x + 130 && tbullet->getpos().x > tpas1->getpos().x - 85 &&  tbullet->getpos().y >= tpas1->getpos().y - 100 && tbullet->getpos().y <= tpas1->getpos().y + 100)//敌机被击中
				{
					
					CExplode *texp=new CExplode(tbullet->getpos().x+25,tbullet->getpos().y);//我的子弹1爆炸
	                 plist_exp.AddHead(texp);					
					gamectrl.changescore(-2);
					tpas1->setpos(0,2001);
					tbullet->setpos(0,-2000);
				}

			}
		}
		this->Invalidate();
	}

lion.setpos(My_plane.getpos().x+330,My_plane.getpos().y+130);
//=============================================================================================================================================================


//================================================我方飞机碰撞=============================================================================================================
if (gamectrl.is_continue==1 )//
{
	POSITION pos_enebullet;
	CEnemybullet *tenebullet;

	for (pos_enebullet = plist_enebullet.GetHeadPosition(); pos_enebullet != NULL;)//被子弹击中
			{
				tenebullet = (CEnemybullet*)plist_bullet.GetNext(pos_enebullet);
				if(tenebullet->type==EBOSSBU||tenebullet->type==ENORMALBU)//子弹1
				{
if (tenebullet->getpos().x < My_plane.getpos().x + 130 && tenebullet->getpos().x >  My_plane.getpos().x - 85 &&  tenebullet->getpos().y >=  My_plane.getpos().y - 100 && tenebullet->getpos().y <=  My_plane.getpos().y + 100)//碰撞坐标检测
				{
					CExplode *texp=new CExplode(My_plane.getpos().x+35,My_plane.getpos().y-35);//爆炸
	                 plist_exp.AddHead(texp);
					 My_plane.changelife(-1);
					tenebullet->setpos(0,2000);
				}
				}
				else if(tenebullet->type==ELASER)//激光
				{
				if (tenebullet->getpos().x < My_plane.getpos().x + 130 && tenebullet->getpos().x >  My_plane.getpos().x - 85 )//不必判断Y
				{
					CExplode *texp=new CExplode(My_plane.getpos().x+35,My_plane.getpos().y-35);//爆炸
	                 plist_exp.AddHead(texp);
					 My_plane.changelife(-10);
					//tenebullet->setpos(0,2000);
				}
				}
				
			}
	POSITION pos_eneplane;
	CEnemyplane *temp,*temp2;
	for (pos_eneplane = plist.GetHeadPosition(); pos_eneplane != NULL;)//被敌机1击中
			{
				temp = (CEnemyplane*)plist.GetNext(pos_eneplane);
				if (temp->getpos().x < My_plane.getpos().x + 130 && temp->getpos().x >  My_plane.getpos().x - 85 &&  temp->getpos().y >=  My_plane.getpos().y - 100 && temp->getpos().y <=  My_plane.getpos().y + 100)//碰撞坐标检测
				{
					
					CExplode *texp=new CExplode(My_plane.getpos().x-35,My_plane.getpos().y-35);
	                 plist_exp.AddHead(texp);
					 My_plane.changelife(-2);
					temp->setpos(0,2000);
				}
			}
	for (pos_eneplane = plist2.GetHeadPosition(); pos_eneplane != NULL;)//被UFO击中
			{
				temp2 = (CEnemyplane*)plist2.GetNext(pos_eneplane);
				if (temp2->getpos().x < My_plane.getpos().x + 130 && temp2->getpos().x >  My_plane.getpos().x - 85 &&  temp2->getpos().y >=  My_plane.getpos().y - 100 && temp2->getpos().y <=  My_plane.getpos().y + 100)//碰撞坐标检测
				{
					
					CExplode *texp=new CExplode(My_plane.getpos().x-35,My_plane.getpos().y-35);
	                 plist_exp.AddHead(texp);
					 My_plane.changelife(-2);
					temp2->setpos(0,2000);
				}
			}
		CGift* tgft;
	for (pos_eneplane = plist_gft.GetHeadPosition(); pos_eneplane != NULL;)//补给架get
			{
				tgft = (CGift*)plist_gft.GetNext(pos_eneplane);
				if (tgft->getpos().x < My_plane.getpos().x + 130 && tgft->getpos().x >  My_plane.getpos().x - 85 &&  tgft->getpos().y >=  My_plane.getpos().y - 100 && tgft->getpos().y <=  My_plane.getpos().y + 100)//碰撞坐标检测
				{
					tgft->effect(My_plane);
					tgft->setpos(0,2000);
				}
			}

}
//======================================================================================================================================================
if(My_plane.getlife()<=0)
{
	this->KillTimer(1);
	this->KillTimer(2);
	this->KillTimer(3);
	this->KillTimer(4);
	this->KillTimer(5);
	lion.num=0;
	if(AfxMessageBox(L"GAME OVER !是否重新开始？",MB_YESNO)==6)
		{
	this->SetTimer(1,50,0);
	this->SetTimer(2,CEnemyplane::getpro_speed()-level*10,0);//产生敌机+发射子弹
	this->SetTimer(3,CEnemyplane::getattack_speed()-level*10,0);//敌机二次发射子弹
	this->SetTimer(4,20001,0);//关卡
	this->SetTimer(5,lion.getattack_speed(),0);//宠物发射子弹
				plist.RemoveAll();
				plist2.RemoveAll();
				plist_gft.RemoveAll();
				plist_petbu.RemoveAll();
				plist_bos.RemoveAll();
				plist_bullet.RemoveAll();
				plist_bullet2.RemoveAll();
				plist_enebullet.RemoveAll();
				plist_pas.RemoveAll();
				plist_airbus.RemoveAll();
				My_plane.setlife(10);
				My_plane.setenegy(10);
				level=0;
				gamectrl.is_continue=1;
				gamectrl.setscore(0);
				gamectrl.state=1000;
			
		}
		else
			exit(1);
}
	

		
}


void CspacewarView::OnInitialUpdate()
{
	CView::OnInitialUpdate();
	this->SetTimer(1,50,0);
	this->SetTimer(2,CEnemyplane::getpro_speed(),0);//产生敌机+发射子弹
	this->SetTimer(3,CEnemyplane::getattack_speed(),0);//敌机二次发射子弹
	this->SetTimer(4,20001,0);//关卡
	this->SetTimer(5,lion.getattack_speed(),0);//宠物发射子弹
	// TODO: 在此添加专用代码和/或调用基类
}


void CspacewarView::OnDestroy()
{
	CView::OnDestroy();
	this->KillTimer(1);
	this->KillTimer(2);
	this->KillTimer(3);
	this->KillTimer(4);
	this->KillTimer(5);
	POSITION pos;
	CEnemyplane *temp;
	for( pos = plist.GetHeadPosition(); pos != NULL; )
{
	temp=(CEnemyplane *) plist.GetNext(pos);
	delete temp;
}//清除所有敌机1
	CEnemyplane *temp2;
	for( pos = plist2.GetHeadPosition(); pos != NULL; )
{
	temp2=(CEnemyplane *) plist2.GetNext(pos);
	delete temp2;
}//清除所有UFO
	CBullet *tbullet;
	for( pos = plist_bullet.GetHeadPosition(); pos != NULL; )
{
	tbullet=(CBullet *) plist_bullet.GetNext(pos);
	delete tbullet;
}//清除我方子弹
	for( pos = plist_bullet2.GetHeadPosition(); pos != NULL; )
{
	tbullet=(CBullet *) plist_bullet2.GetNext(pos);
	delete tbullet;
}//清除我方子弹2
	CBullet *tenebullet;
	for( pos = plist_enebullet.GetHeadPosition(); pos != NULL; )
{
	tenebullet=(CEnemybullet *) plist_enebullet.GetNext(pos);
	delete tenebullet;
}//清除敌方子弹
	CExplode *texp;
	for( pos = plist_exp.GetHeadPosition(); pos != NULL; )
{
	texp=(CExplode *) plist_exp.GetNext(pos);
	delete texp;
}//清除爆炸
	// TODO: 在此处添加消息处理程序代码
}


void CspacewarView::Onsetlevel()
{
	Sethardlevel setld;
	setld.level=level;
	if(setld.DoModal()==IDOK)
	{
		level=setld.level-1;
		if(level<=10)
		{	
			this->SetTimer(2,CEnemyplane::getpro_speed()-level*10,0);//产生敌机+发射子弹
	this->SetTimer(3,CEnemyplane::getattack_speed()-level*10,0);//敌机二次发射子弹
		}
		else//支持上万关
	    {	
			this->SetTimer(2,CEnemyplane::getpro_speed()-level/100-100,0);//产生敌机+发射子弹
	this->SetTimer(3,CEnemyplane::getattack_speed()-level/100-1000,0);//敌机二次发射子弹
		}
		
	}

	// TODO: 在此添加命令处理程序代码
}


BOOL CspacewarView::OnEraseBkgnd(CDC* pDC)
{
	MemDC.FillSolidRect(0,0,rect.Width(),rect.Height(),RGB(255,255,255));
	return FALSE;
}



void CspacewarView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);
    CDC* pDC=this->GetWindowDC();	
	this->GetClientRect(&rect);
	My_plane.setspeed(32);
	My_plane.setpos(rect.Width()/2,rect.Height()/2);//初始化主角位置
	if(MemBitmap.m_hObject!=NULL)
	{
		MemBitmap.DeleteObject();
	}
	MemBitmap.CreateCompatibleBitmap(pDC,rect.Width(),rect.Height());

	//将位图选入到内存显示设备中
	//只有选入了位图的内存显示设备才有地方绘图，画到指定的位图上
	CBitmap *pOldBit=MemDC.SelectObject(&MemBitmap);
	// TODO: 在此处添加消息处理程序代码
}


int CspacewarView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO:  在此添加您专用的创建代码

	return 0;
}


void CspacewarView::UpDateWin(CDC* pDC)
{
	
}


void CspacewarView::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
		///////////////////////开始添加开关////////////////
	switch(nChar)
	{
	case 'P':
if(gamectrl.is_continue==0)
{
	gamectrl.is_continue=1;
}
else if(gamectrl.is_continue==1)
{
	gamectrl.is_continue=0;
}
break;
	case'L':
		if(My_plane.getenegy()>=1)
	{
		CMISSILE * tmis=new CMISSILE(); tmis->setpos(My_plane.getpos().x,My_plane.getpos().y);plist_missile.AddHead(tmis); 
		tmis->setspeed(level*2+tmis->getspeed());
		My_plane.changeenegy(-1);
	}
break;
	case'R':	
		if(My_plane.is_invincible==0)
		{
			My_plane.is_invincible=1;
		}
		else if(My_plane.is_invincible==1)
		{
			My_plane.is_invincible=0;
		}
break;
		case'K':	
			My_plane.is_protected=1;
			My_plane.changeenegy(-5);
break;

	}
/////////////////////////////////////////////////////
	CView::OnKeyUp(nChar, nRepCnt, nFlags);
}
