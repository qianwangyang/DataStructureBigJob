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
{

}

adDlg::~adDlg()
{
}

void adDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(adDlg, CDialogEx)
	ON_LBN_SELCHANGE(IDC_LIST3, &adDlg::OnLbnSelchangeList3)
END_MESSAGE_MAP()


// adDlg 消息处理程序


void adDlg::OnLbnSelchangeList3()
{
	// TODO:  在此添加控件通知处理程序代码
}
