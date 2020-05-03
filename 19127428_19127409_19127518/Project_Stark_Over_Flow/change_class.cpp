#include "change_class.h"
namespace fs = std::filesystem;
void chang_stu_class(member& type)
{
	string ID, new_class, old_class;
	int location; 
	int N_old_stu;
	cout << " Enter student ID : ";
	cin >> ID;
	for (int i = 0; i < type.N_student; ++i)
	{
		if (type.stdnt[i].user == ID)
		{
			location = i;
			cout << " Student Profile " << endl;
			cout << " Name : " << type.stdnt[i].name << endl;
			cout << " Class : " << type.stdnt[i].class_stu << endl;
			cout << " Date of Birth : " << type.stdnt[i].dob.day << "/" << type.stdnt[i].dob.month << "/" << type.stdnt[i].dob.year << endl << endl;
			break; // just break out after finding user, no point wasting performance
		}
	}
	cout << " Which class do you want to change to ";
	cin >> new_class;
	// Change class
	old_class = type.stdnt[location].class_stu;
	type.stdnt[location].class_stu = new_class;
	// Chang number student and add student in new class
	string dir1 = "D:\\project\\Student_";
	string dir1_temp = dir1;
	dir1 = dir1 + new_class + ".txt";
	dir1_temp = dir1_temp + new_class + "-copied.txt";
	fstream fW;
	fW.open(dir1, ios::app);
	fW << endl;
	fW << type.stdnt[location].user << endl;
	fW << type.stdnt[location].password << endl;
	fW << type.stdnt[location].name << endl;
	fW << type.stdnt[location].dob.year << " " << type.stdnt[location].dob.month << " " << type.stdnt[location].dob.day << endl;
	fW << type.stdnt[location].class_stu << endl;
	fW.close();
	fW.open(dir1, ios::in);
	fW >> N_old_stu;
	fW.close();
	chg_num_stu(N_old_stu + 1, dir1, dir1_temp);
	// Delete student and change student number in old class
	string dir2 = "D:\\project\\Student_";
	string dir2_temp = dir2;
	dir2 = dir2 + old_class + ".txt";
	dir2_temp = dir2_temp + old_class + "-copied.txt";
	fW.open(dir2, ios::in);
	fW >> N_old_stu;
	student* a = new student[N_old_stu];
	fW.close();
	delete_student(dir2, dir2_temp, ID);
	// Change class in Student.txt
	change_class_in_txt(type, "D:\\project\\Student.txt", "D:\\projet\\Student-copied.txt");
	delete[]a;
}
void change_class_in_txt(member type , string namefile, string tempname)
{
	ofstream fileW;
	fileW.open(namefile);
	if (fileW.fail())
	{
		return;
	}
	else
	{
		fileW << type.N_student << "\n";
		fileW << std::endl;
		for (int i = 0; i < type.N_student; ++i)
		{
			fileW << type.stdnt[i].user << "\n";
			fileW << type.stdnt[i].password << "\n";
			fileW << type.stdnt[i].name << "\n";
			fileW << type.stdnt[i].dob.year << " " <<type.stdnt[i].dob.month << " " << type.stdnt[i].dob.day << "\n";
			fileW << type.stdnt[i].class_stu << "\n";
			fileW << std::endl;
		}
		fileW.close();
	}
	rename((namefile).c_str(), (tempname).c_str());
}
void delete_student(string namefile, string tempname, string user)
{
	// Read student in class 
	int Nstudent;
	student* arr;
	fstream fileR;
	int loc;
	fileR.open(namefile, ios ::in );
	if (fileR.fail())
	{
		return;
	}
	else
	{
		fileR >> Nstudent;
		arr = new student[Nstudent];
		for (int i = 0; i < Nstudent ; ++i)
		{
			fileR >> arr[i].user;
			//cout << arr[i].user << endl;
			fileR >> arr[i].password;
			//cout << arr[i].password << endl;
			fileR.ignore();
			getline(fileR, arr[i].name);
			//cout << arr[i].name << endl;
			fileR >> arr[i].dob.year;
			//cout << arr[i].dob.year << endl;
			fileR >> arr[i].dob.month;
			//cout << arr[i].dob.month << endl;
			fileR >> arr[i].dob.day;
			//cout << arr[i].dob.day << endl;
			fileR >> arr[i].class_stu;
		//	cout << arr[i].class_stu << endl;
		}
	}
	fileR.close();
	// Define location of student
	for (int i = 0; i < Nstudent; ++i)
	{
		if (arr[i].user == user)
		{
			loc = i;
			break; // break right here after getting the correct location of that student in memory
		}
	}

	// Change class infomation 
	fstream f;
	f.open(tempname,ios::out); // should be tempname
	if (f.fail())
	{
		return;
	}
	else
	{
		f << Nstudent - 1 << "\n";
		f << std::endl;
		for (int i = 0; i < loc; ++i)
		{
			f<< arr[i].user << "\n";
			f << arr[i].password << "\n";
			f<< arr[i].name << "\n";
			f << arr[i].dob.year << " " << arr[i].dob.month << " " << arr[i].dob.day << "\n";
			f << arr[i].class_stu << "\n";
			f << std::endl;
		}
		for (int i = loc + 1; i < Nstudent; ++i)
		{
			f << arr[i].user << "\n";
			f << arr[i].password << "\n";
			f<< arr[i].name << "\n";
			f << arr[i].dob.year << " " << arr[i].dob.month << " " << arr[i].dob.day << "\n";
			f << arr[i].class_stu << "\n";
			f << std::endl;
		}
		f.close();
	}
	fs::rename(tempname, namefile);
}