
#ifndef PERSON_H
#define PERSON_H
class Person
{
public :
	Person();
	Person(CString pw, CString status, CString num, Person *next);
	Person(CString pw, CString status, CString num);

	static Person *person;
	static Person *who;

	CString num;//学号
	CString name;//姓名
	CString className;//班级
	CString pw;//密码
	CString status;//身份
	Person *next;//person的指针

	//CString id;//账号

	int writePerson(Person *person);//写文件
	int readPerson(Person *person);//读文件

	//int getPW();
	//CString getNum();
	//int getStatus();
	//Person* getNext();
	//CString getClassName();


	//void setClassName(CString className);
	//void setPW(int pw);
	//void setStatus(int status);
	//void setNum(CString Num);
	//void setNext(Person *next);
	//
	
};

#endif