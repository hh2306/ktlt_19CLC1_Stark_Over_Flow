#include "changepassword.h"
bool chpass(member& user, loginresult F) //F has the location of that array which holds the infomation about the user by the login function
{
loop:
	{
		string password;
		cout << "Enter your old password: ";
		cin >> password;
		string passwordcheck;
		// For staff
		if (F.type == 1)
		{
			if (password == user.stf[F.location].password)
			{

			loop1:
				{
					cout << " Enter your new password: ";
					cin >> password;
					cout << " Please confirm your new password: ";
					cin >> passwordcheck;
					if (password != passwordcheck)
					{
						cout << " New password confirmation is not equal!!!" << endl;
						goto loop1;
					}
					else
					{
						user.stf[F.location].password = passwordcheck;
						return true;
					}
				}
			}
			else if (password == "exit")
			{
				return false;
			}
			else if (password != user.stf[F.location].password)
			{
				cout << " Incorrect old password!!" << endl;
				goto loop;
			}

		}
		// For Lecturer
		if (F.type == 2)
		{
			if (password == user.lec[F.location].password)
			{
			loop2:
				{
					cout << " Enter your new password: ";
					cin >> password;
					cout << " Please confirm your new password: ";
					cin >> passwordcheck;
					if (password != passwordcheck)
					{
						cout << " New password confirmation is not equal!!!" << endl;
						goto loop2;

					}
					else
					{
						user.lec[F.location].password = passwordcheck;
						return true;
					}
				}
			}
			else if (password == "exit")
			{
				return false;
			}
			else if (password != user.lec[F.location].password)
			{
				cout << " Incorrect old password!!" << endl;
				goto loop;
			}
		}
		// For student
		if (F.type == 3)
		{
			if (password == user.stdnt[F.location].password)
			{
			loop3:
				{
					cout << " Enter your new password: ";
					cin >> password;
					cout << " Please confirm your new password: ";
					cin >> passwordcheck;
					if (password != passwordcheck)
					{
						cout << " New password confirmation is not equal!!!" << endl;
						goto loop3;

					}
					else
					{
						user.stdnt[F.location].password = passwordcheck;
						return true;
					}
				}
			}
			else if (password == "exit")
			{
				return false;
			}
			else if (password != user.stdnt[F.location].password)
			{
				cout << " Incorrect old password!!" << endl;
				goto loop;
			}
		}
	}
}