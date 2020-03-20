// StudiesDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "JCS.h"
#include "StudiesDlg.h"
#include "Course.h"
#include "classList.h"
#include "person.h"
#include "homework.h"
#include "Assignmen.h"
#include "afxdialogex.h"


// StudiesDlg 对话框

IMPLEMENT_DYNAMIC(StudiesDlg, CDialogEx)

StudiesDlg::StudiesDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(StudiesDlg::IDD, pParent)
	, m_PublishTime(_T(""))
	, m_SubmitCourse(_T(""))
	//, m_publicCourseNumEdit(_T(""))
	, m_publishCourseNameEdit(_T(""))
	, m_PublishTimesEdit(_T(""))
	, m_publishStartTime(_T(""))
	, m_stopTime(_T(""))
	, m_publishContent(_T(""))
	, m_submitNum(_T(""))
	, m_submitName(_T(""))
	, m_timeOfSubmit(_T(""))
	, m_submitNo(_T(""))
	, m_submitNotes(_T(""))
	, m_statistics(_T(""))
	, m_radioPublish(0)
	, m_RadioSubimt(0)
	, m_publishOver(_T(""))
	, m_subimtOver(_T(""))
	, m_publishRemark(_T(""))
	, m_submitCourse(_T(""))
{

}

StudiesDlg::~StudiesDlg()
{
}

void StudiesDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//DDX_Control(pDX, IDC_COMBO1, m_courseOrClass);
	DDX_Control(pDX, IDC_COMBO1, m_studentOrCourse);
	//DDX_Control(pDX, IDC_LIST1, m_courseOrClassListBox);
	DDX_Control(pDX, IDC_LIST1, m_studentOrCourseListBox);
	//课程伪数据
	//Course *co1 = new Course();
	//Course *co2 = new Course();
	//Course *co3 = new Course();
	//Course *co4 = new Course();
	//Course *co5 = new Course();

	//co1->courseName = "高数";
	//co2->courseName = "数据结构";
	//co3->courseName = "计算机组成原理";
	//co4->courseName = "离散数学";
	//co5->courseName = "线性代数";

	//co1->next = co2;
	//co2->next = co3;
	//co3->next = co4;
	//co4->next = co5;
	//co5->next = NULL;

	//co1->writeCourse(co1);

	//读course
	//Course *course = new Course();
	//course->readCourse(course);
	//Course::course = course;

	//while (course->next != NULL)
	//{
	//	MessageBox(course->courseName);
	//	course = course->next;
	//}
	DDX_Control(pDX, IDC_LIST2, m_homeWordContent);
	DDX_Control(pDX, IDC_LIST4, m_SearchPublish);
	DDX_Control(pDX, IDC_LIST3, m_SearchSubmit);
	DDX_Text(pDX, IDC_EDIT1, m_PublishTime);
	//DDX_Control(pDX, IDC_EDIT3, m_PublishCourse);
	//DDX_Control(pDX, IDC_EDIT2, m_SubmitTime);
	DDX_Text(pDX, IDC_EDIT3, m_PublishCourse);//改过
	DDX_Text(pDX, IDC_EDIT2, m_SubmitTime);

	DDX_Text(pDX, IDC_EDIT4, m_SubmitCourse);
	//DDX_Text(pDX, IDC_EDIT8, m_publicCourseNumEdit);
	DDX_Text(pDX, IDC_EDIT8, m_publishCourseNumEdit);
	DDX_Text(pDX, IDC_EDIT9, m_publishCourseNameEdit);
	DDX_Text(pDX, IDC_EDIT7, m_PublishTimesEdit);
	DDX_Text(pDX, IDC_EDIT5, m_publishStartTime);
	DDX_Text(pDX, IDC_EDIT11, m_stopTime);
	DDX_Text(pDX, IDC_EDIT12, m_publishContent);
	DDX_Text(pDX, IDC_EDIT10, m_submitNum);
	DDX_Text(pDX, IDC_EDIT13, m_submitName);
	DDX_Text(pDX, IDC_EDIT16, m_timeOfSubmit);
	DDX_Text(pDX, IDC_EDIT15, m_submitNo);
	DDX_Text(pDX, IDC_EDIT17, m_submitNotes);
	DDX_Text(pDX, IDC_EDIT18, m_statistics);
	DDX_Radio(pDX, IDC_RADIO1, m_radioPublish);
	DDX_Radio(pDX, IDC_RADIO3, m_RadioSubimt);
	DDX_Text(pDX, IDC_EDIT19, m_publishOver);
	DDX_Text(pDX, IDC_EDIT20, m_subimtOver);
	DDX_Control(pDX, IDC_COMBO2, m_refer);
	DDX_Text(pDX, IDC_EDIT6, m_publishRemark);
	DDX_Text(pDX, IDC_EDIT14, m_submitCourse);

	if (judgeFirst)
	{
		m_refer.AddString("时间");
		m_refer.AddString("次数");
		m_refer.SetCurSel(0);

		m_studentOrCourse.AddString("课程");
		m_studentOrCourse.AddString("学生");
		m_studentOrCourse.SetCurSel(0);

		Course *co = Course::course;
		while (co->next != NULL)
		{
			m_studentOrCourseListBox.AddString(co->courseName);
			co = co->next;
		}
		judgeFirst = 0;
	}
}


