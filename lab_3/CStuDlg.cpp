// CStuDlg.cpp: 实现文件
//

#include "pch.h"
#include "lab_3.h"
#include "afxdialogex.h"
#include "CStuDlg.h"


// CStuDlg 对话框

IMPLEMENT_DYNAMIC(CStuDlg, CDialogEx)

CStuDlg::CStuDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_STU, pParent)
	, m_cls(_T(""))
	, m_age(0)
	, m_name(_T(""))
{

}

CStuDlg::~CStuDlg()
{
}

void CStuDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_CBString(pDX, IDC_COMBO_CLS, m_cls);
	DDX_Text(pDX, IDC_EDIT_AGE, m_age);
	DDX_Text(pDX, IDC_EDIT_NAME, m_name);
}


BEGIN_MESSAGE_MAP(CStuDlg, CDialogEx)
END_MESSAGE_MAP()


// CStuDlg 消息处理程序
