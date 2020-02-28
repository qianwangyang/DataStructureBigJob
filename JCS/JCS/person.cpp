#include "stdafx.h"
#include "person.h"

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
Person* Person::getPerson()
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