BEGIN_MESSAGE_MAP(StudiesDlg, CDialogEx)
	//ON_CBN_SELCHANGE(IDC_COMBO1, &StudiesDlg::OnSelectCourseOrClass)
	ON_CBN_SELCHANGE(IDC_COMBO1, &StudiesDlg::OnSelectStudentOrCourse)
	//ON_LBN_SELCHANGE(IDC_LIST1, &StudiesDlg::OnSelectClassOrCourseListBox)
	ON_LBN_SELCHANGE(IDC_LIST1, &StudiesDlg::OnSelectStudentOrCourseListBox)
	ON_LBN_SELCHANGE(IDC_LIST2, &StudiesDlg::OnSelectHomeWordContent)
	ON_LBN_SELCHANGE(IDC_LIST4, &StudiesDlg::OnSearchPublish)
	ON_LBN_SELCHANGE(IDC_LIST3, &StudiesDlg::OnSearchSubmit)
	ON_BN_CLICKED(IDC_BUTTON3, &StudiesDlg::OnSearchPublishByTime)
	ON_BN_CLICKED(IDC_BUTTON4, &StudiesDlg::OnSearchPublishByCourse)
	ON_BN_CLICKED(IDC_BUTTON5, &StudiesDlg::OnSearchSubimtByTime)
	ON_BN_CLICKED(IDC_BUTTON6, &StudiesDlg::OnSearchSubmitByCourse)
	ON_BN_CLICKED(IDC_BUTTON7, &StudiesDlg::OnPublishHomework)
	ON_BN_CLICKED(IDC_BUTTON8, &StudiesDlg::OnRevampHomework)
	ON_BN_CLICKED(IDC_BUTTON9, &StudiesDlg::OnAddStudentHomework)
	ON_BN_CLICKED(IDC_BUTTON10, &StudiesDlg::OnRevampStudentHomework)
	ON_BN_CLICKED(IDC_RADIO1, &StudiesDlg::OnRadioPublish)
	ON_BN_CLICKED(IDC_RADIO2, &StudiesDlg::OnRadioPublish)
	ON_BN_CLICKED(IDC_RADIO3, &StudiesDlg::OnRadioSubimt)
	ON_BN_CLICKED(IDC_RADIO4, &StudiesDlg::OnRadioSubimt)
	ON_BN_CLICKED(IDC_BUTTON1, &StudiesDlg::OnDeleteStudentOrCourse)
	ON_BN_CLICKED(IDC_BUTTON2, &StudiesDlg::OnDeleteContent)
END_MESSAGE_MAP()


// StudiesDlg 消息处理程序




void StudiesDlg::OnSelectStudentOrCourse()
{
	int index = m_studentOrCourse.GetCurSel();
	CString str;
	m_studentOrCourse.GetLBText(index, str);
	m_studentOrCourseListBox.ResetContent();
	if (str == "课程")
	{
		Course *course = Course::course;
		while (course != NULL)
		{
			m_studentOrCourseListBox.AddString(course->courseName);
			course = course->next;
		}
	}
	else
	{
		Person *person = Person::person;
		Person *who = Person::who;
		while (person != NULL)
		{
			if (person->className == who->className)
			{
				m_studentOrCourseListBox.AddString(person->name);
			}
			person = person->next;
		}

	}
}


