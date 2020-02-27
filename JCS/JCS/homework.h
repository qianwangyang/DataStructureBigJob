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
	CString className;//班名
	CString num;//学号
	CString No;//编号
	CString time;//截止时间
	CString remark;//备注
	

};

#endif