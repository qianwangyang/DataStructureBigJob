#pragma once


// adDlg �Ի���

class adDlg : public CDialogEx
{
	DECLARE_DYNAMIC(adDlg)

public:
	adDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~adDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