void StudiesDlg::OnSelectStudentOrCourseListBox()
{
	int index = m_studentOrCourse.GetCurSel();
	CString str;
	m_studentOrCourse.GetLBText(index, str);

	CString name;
	index = m_studentOrCourseListBox.GetCurSel();
	m_studentOrCourseListBox.GetText(index, name);

	Person *per = Person::who;
	int judge = 1;
	m_homeWordContent.ResetContent();
	if (str == "学生")
	{
		Homework *homework = Homework::homework;
		//Person *person = Person::person;
		while (homework != NULL)
		{
			if (homework->name == name && per->className == homework->className);
			{
				m_homeWordContent.AddString(homework->className + " " + homework->num 
					+ " " + homework->name + " " + " " + homework->No + " " + homework->course
					 + " " + homework->time + " " + homework->remark);
				judge = 0;
			}
			homework = homework->next;
		}
	}
	else
	{
		Assignmen *assignmen = Assignmen::assignmen;
		while (assignmen != NULL)
		{
			if (assignmen->course == name && per->className == assignmen->className)
			{
				m_homeWordContent.AddString(assignmen->No + " " + assignmen->course 
					+ " " + assignmen->contet + " " + assignmen->time + " " 
					+ assignmen->startTime + " " + assignmen->overTime + " " 
					+ assignmen->remark);
				judge = 0;
			}
			assignmen = assignmen->next;
		}
	}
	if (judge)
	{
		MessageBox("未有记录！");
	}
}


void StudiesDlg::OnSelectHomeWordContent()
{
	int index = m_studentOrCourse.GetCurSel();
	CString str;
	m_studentOrCourse.GetLBText(index, str); 
	if (str == "学生")
	{
		//获取作业编号和学号
		index = m_homeWordContent.GetCurSel();
		m_homeWordContent.GetText(index,str);
		index = str.Find(" ");
		str.Delete(0, index+1);
		index = str.Find(" ");
		CString num = str.Left(index);
		str.Delete(0, index + 1);
		index = str.Find(" ");
		str.Delete(0, index + 1);
		index = str.Find(" ");
		str.Delete(0, index + 1);
		index = str.Find(" ");
		CString No = str.Left(index);
		//MessageBox(No + " " + num);
		//MessageBox(num);
		Homework *homework = Homework::homework;
		while (homework != NULL)
		{
			if (homework->No == No && homework->num == num)
			{
				MessageBox(homework->className + " " + homework->num
					+ " " + homework->name + " " + " " + homework->No + " " + homework->course
					+ " " + homework->time + " " + homework->remark);
				GetDlgItem(IDC_EDIT10)->SetWindowTextA(homework->num);
				GetDlgItem(IDC_EDIT13)->SetWindowTextA(homework->name);
				GetDlgItem(IDC_EDIT16)->SetWindowTextA(homework->time);
				GetDlgItem(IDC_EDIT15)->SetWindowTextA(homework->No);
				GetDlgItem(IDC_EDIT17)->SetWindowTextA(homework->remark);
				GetDlgItem(IDC_EDIT14)->SetWindowTextA(homework->course);
				break;
			}
			homework = homework->next;
		}
	}
	else
	{
		Assignmen *assignmen = Assignmen::assignmen;
		index = m_homeWordContent.GetCurSel();
		m_homeWordContent.GetText(index, str);
		index = str.Find(" ");
		CString No = str.Left(index);
		while (assignmen != NULL)
		{
			if (assignmen->No == No)
			{
				MessageBox(assignmen->No + " " + assignmen->course
					+ " " + assignmen->contet + " " + assignmen->time + " "
					+ assignmen->startTime + " " + assignmen->overTime + " "
					+ assignmen->remark);

				GetDlgItem(IDC_EDIT8)->SetWindowTextA(assignmen->No);
				GetDlgItem(IDC_EDIT9)->SetWindowTextA(assignmen->course);
				GetDlgItem(IDC_EDIT7)->SetWindowTextA(assignmen->time);
				GetDlgItem(IDC_EDIT5)->SetWindowTextA(assignmen->startTime);
				GetDlgItem(IDC_EDIT11)->SetWindowTextA(assignmen->overTime);
				GetDlgItem(IDC_EDIT6)->SetWindowTextA(assignmen->remark);
				GetDlgItem(IDC_EDIT12)->SetWindowTextA(assignmen->contet);
				break;

			}
			assignmen = assignmen->next;
		}
	}
}


void StudiesDlg::OnSearchPublish()
{
	// TODO:  在此添加控件通知处理程序代码
}


void StudiesDlg::OnSearchSubmit()
{
	// TODO:  在此添加控件通知处理程序代码
}


