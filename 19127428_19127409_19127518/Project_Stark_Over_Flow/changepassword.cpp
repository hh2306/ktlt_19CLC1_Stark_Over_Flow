#include "changepassword.h"
void chpass(member& user, string password, loginresult F) //F has the location of that array which holds the infomation about the user by the login function
{
	cout << "Enter your old password: ";
	cin >> password;
	string passwordcheck;
	// For staff
	if (F.type == 1)
	{
		if (password == user.stf[F.location].password)
		{
			cout << "Enter your new password: ";
			cin >> password;
			cout << "Please confirm your new password: ";
			cin >> passwordcheck;
			if (password == passwordcheck)
			{
				user.stf[F.location].password = passwordcheck;
			}
		}
	}
	// For Lecturer
	if (F.type == 2)
	{
		if (password == user.lec[F.location].password)
		{
			cout << "Enter your new password: ";
			cin >> password;
			cout << "Please confirm your new password: ";
			cin >> passwordcheck;
			if (password == passwordcheck)
			{
				user.lec[F.location].password = passwordcheck;
			}
		}
	}
	// For student
	if (F.type == 3)
	{
		if (password == user.stdnt[F.location].password)
		{
			cout << "Enter your new password: ";
			cin >> password;
			cout << "Please confirm your new password: ";
			cin >> passwordcheck;
			if (password == passwordcheck)
			{
				user.stdnt[F.location].password = passwordcheck;
			}
		}
	}
}