
// JCSDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "JCS.h"
#include "JCSDlg.h"
#include "afxdialogex.h"
#include "adDlg.h"

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

	//tow *to = new tow;
	//to->Create(IDD_DIALOG1, this);//第一个参数为打开窗口的ID号
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
	//	MessageBox("未选择身份");
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
