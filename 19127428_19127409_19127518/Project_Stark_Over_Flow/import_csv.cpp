#include "import_csv.h"
namespace fs = std::filesystem;
void open_csv(int& N_student, student*& arr)
{
	fstream f;
	f.open("D:\\project\\19APCS1-Student.csv",ios::in);
	string str_temp;
	// Find a number of student in list 
	f.seekg(-1, ios::end);
	if (f.peek() == '\n')
	{
		f.seekg(-1, ios::cur);
		int i = f.tellg();
		for (i; i > 0; --i)
		{
			if (f.peek() == '\n')
			{
				f.seekg(2, ios::cur);
				f >> N_student;
				break;
			}
			f.seekg(-1, ios::cur);
		}
	}
	// Make array of new student 
	f.seekg(0,ios::beg);
	getline(f, str_temp);// to skip the first line

	string str;
	arr = new student[N_student];
	for (int i = 0; i < N_student; ++i)
	{
		getline(f, str, ',');
		getline(f, arr[i].user, ',');
		getline(f, arr[i].name, ',');
		f >> arr[i].dob.year;
		f.seekg(1, ios::cur);
		f >> arr[i].dob.month;
		f.seekg(1, ios::cur);
		f >> arr[i].dob.day;
		f.seekg(1, ios::cur);
		getline(f, arr[i].class_stu);
		if (arr[i].dob.day < 10)
		{
			arr[i].password = "0" + IntToString(arr[i].dob.day);
		}
		else
		{
			arr[i].password = IntToString(arr[i].dob.day);
		}
		if (arr[i].dob.month < 10)
		{
			arr[i].password += "0" + IntToString(arr[i].dob.month);
		}
		else
		{
			arr[i].password += IntToString(arr[i].dob.month);
		}
		arr[i].password += IntToString(arr[i].dob.year);
	}
	f.close();
	// Save to Class 
	fstream fs;
	fs.open("D:\\project\\Student_19APCS1.txt", ios::out);
	fs << N_student << endl;
	fs << endl;
	for (int i = 0; i < N_student; ++i)
	{
		fs << arr[i].user << endl;
		fs << arr[i].password << endl;
		fs << arr[i].name << endl;
		fs << arr[i].dob.year << " " << arr[i].dob.month << " " << arr[i].dob.day << endl;
		fs << arr[i].class_stu << endl;
		fs << endl;
	}
	fs.close();
	// Save to Student.txt
	fstream fi;
	fi.open("D:\\project\\Student.txt", ios::app);
	if (fi.fail())
	{
		cout << " Error openning " << endl;
	}
	fi << endl;
	fi << endl;
	for (int i = 0; i < N_student; ++i)
	{
		fi << arr[i].user << endl;
		fi << arr[i].password << endl;
		fi << arr[i].name << endl;
		fi << arr[i].dob.year << " " << arr[i].dob.month << " " << arr[i].dob.day << endl;
		fi << arr[i].class_stu << endl;
		fi << endl;
	}
	fi.close();
	fstream file;
	file.open("D:\\project\\Student.txt ", ios::in);
	int N_old_stu;
	file >> N_old_stu;
	int N_new_stu = N_old_stu + N_student;
	file.close();
	chg_num_stu(N_new_stu);
}
string IntToString(int a)
{
	ostringstream temp;
	temp << a;
	return temp.str();
}
void chg_num_stu(int N_new_stu)
{
	string line;
	ifstream file;
	file.open("D:\\project\\Student.txt");
	if (file.fail())
	{
		cout << "Unable to open file" << endl;		
	}
	ofstream file1;
	file1.open("D:\\project\\Student-copied.txt");
	file1 << N_new_stu << endl;
	file.seekg(3, ios::beg);
	while (!file.eof())
	{
		getline(file, line);
		file1 << line << endl;
	}
	file.close();
	file1.close();
	string dir = "D:\\project\\";
	string oldname = "Student.txt";
	string newname = "Student-copied.txt";
	fs::rename(dir + newname, dir + oldname);
}