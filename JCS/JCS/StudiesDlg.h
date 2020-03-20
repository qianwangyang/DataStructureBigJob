#pragma once
#include "afxwin.h"


// StudiesDlg �Ի���

class StudiesDlg : public CDialogEx
{
	DECLARE_DYNAMIC(StudiesDlg)

public:
	StudiesDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~StudiesDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	// �γ̻�༶
	//CComboBox m_courseOrClass;
	CComboBox m_studentOrCourse;
	//ѡ��༶��γ���Ӧ����
	//afx_msg void OnSelectCourseOrClass();
	afx_msg void OnSelectStudentOrCourse();
	// �γ̻�༶ListBox
	//CListBox m_courseOrClassListBox;
	CListBox m_studentOrCourseListBox;
	//afx_msg void OnSelectClassOrCourseListBox();//�γ̻�༶ListBox
	afx_msg void OnSelectStudentOrCourseListBox();
	//��ҵ����
	CListBox m_homeWordContent;
	afx_msg void OnSelectHomeWordContent();//��ϸ����
	// ��ѯ��������ҵ
	CListBox m_SearchPublish;
	afx_msg void OnSearchPublish();//��ѯ������ҵ��ListBox
	//��ѯѧ���ύ����ҵ
	CListBox m_SearchSubmit;
	afx_msg void OnSearchSubmit();//��ѯ�ύ��ҵ��ListBox
	//����ʱ�䷶Χ��ѯ
	CString m_PublishTime;
	//������ҵ�γ����Ʋ�ѯ
	CString m_PublishCourse;
	// ѧ���ύʱ�䷶Χ��ѯ
	CString m_SubmitTime;
	// ѧ���ύ�γ�����ѯEdit
	CString m_SubmitCourse;
	// //��������ĵ���ҵ���
	CString m_publishCourseNumEdit;
	// //��������ĵĿγ�����
	CString m_publishCourseNameEdit;
	// ��������ĵ���ҵ����
	CString m_PublishTimesEdit;
	// ����ʱ��
	CString m_publishStartTime;
	// ��ֹʱ��
	CString m_stopTime;
	// ������ҵ����
	CString m_publishContent;
	// ��ӻ����ѧ��ѧ��
	CString m_submitNum;
	// ��ӻ����ѧ������
	CString m_submitName;
	// ��ӻ��޸�ѧ�����ύʱ��
	CString m_timeOfSubmit;
	// ��ӻ��޸�ѧ������ҵ���
	CString m_submitNo;
	// ��ӻ��޸�ѧ���ύ����ҵ��ע
	CString m_submitNotes;
	// ��ҵ�ύ���ͳ��
	CString m_statistics;
	afx_msg void OnSearchPublishByTime();//ͨ��ʱ�䷶Χ��ѯ������ҵ
	afx_msg void OnSearchPublishByCourse();//ͨ���γ����Ʋ�ѯ������ҵ
	afx_msg void OnSearchSubimtByTime();//ͨ��ʱ�䷶Χ����ѧ���ύ����ҵ
	afx_msg void OnSearchSubmitByCourse();//ͨ���γ����Ʋ���
	afx_msg void OnPublishHomework();//������ҵ
	afx_msg void OnRevampHomework();//�޸ķ�������ҵ
	afx_msg void OnAddStudentHomework();//���ѧ���ύ����ҵ
	afx_msg void OnRevampStudentHomework();//�޸�ѧ���ύ����ҵ
	// ������ҵ��ѡ��
	int m_radioPublish;
	afx_msg void OnRadioPublish();
	// �ύ��ҵ����
	int m_RadioSubimt;
	afx_msg void OnRadioSubimt();

	int judgeFirst = 1;
	// ������ҵ��ѯʱ�䷶Χ��
	CString m_publishOver;
	// ѧ���ύ��ҵʱ�䷶Χ��
	CString m_subimtOver;
	// ѧ���ύ��ҵ�������
	CComboBox m_refer;
	// ������ҵ�ı�ע
	CString m_publishRemark;
	// ѧ���ύ��ҵ�Ŀ�Ŀ
	CString m_submitCourse;
	afx_msg void OnDeleteStudentOrCourse();
	afx_msg void OnDeleteContent();
};
