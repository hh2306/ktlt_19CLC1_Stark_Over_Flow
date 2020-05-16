#include "edit_attendance.h"
void edit_attendance()
{
	string classes, year, semester, course, ID, command;
	cout << " Enter year (ex: 2019-2020) ";
	cin >> year;
	cout << " Enter semester (ex: HK2) ";
	cin >> semester;
	cout << " Enter name of course (ex: CM101) ";
	cin >> course;
	cout << " Enter class you are teaching (ex: 19APCS1) ";
	cin >> classes;
	string filename = "D:\\project\\" + year + "-" + semester + "-" + classes + "-" + course + "-Student.txt";
	string temp = "D:\\project\\" + year + "-" + semester + "-" + classes + "-" + course + "-Student-copied.txt";
	fstream f;
	f.open(filename, ios::in);
	if (f.fail())
	{
		cout << " Error file openning " << endl;
		return;
	}
	int n, cur, date;
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
	cout << " Enter ID student you want to edit attendance ";
	cin >> ID;
	for (int i = 0; i < n; ++i)
	{
		if (a[i].user == ID)
		{
			cur = i;
			break;
		}
	}
	cout << endl;
	cout << " List Attendance of Student " << a[cur].name << endl;
	for (int j = 0; j < 10; ++j)
	{
		cout << " Day " << j + 1 << " " << a[cur].arr[j].year << " ";
		if (a[cur].arr[j].month < 10)
			cout << "0" << a[cur].arr[j].month << " ";
		else
			cout << a[cur].arr[j].month << " ";
		if (a[cur].arr[j].day < 10)
			cout << "0" << a[cur].arr[j].day << " ";
		else
			cout << a[cur].arr[j].day << " ";
		cout << a[cur].arr[j].s_hour << " " << a[cur].arr[j].s_minute << " " << a[cur].arr[j].e_hour;
		cout << " " << a[cur].arr[j].e_minute;
		if (a[cur].arr[j].check_in == 0)
			cout << " attendance " << endl;
		else
			cout << " absence " << endl;
	}
	cout << endl;
loop:
	{
		cout << " Which day do you want to edit ( exit enter 0 ) ";
		cin >> date;
		if (date == 0)
		{
			cout << " Edit attendance sucessfully " << endl;
		}
		else
		{
			cout << " If student is absence, enter absence. If student is attendance, enter attendance ";
			cin >> command;
			if (command == "absence")
				a[cur].arr[date - 1].check_in = -1;
			if(command=="attendance")
				a[cur].arr[date - 1].check_in = 0;
			goto loop;
		}
	}
	change_attendance(a, n, filename, temp);
	delete[]a;
}
void change_attendance(list_attendance* a, int n, string namefile, string tempname)
{
	ofstream f;
	f.open(tempname);
	if (f.fail())
	{
		return;
	}
	else
	{
		f << n << "\n";
		f << std::endl;
		for (int i = 0; i < n; ++i)
		{
			f << a[i].user << endl;
			f << a[i].password << endl;
			f << a[i].name << endl;
			f << a[i].dob.year << " " << a[i].dob.month << " " << a[i].dob.day << endl;
			f << a[i].class_stu << endl;
			f << a[i].midterm_p << endl;
			f << a[i].final_p << endl;
			f << a[i].extra_p << endl;
			f << a[i].total_p << endl;
			for (int j = 0; j < 10; ++j)
			{
				f << a[i].arr[j].year << " " << a[i].arr[j].month << " " << a[i].arr[j].day << " ";
				f << a[i].arr[j].s_hour << " " << a[i].arr[j].s_minute << " " << a[i].arr[j].e_hour << " " << a[i].arr[j].e_minute << " ";
				f << a[i].arr[j].check_in << endl;
			}
			f << endl;
		}
		f.close();
	}
	fs::rename(tempname, namefile);
}