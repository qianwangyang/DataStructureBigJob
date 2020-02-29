#ifndef CLASSLIST_H
#define CLASSLIST_H

class ClassList
{
public :
	ClassList();
	static ClassList *classList;

	CString getClassName();
	ClassList* getNext();

	int writeClassList(ClassList *classList);//读文件
	int readClassList(ClassList *classList);//写文件

	void setClassName(CString className);
	void setNext(ClassList *next);


private:
	CString className;
	ClassList *next;
};

#endif