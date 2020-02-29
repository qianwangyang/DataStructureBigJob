#include"stdafx.h"
#include "classList.h"
#include "afxdialogex.h"

ClassList::ClassList()
{

}

ClassList *ClassList::classList = NULL;

//д�ļ�
int ClassList::writeClassList(ClassList *classList)//��ͷ�ڵ�
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

//���ļ�
int ClassList::readClassList(ClassList *classList)//��ͷָ��
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