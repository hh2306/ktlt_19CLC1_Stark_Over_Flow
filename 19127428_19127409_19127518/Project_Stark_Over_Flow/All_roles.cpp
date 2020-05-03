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
					if (log_in.type == 1) // staff
					{
						int n1;
						for (;;)
						{
							cout << " Enter your command : ";
							cin >> n1;
							switch (n1)
							{
							case 0:
							{
								goto loop2;
								
							}
							case 1:
							{
								int N_csv_stu;
								student* arr_csv;
								open_csv(N_csv_stu, arr_csv);
								delete[]arr_csv;
								break;							
							}
							case 2:
							{
								AddNewStudent();
								break;
							}
							case 3:
							{
								//Phuoc Edit an existing student
								break;
							}
							case 4:
							{
								string user;
								cout << "Enter an ID of a student you want to remove: ";
								cin >> user;
								delete_student("D:\\project\\Student.txt", "D:\\project\\Student-copied.txt", user);
								break;
							}
							case 5:
							{
								chang_stu_class(type);
								break;
							}
							case 6:
							{
								ViewAllClasses();
								break;
							}
							case 7:
							{
								string classes;
								cout << " Which class do you want to see ";
								cin >> classes;
								ViewAllStudentOfClass(classes);
								break;
							}
							//case 8 to 20 // Add later
							}
						}
					}
					// Case for Lecturer


					// Case for Student
					goto loop2;
				}
				if (command == "profile")
				{
					ViewProfileInfo(type, log_in);
					goto loop2;
				}
				if (command == "password")
				{
					if (chpass(type, log_in) == true)
					{
						cout << " Password has changed succesfully " << endl;
					}
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