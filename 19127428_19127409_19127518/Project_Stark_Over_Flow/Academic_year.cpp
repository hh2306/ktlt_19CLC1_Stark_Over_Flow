#include "Academic_year.h"
namespace fs = std::filesystem;
void Academic()
{
	string command;
	cout << " Create academic years  ( Enter create )" << endl;
	cout << " Update academic years  ( Enter update )" << endl;
	cout << " Delete academic years  ( Enter delete )" << endl;
	cout << " View academic years    ( Enter view   )" << endl;
	cout << " Exit                   ( Enter exit   )" << endl;
loop:
	{
		cout << " Enter Your Command ";
		cin >> command;
		cin.ignore();
		if (command == "create")
		{
			course a;
			// Pass the number of course in semester.txt
			int N_course;
			fstream f;
			f.open("D:\\project\\Semester.txt", ios::in);
			f >> N_course;
			f.close();
			cout << " Enter year ( ex: 2018-2019 ) ";
			cin >> a.year;
			cout << " Enter semester ( ex: HK2 ) ";
			cin >> a.semester;

			// Add new course to file
			f.open("D:\\project\\Semester.txt", ios::app);
			f << a.year << endl;
			f << a.semester << endl;
			f.close();
			chg_num_stu(N_course + 1, "D:\\project\\Semester.txt", "D:\\project\\Semester-copied.txt");
			cout << " Your course has added to semester " << endl;
			cout << endl;
			goto loop;
		}
		if (command == "update")
		{
			int N_course, location;
			// read course 
			fstream f;
			f.open("D:\\project\\Semester.txt", ios::in);
			f >> N_course;
			course* a = new course[N_course];
			for (int i = 0; i < N_course; ++i)
			{
				f >> a[i].year;
				f >> a[i].semester;
			}
			f.close();
			cout << " Infomation of all course " << endl;
			for (int i = 0; i < N_course; ++i)
			{
				cout << " Course number " << i + 1  << " : year " << a[i].year << " semester " << a[i].semester << endl;
			}
			cout << " Enter course number you want to change (ex : 1) ";
			cin >> location;
			cout << " Enter year ";
			cin >> a[location-1].year;
			cout << " Enter semester ";
			cin >> a[location-1].semester;
			change_course_in_txt(a, N_course, "D:\\project\\Semester.txt", "D:\\project\\Semester-copied.txt");
			cout << " Your course has update " << endl;
			cout << endl;
			delete[]a;
			goto loop;
		}
		if (command == "delete")
		{
			int N_course, location;
			fstream f;
			f.open("D:\\project\\Semester.txt", ios::in);
			f >> N_course;
			course* b = new course[N_course];
			for (int i = 0; i < N_course; ++i)
			{
				f >> b[i].year;
				f >> b[i].semester;
			}
			f.close();
			cout << " Infomation of all course " << endl;
			for (int i = 0; i < N_course; ++i)
			{
				cout << " Course number " << i + 1 << " : year " << b[i].year << " semester " << b[i].semester << endl;
			}
			cout << " Enter course number you want to delete (ex 1) ";
			cin >> location;
			delete_course("D:\\project\\Semester.txt", "D:\\project\\Semester-copied.txt", b, N_course, location - 1);
			cout << " Your choice course deleted successfully " << endl;
			cout << endl;
			delete[]b;
			goto loop;
		}
		if (command == "view")
		{
			int N_course, location;
			fstream f;
			f.open("D:\\project\\Semester.txt", ios::in);
			f >> N_course;
			course* b = new course[N_course];
			for (int i = 0; i < N_course; ++i)
			{
				f >> b[i].year;
				f >> b[i].semester;
			}
			f.close();
			cout << " Infomation of all course " << endl;
			for (int i = 0; i < N_course; ++i)
			{
				cout << " Course number " << i + 1 << " : year " << b[i].year << " semester " << b[i].semester << endl;
			}
			cout << endl;
			delete[]b;
			goto loop;
		}
		if (command == "exit")
		{
			return; // goto loop in main
		}

	}
}
void change_course_in_txt(course *a, int N_course, string namefile, string tempname)
{
	ofstream fileW;
	fileW.open(tempname);
	if (fileW.fail())
	{
		return;
	}
	else
	{
		fileW << N_course << "\n";
		fileW << std::endl;
		for (int i = 0; i < N_course; ++i)
		{
			fileW <<a[i].year << "\n";
			fileW << a[i].semester << "\n";
			fileW << std::endl;
		}
		fileW.close();
	}
	fs::rename(tempname, namefile);
}
void delete_course(string namefile, string tempname, course* a, int N_course, int location)
{
	// delete course infomation 
	fstream f;
	f.open(tempname, ios::out); // should be tempname
	if (f.fail())
	{
		return;
	}
	else
	{
		f << N_course - 1 << "\n";
		f << std::endl;
		for (int i = 0; i < location; ++i)
		{
			f << a[i].year<< "\n";
			f << a[i].semester << "\n";
			f << std::endl;
		}
		for (int i = location + 1; i < N_course; ++i)
		{
			f << a[i].year << "\n";
			f << a[i].semester << "\n";
			f << std::endl;
		}
		f.close();
	}
	fs::rename(tempname, namefile);
}
