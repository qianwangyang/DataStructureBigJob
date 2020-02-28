#pragma once


// StudiesDlg 对话框

class StudiesDlg : public CDialogEx
{
	DECLARE_DYNAMIC(StudiesDlg)

public:
	StudiesDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~StudiesDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
