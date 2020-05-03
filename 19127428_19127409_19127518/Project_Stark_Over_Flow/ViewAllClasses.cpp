#include "ViewAllClasses.h"
void ViewAllClasses()
{
	string dir = "D:\\project\\Class.txt";
	string line;
	ifstream file(dir);
	if (file.fail())
	{
		cout << "Unable to open Class file";
		return;
	}
	file.seekg(3, ios::beg);
	while (!file.eof())
	{
		getline(file, line);
		cout << line << endl;
	}
	file.close();
}
