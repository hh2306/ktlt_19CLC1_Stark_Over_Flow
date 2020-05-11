#include "export_attendance_list.h"
void export_attendance_list()
{
	int n, dd, mm, yy;
	ifstream fileR;
	ofstream fileW;
	string line, Class, course, academic_year, semester;
	cout << "Please enter academic year ( Ex: 2019-2020 ): ";
	cin >> academic_year;
	cout << "Please enter semester ( Ex: HK2 ): ";
	cin >> semester;
	cout << "Please enter the class: ";
	cin >> Class;
	cout << "Please enter name of the course: ";
	cin >> course;
	string csv = "Attendance.csv";
	string txt = "Student.txt";
	string dircsv = "D:\\project\\" + academic_year + "-" + semester + "-" + Class + "-" + course + "-" + csv;
	string dirtxt = "D:\\project\\" + academic_year + "-" + semester + "-" + Class + "-" + course + "-" + txt;
	fileR.open(dirtxt);
	if (fileR.fail())
	{
		cout << "Unable to open " << dirtxt << endl;
		return;
	}
	fileR >> n;
	fileR.seekg(2, ios::cur);
	fileW.open(dircsv);
	if (fileW.fail())
	{
		cout << "Unable to open " << dircsv << endl;
		fileR.close();
		return;
	}
	fileW << "No,Student ID,Fullname,Class,Course,Dates,Start Time,End Time,Check In Status\n"; // first line
	for (int i = 1; i <= n; ++i)
	{
		fileW << i  << ",";
	loop:
		{
			getline(fileR, line);
			if (line != "")
			{
				fileW << line << ","; //student id
				getline(fileR, line);		//password
				getline(fileR, line);
				fileW << line << ","; // Student name;
				fileW << Class << ","; //class
				fileW << course << ",";
				for (int j = 0; j < 6; ++j)	// skip 6 lines
				{
					while (fileR.peek() != '\n')
					{
						fileR.seekg(1, ios::cur);
					}
					fileR.seekg(2, ios::cur);
				}
				for (int l = 0; l < 10; ++l)		// 10 attendance days
				{
					fileR >> yy;
					fileR >> mm;
					fileR >> dd;
					fileW << dd <<'/'<< mm<<'/' << yy << ",";
					fileR.seekg(1, ios::cur);
					getline(fileR, line, ' '); //start time
					fileW << line << " ";
					getline(fileR, line, ' ');
					fileW << line << ",";

					getline(fileR, line, ' '); //end time
					fileW << line << " ";
					getline(fileR, line, ' ');
					fileW << line << ",";

					getline(fileR, line);
					fileW << line << endl; // check in status
					if (l != 9)
					{
						for (int a = 0; a < 5; ++a) // skip cells 5 times
						{
							fileW << ",";
						}
					}
					else fileW << endl;
				}
			}
			else goto loop;
		}
	}
	fileR.close();
	fileW.close();
	cout << "Export attendance list successfully!!!\n";
	cout << "New csv file is: " << dircsv << endl;
}