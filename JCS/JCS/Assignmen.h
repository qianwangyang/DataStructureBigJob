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

	CString getNo();
	CString getCourse();
	int getTime();
	CString getStartTime();
	CString getOverTime();
	CString getRemark();
	CString getContet();
	void setContet(CString contet);
	void setNo(CString No);
	void setCourse(CString course);
	void setTime(int time);
	void setStartTime(CString startTime);
	void setOverTime(CString overTime);
	void SetRemark(CString remark);

private:
	CString No;
	CString course;
	CString contet;
	int time;
	CString startTime;
	CString overTime;
	CString remark;

};


#endif