void StudiesDlg::OnSearchPublishByTime()
{
	UpdateData(true);
	CString startTime;
	CString overTime;
	GetDlgItem(IDC_EDIT1)->GetWindowText(startTime);
	GetDlgItem(IDC_EDIT19)->GetWindowText(overTime);
	Assignmen *assignmen = Assignmen::assignmen;
	Assignmen *as = new Assignmen();
	Assignmen *head = as;
	if (startTime == "" || overTime == "")
	{
		MessageBox("关键信息未填写！");
	}
	while (assignmen != NULL)
	{
		if (assignmen->startTime >= startTime &&assignmen->overTime <= overTime)
		{
			*as = *assignmen;//最后一个为空，不可用
			as->next = new Assignmen();
			as = as->next;
		}
		assignmen = assignmen->next;
	}

	Assignmen *p = NULL;
	Assignmen *q = NULL;
	Assignmen *h = NULL;
	Assignmen *t = new Assignmen();

	switch (m_radioPublish)
	{
	case 0:
		if (head->next == NULL)
		{
			MessageBox("未有记录！");
			return;
		}
		for (p = head; p->next != NULL; p = p->next)
		{
			for (q = head; q->next->next != NULL; q = q->next)
			{
				if (q->startTime > q->next->startTime)
				{
					*t = *q;
					h = q->next;

					q->No = h->No;
					q->course = h->course;
					q->contet = h->contet;
					q->time = h->time;
					q->startTime = h->startTime;
					q->overTime = h->overTime;
					q->remark = h->remark;
					q->className = h->className;

					h->No = t->No;
					h->course = t->course;
					h->contet = t->contet;
					h->time = t->time;
					h->startTime = t->startTime;
					h->overTime = t->overTime;
					h->remark = t->remark;
					h->className = t->className;
				}
			}
		}
		break;
	case 1:
		if (head->next == NULL)
		{
			MessageBox("未有记录！");
			return;
		}
		for (p = head; p->next != NULL; p = p->next)
		{
			for (q = head; q->next->next != NULL; q = q->next)
			{
				if (q->startTime < q->next->startTime)
				{
					*t = *q;
					h = q->next;

					q->No = h->No;
					q->course = h->course;
					q->contet = h->contet;
					q->time = h->time;
					q->startTime = h->startTime;
					q->overTime = h->overTime;
					q->remark = h->remark;
					q->className = h->className;

					h->No = t->No;
					h->course = t->course;
					h->contet = t->contet;
					h->time = t->time;
					h->startTime = t->startTime;
					h->overTime = t->overTime;
					h->remark = t->remark;
					h->className = t->className;
				}
			}
		}
		break;
	default:
		break;
	}
}


void StudiesDlg::OnSearchPublishByCourse()
{
	UpdateData(true);
	CString course;
	GetDlgItem(IDC_EDIT1)->GetWindowText(course);
	Assignmen *assignmen = Assignmen::assignmen;
	Assignmen *as = new Assignmen();
	Assignmen *head = as;

	if (course == "" )
	{
		MessageBox("关键信息未填写！");
	}
	while (assignmen != NULL)
	{
		if (assignmen->course == course)
		{
			*as = *assignmen;//最后一个为空，不可用
			as->next = new Assignmen();
			as = as->next;
			as->next = NULL;
		}
		assignmen = assignmen->next;
	}

	if (head->next == NULL)
	{
		MessageBox("未有记录！");
		return;
	}

	Assignmen *p = NULL;
	Assignmen *q = NULL;
	Assignmen *h = NULL;
	Assignmen *t = new Assignmen();

	switch (m_radioPublish)
	{
	case 0:
		for (p = head; p->next != NULL; p = p->next)
		{
			for (q = head; q->next->next != NULL; q = q->next)
			{
				if (q->startTime > q->next->startTime)
				{
					*t = *q;
					h = q->next;

					q->No = h->No;
					q->course = h->course;
					q->contet = h->contet;
					q->time = h->time;
					q->startTime = h->startTime;
					q->overTime = h->overTime;
					q->remark = h->remark;
					q->className = h->className;

					h->No = t->No;
					h->course = t->course;
					h->contet = t->contet;
					h->time = t->time;
					h->startTime = t->startTime;
					h->overTime = t->overTime;
					h->remark = t->remark;
					h->className = t->className;
				}
			}
		}
		break;
	case 1:
		for (p = head; p->next != NULL; p = p->next)
		{
			for (q = head; q->next->next != NULL; q = q->next)
			{
				if (q->startTime < q->next->startTime)
				{
					*t = *q;
					h = q->next;

					q->No = h->No;
					q->course = h->course;
					q->contet = h->contet;
					q->time = h->time;
					q->startTime = h->startTime;
					q->overTime = h->overTime;
					q->remark = h->remark;
					q->className = h->className;

					h->No = t->No;
					h->course = t->course;
					h->contet = t->contet;
					h->time = t->time;
					h->startTime = t->startTime;
					h->overTime = t->overTime;
					h->remark = t->remark;
					h->className = t->className;
				}
			}
		}
	default:
		break;
	}
}


