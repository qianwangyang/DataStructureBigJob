#ifndef CLASSLIST_H
#define CLASSLIST_H

class ClassList
{
public :
	ClassList();
	static ClassList *classList;
	CString className;
	ClassList *next;


	CString getClassName();
	ClassList* getNext();
	ClassList* xxx();

	int writeClassList(ClassList *classList);//���ļ�
	 int readClassList(ClassList *head);//д�ļ�

	void setClassName(CString className);
	void setNext(ClassList *next);


//private:
//	CString className;
//	ClassList *next;
};

#endif