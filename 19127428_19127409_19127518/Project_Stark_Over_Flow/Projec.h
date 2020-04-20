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

