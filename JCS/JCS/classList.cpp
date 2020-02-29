#include"stdafx.h"
#include "classList.h"
#include "afxdialogex.h"

ClassList::ClassList()
{

}

ClassList *ClassList::classList = NULL;

//写文件
int ClassList::writeClassList(ClassList *classList)//有头节点
{
	FILE *fp;
	if ((fp = fopen("classList", "wb")) == NULL)
	{
		return 1;
	}
	while (classList->getNext() != NULL)
	{
		classList = classList->getNext();
		if (fwrite(classList, sizeof(ClassList), 1, fp) != 1)
		{
			return 2;
		}
	}
	fclose(fp);
	return 0;
}

//读文件
int ClassList::readClassList(ClassList *classList)//带头指针
{
	FILE *fp;
	if ((fp = fopen("classList", "rb")) == NULL)
	{
		return 1;
	}
	while (!feof(fp))
	{
		ClassList *next = new ClassList();
		classList->setNext(next);
		classList = next;
		fread(classList, sizeof(ClassList), 1, fp);

	}
	classList->setNext(NULL); 
	rewind(fp);
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