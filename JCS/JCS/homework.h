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

	CString getClassName();
	CString getNum();
	CString getTime();
	CString getNo();
	CString getRemark();

	void setClassName(CString className);
	void setNum(CString num);
	void setNo(CString No);
	void setTime(CString time);
	void setRemark(CString remark);

private:
	CString className;//����
	CString num;//ѧ��
	CString No;//���
	CString time;//��ֹʱ��
	CString remark;//��ע
	

};

#endif