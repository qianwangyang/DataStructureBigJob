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

	m_studentOrCourse.AddString("课程");
	m_studentOrCourse.AddString("学生");
	m_studentOrCourse.SetCurSel(0);

	Course *co = Course::course;
	while (co->next != NULL)
	{
		m_studentOrCourseListBox.AddString(co->courseName);
		co = co->next;
	}

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
			if (homework->name == name && per->className == homework->className)
			{
				m_homeWordContent.AddString(homework->className + " " + homework->num 
					+ " " + homework->name + " " + homework->course + " " 
					+ homework->No + " " + homework->time + " " + homework->remark);
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
	// TODO:  在此添加控件通知处理程序代码
}


void StudiesDlg::OnSearchPublishByCourse()
{
	// TODO:  在此添加控件通知处理程序代码
}


void StudiesDlg::OnSearchSubimtByTime()
{
	// TODO:  在此添加控件通知处理程序代码
}


void StudiesDlg::OnSearchSubmitByCourse()
{
	// TODO:  在此添加控件通知处理程序代码
}


void StudiesDlg::OnPublishHomework()
{
	// TODO:  在此添加控件通知处理程序代码
}


void StudiesDlg::OnRevampHomework()
{
	// TODO:  在此添加控件通知处理程序代码
}


void StudiesDlg::OnAddStudentHomework()
{
	// TODO:  在此添加控件通知处理程序代码
}


void StudiesDlg::OnRevampStudentHomework()
{
	// TODO:  在此添加控件通知处理程序代码
}