void StudiesDlg::OnSearchSubimtByTime()
{
	UpdateData(true);
	CString startTime;
	CString overTime;
	GetDlgItem(IDC_EDIT2)->GetWindowText(startTime);
	GetDlgItem(IDC_EDIT20)->GetWindowText(overTime);
	if (startTime == "" || overTime == "")
	{
		MessageBox("关键信息未填写！");
	}
	Homework *homework = Homework::homework;
	Homework *ho = new Homework();
	Homework *head = ho;
	Homework *t = new Homework();
	Homework *p = NULL;
	Homework *q = NULL;
	Homework *h = NULL;

	while (homework != NULL)
	{
		if (homework->time >= startTime && homework->time <= overTime)
		{
			*ho = *homework;
			ho->next = new Homework();
			ho = ho->next;
			ho->next = NULL;
		}
		homework = homework->next;
	}

	if (head->next == NULL)
	{
		MessageBox("未有记录！");
		return;
	}

	int index = m_refer.GetCurSel();
	CString cstr;
	m_refer.GetLBText(index, cstr);
	if (cstr == "时间")
	{
		switch (m_RadioSubimt)
		{
		case 0:
			for (p = head; q->next != NULL; p = p->next)
			{
				for (q = head; q->next->next != NULL; q = q->next)
				{
					if (q->time > q->next->time)
					{
						*t = *q;
						h = q->next;
						q->className = h->className;
						q->num = h->num;
						q->course = h->course;
						q->No = h->No;
						q->time = h->time;
						q->remark = h->remark;
						q->name = h->name;

						h->className = t->className;
						h->num = t->num;
						h->course = t->course;
						h->No = t->No;
						h->time = t->time;
						h->remark = t->remark;
						h->name = t->name;
					}
				}
			}
			break;
		case 1:
			for (p = head; q->next != NULL; p = p->next)
			{
				for (q = head; q->next->next != NULL; q = q->next)
				{
					if (q->time < q->next->time)
					{
						*t = *q;
						h = q->next;
						q->className = h->className;
						q->num = h->num;
						q->course = h->course;
						q->No = h->No;
						q->time = h->time;
						q->remark = h->remark;
						q->name = h->name;

						h->className = t->className;
						h->num = t->num;
						h->course = t->course;
						h->No = t->No;
						h->time = t->time;
						h->remark = t->remark;
						h->name = t->name;

					}
				}
			}

			break; 
		default:
			break;
		}
	}
	else
	{
		switch (m_RadioSubimt)
		{
		case 0:

			for (p = head; q->next != NULL; p = p->next)
			{
				for (q = head; q->next->next != NULL; q = q->next)
				{
					if (q->No > q->next->No)
					{
						*t = *q;
						h = q->next;
						q->className = h->className;
						q->num = h->num;
						q->course = h->course;
						q->No = h->No;
						q->time = h->time;
						q->remark = h->remark;
						q->name = h->name;

						h->className = t->className;
						h->num = t->num;
						h->course = t->course;
						h->No = t->No;
						h->time = t->time;
						h->remark = t->remark;
						h->name = t->name;

					}
				}
			}
			break;
		case 1:
			for (p = head; q->next != NULL; p = p->next)
			{
				for (q = head; q->next->next != NULL; q = q->next)
				{
					if (q->No < q->next->No)
					{
						*t = *q;
						h = q->next;
						q->className = h->className;
						q->num = h->num;
						q->course = h->course;
						q->No = h->No;
						q->time = h->time;
						q->remark = h->remark;
						q->name = h->name;

						h->className = t->className;
						h->num = t->num;
						h->course = t->course;
						h->No = t->No;
						h->time = t->time;
						h->remark = t->remark;
						h->name = t->name;
					}
				}
			}
			break;
		default:
			break;
		}
	}
}


