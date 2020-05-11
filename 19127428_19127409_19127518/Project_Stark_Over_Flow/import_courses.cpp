#include "import_courses.h"
void import_course(schedule *& a, int& N_course)
{
	// Find name file 
	string namefile, classes, year, semester;
	cout << " Enter year ( ex : 2019-2020 ) ";
	cin >> year;
	cout << " Enter semester (ex : HK2 ) ";
	cin >> semester;
	cout << " Enter class you want to import ( ex : 19APCS1 ) ";
	cin >> classes;
	namefile = "D:\\project\\" + classes + "-Schedule.csv";

	fstream f;
	f.open(namefile, ios::in);
	if (f.fail())
	{
		cout << " Error open file" << endl;
		return;
	}
	// Find number of courses in file
	f.seekg(-1, ios::end);
		f.seekg(-1, ios::cur);
		int k = f.tellg();
		for (k; k > 0; --k)
		{
			if (f.peek() == '\n')
			{
				f.seekg(2, ios::cur);
				f >> N_course;
				break;
			}
			f.seekg(-1, ios::cur);
		}

	// Make array of new student 
	a = new schedule[N_course];
	string str_temp;
	f.seekg(0, ios::beg);
	getline(f, str_temp);// to skip the first line

	for (int i = 0; i < N_course; ++i)
	{
		f >> a[i].No;
		f.seekg(1, ios::cur);
		getline(f, a[i].ID, ',');
		getline(f, a[i].name, ',');
		getline(f, a[i].classes, ',');
		getline(f, a[i].account, ',');
		getline(f, a[i].lc_name, ',');
		getline(f, a[i].degree, ',');
		getline(f, a[i].gender, ',');
		f >> a[i].s_month;
		f.seekg(1, ios::cur);
		f >> a[i].s_day;
		f.seekg(1, ios::cur);
		f >> a[i].s_year;
		f.seekg(1, ios::cur);
		f >> a[i].e_month;
		f.seekg(1, ios::cur);
		f >> a[i].e_day;
		f.seekg(1, ios::cur);
		f >> a[i].e_year;
		f.seekg(1, ios::cur);
		getline(f, a[i].day, ',');
		f >> a[i].s_hour;
		f.seekg(1, ios::cur);
		f >> a[i].s_minute;
		f.seekg(1, ios::cur);
		f >> a[i].e_hour;
		f.seekg(1, ios::cur);
		f >> a[i].e_minute;
		f.seekg(1, ios::cur);
		getline(f, a[i].room);
	}
	f.close();

	// Add schedule to schedule file 
	namefile = "D:\\project\\" + year + "-" + semester +"-Schedule-" + classes + ".txt";	
	ofstream fs;
	fs.open(namefile,ios::out);
	if (fs.fail())
	{
		cout << " Error opening file " << endl;
		return;
	}
	else
	{
		for (int i = 0; i < N_course; ++i)
		{
			fs << a[i].ID << endl;
			fs << a[i].name << endl;
			fs << a[i].classes << endl;
			fs << a[i].account << endl;
			fs << a[i].lc_name << endl;
			fs << a[i].degree << endl;
			fs << a[i].gender << endl;
			fs << a[i].s_year << " ";
			if (a[i].s_month < 10)
				fs << 0 << a[i].s_month << " ";
			else
				fs << a[i].s_month << " ";
			if (a[i].s_day < 10)
				fs << 0 << a[i].s_day << endl;
			else
				fs << a[i].s_day << endl;
			fs << a[i].e_year << " ";
			if (a[i].e_month < 10)
				fs << 0 << a[i].e_month << " ";
			else
				fs << a[i].e_month << " ";
			if (a[i].e_day < 10)
				fs << 0 << a[i].e_day << endl;
			else
			fs << a[i].day << endl;
			fs << a[i].s_hour << " ";
			fs << a[i].s_minute << endl;
			fs << a[i].e_hour << " ";
			fs << a[i].e_minute << endl;
			fs << a[i].room << endl;
			fs << endl;
		}
	}
	fs.close();

	// Read array student in class student file
	int N_student;
	namefile = "D:\\project\\Student_" + classes + ".txt";
	f.open(namefile, ios::in);
	f >> N_student;
	student* stu_a = new student[N_student];
	for (int i = 0; i < N_student; ++i)
	{
		f >> stu_a[i].user;
		f >> stu_a[i].password;
		f.ignore();
		getline(f, stu_a[i].name);
		f >> stu_a[i].dob.year;
		f >> stu_a[i].dob.month;
		f >> stu_a[i].dob.day;
		f >> stu_a[i].class_stu;
	}
	f.close();

	//Add student to class
	for (int i = 0; i < N_course; ++i)
	{
		namefile = "D:\\project\\" + year + "-" + semester + "-" + classes + '-' + a[i].ID + "-Student.txt";
		fs.open(namefile);
		fs << N_student << endl;
		fs << endl;
		for (int j = 0; j < N_student; ++j)
		{
			int day = a[i].s_day;
			int month = a[i].s_month;
			fs << stu_a[j].user << endl;
			fs << stu_a[j].password << endl;
			fs << stu_a[j].name << endl;
			fs << stu_a[j].dob.year << " " << stu_a[j].dob.month << " " << stu_a[j].dob.day << endl;
			fs << stu_a[j].class_stu << endl;
			fs << -1 << endl;
			fs << -1 << endl;
			fs << -1 << endl;
			fs << -1 << endl;
			for (int k = 0; k < 10; ++k)
			{
				count_date(month, day);
				fs << a[i].s_year << " ";
				if (month < 10)
					fs << 0 << month << " ";
				else
					fs << month << " ";
				if (day < 10)
					fs << 0 << day << " ";
				else
					fs << day << " ";
				fs << a[i].s_hour << " " << a[i].s_minute << " " << a[i].e_hour << " " << a[i].e_minute << " " << -1 << endl;
				day = day + 7;
			}
			fs << endl;
		}
		fs.close();

	}
		delete[]stu_a;
}

void count_date(int& month, int& day)
{
	switch (month)
	{
	case 1:
	{
		if (day > 31)
		{
			month++;
			day = day - 31;
			return;
		}
		else
			return;
	}
	case 2:
	{
		if (day > 28)
		{
			month++;
			day = day - 28;
			return;
		}
		else
			return;
	}
	case 3:
	{
		if (day > 31)
		{
			month++;
			day = day - 31;
			return;
		}
		else
			return;
	}
	case 4:
	{
		if (day > 30)
		{
			month++;
			day = day - 30;
			return;
		}
		else
			return;
	}
	case 5:
	{
		if (day > 31)
		{
			month++;
			day = day - 31;
			return;
		}
		else
			return;
	}
	case 6:
	{
		if (day > 30)
		{
			month++;
			day = day - 30;
			return;
		}
		else
			return;
	}
	case 7:
	{
		if (day > 31)
		{
			month++;
			day = day - 31;
			return;
		}
		else
			return;
	}
	case 8:
	{
		if (day > 31)
		{
			month++;
			day = day - 31;
			return;
		}
		else
			return;
	}
	case 9:
	{
		if (day > 30)
		{
			month++;
			day = day - 30;
			return;
		}
		else
			return;
	}
	case 10:
	{
		if (day > 31)
		{
			month++;
			day = day - 31;
			return;
		}
		else
			return;
	}
	case 11:
	{
		if (day > 30)
		{
			month++;
			day = day - 30;
			return;
		}
		else
			return;
	}
	case 12:
	{
		if (day > 31)
		{
			month++;
			day = day - 31;
			return;
		}
		else
			return;
	}
	}
}