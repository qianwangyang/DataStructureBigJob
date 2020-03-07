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

	int writeClassList(ClassList *classList);//读文件
	 int readClassList(ClassList *head);//写文件

	void setClassName(CString className);
	void setNext(ClassList *next);


//private:
//	CString className;
//	ClassList *next;
};

#endif