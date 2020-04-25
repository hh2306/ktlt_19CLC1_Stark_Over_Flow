#include "ViewProfileInfo.h"
void ViewProfileInfo(member user, loginresult F)
{
	cout << endl;
	if (F.type == 1)      // For staff
	{
		cout << " Staff Profile " << endl;
		cout << " Name : " << user.stf[F.location].name << endl;
		cout << " Sex : " << user.stf[F.location].sex << endl;
	} if (F.type == 2)      // For Lecturer
	{
		cout << " Lecturer Profile " << endl;
		cout << " Name : " << user.lec[F.location].name << endl;
		cin.ignore();
		cout << " Acedemic Rank : " << user.lec[F.location].academic_rank << endl;
		cout << " Sex : " << user.lec[F.location].sex << endl;
	}
	if (F.type == 3)         // For student
	{
		cout << " Student Profile " << endl;
		cout << " Name : " << user.stdnt[F.location].name << endl;
		cout << " Class : " << user.stdnt[F.location].class_stu << endl;
		cout << " Date of Birth : " << user.stdnt[F.location].dob.day << "/" << user.stdnt[F.location].dob.month << "/" << user.stdnt[F.location].dob.year << endl << endl;
	}
}