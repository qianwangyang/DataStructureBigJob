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
END_MESSAGE_MAP()


// adDlg 消息处理程序
