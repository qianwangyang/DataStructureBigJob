
// JCSDlg.h : ͷ�ļ�
//

#pragma once


// CJCSDlg �Ի���
class CJCSDlg : public CDialogEx
{
// ����
public:
	CJCSDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_JCS_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString m_ID;
	CString m_ps;
	int m_ad = 0;
	int m_sc = 0;
	int m_s = 0;
	CStatic temp[3];
	//Person *per;
	int m_radio = 0;
	afx_msg void logIn();
	afx_msg void radioAd();
	afx_msg void radioSC();
	afx_msg void radioS();
};
