#include "Remove_Student_From_Course.h"
void Remove_Student_From_Course(std::string userID)
{
	int n;
	ifstream fileR;
	ofstream fileW;
	string line;
	string Class;
	string course;
	string oldname = "Student.txt";
	string newname = "Student-copied.txt";
	cout << "Please enter the class: ";
	cin >> Class;
	cout << "Please enter name of the course: ";
	cin >> course;
	string dir = "D:\\project\\2019-2020-HK2-";
	dir += Class + "-" + course + "-";
	fileR.open(dir + oldname);
	if (fileR.fail())
	{
		cout << "Unable to open file!!!\n";
		return;
	}
	fileW.open(dir + newname);
	if (fileW.fail())
	{
		fileR.close();
		cout << "Unable to open file!!!\n";
		return;
	}
	fileR >> n;
	fileW << n - 1 << endl;
	while (!fileR.eof())
	{
		getline(fileR, line);
		if (line != userID)
		{
			fileW << line << endl;
		}
		else
		{
			for (int i = 0; i < 9; ++i) // i = each line, skip 9 lines according to txt file format
			{
				while (fileR.peek() != '\n')
				{
					fileR.seekg(1, ios::cur);
				}
				fileR.seekg(2, ios::cur);
			}
		}
	}
	fileR.close();
	fileW.close();
	fs::rename(dir + newname, dir + oldname);
}