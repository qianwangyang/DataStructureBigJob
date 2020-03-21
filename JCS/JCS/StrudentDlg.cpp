// StrudentDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "JCS.h"
#include "StrudentDlg.h"
#include "homework.h"
#include "person.h"
#include "Assignmen.h"
#include "Course.h"
#include "classList.h"
#include "afxdialogex.h"


// StrudentDlg 对话框

IMPLEMENT_DYNAMIC(StrudentDlg, CDialogEx)

StrudentDlg::StrudentDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(StrudentDlg::IDD, pParent)
	, m_course(_T(""))
	, m_No(_T(""))
	, m_time(_T(""))
	, m_remark(_T(""))
	, m_notice(_T(""))
{

}

StrudentDlg::~StrudentDlg()
{
}

void StrudentDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_submitCase);
	DDX_Text(pDX, IDC_EDIT2, m_course);
	DDX_Text(pDX, IDC_EDIT3, m_No);
	DDX_Text(pDX, IDC_EDIT1, m_time);
	DDX_Text(pDX, IDC_EDIT4, m_remark);
	DDX_Text(pDX, IDC_EDIT5, m_notice);

	m_submitCase.ResetContent();
	Homework *ho = Homework::homework;
	Assignmen *as = Assignmen::assignmen;
	Person *per = Person::who;
	while (ho != NULL)
	{
		if (ho->num == per->num &&ho->name == per->name && ho->className == per->className)
		{
			m_submitCase.AddString(ho->className + " " + ho->name + " " + ho->course + " " + ho->No + " " + ho->time + " " + ho->remark);
		}
		ho = ho->next;
	}
	CString content;
	while (as != NULL)
	{
		if (as->className == per->className)
		{
			content += as->course + " " + as->No+ " " + as->contet + " " + as->remark + " " + as->startTime + " " + as->overTime + "\r\n";
		}
		as = as->next;
	}
	GetDlgItem(IDC_EDIT5)->SetWindowTextA(content);
}


BEGIN_MESSAGE_MAP(StrudentDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &StrudentDlg::OnSubmitHomework)
END_MESSAGE_MAP()


// StrudentDlg 消息处理程序


void StrudentDlg::OnSubmitHomework()
{
	UpdateData(true);
	Homework *ho = new Homework();
	Person *per = Person::who;
	if (m_course == "" || m_No == "" || m_time == "" || m_remark == "")
	{
		MessageBox("请完善信息！");
		return;
	}
	ho->className = per->className;
	ho->name = per->name;
	ho->num = per->num;
	ho->course = m_course;
	ho->No = m_No;
	ho->time = m_time;
	ho->remark = m_remark;

	Homework *head = Homework::homework;
	if (head->No == "")
	{
		head = ho;
		head->writeHomework(head);
		Homework::homework = head;
	}
	else
	{
		ho->next = head->next;
		head->next = ho;
		head->writeHomework(head);
		Homework::homework = head;
	}
	m_submitCase.AddString(ho->className + " " + ho->name + " " + ho->course + " " + ho->No + " " + ho->time + " " + ho->remark);
	MessageBox("提交成功！");
	UpdateData(false);
}
