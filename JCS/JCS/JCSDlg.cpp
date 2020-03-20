
// JCSDlg.cpp : ʵ���ļ�
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


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CJCSDlg �Ի���



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

BEGIN_MESSAGE_MAP(CJCSDlg, CDialogEx)//������
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CJCSDlg::logIn)
	ON_BN_CLICKED(IDC_RADIO1, &CJCSDlg::radioAd)
	ON_BN_CLICKED(IDC_RADIO2, &CJCSDlg::radioSC)
	ON_BN_CLICKED(IDC_RADIO3, &CJCSDlg::radioS)
END_MESSAGE_MAP()


// CJCSDlg ��Ϣ�������

BOOL CJCSDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������
	CFont font;
	font.CreatePointFont(400, "����");
	temp[0].SetFont(&font);

	//��ClassList��

	ClassList *read = new ClassList();
	int a = read->readClassList(read);
	ClassList::classList = read;

	////��Person������
	Person *readPerson = new Person();
	readPerson->readPerson(readPerson);
	Person::person = readPerson;
	Person::who = readPerson;

	//��Course����
	Course *course = new Course();
	course->readCourse(course);
	Course::course = course;

	//��homework������
	Homework *homework = new Homework();
	homework->readHomework(homework);
	Homework::homework = homework;

	//��Assignmen��
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

	//Assignmen�������
	//Assignmen *as1 = new Assignmen();
	//Assignmen *as2 = new Assignmen();
	//Assignmen *as3 = new Assignmen();
	//as1->No = "001";
	//as1->course = "���ݽṹ";
	//as1->contet = "��ҵһ";
	//as1->time = "1";
	//as1->startTime = "2020-3-17";
	//as1->overTime = "2020-3-20";
	//as1->remark = "�ǵý�";
	//as1->className = "�ƿ�һ��";
	//as1->next = as2;

	//as2->No = "002";
	//as2->course = "����";
	//as2->contet = "��ҵһ";
	//as2->time = "1";
	//as2->startTime = "2020-3-17";
	//as2->overTime = "2020-3-20";
	//as2->remark = "�ǵý�";
	//as2->className = "�ƿ�һ��";
	//as2->next = as3;

	//as3->No = "003";
	//as3->course = "���Դ���";
	//as3->contet = "��ҵһ";
	//as3->time = "1";
	//as3->startTime = "2020-3-17";
	//as3->overTime = "2020-3-20";
	//as3->remark = "�ǵý�";
	//as1->className = "�ƿ�һ��";
	//as3->next = NULL;

	//as1->writeAssignmen(as1);

	//homework�������
	//Homework *ho1 = new Homework();
	//Homework *ho2 = new Homework();
	//Homework *ho3 = new Homework();

	//ho1->className = "�ƿ�һ��";
	//ho1->num = "1";
	//ho1->name = "��ǧ��";
	//ho1->course = "���ݽṹ";
	//ho1->No = "001";
	//ho1->time = "2020-3-19";
	//ho1->remark = "�Ѿ���";

	//ho2->className = "�ƿ�һ��";
	//ho2->num = "3";
	//ho2->name = "���½�";
	//ho2->course = "����";
	//ho2->No = "002";
	//ho2->time = "2020-3-19";
	//ho2->remark = "�Ѿ���";

	//ho3->className = "�ƿ�һ��";
	//ho3->num = "5";
	//ho3->name = "������";
	//ho3->course = "���Դ���";
	//ho3->No = "001";
	//ho3->time = "2020-3-19";
	//ho3->remark = "�Ѿ���";

	//ho1->writeHomework(ho1);


	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CJCSDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CJCSDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CJCSDlg::logIn()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CString pw;
	CString num;
	Person *per = Person::person;
	int judge = 1;
	GetDlgItem(IDC_EDIT1)->GetWindowTextA(num);
	GetDlgItem(IDC_EDIT2)->GetWindowTextA(pw);

	StudiesDlg *studies = new StudiesDlg();
	studies->Create(IDD_DIALOG3, this);
	studies->ShowWindow(SW_SHOW);

	switch (m_radio)
	{
	case 0:
		MessageBox("��ѡ����ݣ�");
		break;
	case 1:
		if (pw == "000" && num == "000")
		{
			adDlg *ad = new adDlg();
			ad->Create(IDD_DIALOG1, this);
			ad->ShowWindow(SW_SHOW);
		}
		else
		{
			MessageBox("��������");
		}
		break;
	case 2:
		judge = 1;
		per = Person::person;
		while (per->next != NULL)
		{
			if (per->num == num && per->pw == pw && per->status == "ѧί")
			{
				StudiesDlg *studies = new StudiesDlg();
				studies->Create(IDD_DIALOG3, this);
				studies->ShowWindow(SW_SHOW);
				judge = 0;
				break;
			}
			per = per->next;
		}
		if (judge)
		{
			MessageBox("��������!");
		}
		break;
	case 3 :
		judge = 1;
		per = Person::person;
		while (per->next != NULL)
		{
			if (per->num == num && per->pw == pw && per->status == "ѧ��")
			{
				StrudentDlg *student = new StrudentDlg();
				student->Create(IDD_DIALOG2, this);
				student->ShowWindow(SW_SHOW);
				judge = 0;
				break;
			}
			per = per->next;
		}
		if (judge)
		{
			MessageBox("��������");
		}
		break;
	}
	


}


void CJCSDlg::radioAd()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_radio = 1;
}


void CJCSDlg::radioSC()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_radio = 2;
}


void CJCSDlg::radioS()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_radio = 3;
}
