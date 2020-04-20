#pragma once
#include <iostream>
using namespace std;
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
	string pass;
	DoB date;
	string class_stu;
};
struct DoB
{
	int year;
	int month;
	int day;
};

struct member
{
	struct staff;
	struct lecture;
	struct student;
};