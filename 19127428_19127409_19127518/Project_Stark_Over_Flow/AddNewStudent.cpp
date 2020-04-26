#include "AddNewStudent.h"
void AddNewStudent()
{
	member New;
	New.stdnt = new student[1];
	string Class;
	cout << "Enter which class for the new student: "; //for example 19CLC6
	cin >> Class;
	cout << "Enter new student's ID: ";
	cin >> New.stdnt[0].user;
	cin.ignore();
	cout << "Enter new student's name: ";
	getline(cin, New.stdnt[0].name);
	
	cout << "Enter new student's date of birth (dd mm yy): ";
	cin >> New.stdnt[0].dob.day >> New.stdnt[0].dob.month >> New.stdnt[0].dob.year;
	//create password for new student
	if (New.stdnt[0].dob.day < 10)
	{
		New.stdnt[0].password = "0" + IntToString(New.stdnt[0].dob.day);
	}
	else
	{
		New.stdnt[0].password = IntToString(New.stdnt[0].dob.day);
	}
	if (New.stdnt[0].dob.month < 10)
	{
		New.stdnt[0].password += "0" + IntToString(New.stdnt[0].dob.month);
	}
	else
	{
		New.stdnt[0].password += IntToString(New.stdnt[0].dob.month);
	}
	New.stdnt[0].password += IntToString(New.stdnt[0].dob.year);
	// Adding the info of new student to file
	ofstream fileW;
	string dir = "D:\\project\\Student_";
	string ext = ".txt";
	string path = dir + Class + ext;
	fileW.open(path, ios::app);
	if (fileW.fail())
	{
		cout << "Unable to open file!!!\n";	
		return;
	}
	fileW << endl;
	fileW << New.stdnt[0].user << endl;
	fileW << New.stdnt[0].password << endl;
	fileW << New.stdnt[0].name << endl;
	fileW << New.stdnt[0].dob.year << " " << New.stdnt[0].dob.month << " " << New.stdnt[0].dob.day << endl;
	fileW << Class << endl;
	fileW.close();
	// Change number of student of that class after adding a new student
	ifstream fileR;
	int N_old_students;
	fileR.open(path);
	if (fileR.fail())
	{
		cout << "Unable to open file!!!\n";
		return;
	}
	fileR >> N_old_students;		//Take the old value of number of students
	fileR.close();		
	//
	fileR.open(path);
	string temp_path = dir + Class + "-copied" + ext;		//tempory path for the rename function
	string line;
	fileW.open(temp_path);
	fileW << N_old_students + 1 << endl;
	fileR.seekg(3, ios::cur); // skip the first line which containing the number of students
	while (!fileR.eof())
	{
		getline(fileR, line);
		fileW << line << endl;
	}
	fileR.close();
	fileW.close();
	fs::rename(temp_path, path);
	// Modifying the Student.txt
	// Adding the new student to Student
	fileW.open("D:\\project\\Student.txt", ios::app);
	fileW << endl;
	fileW << New.stdnt[0].user << endl;
	fileW << New.stdnt[0].password << endl;
	fileW << New.stdnt[0].name << endl;
	fileW << New.stdnt[0].dob.year << " " << New.stdnt[0].dob.month << " " << New.stdnt[0].dob.day << endl;
	fileW << Class << endl;
	fileW.close();
	// Change number of student in Student.txt file after adding a new student
	fileR.open(path);
	if (fileR.fail())
	{
		cout << "Unable to open file!!!\n";
		return;
	}
	fileR >> N_old_students;		//Take the old value of number of students
	fileR.close();
	//
	fileW.open("D:\\project\\Student-copied.txt");
	fileR.open("D:\\project\\Student.txt");
	fileW << N_old_students + 1 << endl;
	fileR.seekg(3, ios::cur);	//Skipping the first line which containning the number of student
	while (!fileR.eof())
	{
		getline(fileR, line);
		fileW << line << endl;
	}
	fileR.close();
	fileW.close();
	fs::rename("D:\\project\\Student-copied.txt", "D:\\project\\Student.txt");
	delete[]New.stdnt;
}

