#include "view_score.h"
void view_score()
{
	string classes, year, semester, course, ID;
	cout << " Enter year (ex: 2019-2020) ";
	cin >> year;
	cout << " Enter semester (ex: HK2) ";
	cin >> semester;
	cout << " Enter name of course (ex: CM101) ";
	cin >> course;
	cout << " Enter class you are studying (ex: 19APCS1) ";
	cin >> classes;
	string filename = "D:\\project\\" + year + "-" + semester + "-" + classes + "-" + course + "-Student.txt";
	fstream f;
	f.open(filename, ios::in);
	if (f.fail())
	{
		cout << " Error file openning " << endl;
		return;
	}
	int n, cur;
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
	f.close();
	cout << " Enter your ID ";
	cin >> ID;
	for (int i = 0; i < n; ++i)
	{
		if (a[i].user == ID)
		{
			cout << " Your score is " << endl;
			cout << " Midterm score " << a[i].midterm_p << endl;
			cout << " Final score " << a[i].final_p << endl;
			cout << " Bonus score " << a[i].extra_p << endl;
			cout << " Total score " << a[i].total_p << endl;
			break;
		}
	}
	delete[]a;
}