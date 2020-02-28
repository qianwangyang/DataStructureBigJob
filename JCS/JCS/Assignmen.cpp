#include "stdafx.h"
#include "Assignmen.h"
Assignmen::Assignmen(CString No,
	CString course,
	CString contet,
	int time,
	CString startTime,
	CString overTime,
	CString remark)
{
	this->No = No;
	this->contet = contet;
	this->time = time;
	this->startTime = startTime;
	this->overTime = overTime;
	this->remark = remark;
}
Assignmen::Assignmen();

CString Assignmen::getNo()
{
	return No;
}
CString Assignmen::getCourse()
{
	return course;
}
int Assignmen::getTime()
{
	return time;
}
CString Assignmen::getStartTime()
{
	return startTime;
}
CString Assignmen::getOverTime()
{
	return overTime;
}
CString Assignmen::getRemark()
{
	return remark;
}
CString Assignmen::getContet()
{
	return contet;
}
Assignmen* Assignmen::getNext()
{
	return next;
}

void Assignmen::setContet(CString contet)
{
	this->contet = contet;
}
void Assignmen::setNo(CString No)
{
	this->No = No;
}
void Assignmen::setCourse(CString course)
{
	this->course = course;
}
void Assignmen::setTime(int time)
{
	this->time = time;
}
void Assignmen::setStartTime(CString startTime)
{
	this->startTime = startTime;
}
void Assignmen::setOverTime(CString overTime)
{
	this->overTime = overTime;
}
void Assignmen::setRemark(CString remark)
{
	this->remark = remark;
}
void Assignmen::setNext(Assignmen *next)
{
	this->next = next;
}

