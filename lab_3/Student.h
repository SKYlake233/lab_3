#pragma once
class Student:public CObject
{
	DECLARE_SERIAL(Student)
private:
	CString name;
	CString cls;
	int age;

public:
	Student();
	~Student();

	CString get_name();
	void set_name(CString iname);
	CString get_cls();
	void set_cls(CString icls);
	int get_age();
	void set_age(int iage);
	virtual void Serialize(CArchive& ar);
	void showStu(CDC* pDC, int x, int y);
};

