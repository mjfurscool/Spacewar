// Sethardlevel.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "spacewar.h"
#include "Sethardlevel.h"
#include "afxdialogex.h"


// Sethardlevel �Ի���

IMPLEMENT_DYNAMIC(Sethardlevel, CDialog)

Sethardlevel::Sethardlevel(CWnd* pParent /*=NULL*/)
	: CDialog(Sethardlevel::IDD, pParent)
{

	level = 0;
}

Sethardlevel::~Sethardlevel()
{
}

void Sethardlevel::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, level);
	DDV_MinMaxInt(pDX, level, 1, 100);
}


BEGIN_MESSAGE_MAP(Sethardlevel, CDialog)
END_MESSAGE_MAP()


// Sethardlevel ��Ϣ�������
