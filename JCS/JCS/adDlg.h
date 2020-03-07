#pragma once
#include "afxwin.h"


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
	afx_msg void OnLbnSelchangeList3();//学生ListBox响应函数
	CListBox m_clasListBox;//班级ListBox
	CListBox m_studentListBox;//学生ListBox
	afx_msg void OnSelectClassChange();//班级ListBox响应函数
	afx_msg void OnDeleteClass();//删除班级按钮
	afx_msg void OnDeleteStudent();//删除学生按钮
	CString m_addClassEdit;//添加班级编辑框
	CString m_searchClassEdit;//班级查询编辑框
	CString m_beforeEdit;//修改前编辑框
	CString m_afterEdit;//修改后编辑框
	CString m_idEdil;//学号
	CString m_name;//姓名
	CString m_pw;//密码
	CString m_status;//状态
	CEdit m_searchStudentEdit;//查询学生编辑框

	afx_msg void OnAddClass();//添加班级按钮
	afx_msg void OnSearchClass();//查询班级
	afx_msg void OnRevampClass();//修改班级
	afx_msg void OnAddStudent();//添加学生
	afx_msg void OnRevampStudent();//修改学生 
	afx_msg void OnSearchStudent();//查询学生
	CString m_classNameEdit;//学生班级Edit
};
