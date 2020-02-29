
#ifndef PERSON_H
#define PERSON_H
class Person
{
public :
	Person();
	Person(int id,int pw,int status,CString num,Person *next);
	Person(int id, int pw, int status, CString num);

	static Person *person;

	int writePerson(Person *person);//写文件
	int readPerson(Person *person);//读文件

	int getPW();
	int getID();
	CString getNum();
	int getStatus();
	Person* getNext();
	CString getClassName();


	void setClassName(CString className);
	void setPW(int pw);
	void setID(int id);
	void setStatus(int status);
	void setNum(CString Num);
	void setNext(Person *next);
	
private :
	CString num;//学号
	CString className;//班级
	int pw;//密码
	int id;//账号
	int status;//身份
	Person *next;//person的指针
};

#endif