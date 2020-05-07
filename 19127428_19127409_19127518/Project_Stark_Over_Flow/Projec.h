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
struct member
{
	struct student *stdnt;
	struct staff *stf;
	struct lecture *lec;
	int N_student;
	int N_staff;
	int N_lecture;
};
struct loginresult
{
	int type; // 1 = staff , 2 = lecture, 3 = student
	int location; //location at which array hold the information of that logged in user
};
struct course
{
	string year;
	string semester;
};
struct schedule
{
	int No;
	string ID;
	string name;
	string classes;
	string account;
	string lc_name;
	string degree;
	string gender;
	int s_day;
	int s_month;
	int s_year;
	int e_day;
	int e_month;
	int e_year;
	string day;
	int s_hour;
	int s_minute;
	int e_hour;
	int e_minute;
	string room;
};