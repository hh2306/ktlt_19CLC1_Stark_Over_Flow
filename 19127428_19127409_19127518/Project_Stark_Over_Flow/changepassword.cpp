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
void ViewProfileInfo(member& user, loginresult F)
{
	cout << endl;
	if (F.type==1)      // For staff
	{
		cout << " Profile Staff :" << endl;
		cout <<" Name : "<< user.stf[F.location].name << endl;
		cout <<" Sex : "<< user.stf[F.location].sex << endl;
	} if (F.type==2)      // For Lecturer
	{
		cout << " Profile Lecturer :" << endl;
		cout << " Name : " << user.lec[F.location].name << endl;
		cin.ignore();
		cout << " Acedemic Rank : "<<user.lec[F.location].academic_rank << endl;
		cout << " Sex : " << user.lec[F.location].sex << endl;
	}
	 if( F.type==3)         // For student
	{
		cout << " Profile Student :" << endl;
		cout << " Name : " << user.stdnt[F.location].name << endl;
		cout <<" Class : "<< user.stdnt[F.location].class_stu << endl;
		cout << " Date of Birth : "<<user.stdnt[F.location].dob.day<<"/"<< user.stdnt[F.location].dob.month<<"/"<<user.stdnt[F.location].dob.year << endl<<endl;
	}
}