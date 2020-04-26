#include "ViewAllStudentOfClass.h"
void ViewAllStudentOfClass(string Class)	 // Example : Class = 19CLC1 
{
	ifstream file;
	string line;
	string dir = "D:\\project\\Student_" + Class + ".txt";
	file.open(dir);
	if (file.fail())
	{
		cout << "Unable to open file!!!";
	}
	file.seekg(3, ios::beg);
	while (!file.eof())
	{
		getline(file, line);
		if (line[0] > '9') // print only the name 
		{
			cout << line << endl;
		}
	}
	file.close();
}