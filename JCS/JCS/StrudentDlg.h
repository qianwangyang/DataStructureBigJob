#pragma once
#include "afxwin.h"


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
public:
	// �ύ���
	CListBox m_submitCase;
	afx_msg void OnSubmitHomework();
	// �γ�����
	CString m_course;
	// ��ҵ����
	CString m_No;
	// �ύʱ��
	CString m_time;
	// ��ע
	CString m_remark;
	// ��ҵ����
	CString m_notice;
};
