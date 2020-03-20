// adDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "JCS.h"
#include "adDlg.h"
#include "classList.h"
#include "person.h"
#include "afxdialogex.h"


// adDlg 对话框

IMPLEMENT_DYNAMIC(adDlg, CDialogEx)

adDlg::adDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(adDlg::IDD, pParent)
	, m_addClassEdit(_T(""))
	, m_searchClassEdit(_T(""))
	, m_beforeEdit(_T(""))
	, m_afterEdit(_T(""))
	, m_idEdil(_T(""))
	, m_name(_T(""))
	, m_pw(_T(""))
	, m_status(_T(""))
	, m_classNameEdit(_T(""))
{
	/*ClassList *classList = new ClassList();
	ClassList *classHead = new ClassList();
	classList->readClassList(classHead);
	ClassList::classList = classHead;
	while (classHead->getNext() != NULL)
	{
		classHead = classHead->getNext();
		m_clasListBox.AddString(classHead->getClassName());
	}*/
	//m_clasListBox.AddString("aaaa0");
}

adDlg::~adDlg()
{
}

void adDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST2, m_clasListBox);
	DDX_Control(pDX, IDC_LIST3, m_studentListBox);
	DDX_Text(pDX, IDC_EDIT5, m_addClassEdit);
	DDX_Text(pDX, IDC_EDIT2, m_searchClassEdit);
	DDX_Text(pDX, IDC_EDIT3, m_beforeEdit);
	DDX_Text(pDX, IDC_EDIT4, m_afterEdit);
	DDX_Text(pDX, IDC_EDIT9, m_idEdil);
	DDX_Text(pDX, IDC_EDIT8, m_name);
	DDX_Text(pDX, IDC_EDIT7, m_pw);
	DDX_Text(pDX, IDC_EDIT10, m_status);
	DDX_Control(pDX, IDC_EDIT6, m_searchStudentEdit);
	DDX_Text(pDX, IDC_EDIT1, m_classNameEdit);

	//ClassList的虚数据


	//ClassList *cs1 = new ClassList();
	//ClassList *cs2 = new ClassList();
	//ClassList *cs3 = new ClassList();
	//ClassList *cs4 = new ClassList();
	//ClassList *cs5 = new ClassList();
	//
	//cs1->className = "计科一班";
	//cs1->next = cs2;
	//cs2->className = "计科二班";
	//cs2->next = cs3;
	//cs3->className = "计科三班";
	//cs3->next = cs4;
	//cs4->className = "计科四班";
	//cs4->next = cs5;
	//cs5->className = "计科五班";
	//cs1->writeClassList(cs1);

	//读ClassList类

	ClassList *read = ClassList::classList;
	while (read->next != NULL)
	{
		//MessageBox(read->className);
		m_clasListBox.AddString(read->className);
		read = read->next;
	}




	//Person类的虚数据

	//Person *per1 = new Person();
	//Person *per2 = new Person();
	//Person *per3 = new Person();

	//per1->num = "1";
	//per1->name = "杨千旺";
	//per1->className = "计科一班";
	//per1->pw = "1111";
	//per1->status = "1";
	//per1->next = per2;

	//per2->num = "2";
	//per2->name = "何超佳";
	//per2->className = "计科二班";
	//per2->pw = "2222";
	//per2->status = "1";
	//per2->next = per3;

	//per3->num = "3";
	//per3->name = "苏新杰";
	//per3->className = "计科三班";
	//per3->pw = "3333";
	//per3->status = "2";
	//per3->next = NULL;
	//per1->writePerson(per1);

	//读Person类数据

	//Person *readPerson = new Person();
	//readPerson->readPerson(readPerson);
	//Person::person = readPerson;

	//MessageBox("再次出现");
	//Person *pe = Person::person;
	//while (pe->next != NULL)
	//{
	//	MessageBox(pe->num + " " + pe->className + " " + pe->pw + " " + pe->status);
	//	pe = pe->next;
	//}


}


BEGIN_MESSAGE_MAP(adDlg, CDialogEx)
	ON_LBN_SELCHANGE(IDC_LIST3, &adDlg::OnLbnSelchangeList3)//函数绑定
	ON_LBN_SELCHANGE(IDC_LIST2, &adDlg::OnSelectClassChange)
	ON_BN_CLICKED(IDC_BUTTON1, &adDlg::OnDeleteClass)
	ON_BN_CLICKED(IDC_BUTTON4, &adDlg::OnDeleteStudent)
	ON_BN_CLICKED(IDC_BUTTON9, &adDlg::OnAddClass)
	ON_BN_CLICKED(IDC_BUTTON7, &adDlg::OnSearchClass)
	ON_BN_CLICKED(IDC_BUTTON8, &adDlg::OnRevampClass)
	ON_BN_CLICKED(IDC_BUTTON12, &adDlg::OnAddStudent)
	ON_BN_CLICKED(IDC_BUTTON11, &adDlg::OnRevampStudent)
	ON_BN_CLICKED(IDC_BUTTON10, &adDlg::OnSearchStudent)
