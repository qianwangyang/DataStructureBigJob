#pragma once


// adDlg 对话框

class adDlg : public CDialogEx
{
	DECLARE_DYNAMIC(adDlg)

public:
	adDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~adDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLbnSelchangeList3();
};
