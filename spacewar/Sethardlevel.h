#pragma once
#include "resource.h"

// Sethardlevel �Ի���

class Sethardlevel : public CDialog
{
	DECLARE_DYNAMIC(Sethardlevel)

public:
	Sethardlevel(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Sethardlevel();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	int level;
};