void StudiesDlg::OnSearchSubmitByCourse()
{
	UpdateData(true);
	CString course;
	GetDlgItem(IDC_EDIT4)->GetWindowText(course);
	if (course == "")
	{
		MessageBox("关键信息未填写！");
	}
	Homework *homework = Homework::homework;
	Homework *ho = new Homework();
	Homework *head = ho;
	Homework *t = new Homework();
	Homework *p = NULL;
	Homework *q = NULL;
	Homework *h = NULL;

	while (homework != NULL)
	{
		if (homework->course)
		{
			*ho = *homework;
			ho->next = new Homework();
			ho = ho->next;
			ho->next = NULL;
		}
		homework = homework->next;
	}

	if (head->next == NULL)
	{
		MessageBox("未有记录！");
		return;
	}

	int index = m_refer.GetCurSel();
	CString cstr;
	m_refer.GetLBText(index, cstr);
	if (cstr == "时间")
	{
		switch (m_RadioSubimt)
		{
		case 0:
			for (p = head; q->next != NULL; p = p->next)
			{
				for (q = head; q->next->next != NULL; q = q->next)
				{
					if (q->time > q->next->time)
					{
						*t = *q;
						h = q->next;
						q->className = h->className;
						q->num = h->num;
						q->course = h->course;
						q->No = h->No;
						q->time = h->time;
						q->remark = h->remark;
						q->name = h->name;

						h->className = t->className;
						h->num = t->num;
						h->course = t->course;
						h->No = t->No;
						h->time = t->time;
						h->remark = t->remark;
						h->name = t->name;
					}
				}
			}
			break;
		case 1:
			for (p = head; q->next != NULL; p = p->next)
			{
				for (q = head; q->next->next != NULL; q = q->next)
				{
					if (q->time < q->next->time)
					{
						*t = *q;
						h = q->next;
						q->className = h->className;
						q->num = h->num;
						q->course = h->course;
						q->No = h->No;
						q->time = h->time;
						q->remark = h->remark;
						q->name = h->name;

						h->className = t->className;
						h->num = t->num;
						h->course = t->course;
						h->No = t->No;
						h->time = t->time;
						h->remark = t->remark;
						h->name = t->name;

					}
				}
			}

			break;
		default:
			break;
		}
	}
	else
	{
		switch (m_RadioSubimt)
		{
		case 0:

			for (p = head; q->next != NULL; p = p->next)
			{
				for (q = head; q->next->next != NULL; q = q->next)
				{
					if (q->No > q->next->No)
					{
						*t = *q;
						h = q->next;
						q->className = h->className;
						q->num = h->num;
						q->course = h->course;
						q->No = h->No;
						q->time = h->time;
						q->remark = h->remark;
						q->name = h->name;

						h->className = t->className;
						h->num = t->num;
						h->course = t->course;
						h->No = t->No;
						h->time = t->time;
						h->remark = t->remark;
						h->name = t->name;

					}
				}
			}
			break;
		case 1:
			for (p = head; q->next != NULL; p = p->next)
			{
				for (q = head; q->next->next != NULL; q = q->next)
				{
					if (q->No < q->next->No)
					{
						*t = *q;
						h = q->next;
						q->className = h->className;
						q->num = h->num;
						q->course = h->course;
						q->No = h->No;
						q->time = h->time;
						q->remark = h->remark;
						q->name = h->name;

						h->className = t->className;
						h->num = t->num;
						h->course = t->course;
						h->No = t->No;
						h->time = t->time;
						h->remark = t->remark;
						h->name = t->name;
					}
				}
			}
			break;
		default:
			break;
		}
	}
}


void StudiesDlg::OnPublishHomework()
{
	CString No;//作业编号
	CString course;//课程名称
	CString contet;//作业内容
	CString time;//作业次数
	CString startTime;//发布时间
	CString overTime;//截止时间
	CString remark;//备注
	GetDlgItem(IDC_EDIT8)->GetWindowText(No);
	GetDlgItem(IDC_EDIT9)->GetWindowText(course);
	GetDlgItem(IDC_EDIT7)->GetWindowText(time);
	GetDlgItem(IDC_EDIT5)->GetWindowText(startTime);
	GetDlgItem(IDC_EDIT11)->GetWindowText(overTime);
	GetDlgItem(IDC_EDIT12)->GetWindowText(contet);
	GetDlgItem(IDC_EDIT6)->GetWindowText(remark);

	if (time == "" || No == "" || course == "" || startTime == "" || overTime == "" || contet == "" ||remark == "")
	{
		MessageBox("请完善信息");
	}
	Assignmen *as = Assignmen::assignmen;
	while (as != NULL)
	{
		if (as->No == No)
		{
			MessageBox("作业编号已经使用，请重新填写！");
			return;
		}
	}
	as = Assignmen::assignmen;
	Assignmen *as1 = new Assignmen();
	Person *per = Person::who;

	as1->className = per->className;
	as1->contet = contet;
	as1->course = course;
	as1->time = time;
	as1->startTime = startTime;
	as1->overTime = overTime;
	as1->remark = remark;
	as1->No = No;

	as1->next = as->next;
	as->next = as1;
	as->writeAssignmen(as);
	Assignmen::assignmen = as;
	MessageBox("添加成功！");
}


