#include "Readmember.h"
<<<<<<< HEAD

void Read_staff(staff*& a, int& N_staff)
{
	ifstream f;
	f.open("D:\\project\\Staff.txt",ios::in);
=======
void Read_staff(staff*& a, int& N_staff)
{
	ifstream f;
	f.open("Staff.txt",ios::in);
>>>>>>> ac657d99f53674730eef7ce2f57f8368cc9f1db2
	if (f.fail())
	{
		cout << " Error open file " << endl;
		return;
	}
	f >> N_staff;
	a = new staff[N_staff];
	for (int i = 0; i < N_staff; i++)
	{
		f >> a[i].user;
		f >> a[i].password;
		f.ignore();
		getline(f, a[i].name);
		f >> a[i].sex;
	}
	f.close();
	
}
void Read_student(student*& a, int& N_student)
{
	ifstream f;
<<<<<<< HEAD
	f.open("D:\\project\\Student.txt",ios::in);
=======
	f.open("Student.txt",ios::in);
>>>>>>> ac657d99f53674730eef7ce2f57f8368cc9f1db2
	if (f.fail())
	{
		cout << " Error open file " << endl;
		return;
	}
	f >> N_student;
	a = new student[N_student];
	for (int i = 0; i < N_student; i++)
	{
		f >> a[i].user;
		f >> a[i].password;
		f.ignore();
		getline(f, a[i].name);
		f >> a[i].dob.year;
		f >> a[i].dob.month;
		f >> a[i].dob.day;
		f >> a[i].class_stu;
	}
	f.close();
}
void Read_lecture(lecture*& a, int& N_lecture)
{
		ifstream f;
<<<<<<< HEAD
		f.open("D:\\project\\Lecture.txt",ios::in);
=======
		f.open("Lecturer.txt",ios::in);
>>>>>>> ac657d99f53674730eef7ce2f57f8368cc9f1db2
		if (f.fail())
		{
			cout << " Error open file " << endl;
			return;
		}
		f >> N_lecture;
		a = new lecture[N_lecture];
		for (int i = 0; i < N_lecture; i++)
		{
			f >> a[i].user;
			f >> a[i].password;
			f.ignore();
			getline(f, a[i].name);
			getline(f, a[i].academic_rank);
			f >> a[i].sex;
		}
		f.close();
		
}