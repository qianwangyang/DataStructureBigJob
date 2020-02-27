
#ifndef PERSON_H
#define PERSON_H
class Person
{
public :
	Person(int id,int pw,int status,CString name,Person *next);
	int getPW();
	int getID();
	CString getName();
	int getStatus();
	Person* getPerson();
	void setPW(int pw);
	void setID(int id);
	void setStatus(int status);
	void setName(CString name);
	void setNext(Person *next);
	
private :
	CString name;
	int pw;
	int id;
	int status;
	Person *next;
};

#endif