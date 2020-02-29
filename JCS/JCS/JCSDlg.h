
// JCSDlg.h : 头文件
//

#pragma once


// CJCSDlg 对话框
class CJCSDlg : public CDialogEx
{
// 构造
public:
	CJCSDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_JCS_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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
