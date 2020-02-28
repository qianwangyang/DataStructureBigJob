#include "stdafx.h"
#include "homework.h"

Homework::Homework(CString className,
	CString num,
	CString No,
	CString time,
	CString remark)
{
	this->className = className;
	this->num = num;
	this->No = No;
	this->time = time;
	this->remark = remark;
}

CString Homework::getClassName()
{
	return className;
}
CString Homework::getNum()
{
	return num;
}
CString Homework::getTime()
{
	return time;
}
CString Homework::getNo()
{
	return No;
}
CString Homework::getRemark()
{
	return remark;
}
CString Homework::getCourse()
{
	return course;
}


void Homework::setCourse(CString course)
{
	this->course = course;
}
void Homework::setClassName(CString className)
{
	this->className = className;
}
void Homework::setNum(CString num)
{
	this->num = num;
}
void Homework::setNo(CString No)
{
	this->No = No;
}
void Homework::setTime(CString time)
{
	this->time = time;
}
void Homework::setRemark(CString remark)
{
	this->remark = remark;
}