#include "chpassintxt.h"
void chpassintxt(member user, loginresult type,int x,int y ,int z)
{
	ofstream fileW;
	string oldname;
	string newname;
	string dir = "D:\\";
	// For staff
	if (type.type == 1)
	{
		newname = "staff-copied.txt";
		oldname = "staff.txt";
		fileW.open(dir+oldname);
		if (fileW.fail())
		{
			return;
		}
		else
		{
			fileW << x << "\n";
			fileW << std::endl;
			for (int i = 0; i < x; ++i)
			{
				fileW << user.stf[i].user << "\n";
				fileW << user.stf[i].password << "\n";
				fileW << user.stf[i].name << "\n";
				fileW << user.stf[i].sex << "\n";
				fileW << std::endl;
			}
		}
		if (rename((dir + oldname).c_str(), (dir + newname).c_str()) == 0) //agruments take char
		{
			cout << "Renaming file successfully!!!\n";
			return;
		}
		else
		{
			cout << "Error renaming file\n";
			return;
		}

	}
	//For Lec
	if (type.type == 2)
	{
		newname = "Lecturer-copied.txt";
		oldname = "LEcturer.txt";
		fileW.open(dir + oldname);
		if (fileW.fail())
		{
			return;
		}
		else
		{
			fileW << x << "\n";
			fileW << std::endl;
			for (int i = 0; i < y; ++i)
			{
				fileW << user.lec[i].user << "\n";
				fileW << user.lec[i].password << "\n";
				fileW << user.lec[i].name << "\n";
				fileW << user.lec[i].academic_rank << "\n";
				fileW << user.stf[i].sex << "\n";
				fileW << std::endl;
			}
		}
		if (rename((dir + oldname).c_str(), (dir + newname).c_str()) == 0) //agruments take char
		{
			cout << "File renamed successfully\n";
			return;
		}
		else
		{
			return;
		}
	}
	//For Student
	if (type.type == 3)
	{
		newname = "Student-copied.txt";
		oldname = "Student.txt";
		fileW.open(dir + oldname);
		if (fileW.fail())
		{
			return;
		}
		else
		{
			fileW << x << "\n";
			fileW << std::endl;
			for (int i = 0; i < z; ++i)
			{
				fileW << user.stdnt[i].user << "\n";
				fileW << user.stdnt[i].password << "\n";
				fileW << user.stdnt[i].name << "\n";
				fileW << user.stdnt[i].dob.year<<" "<<user.stdnt[i].dob.month<<" "<<user.stdnt[i].dob.day<< "\n";
				fileW << user.stdnt[i].class_stu << "\n";
				fileW << std::endl;
			}
		}
		if (rename((dir + oldname).c_str(), (dir + newname).c_str()) == 0) //agruments take char
		{
			cout << "File renamed successfully\n";
			return;
		}
		else
		{
			return;
		}
	}
}