END_MESSAGE_MAP()


// adDlg 消息处理程序


void adDlg::OnLbnSelchangeList3()//学生列表改变函数
{
	// TODO:  在此添加控件通知处理程序代码
	int index = m_studentListBox.GetCurSel();
	CString student;
	m_studentListBox.GetText(index, student);
	
	int strIndex = student.Find(" ");
	CString num = student.Left(strIndex);
	
	Person *per = Person::person;
	
	while (per->next != NULL)
	{
		if (per->num == num)
		{
			break;
		}
		per = per->next;
	}
	GetDlgItem(IDC_EDIT9)->SetWindowTextA(per->num);
	GetDlgItem(IDC_EDIT7)->SetWindowTextA(per->pw);
	GetDlgItem(IDC_EDIT1)->SetWindowTextA(per->className);
	GetDlgItem(IDC_EDIT8)->SetWindowTextA(per->name);
	GetDlgItem(IDC_EDIT10)->SetWindowTextA(per->status);
	
}


void adDlg::OnSelectClassChange()
{
	// TODO:  在此添加控件通知处理程序代码
	//MessageBox("classListBox");
	int index;
	CString str;
	int judge = 0;
	Person *person = Person::person;

	index = m_clasListBox.GetCurSel();
	m_clasListBox.GetText(index, str);

	m_studentListBox.ResetContent();

	while (person->next != NULL)
	{
		if (person->className == str)
		{
			m_studentListBox.AddString(person->num +" "+person->name+" "+person->pw+" "+ person->className+" "+person->status);
			judge = 1;
		}
		person = person->next;
	}
	GetDlgItem(IDC_EDIT3)->SetWindowTextA(str);//获取编辑框数据
	if (!judge)
	{
		MessageBox("未有该班级学生信息！");
	}
}


void adDlg::OnDeleteClass()
{
	// TODO:  在此添加控件通知处理程序代码
	int index = m_clasListBox.GetCurSel();
	CString className;
	if (index < 0)
	{
		MessageBox("请选择要删项！");
		return;
	}
	m_clasListBox.GetText(index, className);
	ClassList *cl = ClassList::classList;
	ClassList *copy;
	copy = cl;
	while (cl->next != NULL)
	{
		if (cl->className == className)
		{
			if (copy != cl)
			{
				copy->next = cl->next;

				delete cl;//释放删掉的空间

				cl = ClassList::classList;
				cl->writeClassList(cl);
				m_clasListBox.DeleteString(index);
				MessageBox("修改成功！");
				return;
			}
			else
			{
				cl = cl->next;
				delete copy;
				cl->writeClassList(cl);
				m_clasListBox.DeleteString(index);
				ClassList::classList = cl;
				MessageBox("修改成功！");
				return;
			}
		}
		copy = cl;
		cl = cl->next;
	}
	MessageBox("修改失败！");
}


void adDlg::OnDeleteStudent()
{
	// TODO:  在此添加控件通知处理程序代码
	int index = m_studentListBox.GetCurSel();
	if (index < 0)
	{
		MessageBox("请选择要删项！");
		return;
	}
	CString student;
	m_studentListBox.GetText(index, student);

	CString num;
	int strIndex = student.Find(" ");
	num = student.Left(strIndex);
	//MessageBox(num);
	Person *per = Person::person;
	Person *copy;

	copy = per;
	while (per->next != NULL)
	{
		if (per->num == num)
		{
			if (copy == per)
			{
				per = per->next;
				per->writePerson(per);
				Person::person = per;
				delete copy;
				copy = NULL;
				m_studentListBox.DeleteString(index);
				MessageBox("学生删除成功！");
				return;
			}
			else
			{
				copy->next = per->next;

				delete per;

				per = Person::person;
				per->writePerson(per);
				m_studentListBox.DeleteString(index);
				MessageBox("学生删除成功");
				return;
			}
		}
		copy = per;
		per = per->next;
	}
	MessageBox("学生删除失败！");
}


void adDlg::OnAddClass()
{
	CString className;
	GetDlgItem(IDC_EDIT5)->GetWindowText(className);
	ClassList *head = ClassList::classList;
	ClassList *cl = new ClassList();
	cl->className = className;

	cl->next = head->next;
	head->next = cl;

	m_clasListBox.AddString(className);
	head->writeClassList(head);


	//ClassList *cl1 = ClassList::classList;
	//while (cl1->next != NULL)
	//{
	//	MessageBox(cl1->className);
	//	cl1 = cl1->next;
	//}

}


void adDlg::OnSearchClass()
{
	// TODO:  在此添加控件通知处理程序代码
	CString className;
	int judge = 1;
	GetDlgItem(IDC_EDIT2)->GetWindowText(className);
	MessageBox(className);

	ClassList *cl = ClassList::classList;
	
	while (cl->next != NULL)
	{
		if (cl->className == className)
		{
			judge = 0;
			m_clasListBox.SelectString(-1, className);
			break;
		}
		cl = cl->next;
	}
	if (judge)
	{
		MessageBox("未找到班级");
	}
}


