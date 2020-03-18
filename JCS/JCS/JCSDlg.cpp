
// JCSDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "JCS.h"
#include "JCSDlg.h"
#include "afxdialogex.h"
#include "adDlg.h"
#include "StrudentDlg.h"
#include "StudiesDlg.h"
#include "person.h"
#include "Course.h"
#include "classList.h"
#include "Assignmen.h"
#include "homework.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CJCSDlg 对话框



CJCSDlg::CJCSDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CJCSDlg::IDD, pParent)
	, m_ID(_T(""))
	, m_ps(_T(""))
	, m_ad(0)
	, m_sc(0)
	, m_s(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CJCSDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_ID);
	DDX_Text(pDX, IDC_EDIT2, m_ps);
	DDX_Control(pDX, IDC_STATIC1, temp[0]);
	DDX_Control(pDX, IDC_STATIC2, temp[1]);
	DDX_Control(pDX, IDC_STATIC3, temp[2]);
}

BEGIN_MESSAGE_MAP(CJCSDlg, CDialogEx)//函数绑定
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CJCSDlg::logIn)
	ON_BN_CLICKED(IDC_RADIO1, &CJCSDlg::radioAd)
	ON_BN_CLICKED(IDC_RADIO2, &CJCSDlg::radioSC)
	ON_BN_CLICKED(IDC_RADIO3, &CJCSDlg::radioS)
END_MESSAGE_MAP()


// CJCSDlg 消息处理程序

BOOL CJCSDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码
	CFont font;
	font.CreatePointFont(400, "宋体");
	temp[0].SetFont(&font);

	//读ClassList类

	ClassList *read = new ClassList();
	int a = read->readClassList(read);
	ClassList::classList = read;

	////读Person类数据
	Person *readPerson = new Person();
	readPerson->readPerson(readPerson);
	Person::person = readPerson;
	Person::who = readPerson;

	//读Course数据
	Course *course = new Course();
	course->readCourse(course);
	Course::course = course;

	//读homework类数据
	Homework *homework = new Homework();
	homework->readHomework(homework);
	Homework::homework = homework;

	//读Assignmen类
	//Assignmen *assignmen = new Assignmen();
	//assignmen->readAssignmen(assignmen);
	//Assignmen::assignmen = assignmen;

	//while (homework != NULL)
	//{
	//	MessageBox(homework->className);
	//	MessageBox(homework->name);
	//	MessageBox(homework->remark);
	//	homework = homework->next;
	//}

	//while (assignmen != NULL)
	//{
	//	MessageBox(assignmen->course);
	//	MessageBox(assignmen->remark);
	//	assignmen = assignmen->next;
	//}

	//Assignmen虚假数据
	//Assignmen *as1 = new Assignmen();
	//Assignmen *as2 = new Assignmen();
	//Assignmen *as3 = new Assignmen();
	//as1->No = "001";
	//as1->course = "数据结构";
	//as1->contet = "作业一";
	//as1->time = "1";
	//as1->startTime = "2020-3-17";
	//as1->overTime = "2020-3-20";
	//as1->remark = "记得交";
	//as1->className = "计科一班";
	//as1->next = as2;

	//as2->No = "002";
	//as2->course = "高数";
	//as2->contet = "作业一";
	//as2->time = "1";
	//as2->startTime = "2020-3-17";
	//as2->overTime = "2020-3-20";
	//as2->remark = "记得交";
	//as2->className = "计科一班";
	//as2->next = as3;

	//as3->No = "003";
	//as3->course = "线性代数";
	//as3->contet = "作业一";
	//as3->time = "1";
	//as3->startTime = "2020-3-17";
	//as3->overTime = "2020-3-20";
	//as3->remark = "记得交";
	//as1->className = "计科一班";
	//as3->next = NULL;

	//as1->writeAssignmen(as1);

	//homework虚假数据
	//Homework *ho1 = new Homework();
	//Homework *ho2 = new Homework();
	//Homework *ho3 = new Homework();

	//ho1->className = "计科一班";
	//ho1->num = "1";
	//ho1->name = "杨千旺";
	//ho1->course = "数据结构";
	//ho1->No = "001";
	//ho1->time = "2020-3-19";
	//ho1->remark = "已经交";

	//ho2->className = "计科一班";
	//ho2->num = "3";
	//ho2->name = "苏新杰";
	//ho2->course = "高数";
	//ho2->No = "002";
	//ho2->time = "2020-3-19";
	//ho2->remark = "已经交";

	//ho3->className = "计科一班";
	//ho3->num = "5";
	//ho3->name = "邹龙生";
	//ho3->course = "线性代数";
	//ho3->No = "001";
	//ho3->time = "2020-3-19";
	//ho3->remark = "已经交";

	//ho1->writeHomework(ho1);


	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CJCSDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CJCSDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CJCSDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CJCSDlg::logIn()
{
	// TODO:  在此添加控件通知处理程序代码
	CString pw;
	CString num;
	Person *per = Person::person;
	int judge = 1;
	GetDlgItem(IDC_EDIT1)->GetWindowTextA(num);
	GetDlgItem(IDC_EDIT2)->GetWindowTextA(pw);

	StudiesDlg *studies = new StudiesDlg();
	studies->Create(IDD_DIALOG3, this);
	studies->ShowWindow(SW_SHOW);

	//switch (m_radio)
	//{
	//case 0:
	//	MessageBox("请选择身份！");
	//	break;
	//case 1:
	//	if (pw == "000" && num == "000")
	//	{
	//		adDlg *ad = new adDlg();
	//		ad->Create(IDD_DIALOG1, this);
	//		ad->ShowWindow(SW_SHOW);
	//	}
	//	else
	//	{
	//		MessageBox("输入有误！");
	//	}
	//	break;
	//case 2:
	//	judge = 1;
	//	per = Person::person;
	//	while (per->next != NULL)
	//	{
	//		if (per->num == num && per->pw == pw && per->status == "学委")
	//		{
	//			StudiesDlg *studies = new StudiesDlg();
	//			studies->Create(IDD_DIALOG3, this);
	//			studies->ShowWindow(SW_SHOW);
	//			judge = 0;
	//			break;
	//		}
	//		per = per->next;
	//	}
	//	if (judge)
	//	{
	//		MessageBox("输入有误!");
	//	}
	//	break;
	//case 3 :
	//	judge = 1;
	//	per = Person::person;
	//	while (per->next != NULL)
	//	{
	//		if (per->num == num && per->pw == pw && per->status == "学生")
	//		{
	//			StrudentDlg *student = new StrudentDlg();
	//			student->Create(IDD_DIALOG2, this);
	//			student->ShowWindow(SW_SHOW);
	//			judge = 0;
	//			break;
	//		}
	//		per = per->next;
	//	}
	//	if (judge)
	//	{
	//		MessageBox("输入有误！");
	//	}
	//	break;
	//}
	//


}


void CJCSDlg::radioAd()
{
	// TODO:  在此添加控件通知处理程序代码
	m_radio = 1;
}


void CJCSDlg::radioSC()
{
	// TODO:  在此添加控件通知处理程序代码
	m_radio = 2;
}


void CJCSDlg::radioS()
{
	// TODO:  在此添加控件通知处理程序代码
	m_radio = 3;
}
