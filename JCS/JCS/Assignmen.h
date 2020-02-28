#ifndef ASSIGNMEN_H
#define ASSIGNMEN_H

class Assignmen
{
	public :
		Assignmen(CString No,
		CString course,
		CString contet,
		int time,
		CString startTime,
		CString overTime,
		CString remark );
		Assignmen();

	CString getNo();
	CString getCourse();
	int getTime();
	CString getStartTime();
	CString getOverTime();
	CString getRemark();
	CString getContet();
	Assignmen* getNext();

	void setNext(Assignmen *next);
	void setContet(CString contet);
	void setNo(CString No);
	void setCourse(CString course);
	void setTime(int time);
	void setStartTime(CString startTime);
	void setOverTime(CString overTime);
	void setRemark(CString remark);

private:
	CString No;//��ҵ���
	CString course;//�γ�����
	CString contet;//��ҵ����
	int time;//��ҵ����
	CString startTime;//����ʱ��
	CString overTime;//��ֹʱ��
	CString remark;//��ע
	Assignmen *next;

};


#endif