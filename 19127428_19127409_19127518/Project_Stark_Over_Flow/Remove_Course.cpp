#include "Remove_Course.h"
void Remove_Course()
{
	string Class;
	string course;
	string name = "Student.txt";
	cout << "Please enter the class of the course you want to delete: ";
	cin >> Class;
	cout << "Please enter name of the course you want to delete: ";
	cin >> course;
	string dir = "D:\\project\\2019-2020-HK2-";
	dir += Class + "-" + course + "-";
	ofstream file;
	file.open(dir + name); //delete everything inside
	if (file.fail())
	{
		cout << "Unable to delete file!!!" << endl;
		return;
	}
	file.close();
}