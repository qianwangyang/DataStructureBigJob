// adDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "JCS.h"
#include "adDlg.h"
#include "afxdialogex.h"


// adDlg �Ի���

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


// adDlg ��Ϣ�������


void adDlg::OnLbnSelchangeList3()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
