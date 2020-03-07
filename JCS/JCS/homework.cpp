#include "stdafx.h"
#include "homework.h"
#include "person.h"
#include "afxdialogex.h"

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
Homework::Homework()
{
	next = NULL;
}
Homework *Homework::homework = NULL;
//读写文件
int Homework::writeHomework(Homework *homework)//有头节点
{
	FILE *fp;
	if ((fp = fopen("homework", "wb")) == NULL)
	{
		return 1;
	}
	while (homework->getNext() != NULL)
	{
		homework = homework->getNext();
		if (fwrite(homework, sizeof(Homework), 1, fp) != 1)
		{
			return 2;
		}
	}
	fclose(fp);
	return 0;
}

int Homework::readHomework(Homework *homework)//带头指针
{
	FILE *fp;
	//Homework *head = homework;
	if ((fp = fopen("homework", "rb")) == NULL)
	{
		return 1;
	}
	while (!feof(fp))
	{
		Homework *next = new Homework();
		homework->setNext(next);
		homework = next;
		fread(homework, sizeof(Homework), 1, fp);

	}
	homework->setNext(NULL);
	//homework = head;
	rewind(fp);
	fclose(fp);
	return 0;
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
Homework* Homework::getNext()
{
	return next;
}

void Homework::setNext(Homework *next)
{
	this->next = next;
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