#include"stdafx.h"
#include "classList.h"
#include "afxdialogex.h"

ClassList::ClassList()
{
	next = NULL; 
}

ClassList *ClassList::classList = NULL;

//写文件
int ClassList::writeClassList(ClassList *classList)
{
	FILE *fp;
	if ((fp = fopen("classList", "w")) == NULL)
	{
		return 1;
	}
	CString cstr(" ");
	while (classList != NULL)
	{
		fprintf(fp, classList->className);
		classList = classList->next;
		if (classList == NULL)
		{
			break;
		}
		fprintf(fp, cstr);
		
	}
	fflush(fp);
	fclose(fp);
	return 0;
}

ClassList*  ClassList::xxx()
{
	ClassList *xx = new ClassList();
//	xx->setClassName("4444");
	return xx;
}

//读文件
 int ClassList::readClassList(ClassList *head)
{
	


	FILE *fp;
	CString str;
	if ((fp = fopen("classList", "r+")) == NULL)
	{
		return 1;
	}
	
	char buf;
	int status = 0;
	status = fread(&buf, sizeof(char), 1, fp);
	str.Format("%c", buf);
	head->className += str;
	while (status > 0)
	{
		status = fread(&buf, sizeof(char), 1, fp);
		str.Format("%c", buf);
		if (str == " " && status > 0)
		{
			head->next = new ClassList();
			head = head->next;
			head->next = NULL;
		}
		if (status > 0 && str != " " )
		{
			head->className += str;
		}
	}
	fclose(fp);
	return 0;
}

CString ClassList::getClassName()
{
	return className;
}
ClassList* ClassList::getNext()
{
	return next;
}

void ClassList::setClassName(CString className)
{
	this->className = className;
}
void ClassList::setNext(ClassList *next)
{
	this->next = next;
}