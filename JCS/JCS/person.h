
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

	CString num;//ѧ��
	CString name;//����
	CString className;//�༶
	CString pw;//����
	CString status;//���
	Person *next;//person��ָ��

	//CString id;//�˺�

	int writePerson(Person *person);//д�ļ�
	int readPerson(Person *person);//���ļ�

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