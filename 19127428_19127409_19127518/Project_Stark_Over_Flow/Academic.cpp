#include "Academic.h"
#include "Academic.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

void  Create_Update_Delete_View_Academic(ViewAcademic& v)
{
	string command;
	cout << "Create / update / delete / view academic years (2019-2020)" << endl;
	cout << "Enter Your Command ( Ex: create / update / delete / view ) : ";
	cin >> command;
	cin.ignore();
	cout << "Years ( Ex: 2018-2019 ) : ";
	getline(cin, v.school_year);
	cout << "Semesters ( Ex: HK1 ) : ";
	getline(cin, v.semester);
	fstream f;
	if (command == "create")
	{
		f.open("Semesters.txt", ios::out);
		if (f.fail())
		{
			cout << "Error Open File !" << endl;
			return;
		}
		v.number_course++;
		f << v.number_course;
		f << endl;
		f << v.school_year;
		f << endl;
		f << v.semester;
		f.seekg(-3, ios::cur);
		f.close();
		cout << "Create Successfully !!!" << endl;
	}
	if (command == "update")
	{
		f.open("Semesters.txt", ios::out | ios::app);
		f << endl;
		f << v.school_year;
		f << endl;
		f << v.semester;
		f.close();
		cout << "Update Successfully !!!" << endl;

	}


}