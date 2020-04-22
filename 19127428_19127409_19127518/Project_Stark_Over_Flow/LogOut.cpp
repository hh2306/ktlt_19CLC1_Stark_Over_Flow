#include "LogOut.h"
bool LogOut(string command,loginresult &F)
{
	if (command == "logout")			//command
	{
		F.type = 0;		//type 1 staff, 2 lecturer, 3 students
		return true;
	}
	else
	{
		return false;
	}
}