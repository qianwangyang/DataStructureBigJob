#pragma once


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
};
