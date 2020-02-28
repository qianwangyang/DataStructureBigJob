#ifndef HOMEWORK_H
#define HOMEWORK_H

/**
学生做的作业

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
	CString className;//班名
	CString num;//学号
	CString course;//课程名称
	CString No;//作业编号
	CString time;//截止时间
	CString remark;//备注
	Homework *next;//下一个
	

};

#endif