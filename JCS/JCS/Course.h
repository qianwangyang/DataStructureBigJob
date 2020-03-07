#ifndef COURSE_H
#define COURSE_H

class Course
{
public:
	Course();

	CString courseName;

	Course *next;
	static Course *course;

	int writeCourse(Course *course);
	int readCourse(Course *course);

};

#endif