#include "stdafx.h"
#include "Assignmen.h"
#include "afxdialogex.h"
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
Assignmen::Assignmen()
{
	//assignmen = NULL;
}

Assignmen *Assignmen::assignmen = NULL;

int Assignmen::writeAssignmen(Assignmen *assignmen)//有头节点
{
	FILE *fp;
	if ((fp = fopen("Assignmen", "wb")) == NULL)
	{
		return 1;
	}
	while (assignmen->getNext() != NULL)
	{
		assignmen = assignmen->getNext();
		if (fwrite(assignmen, sizeof(Assignmen), 1, fp) != 1)
		{
			return 2;
		}
	}
	fclose(fp);
	return 0;
}

int Assignmen::readAssignmen(Assignmen *assignmen)//带头指针
{
	FILE *fp;
	//Assignmen *head = assignmen;
	if ((fp = fopen("Assignmen", "rb")) == NULL)
	{
		return 1;
	}
	while (!feof(fp))
	{
		Assignmen *next = new Assignmen();
		assignmen->setNext(next);
		assignmen = next;
		fread(assignmen, sizeof(Assignmen), 1, fp);

	}
	assignmen->setNext(NULL);
	//assignmen = head;
	rewind(fp);
	fclose(fp);
	return 0;
}


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

