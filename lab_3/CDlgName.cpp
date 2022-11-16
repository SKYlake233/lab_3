// CDlgName.cpp: 实现文件
//

#include "pch.h"
#include "lab_3.h"
#include "afxdialogex.h"
#include "CDlgName.h"


// CDlgName 对话框

IMPLEMENT_DYNAMIC(CDlgName, CDialogEx)

CDlgName::CDlgName(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_EDIT, pParent)
	, m_name(_T(""))
{

}

CDlgName::~CDlgName()
{
}

void CDlgName::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, ID_EDIT_NAME, m_name);
}


BEGIN_MESSAGE_MAP(CDlgName, CDialogEx)
END_MESSAGE_MAP()


// CDlgName 消息处理程序
