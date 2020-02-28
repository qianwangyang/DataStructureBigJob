#include "stdafx.h"
#include "memory.h"
#include "afxdialogex.h"
#include "person.h"
#include "Assignmen.h"

Memory::Memory()
{

}

int Memory::write(Person *person)//有头节点
{
	FILE *fp;
	if ((fp = fopen("XueWei","wb")) == NULL)
	{
		//CString str("打开文件XueWei错误");
		//MessageBox("打开文件XueWei错误");
		return 1;
	}
	while (person->getNext() != NULL)
	{
		person = person->getNext();
		if (fwrite(person, sizeof(Person), 1, fp) != 1)
		{
			return 2;
		}
	}
	return 0;
}

int Memory::read(Person *person)//带头指针
{
	FILE *fp;
	Person *head = person;
	if ((fp = fopen("XueWei", "rb")) == NULL)
	{
		return 1;
	}
	while (1)
	{
		Person *next = new Person();
		person->setNext(next);
		person = next;
		fread(person, sizeof(Person), 1, fp);
		if (feof(fp))
		{
			break;
		}

	}
	person->setNext(NULL);
	person = head;
	return 0;
}


int Memory::write(Assignmen *assignmen)//有头节点
{
	FILE *fp;
	if ((fp = fopen("Assignmen", "wb")) == NULL)
	{
		//CString str("打开文件XueWei错误");
		//MessageBox("打开文件XueWei错误");
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
	return 0;
}

int Memory::read(Assignmen *assignmen)//带头指针
{
	FILE *fp;
	Assignmen *head = assignmen;
	if ((fp = fopen("Assignmen", "rb")) == NULL)
	{
		return 1;
	}
	while (1)
	{
		Assignmen *next = new Assignmen();
		assignmen->setNext(next);
		assignmen = next;
		fread(assignmen, sizeof(Assignmen), 1, fp);
		if (feof(fp))
		{
			break;
		}

	}
	assignmen->setNext(NULL);
	assignmen = head;
	return 0;
}