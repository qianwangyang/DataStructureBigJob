
#ifndef PERSON_H
#define PERSON_H
class Person
{
public :
	Person(int id,int pw,int status,CString num,Person *next);
	Person(int id, int pw, int status, CString num);
	int getPW();
	int getID();
	CString getNum();
	int getStatus();
	Person* getPerson();
	CString getClassName();

	void setClassName(CString className);
	void setPW(int pw);
	void setID(int id);
	void setStatus(int status);
	void setNum(CString Num);
	void setNext(Person *next);
	
private :
	CString num;//ѧ��
	CString className;//�༶
	int pw;//����
	int id;//�˺�
	int status;//���
	Person *next;//person��ָ��
};

#endif