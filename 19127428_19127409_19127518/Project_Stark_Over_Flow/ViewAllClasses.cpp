#include "ViewAllClasses.h"
void ViewAllClasses()
{
	int n;
	string dir = "D:\\project\\Class.txt";
	string line;
	ifstream file(dir);
	if (file.fail())
	{
		cout << "Unable to open Class file";
		return;
	}
	file >> n;
	//file.seekg(2, ios_base::cur); dont use this
	while (!file.eof())
	{
		getline(file, line);
		cout << line << endl;
	}
	file.close();
}
