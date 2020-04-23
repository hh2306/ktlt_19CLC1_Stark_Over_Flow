#include "All_roles.h"
void all_first_function()
{
	member type;
	// Read file
	Read_staff(type.stf, type.N_staff);
	Read_lecture(type.lec, type.N_lecture);
	Read_student(type.stdnt, type.N_student);
	// Login
	loginresult login_res = login(type);
	showmenu(login_res);
	delete[]type.lec;
	delete[]type.stdnt;
	delete[]type.stf;
}