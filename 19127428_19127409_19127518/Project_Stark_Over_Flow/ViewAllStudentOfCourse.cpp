#include "ViewAllStudentOfCourse.h"
void ViewAllStudentOfCourse()
{
	int n;// use this to skip the first line in the txt file
	ifstream file;
	string line;
	string Class;
	string course;
	string name = "Student.txt";
	cout << "Please enter the class: ";
	cin >> Class;
	cout << "Please enter name of the course: ";
	cin >> course;
	string dir = "D:\\project\\2019-2020-HK2-";
	dir += Class + "-" + course + "-";
	file.open(dir + name);
	if (file.fail())
	{
		cout << "Unable to open file to view all students of a course" << endl;
		return;
	}
	file >> n;
	//file.seekg(2, ios_base::cur); dont use this
	while (!file.eof())
	{
		getline(file, line);
		if (line[0] > '9')
		{
			cout << line << endl;
		}
	}
	file.close();
}