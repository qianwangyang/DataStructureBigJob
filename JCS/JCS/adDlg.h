#pragma once
#include "afxwin.h"


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
public:
	afx_msg void OnLbnSelchangeList3();
	CListBox m_clasListBox;//�༶ListBox
	CListBox m_studentListBox;//ѧ��ListBox
	afx_msg void OnSelectClassChange();
	afx_msg void OnDeleteClass();
	afx_msg void OnDeleteStudent();
	CString m_addClassEdit;//��Ӱ༶�༭��
	CString m_searchClassEdit;//�༶��ѯ�༭��
	CString m_beforeEdit;//�޸�ǰ�༭��
	CString m_afterEdit;//�޸ĺ�༭��
	CString m_idEdil;//ѧ��
	CString m_name;//����
	CString m_pw;//����
	CString m_status;//״̬
	CEdit m_searchStudentEdit;//��ѯѧ���༭��
	afx_msg void OnAddClass();//��Ӱ༶��ť
};