void adDlg::OnRevampClass()
{
	// TODO:  在此添加控件通知处理程序代码
	CString beforName;
	CString afterName;
	GetDlgItem(IDC_EDIT4)->GetWindowText(afterName);
	GetDlgItem(IDC_EDIT3)->GetWindowText(beforName);
	int index = m_clasListBox.FindStringExact(-1, beforName);
	if (index < 0)
	{
		MessageBox("未找到班级");
		return;
	}
	m_clasListBox.DeleteString(index);
	m_clasListBox.InsertString(index, afterName);


	ClassList *cl = ClassList::classList;
	while (cl->next != NULL)
	{
		if (cl->className == beforName)
		{
			cl->className = afterName;
			break;
		}
		cl = cl->next;
	}
	cl = ClassList::classList;
	cl->writeClassList(cl);

	Person *per = Person::person;
	while (per->next != NULL)
	{
		if (per->className == beforName)
		{
			per->className = afterName;
		}
		per = per->next;
	}
	per = Person::person;
	per->writePerson(per);
	MessageBox("修改成功！");
}


void adDlg::OnAddStudent()
{
	// TODO:  在此添加控件通知处理程序代码

	CString num;
	CString name;
	CString pw;
	CString status;
	CString className;

	GetDlgItem(IDC_EDIT9)->GetWindowText(num);
	GetDlgItem(IDC_EDIT7)->GetWindowText(pw);
	GetDlgItem(IDC_EDIT8)->GetWindowText(name);
	GetDlgItem(IDC_EDIT10)->GetWindowText(status);
	GetDlgItem(IDC_EDIT1)->GetWindowText(className);

	if (num.IsEmpty() || name.IsEmpty() || pw.IsEmpty() || status.IsEmpty() ||className.IsEmpty())
	{
		MessageBox("请完善资料！");
		return;
	}
	if (status != "学委" && status != "学生")
	{
		MessageBox("正确填写学生身份！");
		return;
	}

	int judge = 1;
	ClassList *cl = ClassList::classList;
	while (cl->next != NULL)
	{
		if (cl->className == className)
		{
			judge = 0;
			break;
		}
		cl = cl->next;
	}
	if (judge)
	{
		MessageBox("班级有误！");
		return;
	}

	judge = 0;
	Person *per = Person::person;
	while (per->next != NULL)
	{
		if (per->num == num)
		{
			judge = 1;
		}
		per = per->next;
	}
	if (judge)
	{
		MessageBox("学号已存在，请重新输入");
		return;
	}

	Person *person = new Person();
	person->num = num;
	person->name = name;
	person->className = className;
	person->pw = pw;
	person->status = status;
	
	per = Person::person;
	person->next = per->next;
	per->next = person;
	per->writePerson(per);
	MessageBox("学生添加成功！");
}


void adDlg::OnRevampStudent()
{
	// TODO:  在此添加控件通知处理程序代码
	CString num;
	CString name;
	CString pw;
	CString status;
	CString className;

	GetDlgItem(IDC_EDIT9)->GetWindowText(num);
	GetDlgItem(IDC_EDIT7)->GetWindowText(pw);
	GetDlgItem(IDC_EDIT8)->GetWindowText(name);
	GetDlgItem(IDC_EDIT10)->GetWindowText(status);
	GetDlgItem(IDC_EDIT1)->GetWindowText(className);

	if (num.IsEmpty() || name.IsEmpty() || pw.IsEmpty() || status.IsEmpty() || className.IsEmpty())
	{
		MessageBox("请完善资料！");
		return;
	}
	if (status != "学委" && status != "学生")
	{
		MessageBox("正确填写学生身份！");
		return;
	}

	Person *per = Person::person;
	while (per->next != NULL)
	{
		if (per->num == num)
		{
			per->name = name;
			per->pw = pw;
			per->className = className;
			per->status = status;

			per = Person::person;//回到链头
			per->writePerson(per);
			MessageBox("修改成功！");
			return;
		}
		per = per->next;
	}
	MessageBox("未有学号为"+num+"的学生记录！");
	return;
	

}


void adDlg::OnSearchStudent()
{
	// TODO:  在此添加控件通知处理程序代码
	CString name;
	GetDlgItem(IDC_EDIT6)->GetWindowText(name);
	Person *per = Person::person;
	int judge = 1;
	while (per->next != NULL)
	{
		if (per->name == name)
		{
			judge = 0;
			break;
		}
		per = per->next;
	}
	if (judge)
	{
		MessageBox("未有此学生记录！");
		return;
	}
	m_studentListBox.ResetContent();
	m_studentListBox.AddString(per->num + " " + per->name + " " + per->pw + " " + per->className+" "+per->status);

}
