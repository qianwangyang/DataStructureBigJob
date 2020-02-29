#include "stdafx.h"
#include "person.h"
#include "afxdialogex.h"

Person::Person()
{
	//person = NULL;
}
Person::Person(int id, int pw, int status, CString num,Person *next)
{
	this->id = id;
	this->pw = pw;
	this->status = status;
	this->num = num;
	this->next = next;
}

Person::Person(int id, int pw, int status, CString num)
{
	this->id = id;
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
	while (person->getNext() != NULL)
	{
		person = person->getNext();
		if (fwrite(person, sizeof(Person), 1, fp) != 1)
		{
			return 2;
		}
	}
	fclose(fp);
	return 0;
}

int Person::readPerson(Person *person)//带头指针
{
	FILE *fp;
	//	Person *head = person;
	if ((fp = fopen("person", "rb")) == NULL)
	{
		return 1;
	}
	while (!feof(fp))
	{
		Person *next = new Person();
		person->setNext(next);
		person = next;
		fread(person, sizeof(Person), 1, fp);
	}
	person->setNext(NULL);
	//person = head;
	rewind(fp);
	fclose(fp);
	return 0;
}

int Person::getPW()
{
	return pw;
}
int Person::getID()
{
	return id;
}
CString Person::getNum()
{
	return num;
}
int Person::getStatus()
{
	return status;
}
Person* Person::getNext()
{
	return next;
}
CString Person::getClassName()
{
	return className;
}



void Person::setClassName(CString className)
{
	this->className = className;
}

void Person::setPW(int pw)
{
	this->pw = pw;
}
void Person::setID(int id)
{
	this->id = id;
}

void Person::setNum(CString num)
{
	this->num = num;
}

void Person::setStatus(int status)
{
	this->status = status;
}

void Person::setNext(Person *next)
{
	this->next = next;
}


