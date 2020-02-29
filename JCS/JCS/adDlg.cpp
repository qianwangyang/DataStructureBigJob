// adDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "JCS.h"
#include "adDlg.h"
#include "afxdialogex.h"


// adDlg 对话框

IMPLEMENT_DYNAMIC(adDlg, CDialogEx)

adDlg::adDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(adDlg::IDD, pParent)
	, m_addClassEdit(_T(""))
	, m_searchClassEdit(_T(""))
	, m_beforeEdit(_T(""))
	, m_afterEdit(_T(""))
	, m_idEdil(_T(""))
	, m_name(_T(""))
	, m_pw(_T(""))
	, m_status(_T(""))
{

}

adDlg::~adDlg()
{
}

void adDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST2, m_clasListBox);
	DDX_Control(pDX, IDC_LIST3, m_studentListBox);
	DDX_Text(pDX, IDC_EDIT5, m_addClassEdit);
	DDX_Text(pDX, IDC_EDIT2, m_searchClassEdit);
	DDX_Text(pDX, IDC_EDIT3, m_beforeEdit);
	DDX_Text(pDX, IDC_EDIT4, m_afterEdit);
	DDX_Text(pDX, IDC_EDIT9, m_idEdil);
	DDX_Text(pDX, IDC_EDIT8, m_name);
	DDX_Text(pDX, IDC_EDIT7, m_pw);
	DDX_Text(pDX, IDC_EDIT10, m_status);
	DDX_Control(pDX, IDC_EDIT6, m_searchStudentEdit);
}


BEGIN_MESSAGE_MAP(adDlg, CDialogEx)
	ON_LBN_SELCHANGE(IDC_LIST3, &adDlg::OnLbnSelchangeList3)//函数绑定
	ON_LBN_SELCHANGE(IDC_LIST2, &adDlg::OnSelectClassChange)
	ON_BN_CLICKED(IDC_BUTTON1, &adDlg::OnDeleteClass)
	ON_BN_CLICKED(IDC_BUTTON4, &adDlg::OnDeleteStudent)
	ON_BN_CLICKED(IDC_BUTTON9, &adDlg::OnAddClass)
END_MESSAGE_MAP()


// adDlg 消息处理程序


void adDlg::OnLbnSelchangeList3()//学生列表改变函数
{
	// TODO:  在此添加控件通知处理程序代码
}


void adDlg::OnSelectClassChange()
{
	// TODO:  在此添加控件通知处理程序代码
}


void adDlg::OnDeleteClass()
{
	// TODO:  在此添加控件通知处理程序代码
}


void adDlg::OnDeleteStudent()
{
	// TODO:  在此添加控件通知处理程序代码
}


void adDlg::OnAddClass()
{
	// TODO:  在此添加控件通知处理程序代码
}
