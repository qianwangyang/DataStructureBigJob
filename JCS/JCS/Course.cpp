#include "stdafx.h"
#include "Course.h"

Course::Course()
{
	next = NULL;
}

Course *Course::course = NULL;

int Course::writeCourse(Course *course)
{
	FILE *fp;
	if ((fp = fopen("course", "wb")) == NULL)
	{
		return 1;
	}
	CString cstr(" ");
	while (course != NULL)
	{
		fprintf(fp, course->courseName);
		course = course->next;
		if (course == NULL)
		{
			break;
		}
		fprintf(fp, cstr);
	}
	fflush(fp);
	fclose(fp);  
}

int Course::readCourse(Course *course)
{
	FILE *fp;
	if ((fp = fopen("course", "r+")) == NULL)
	{
		return 1;
	}

	CString str;
	char buf;
	int status;
	status = fread(&buf, sizeof(char), 1, fp);
	str.Format("%c", buf);
	
	course->courseName += str;
	while (status > 0)
	{
		status = fread(&buf, sizeof(char), 1, fp);
		str.Format("%c", buf);
		if (str == " " &&status > 0)
		{
			course->next = new Course();
			course = course->next;
			course->next = NULL;
		}
		if (status > 0 && str != " ")
		{
			course->courseName += str;
		}
	}
	fclose(fp);

	return 0;
}