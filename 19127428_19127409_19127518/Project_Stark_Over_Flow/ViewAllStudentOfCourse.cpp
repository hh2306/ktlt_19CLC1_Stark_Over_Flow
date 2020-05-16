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
		if (line != "\n")
		{
			if (line[0] >= '0' && line[0] <= '9') // ID 
			{
				getline(file, line); // password
				getline(file, line); // name
				cout << line << endl;
				for (int i = 0; i < 16; ++i) // i = each line, skip 16 lines according to txt file format
				{
					while (file.peek() != '\n')
					{
						file.seekg(1, ios::cur);
					}
					file.seekg(2, ios::cur);
				}
			}
		}
	}
	file.close();
}