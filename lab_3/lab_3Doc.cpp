﻿
// lab_3Doc.cpp: Clab3Doc 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "lab_3.h"
#endif

#include "lab_3Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// Clab3Doc

IMPLEMENT_DYNCREATE(Clab3Doc, CDocument)

BEGIN_MESSAGE_MAP(Clab3Doc, CDocument)
END_MESSAGE_MAP()


// Clab3Doc 构造/析构

Clab3Doc::Clab3Doc() noexcept
{
	// TODO: 在此添加一次性构造代码

}

Clab3Doc::~Clab3Doc()
{
}

BOOL Clab3Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// Clab3Doc 序列化

void Clab3Doc::Serialize(CArchive& ar)
{
	stuObjs.Serialize(ar);
}

#ifdef SHARED_HANDLERS

// 缩略图的支持
void Clab3Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 修改此代码以绘制文档数据
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 搜索处理程序的支持
void Clab3Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 例如:     strSearchContent = _T("point;rectangle;circle;ole object;")；
	SetSearchContent(strSearchContent);
}

void Clab3Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// Clab3Doc 诊断

#ifdef _DEBUG
void Clab3Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void Clab3Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// Clab3Doc 命令


void Clab3Doc::addStudent(Student *stu)
{
	// TODO: 在此处添加实现代码.
	stuObjs.Add(stu);
	SetModifiedFlag();
}

void Clab3Doc::updateStudent(Student* stu)
{
	for (int i = 0; i < stuObjs.GetCount(); i++)
	{
		Student* st = (Student*)stuObjs.GetAt(i);
		if (st->get_name() == stu->get_name()) {
			st->set_name(st->get_name());
			st->set_cls(st->get_cls());
			st->set_age(st->get_age());
			SetModifiedFlag();
			break;
;		}
	}
	SetModifiedFlag();

}

void Clab3Doc::delStudent(CString name)
{
	for (int i = 0; i < stuObjs.GetCount(); i++)
	{
		Student* st = (Student*)stuObjs.GetAt(i);
		if (st->get_name() == name) {
			stuObjs.RemoveAt(i);
			delete(st);
			SetModifiedFlag();
			return;
		}
	}
	SetModifiedFlag();

}




void Clab3Doc::showStu(CDC* pDC , int x , int y)
{
	// TODO: 在此处添加实现代码.
	for (int i = 0; i < stuObjs.GetCount() ; i++)
	{
		Student* st = (Student*)stuObjs.GetAt(i);
		st->showStu(pDC , x , y);
		y += 10;
	}
}

Student* Clab3Doc::findStu(CString name) {
	for (int i = 0; i < stuObjs.GetCount(); i++)
	{
		Student* st = (Student*)stuObjs.GetAt(i);
		if (st->get_name() == name) {
			return st;
		}
	}
	return NULL;
}