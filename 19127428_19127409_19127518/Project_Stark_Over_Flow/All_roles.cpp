#include "All_roles.h"
void all_first_function()
{
	member type;
	Read_lecture(type.lec, type.N_lecture);
	Read_student(type.stdnt, type.N_student);
	Read_staff(type.stf, type.N_staff);
loop:
	{
		loginresult log_in = login(type);
		if (log_in.type == 0)
		{
			cout << " Your username or your password is incorrect. Please login again " << endl;
			cout << endl;
			goto loop;
		}
		else
		{
			if (log_in.type == 1)
			{
				if (type.stf[log_in.location].sex == "female")
				{
					cout << " Hello Mrs. " << type.stf[log_in.location].name << endl;
				}
				else
				{
					cout << " Hello Mr. " << type.stf[log_in.location].name << endl;
				}
			}
			if (log_in.type == 2)
			{
				if (type.lec[log_in.location].sex == "female")
				{
					cout << " Hello Mrs. " << type.lec[log_in.location].name << endl;
				}
				else
				{
					cout << " Hello Mr. " << type.lec[log_in.location].name << endl;
				}
			}
			else if (log_in.type ==3)
			{
				cout << " Hello student " << type.stdnt[log_in.location].name << endl;
			}
		loop2:
			{
				string command;
				cout << endl;
				cout << " Show menu funtion        Enter menu " << endl;
				cout << " View your profile        Enter profile " << endl;
				cout << " Change your password     Enter password " << endl;
				cout << " Logout                   Enter logout" << endl;
				cout << " Enter your command : ";
				cin >> command;
				if (command == "menu")
				{
					showmenu(log_in);
					goto loop2;
				}
				if (command == "profile")
				{
					ViewProfileInfo(type, log_in);
					goto loop2;
				}
				if (command == "password")
				{
					chpass(type, log_in);
					chpassintxt(type, log_in);
					goto loop2;
				}
				if (command == "logout")
				{
					if (LogOut(command, log_in) == true)
					{
						cout << " logout " << endl;
					}
					goto loop;		// logout go to loop1 enter new username password
				}
			}
		}
	}
	delete[]type.lec;
	delete[]type.stdnt;
	delete[]type.stf;
}