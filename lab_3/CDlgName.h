#pragma once
#include "afxdialogex.h"


// CDlgName 对话框

class CDlgName : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgName)

public:
	CDlgName(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDlgName();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EDIT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_name;
};
