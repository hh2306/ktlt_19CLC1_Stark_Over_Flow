#include "LogIn.h"
loginresult login(std::string username, std::string password, member type, int x, int y, int z) // x = numbers of staffs, y = numbers of lectures, z= numbers of students
{
	cout << "\t\t****LOG IN MENU*****" << endl;
	cout << "Enter username: ";
	cin >> username;
	cout << "Enter password: ";
	cin >> password;
	loginresult result;
	if (username[0] >= '0' && username[0] <= '9')
	{
		for (int i = 0; i < z; ++i)
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
		for (int i = 0; i < y; ++i)
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
		for (int i = 0; i < y; ++i)
		{
			if (username == type.stf[i].user)
			{
				if (password == type.stf[i].password)
				{
					result.type = 2;		// 1 = staffs
					result.location = i;
					return result;
				}
			}
		}
	}
}