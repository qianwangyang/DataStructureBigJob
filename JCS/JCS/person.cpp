#include "stdafx.h"
#include "person.h"
#include "afxdialogex.h"

Person::Person()
{
	next = NULL;
}
Person::Person(CString pw, CString status, CString num,Person *next)
{
	this->pw = pw;
	this->status = status;
	this->num = num;
	this->next = next;
}

Person::Person(CString pw, CString status, CString num)
{
	this->pw = pw;
	this->status = status;
	this->num = num;
}

Person *Person::person = NULL;

int Person::writePerson(Person *person)//有头节点
{
	FILE *fp;
	if ((fp = fopen("person", "wb")) == NULL)
	{
		return 1;
	}
	CString cstr(" ");
	while (person != NULL)
	{
		fprintf(fp, person->num);
		fprintf(fp, cstr);
		fprintf(fp, person->name);
		fprintf(fp, cstr);
		fprintf(fp, person->className);
		fprintf(fp, cstr);
		fprintf(fp, person->pw);
		fprintf(fp, cstr);
		fprintf(fp, person->status);
		person = person->next;
		if (person == NULL)
		{
			break;
		}
		fprintf(fp, cstr);
		
	}
		
	
	fclose(fp);
	return 0;
}

int Person::readPerson(Person *person)
{
	FILE *fp;
	CString str;
	char buf;
	int status = 0;
	int judge = 1;

	if ((fp = fopen("person", "rb")) == NULL)
	{
		return 1;
	}
	
	status = fread(&buf, sizeof(char), 1, fp);
	str.Format("%c", buf);
	person->num += str;
	while (status > 0)
	{  
		status = fread(&buf, sizeof(char), 1, fp);
		str.Format("%c", buf);
		if (status > 0 && str == " ")
		{
			judge++;
			if (judge == 6)
			{
				person->next = new Person();
				person = person->next;
				judge = 1;
			}
		}
		else if (status > 0 && judge == 1)
		{
			person->num += str;
		}
		else if (status > 0 && judge == 2)
		{
			person->name += str;
		}
		else if (status > 0 && judge == 3)
		{
			person->className += str;
		}
		else if (status > 0 && judge == 4)
		{
			person->pw += str;
		}
		else if (status > 0 && judge == 5)
		{
			person->status += str;
		}
	}
	rewind(fp);
	fclose(fp);
	return 0;
}

//int Person::getPW()
//{
//	return pw;
//}
//CString Person::getNum()
//{
//	return num;
//}
//int Person::getStatus()
//{
//	return status;
//}
//Person* Person::getNext()
//{
//	return next;
//}
//CString Person::getClassName()
//{
//	return className;
//}
//
//
//
//void Person::setClassName(CString className)
//{
//	this->className = className;
//}
//
//void Person::setPW(int pw)
//{
//	this->pw = pw;
//}
//}
//
//void Person::setNum(CString num)
//{
//	this->num = num;
//}
//
//void Person::setStatus(int status)
//{
//	this->status = status;
//}
//
//void Person::setNext(Person *next)
//{
//	this->next = next;
//}
