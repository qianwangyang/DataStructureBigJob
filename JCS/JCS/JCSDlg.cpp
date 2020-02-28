
// JCSDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "JCS.h"
#include "JCSDlg.h"
#include "afxdialogex.h"
#include "adDlg.h"

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

	//tow *to = new tow;
	//to->Create(IDD_DIALOG1, this);//��һ������Ϊ�򿪴��ڵ�ID��
	//to->ShowWindow(SW_SHOW);

	//adDlg *ad = new adDlg();
	//ad->Create(IDD_DIALOG1, this);
	//ad->ShowWindow(SW_SHOW);
	
	//char *name = "abc";
	//CString str(name);
	////CString csr = NULL;
	//MessageBox(str);
	//switch (m_radio)
	//{
	//case 0 :
	//	MessageBox("δѡ�����");
	//	break;
	//case 1 :
	//	MessageBox("1");
	//	break;
	//case 2 :
	//	MessageBox("2");
	//	break;
	//case 3:
	//	MessageBox("3");
	//	break;
	//}
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
