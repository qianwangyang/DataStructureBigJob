#ifndef ASSIGNMEN_H
#define ASSIGNMEN_H

class Assignmen
{
	public :
		Assignmen(CString No, CString course, CString contet, CString time, CString startTime, CString overTime, CString remark);

		Assignmen();

		CString No;//作业编号
		CString course;//课程名称
		CString contet;//作业内容
		CString time;//作业次数
		CString startTime;//发布时间
		CString overTime;//截止时间
		CString remark;//备注
		CString className;//班级

		Assignmen *next;

		//静态指针对象
		static Assignmen *assignmen;
		
		int writeAssignmen(Assignmen *assignmen);//写文件
		int readAssignmen(Assignmen *assignmen);//读文件


	//CString getNo();
	//CString getCourse();
	//int getTime();
	//CString getStartTime();
	//CString getOverTime();
	//CString getRemark();
	//CString getContet();
	//Assignmen* getNext();

	//void setNext(Assignmen *next);
	//void setContet(CString contet);
	//void setNo(CString No);
	//void setCourse(CString course);
	//void setTime(int time);
	//void setStartTime(CString startTime);
	//void setOverTime(CString overTime);
	//void setRemark(CString remark);
};


#endif