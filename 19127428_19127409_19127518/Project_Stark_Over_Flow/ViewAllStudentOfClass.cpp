#include "ViewAllStudentOfClass.h"
void ViewAllStudentOfClass(string Class)	 // Example : Class = 19CLC1 
{
	int n; //use this to skip the first line
	ifstream file;
	string line;
	string dir = "D:\\project\\Student_" + Class + ".txt";
	file.open(dir);
	if (file.fail())
	{
		cout << "Unable to open file!!!";
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
				for (int i = 0; i < 2; ++i) // i = each line, skip 2 lines according to txt file format
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