#ifndef CLASSLIST_H
#define CLASSLIST_H

class ClassList
{
public :
	ClassList();
	static ClassList *classList;

	CString getClassName();
	ClassList* getNext();

	int writeClassList(ClassList *classList);//���ļ�
	int readClassList(ClassList *classList);//д�ļ�

	void setClassName(CString className);
	void setNext(ClassList *next);


private:
	CString className;
	ClassList *next;
};

#endif