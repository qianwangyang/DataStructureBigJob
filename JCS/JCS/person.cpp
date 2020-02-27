#include "stdafx.h"
#include "person.h"

Person::Person(int id, int pw, int status, char *name,Person *next)
{
	this->id = id;
	this->pw = pw;
	this->status = status;
	this->name = name;
	this->next = next;
}

int Person::getPW()
{
	return pw;
}
int Person::getID()
{
	return id;
}
char* Person::getName()
{
	return name;
}
int Person::getStatus()
{
	return status;
}

Person* Person::getPerson()
{
	return next;
}

void Person::setPW(int pw)
{
	this->pw = pw;
}
void Person::setID(int id)
{
	this->id = id;
}

void Person::setName(char *name)
{
	this->name = name;
}

void Person::setStatus(int status)
{
	this->status = status;
}

void Person::setNext(Person *next)
{
	this->next = next;
}


