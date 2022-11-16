
// lab_3View.h: Clab3View 类的接口
//

#pragma once
#include"Student.h"
#include"CStuDlg.h"
#include"CDlgName.h"


class Clab3View : public CView
{
protected: // 仅从序列化创建
	Clab3View() noexcept;
	DECLARE_DYNCREATE(Clab3View)

// 特性
public:
	Clab3Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~Clab3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnAdd();
	afx_msg void OnDel();
	afx_msg void OnUpd();
};

#ifndef _DEBUG  // lab_3View.cpp 中的调试版本
inline Clab3Doc* Clab3View::GetDocument() const
   { return reinterpret_cast<Clab3Doc*>(m_pDocument); }
#endif

