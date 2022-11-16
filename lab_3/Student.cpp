#include "pch.h"
#include "Student.h"

IMPLEMENT_SERIAL(Student,CObject,1);
Student::Student() {

}

Student::~Student() {

}

CString Student::get_name() {
	return name;
}
void Student::set_name(CString iname) {
	this->name = iname;
}
CString Student::get_cls() {
	return cls;
}
void Student::set_cls(CString icls) {
	this->cls = icls;
}
int Student::get_age() {
	return this->age;
}
void Student::set_age(int iage) {
	this->age = iage;
}

void Student::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{	// storing code
		ar << name << cls << age;
	}
	else
	{	// loading code
		ar >> name >> cls >> age;
	}
}


void Student::showStu(CDC* pDC, int x, int y)
{
	// TODO: 在此处添加实现代码.
	CString sAge;
	sAge.Format(L"%d", age);
	CString sOut = name + "   " + sAge + "    " + cls;
	pDC->TextOut(x, y, sOut);
} 
