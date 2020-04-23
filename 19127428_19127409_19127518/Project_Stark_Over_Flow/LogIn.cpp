#include "LogIn.h"
<<<<<<< HEAD
loginresult login(member type) // x = numbers of staffs, y = numbers of lectures, z= numbers of students
{
	string username;
	string password;
=======
loginresult login(std::string username, std::string password, member type, int x, int y, int z) // x = numbers of staffs, y = numbers of lectures, z= numbers of students
{
>>>>>>> ac657d99f53674730eef7ce2f57f8368cc9f1db2
	cout << "\t\t****LOG IN MENU*****" << endl;
	cout << "Enter username: ";
	cin >> username;
	cout << "Enter password: ";
	cin >> password;
	loginresult result;
	if (username[0] >= '0' && username[0] <= '9')
	{
<<<<<<< HEAD
		for (int i = 0; i < type.N_student; ++i)
=======
		for (int i = 0; i < z; ++i)
>>>>>>> ac657d99f53674730eef7ce2f57f8368cc9f1db2
		{
			if (username == type.stdnt[i].user)
			{				 
				if (password == type.stdnt[i].password)
				{
					result.type = 3;		// 3 = student
					result.location = i;
					return result;
				}
			}
		}
	}
	string temp = username.substr(0, 3);
	if (username[1] == '.' || username[2] == '.')
	{
<<<<<<< HEAD
		for (int i = 0; i < type.N_lecture; ++i)
=======
		for (int i = 0; i < y; ++i)
>>>>>>> ac657d99f53674730eef7ce2f57f8368cc9f1db2
		{
			if (username == type.lec[i].user)
			{
				if (password == type.lec[i].password)
				{
					result.type = 2;		// 2 = lectures
					result.location = i;
					return result;
				}
			}
		}
	}
	else
	{
<<<<<<< HEAD
		for (int i = 0; i < type.N_staff; ++i)
=======
		for (int i = 0; i < y; ++i)
>>>>>>> ac657d99f53674730eef7ce2f57f8368cc9f1db2
		{
			if (username == type.stf[i].user)
			{
				if (password == type.stf[i].password)
				{
					result.type = 1;		// 1 = staffs
					result.location = i;
					return result;
				}
			}
		}
	}
}