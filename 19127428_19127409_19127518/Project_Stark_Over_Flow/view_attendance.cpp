#include "view_attendance.h"
void view_attendance()
{
	int n;
	string classes, course;
	cout << " Enter class you want to see ( ex : 19APCS1 ) ";
	cin >> classes;
	cout << " Enter course you want to see ( ex : CM101 ) ";
	cin >> course;
	ifstream f;
	string filename = "D:\\project\\2019-2020-HK2-" + classes + "-" + course + "-Student.txt";
	f.open(filename);
	if (f.fail())
	{
		cout << " Error openning file " << endl;
		return;
	}
	f >> n;
	list_attendance* a = new list_attendance[n];
	for (int i = 0; i < n; ++i)
	{
		f >> a[i].user;
		f >> a[i].password;
		f.ignore();
		getline(f, a[i].name);
		f >> a[i].dob.year;
		f >> a[i].dob.month;
		f >> a[i].dob.day;
		f >> a[i].class_stu;
		f >> a[i].midterm_p;
		f >> a[i].final_p;
		f >> a[i].extra_p;
		f >> a[i].total_p;
		for (int j = 0; j < 10; ++j)
		{
			f >> a[i].arr[j].year;
			f >> a[i].arr[j].month;
			f >> a[i].arr[j].day;
			f >> a[i].arr[j].s_hour;
			f >> a[i].arr[j].s_minute;
			f >> a[i].arr[j].e_hour;
			f >> a[i].arr[j].e_minute;
			f >> a[i].arr[j].check_in;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		cout << " List Attendance of student " << a[i].name << endl;
		for (int j = 0; j < 10; ++j)
		{
			cout << " " << a[i].arr[j].year << " ";
			if (a[i].arr[j].month < 10)
				cout << "0" << a[i].arr[j].month << " ";
			else
				cout << a[i].arr[j].month << " "; 
			if (a[i].arr[j].day < 10)
				cout << "0" << a[i].arr[j].day << " ";
			else
				cout << a[i].arr[j].day << " ";
			cout << a[i].arr[j].s_hour << " " << a[i].arr[j].s_minute << " " << a[i].arr[j].e_hour;
			cout << " " << a[i].arr[j].e_minute;
			if (a[i].arr[j].check_in == 0)
				cout << " attendance " << endl;
			else
				cout << " absence " << endl;
		}
		cout << endl;
	}
	f.close();
	delete[]a;
}
