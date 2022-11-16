
// lab_3View.cpp: Clab3View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "lab_3.h"
#endif

#include "lab_3Doc.h"
#include "lab_3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Clab3View

IMPLEMENT_DYNCREATE(Clab3View, CView)

BEGIN_MESSAGE_MAP(Clab3View, CView)
	ON_COMMAND(ID_ADD, &Clab3View::OnAdd)
	ON_COMMAND(ID_DEL, &Clab3View::OnDel)
	ON_COMMAND(ID_UPD, &Clab3View::OnUpd)
END_MESSAGE_MAP()

// Clab3View 构造/析构

Clab3View::Clab3View() noexcept
{
	// TODO: 在此处添加构造代码

}

Clab3View::~Clab3View()
{
}

BOOL Clab3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Clab3View 绘图

void Clab3View::OnDraw(CDC* pDC)
{
	Clab3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pDoc->showStu(pDC, 10, 10);
}


// Clab3View 诊断

#ifdef _DEBUG
void Clab3View::AssertValid() const
{
	CView::AssertValid();
}

void Clab3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Clab3Doc* Clab3View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Clab3Doc)));
	return (Clab3Doc*)m_pDocument;
}
#endif //_DEBUG


// Clab3View 消息处理程序


void Clab3View::OnAdd()
{
	// TODO: 在此添加命令处理程序代码
	CStuDlg Dlg;
	int ret = Dlg.DoModal();
	if (ret == IDOK) {
		Student* stud = new Student();
		stud->set_name(Dlg.m_name);
		stud->set_cls(Dlg.m_cls);
		stud->set_age(Dlg.m_age);
		Clab3Doc* pDoc = GetDocument();
		pDoc->addStudent(stud);
		Invalidate();
	}
	else {

	}
}


void Clab3View::OnDel()
{
	// TODO: 在此添加命令处理程序代码
	CDlgName cDlg;
	int ret = cDlg.DoModal();
	if (ret == IDOK) {
		CString name = cDlg.m_name;
		Clab3Doc* pDoc = GetDocument();
		pDoc->delStudent(name);
		Invalidate();
	}
	else {

	}

	//// TODO: 在此添加命令处理程序代码
	//CDlgName cDlg;
	//int ret = cDlg.DoModal();
	//if (ret == IDOK) {
	//	CString name = cDlg.m_name;
	//	Clab3Doc* pDoc = GetDocument();
	//	Student* stu = pDoc->findStu(name);
	//	if (stu != NULL) {
	//		CStuDlg cdlg_stu;
	//		cdlg_stu.m_name = stu->get_name();
	//		cdlg_stu.m_cls = stu->get_cls();
	//		cdlg_stu.m_age = stu->get_age();
	//		ret = cdlg_stu.DoModal();
	//		if (ret == IDOK) {
	//			stu->set_name(cdlg_stu.m_name);
	//			stu->set_cls(cdlg_stu.m_cls);
	//			stu->set_age(cdlg_stu.m_age);
	//		}
	//		Invalidate();
	//	}
	//}
	//else {

	//}
}


void Clab3View::OnUpd()
{
	
	// TODO: 在此添加命令处理程序代码
	CDlgName cDlg;
	int ret = cDlg.DoModal();
	if (ret == IDOK) {
		CString name = cDlg.m_name;
		Clab3Doc* pDoc = GetDocument();
		Student* stu = pDoc->findStu(name);
		if (stu != NULL) {
			CStuDlg cdlg_stu;
			cdlg_stu.m_name = stu->get_name();
			cdlg_stu.m_cls = stu->get_cls();
			cdlg_stu.m_age = stu->get_age();
			ret = cdlg_stu.DoModal();
			if (ret == IDOK) {
				stu->set_name(cdlg_stu.m_name);
				stu->set_cls(cdlg_stu.m_cls);
				stu->set_age(cdlg_stu.m_age);
			}
			Invalidate();
		}
	}
	else {

	}
}