void StudiesDlg::OnRevampHomework()
{
	CString No;//作业编号
	CString course;//课程名称
	CString contet;//作业内容
	CString time;//作业次数
	CString startTime;//发布时间
	CString overTime;//截止时间
	CString remark;//备注
	GetDlgItem(IDC_EDIT8)->GetWindowText(No);
	GetDlgItem(IDC_EDIT9)->GetWindowText(course);
	GetDlgItem(IDC_EDIT7)->GetWindowText(time);
	GetDlgItem(IDC_EDIT5)->GetWindowText(startTime);
	GetDlgItem(IDC_EDIT11)->GetWindowText(overTime);
	GetDlgItem(IDC_EDIT12)->GetWindowText(contet);
	GetDlgItem(IDC_EDIT6)->GetWindowText(remark);

	if (time == "" || No == "" || course == "" || startTime == "" || overTime == "" || contet == "" || remark == "")
	{
		MessageBox("请完善信息");
	}
	Assignmen *as = Assignmen::assignmen;
	while (as != NULL)
	{
		if (as->No == No)
		{
			as->contet = contet;
			as->course = course;
			as->time = time;
			as->startTime = startTime;
			as->overTime = overTime;
			as->remark = remark;
			as = Assignmen::assignmen;
			as->writeAssignmen(as);
			MessageBox("修改成功");
			return;
		}
		as = as->next;
	}
	MessageBox("修改失败");
}


void StudiesDlg::OnAddStudentHomework()
{
	CString className;//班名
	CString num;//学号
	CString name;//学生姓名
	CString course;//课程名称
	CString No;//作业编号
	CString time;//提交时间
	CString remark;//备注

	GetDlgItem(IDC_EDIT10)->GetWindowText(num);
	GetDlgItem(IDC_EDIT13)->GetWindowText(name);
	GetDlgItem(IDC_EDIT16)->GetWindowText(time);
	GetDlgItem(IDC_EDIT15)->GetWindowText(No);
	GetDlgItem(IDC_EDIT17)->GetWindowText(remark);
	GetDlgItem(IDC_EDIT14)->GetWindowText(course);

	Homework *ho = Homework::homework;

	Homework *ho1 = new Homework();
	Person *per = Person::who;

	ho1->className = per->className;
	ho1->num = num;
	ho1->name = name;
	ho1->course = course;
	ho1->No = No;
	ho1->time = time;
	ho1->remark = remark;

	ho->next = ho1->next;
	ho->next = ho1;
	ho->writeHomework(ho);
	Homework::homework = ho;
	MessageBox("添加成功！");
	
}


void StudiesDlg::OnRevampStudentHomework()
{
	CString className;//班名
	CString num;//学号
	CString name;//学生姓名
	CString course;//课程名称
	CString No;//作业编号
	CString time;//提交时间
	CString remark;//备注

	GetDlgItem(IDC_EDIT10)->GetWindowText(num);
	GetDlgItem(IDC_EDIT13)->GetWindowText(name);
	GetDlgItem(IDC_EDIT16)->GetWindowText(time);
	GetDlgItem(IDC_EDIT15)->GetWindowText(No);
	GetDlgItem(IDC_EDIT17)->GetWindowText(remark);
	GetDlgItem(IDC_EDIT14)->GetWindowText(course);

	Homework *ho = Homework::homework;
	Person *per = Person::who;

	while (ho != NULL)
	{
		if (ho->num == num && ho->No == No)
		{
			ho->name = name;
			ho->course = course;
			ho->time = time;
			ho->remark = remark;
			ho = Homework::homework;
			ho->writeHomework(ho);
			MessageBox("修改成功！");
			return;
		}
		ho = ho->next;
	}
	MessageBox("修改失败！");
}

void StudiesDlg::OnDeleteStudentOrCourse()
{
	CString str;
	int index = m_studentOrCourse.GetCurSel();
	m_studentOrCourse.GetLBText(index, str);

	CString name;
	index = m_studentOrCourseListBox.GetCurSel();
	m_studentOrCourseListBox.GetText(index, name);

	if (str == "学生")
	{
		Person *per = Person::person;
		Person *who = Person::who;
		Person *t = per;
		while (per != NULL)
		{
			if (per->className == who->className && per->name == name)
			{
				if (per == t)
				{
					per = per->next;
					delete t;
					t = NULL;
					per->writePerson(per);
					Person::person = per;
					m_studentOrCourseListBox.DeleteString(index);
					MessageBox("删除成功！");
					return;
				}
				else
				{
					t->next = per->next;
					t = Person::person;
					t->writePerson(t);
					delete per;
					m_studentOrCourseListBox.DeleteString(index);
					MessageBox("删除成功！");
					return;
				}
			}
			t = per;
			per = per->next;
		}
	}
	else
	{
		Course *co = Course::course;
		Course *copy = co;
		while (co != NULL)
		{
			if (co->courseName == name)
			{
				if (co == copy)
				{
					co = co->next;
					co->writeCourse(co);
					Course::course = co;
					delete copy;
					copy = NULL;
					m_studentOrCourseListBox.DeleteString(index);
					MessageBox("删除成功！");
				}
				else
				{
					copy->next = co->next;
					co = Course::course;
					co->writeCourse(co);
					delete co;
					co = NULL;
					m_studentOrCourseListBox.DeleteString(index);
					MessageBox("删除成功！");
				}
			}
		}
	}
	MessageBox("删除成功！");
}


