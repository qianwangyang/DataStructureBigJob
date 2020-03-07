#pragma once
#include "afxwin.h"


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
public:
	// 课程或班级
	//CComboBox m_courseOrClass;
	CComboBox m_studentOrCourse;
	//选择班级或课程响应函数
	//afx_msg void OnSelectCourseOrClass();
	afx_msg void OnSelectStudentOrCourse();
	// 课程或班级ListBox
	//CListBox m_courseOrClassListBox;
	CListBox m_studentOrCourseListBox;
	//afx_msg void OnSelectClassOrCourseListBox();//课程或班级ListBox
	afx_msg void OnSelectStudentOrCourseListBox();
	//作业内容
	CListBox m_homeWordContent;
	afx_msg void OnSelectHomeWordContent();//详细内容
	// 查询发布的作业
	CListBox m_SearchPublish;
	afx_msg void OnSearchPublish();//查询发布作业的ListBox
	// //查询学生提交的作业
	CListBox m_SearchSubmit;
	afx_msg void OnSearchSubmit();//查询提交作业的ListBox
	//发布时间范围查询
	CString m_PublishTime;
	//发布作业课程名称查询
	CString m_PublishCourse;
	// 学生提交时间范围查询
	CString m_SubmitTime;
	// 学生提交课程名查询Edit
	CString m_SubmitCourse;
	// //发布或更改的作业编号
	CString m_publishCourseNumEdit;
	// //发布或更改的课程名称
	CString m_publishCourseNameEdit;
	// 发布或更改的作业次数
	CString m_PublishTimesEdit;
	// 发布时间
	CString m_publishStartTime;
	// 截止时间
	CString m_stopTime;
	// 发布作业内容
	CString m_publishContent;
};
