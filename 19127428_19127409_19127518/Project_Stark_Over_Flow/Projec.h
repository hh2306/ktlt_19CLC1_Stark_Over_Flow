#pragma once
#include <iostream>
using namespace std;
struct DoB
{
	int year;
	int month;
	int day;
};
struct staff
{
	string user;
	string password;
	string name;
	string sex;
};
struct lecture
{
	string user;
	string password;
	string name;
	string academic_rank;
	string sex;
};
struct student
{
	string user;
	string password;
	string name;
	DoB dob;
	string class_stu;
};

void Read_staff(staff*& a, int& N_staff);
void Read_student(student*& a, int& N_student);
void Read_lecture(lecture*& a, int& N_lecture);