#pragma once


// StudiesDlg �Ի���

class StudiesDlg : public CDialogEx
{
	DECLARE_DYNAMIC(StudiesDlg)

public:
	StudiesDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~StudiesDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
