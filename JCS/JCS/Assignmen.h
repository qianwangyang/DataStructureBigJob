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
	CString No;//作业编号
	CString course;//课程名称
	CString contet;//作业内容
	int time;//作业次数
	CString startTime;//发布时间
	CString overTime;//截止时间
	CString remark;//备注
	Assignmen *next;

};


#endif