#pragma once


// StrudentDlg �Ի���

class StrudentDlg : public CDialogEx
{
	DECLARE_DYNAMIC(StrudentDlg)

public:
	StrudentDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~StrudentDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
