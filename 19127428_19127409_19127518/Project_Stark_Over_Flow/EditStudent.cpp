#include "EditStudent.h"
#include "All_roles.h"

void RemoveStudent()
{
	string deleted;
	string reason;
	string dir = "Student_";
	string dirtemp = "-copied";
	string ext = ".txt";
	string Class;
	cout << "Enter which class you want to delete student: "; //for example 19CLC6
	cin >> Class;
	cin.ignore();
	cout << "What reason do you want to this student : ";
	getline(cin, reason);
	string path = dir + Class + ext;
	string pathtemp = dir + Class + dirtemp + ext;
	string user;
	cout << "Enter an ID of a student you want to remove : ";
	cin >> user;
	ReadStudentInClass(path,user);
	cout << "Do you want to remove this Student : ";
	cin >> deleted;
	if (deleted == "yes")
	{
		delete_student_Perfect("Student.txt", "Student-copied.txt", user);
		delete_student_Perfect(path, pathtemp, user);
		cout << "Reason : " << reason << endl;
		cout << "Delete Student Successfully !!!" << endl;
	}
}

void delete_student_Perfect(string namefile, string tempname, string user)
{
	// Read student in class 
	int Nstudent;
	student* arr;
	fstream fileR;
	int loc;
	fileR.open(namefile, ios::in);
	if (fileR.fail())
	{
		return;
	}
	else
	{
		fileR >> Nstudent;
		arr = new student[Nstudent];
		for (int i = 0; i < Nstudent; ++i)
		{
			fileR >> arr[i].user;
			fileR >> arr[i].password;
			fileR.ignore();
			getline(fileR, arr[i].name);
			fileR >> arr[i].dob.year;
			fileR >> arr[i].dob.month;
			fileR >> arr[i].dob.day;
			fileR >> arr[i].class_stu;
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
	
	// Change File student infomation 
	fstream f;
	f.open(tempname, ios::out); // should be tempname
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
			f << arr[i].user << "\n";
			f << arr[i].password << "\n";
			f << arr[i].name << "\n";
			f << arr[i].dob.year << " " << arr[i].dob.month << " " << arr[i].dob.day << "\n";
			f << arr[i].class_stu << "\n";
			f << std::endl;
		}
		for (int i = loc + 1; i < Nstudent; ++i)
		{
			f << arr[i].user << "\n";
			f << arr[i].password << "\n";
			f << arr[i].name << "\n";
			f << arr[i].dob.year << " " << arr[i].dob.month << " " << arr[i].dob.day << "\n";
			f << arr[i].class_stu << "\n";
			f << std::endl;
		}
		f.close();
	}
	fs::rename(tempname, namefile);
}

void ReadStudentInClass(string namefile, string user)
{
	// Read student in class 
	int Nstudent;
	student* arr;
	fstream fileR;
	fileR.open(namefile, ios::in);
	if (fileR.fail())
	{
		return;
	}
	else
	{
		fileR >> Nstudent;
		arr = new student[Nstudent];
		for (int i = 0; i < Nstudent; ++i)
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
			//cout << arr[i].class_stu << endl;
		}
	}
	fileR.close();
	// Define location of student
	for (int i = 0; i < Nstudent; ++i)
	{
		if (arr[i].user == user)
		{
			cout << arr[i].name << endl;
			cout << arr[i].dob.day << "/" << arr[i].dob.month << "/" << arr[i].dob.year << endl;
			break; // break right here after getting the correct location of that student in memory
		}
	}
}

void Edit_Student()
{
	string ok;
	int year,month,day;
	string newname;
	string dir = "Student_";
	string dirtemp = "-copied";
	string ext = ".txt";
	string Class;
	cout << "Enter which class you want to Edit student: "; //for example 19CLC6
	cin >> Class;
	cin.ignore();
	string path = dir + Class + ext;
	string pathtemp = dir + Class + dirtemp + ext;
	string user;
	cout << "Enter an ID of a student you want to Edit : ";
	cin >> user;
	ReadStudentInClass(path, user);
	cin.ignore();
	cout << "Enter your New Name : ";
	getline(cin, newname);
	//cin.ignore();
	cout << "Enter your new Date of Birth (year/month/day) :";
	cin >> year >> month >> day;
	cout << "Do you want to Edit this Student : ";
	cin >> ok;
	if (ok=="yes")
	{
		EditStudent("Student.txt","Student-copied.txt", user, newname,year,month,day);
		EditStudent(path, pathtemp, user, newname, year, month, day);
		cout << "Edit Student Successfully !!!" << endl;
	}
}

void EditStudent(string namefile, string tempname, string user,string newname,int year,int month,int day)
{
	// Read student in class 
	int Nstudent;
	student* arr;
	fstream file;
	file.open(namefile, ios::in);
	if (file.fail())
	{
		return;
	}
	else
	{
		file >> Nstudent;
		arr = new student[Nstudent];
		for (int i = 0; i < Nstudent; ++i)
		{
			file >> arr[i].user;
			file >> arr[i].password;
			file.ignore();
			getline(file, arr[i].name);
			file >> arr[i].dob.year;
			file >> arr[i].dob.month;
			file >> arr[i].dob.day;
			file >> arr[i].class_stu;
		}
	}
	file.close();
	
	// edit File student infomation 
	fstream f;
	f.open(tempname, ios::out); // should be tempname
	if (f.fail())
	{
		cout << "File Error !"<<endl;
		return;
	}
	else
	{
		f << Nstudent<< "\n";
		f << std::endl;
		for (int i = 0; i < Nstudent; ++i)
		{
			if (arr[i].user==user)
			{
				f << arr[i].user << "\n";
				arr[i].password = IntToString(day) + IntToString(month) + IntToString(year);
				f << arr[i].password << "\n";
				arr[i].name = newname;
				f << arr[i].name << "\n";
				arr[i].dob.year = year;
				arr[i].dob.month = month;
				arr[i].dob.day = day;
				f << arr[i].dob.year << " " << arr[i].dob.month << " " << arr[i].dob.day << "\n";
				f << arr[i].class_stu << "\n";
				f << std::endl;
			}
			else
			{
				f << arr[i].user << "\n";
				f << arr[i].password << "\n";
				f << arr[i].name << "\n";
				f << arr[i].dob.year << " " << arr[i].dob.month << " " << arr[i].dob.day << "\n";
				f << arr[i].class_stu << "\n";
				f << std::endl;
			}
		}
		f.close();
	}
	fs::rename(tempname, namefile);
}


