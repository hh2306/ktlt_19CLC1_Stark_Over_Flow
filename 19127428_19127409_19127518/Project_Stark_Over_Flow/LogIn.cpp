#include "LogIn.h"
loginresult login(member type) 
{
	string username;
	string password;
	cout << "\t\t****LOG IN MENU*****" << endl;
	cout << " Enter username: ";
	cin >> username;
	cout << " Enter password: ";
	cin >> password;
	loginresult result;
	result.type = 0;
	result.location = 0;
	if (username[0] >= '0' && username[0] <= '9')
	{
		for (int i = 0; i < type.N_student; ++i)
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
	if (username[1] == '.' || username[2] == '.' || username[4] == '.')
	{
		for (int i = 0; i < type.N_lecture; ++i)
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
		for (int i = 0; i < type.N_staff; ++i)
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
	return result;
}