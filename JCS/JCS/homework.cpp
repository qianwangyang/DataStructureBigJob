#include "stdafx.h"
#include "homework.h"
#include "person.h"
#include "afxdialogex.h"

Homework::Homework(CString className,CString num,CString No,CString time,CString remark)
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
	CString cstr("@");
	while (homework != NULL)
	{
		fprintf(fp, homework->className);
		fprintf(fp, cstr);
		fprintf(fp, homework->num);
		fprintf(fp, cstr);
		fprintf(fp, homework->name);
		fprintf(fp, cstr);
		fprintf(fp, homework->course);
		fprintf(fp, cstr);
		fprintf(fp, homework->No);
		fprintf(fp, cstr);
		fprintf(fp, homework->time);
		fprintf(fp, cstr);
		fprintf(fp, homework->remark);
		homework = homework->next;
		if (homework == NULL)
		{
			break;
		}
		fprintf(fp, cstr);
	}
	fclose(fp);
	return 0;
}

int Homework::readHomework(Homework *homework)//带头指针
{
	FILE *fp;
	//Homework *head = homework;
	if ((fp = fopen("homework", "r+")) == NULL)
	{
		return 1;
	}
	char buf;
	int status = 0;
	int judge = 1;
	CString str;
	status = fread(&buf, sizeof(char), 1, fp);
	str.Format("%c", buf);
	homework->className += str;
	while (status > 0)
	{
		status = fread(&buf, sizeof(char), 1, fp);
		str.Format("%c", buf);
		if (status > 0 && str == "@")
		{
			judge++;
			if (judge == 8)
			{
				homework->next = new Homework();
				homework = homework->next;
				judge = 1;
			}
		}
		else if (status > 0 && judge == 1)
		{
			homework->className += str;
		}
		else if (status > 0 && judge == 2)
		{
			homework->num += str;
		}
		else if (status > 0 && judge == 3)
		{
			homework->name += str;
		}
		else if (status > 0 && judge == 4)
		{
			homework->course += str;
		}
		else if (status > 0 && judge == 5)
		{
			homework->No += str;
		}
		else if (status > 0 && judge == 6)
		{
			homework->time += str;
		}
		else if (status > 0 && judge == 7)
		{
			homework->remark += str;
		}
	}
	rewind(fp);
	fclose(fp);
	return 0;
}




//CString Homework::getClassName()
//{
//	return className;
//}
//CString Homework::getNum()
//{
//	return num;
//}
//CString Homework::getTime()
//{
//	return time;
//}
//CString Homework::getNo()
//{
//	return No;
//}
//CString Homework::getRemark()
//{
//	return remark;
//}
//CString Homework::getCourse()
//{
//	return course;
//}
//Homework* Homework::getNext()
//{
//	return next;
//}
//
//void Homework::setNext(Homework *next)
//{
//	this->next = next;
//}
//void Homework::setCourse(CString course)
//{
//	this->course = course;
//}
//void Homework::setClassName(CString className)
//{
//	this->className = className;
//}
//void Homework::setNum(CString num)
//{
//	this->num = num;
//}
//void Homework::setNo(CString No)
//{
//	this->No = No;
//}
//void Homework::setTime(CString time)
//{
//	this->time = time;
//}
//void Homework::setRemark(CString remark)
//{
//	this->remark = remark;
//}