#pragma once
#include "resource.h"

// Sethardlevel 对话框

class Sethardlevel : public CDialog
{
	DECLARE_DYNAMIC(Sethardlevel)

public:
	Sethardlevel(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Sethardlevel();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int level;
};
