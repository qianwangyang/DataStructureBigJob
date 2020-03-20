#pragma once
#include "afxwin.h"


// StrudentDlg 对话框

class StrudentDlg : public CDialogEx
{
	DECLARE_DYNAMIC(StrudentDlg)

public:
	StrudentDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~StrudentDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	// 提交情况
	CListBox m_submitCase;
	afx_msg void OnSubmitHomework();
	// 课程名称
	CString m_course;
	// 作业编码
	CString m_No;
	// 提交时间
	CString m_time;
	// 备注
	CString m_remark;
	// 作业公告
	CString m_notice;
};
