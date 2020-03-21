  #include "stdafx.h"
#include "Assignmen.h"
#include "afxdialogex.h"
Assignmen::Assignmen(CString No,CString course,CString contet,CString time,CString startTime,CString overTime,CString remark)
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
	next = NULL;
}

Assignmen *Assignmen::assignmen = NULL;

int Assignmen::writeAssignmen(Assignmen *assignmen)//有头节点
{
	FILE *fp;
	if ((fp = fopen("Assignmen", "w")) == NULL)
	{
		return 1;
	}
	CString cstr("@");
	while (assignmen != NULL)
	{
		fprintf(fp, assignmen->No);
		fprintf(fp, cstr);
		fprintf(fp, assignmen->course);
		fprintf(fp, cstr);
		fprintf(fp, assignmen->contet);
		fprintf(fp, cstr);
		fprintf(fp, assignmen->time);
		fprintf(fp, cstr);
		fprintf(fp, assignmen->startTime);
		fprintf(fp, cstr);
		fprintf(fp, assignmen->overTime);
		fprintf(fp, cstr);
		fprintf(fp, assignmen->remark);
		fprintf(fp, cstr);
		fprintf(fp, assignmen->className);
		assignmen = assignmen->next;
		if (assignmen == NULL)
		{
			break;
		}
		fprintf(fp, cstr);
	}


	fclose(fp);
	return 0;
}

int Assignmen::readAssignmen(Assignmen *assignmen)//带头指针
{
	FILE *fp;
	//Assignmen *head = assignmen;
	if ((fp = fopen("Assignmen", "r+")) == NULL)
	{
		return 1;
	}
	char buf;
	int status = 0;
	CString str;
	int judge = 1;
	status = fread(&buf, sizeof(char), 1, fp);
	str.Format("%c", buf);
	assignmen->No += str;
	while (status > 0)
	{
		status = fread(&buf, sizeof(char), 1, fp);
		str.Format("%c", buf);
		if (status > 0 && str == "@")
		{
			judge++;
			if (judge == 9)
			{
				assignmen->next = new Assignmen();
				assignmen = assignmen->next;
				judge = 1;
			}
		}
		else if (status > 0 && judge == 1)
		{
			assignmen->No += str;
		}
		else if (status > 0 && judge == 2)
		{
			assignmen->course += str;
		}
		else if (status > 0 && judge == 3)
		{
			assignmen->contet += str;
		}
		else if (status > 0 && judge == 4)
		{
			assignmen->time += str;
		}
		else if (status > 0 && judge == 5)
		{
			assignmen->startTime += str;
		}
		else if (status > 0 && judge == 6)
		{
			assignmen->overTime += str;
		}
		else if (status > 0 && judge == 7)
		{
			assignmen->remark += str;
		}
		else if (status > 0 && judge == 8)
		{
			assignmen->className += str;
		}
	}

	rewind(fp);
	fclose(fp);
	return 0;
}

//CString Assignmen::getNo()
//{
//	return No;
//}
//CString Assignmen::getCourse()
//{
//	return course;
//}
//int Assignmen::getTime()
//{
//	return time;
//}
//CString Assignmen::getStartTime()
//{
//	return startTime;
//}
//CString Assignmen::getOverTime()
//{
//	return overTime;
//}
//CString Assignmen::getRemark()
//{
//	return remark;
//}
//CString Assignmen::getContet()
//{
//	return contet;
//}
//Assignmen* Assignmen::getNext()
//{
//	return next;
//}
//
//void Assignmen::setContet(CString contet)
//{
//	this->contet = contet;
//}
//void Assignmen::setNo(CString No)
//{
//	this->No = No;
//}
//void Assignmen::setCourse(CString course)
//{
//	this->course = course;
//}
//void Assignmen::setTime(int time)
//{
//	this->time = time;
//}
//void Assignmen::setStartTime(CString startTime)
//{
//	this->startTime = startTime;
//}
//void Assignmen::setOverTime(CString overTime)
//{
//	this->overTime = overTime;
//}
//void Assignmen::setRemark(CString remark)
//{
//	this->remark = remark;
//}
//void Assignmen::setNext(Assignmen *next)
//{
//	this->next = next;
//}

