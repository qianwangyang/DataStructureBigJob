#ifndef HOMEWORK_H
#define HOMEWORK_H

/**
ѧ��������ҵ

*/
class Homework
{
public :
	Homework(CString className,
	CString nun,
	CString No,
	CString time,
	CString remark);
	Homework();

	CString getClassName();
	CString getNum();
	CString getTime();
	CString getNo();
	CString getRemark();
	CString getCourse();
	Homework* getNext();

	void setNext(Homework *next);
	void setClassName(CString className);
	void setNum(CString num);
	void setNo(CString No);
	void setTime(CString time);
	void setRemark(CString remark);
	void setCourse(CString course);

private:
	CString className;//����
	CString num;//ѧ��
	CString course;//�γ�����
	CString No;//��ҵ���
	CString time;//��ֹʱ��
	CString remark;//��ע
	Homework *next;//��һ��
	

};

#endif