void StudiesDlg::OnDeleteContent()
{
	CString str;
	int index = m_studentOrCourse.GetCurSel();
	m_studentOrCourse.GetLBText(index, str);
	
	CString cstr;
	index = m_homeWordContent.GetCurSel();
	m_homeWordContent.GetText(index, cstr);

	if (str == "学生")
	{
		Homework *ho = Homework::homework;
		Homework *copy = ho;
		Person *per = Person::who;

		CString num, name, course, No, time, remark, className;
		AfxExtractSubString(className, cstr, 0, ' ');
		AfxExtractSubString(num, cstr, 1, ' ');
		AfxExtractSubString(name, cstr, 2, ' ');
		AfxExtractSubString(No, cstr, 3, ' ');
		AfxExtractSubString(course, cstr, 4, ' ');
		AfxExtractSubString(time, cstr, 5, ' ');
		AfxExtractSubString(remark, cstr, 6, ' ');

		while (ho != NULL)
		{
			if (ho->className == per->className && ho->course == course && ho->num == num
				&& ho->No == No &&ho->time == time && ho->remark == remark && ho->name == name)
			{
				if (ho == copy)
				{
					ho = ho->next;
					ho->writeHomework(ho);
					Homework::homework = ho;
					delete copy;
					copy = NULL;
					m_homeWordContent.DeleteString(index);
					MessageBox("删除成功！");
					return;
				}
				else
				{
					copy->next = ho->next;
					delete ho;
					ho = Homework::homework;
					ho->writeHomework(ho);
					m_homeWordContent.DeleteString(index);
					MessageBox("删除成功！");
					return;
				}
			}
			copy = ho;
			ho = ho->next;
		}
		MessageBox("删除失败！");
		return;
	}
	else
	{
		Assignmen *as = Assignmen::assignmen;
		Assignmen *copy = as;
		Person *per = Person::who;
		
		CString No;//作业编号
		CString course;//课程名称
		CString contet;//作业内容
		CString time;//作业次数
		CString startTime;//发布时间
		CString overTime;//截止时间
		CString remark;//备注
		CString className;//班级

		AfxExtractSubString(No, cstr, 0, ' ');
		AfxExtractSubString(course, cstr, 0, ' ');
		AfxExtractSubString(contet, cstr, 0, ' ');
		AfxExtractSubString(time, cstr, 0, ' ');
		AfxExtractSubString(startTime, cstr, 0, ' ');
		AfxExtractSubString(overTime, cstr, 0, ' ');
		AfxExtractSubString(remark, cstr, 0, ' ');

		while (as != NULL)
		{
			if (per->className == as->className && as->No == No && as->course == course && as->time == time
				&& as->startTime == startTime && as->overTime == overTime && as->remark == remark)
			{
				if (copy == as)
				{
					as = as->next;
					as->writeAssignmen(as);
					Assignmen::assignmen = as;
					delete copy;
					m_homeWordContent.DeleteString(index);
					MessageBox("删除成功！");
					return;
				}
				else
				{
					copy->next = as->next;
					delete as;
					as = Assignmen::assignmen;
					as->writeAssignmen(as);
					m_homeWordContent.DeleteString(index);
					MessageBox("删除成功！");
					return;
				}
			}
			as = as->next;
		}
		MessageBox("删除失败！");
		return;

	}

}




void StudiesDlg::OnRadioPublish()
{
	//UpdateData(true);
	//switch (m_radioPublish)
	//{
	//case 0:
	//	MessageBox("升");
	//	break;
	//case 1:
	//	MessageBox("降");
	//default:
	//	break;
	//}
}


void StudiesDlg::OnRadioSubimt()
{
	//UpdateData(true);
	//switch (m_RadioSubimt)
	//{
	//case 0:
	//	MessageBox("升");
	//	break;
	//case 1:
	//	MessageBox("降");
	//default:
	//	break;
	//}
}
