#pragma once
#include "afxdialogex.h"


// CStuDlg 对话框

class CStuDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CStuDlg)

public:
	CStuDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CStuDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_STU };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_cls;
	int m_age;
	CString m_name;
};
