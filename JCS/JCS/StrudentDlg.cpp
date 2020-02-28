// StrudentDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "JCS.h"
#include "StrudentDlg.h"
#include "afxdialogex.h"


// StrudentDlg 对话框

IMPLEMENT_DYNAMIC(StrudentDlg, CDialogEx)

StrudentDlg::StrudentDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(StrudentDlg::IDD, pParent)
{

}

StrudentDlg::~StrudentDlg()
{
}

void StrudentDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(StrudentDlg, CDialogEx)
END_MESSAGE_MAP()


// StrudentDlg 消息处理程序
