#include "Show_menu.h"
#include "LogIn.h"
void showmenu(loginresult result)
{
	if (result.type == 1) // Staff
	{
		cout << "\t \t STAFF MENU " << endl;
		cout << " Import student of a class such as 19CLC1 from a csv file " << endl;
		cout << " Manually add a new student to a class " << endl;
		cout << " Edit an existing student " << endl;
		cout << " Remove a student " << endl;
		cout << " Change students from class A to class B " << endl;
		cout << " View list of classes " << endl;
		cout << " View list of students in class " << endl;
		cout << " Create / update /  delete / view academic years (2019-2020), and semesters (Spring) " << endl;
		cout << " Import courses such as CTT008, CTT010 from a csv file " << endl;
		cout << " Manually add a new course " << endl;
		cout << " Edit an existing course " << endl;
		cout << " Remove specific student from a course " << endl;
		cout << " Add a specific student to a course " << endl;
		cout << " View list of courses in current semester " << endl;
		cout << " View list of student of a course " << endl;
		cout << " Create / update / delete / view all lectures " << endl;
		cout << " Seach and view the scoreboard of a course " << endl;
		cout << " Export a scoreboard list to a csv file " << endl;
		cout << " Seach and view attendance list of a course " << endl;
		cout << " Export a attendance list to a csv file " << endl;
	}
	if (result.type == 2) // Lecture
	{
		cout << "\t \t LECTURE MENU " << endl;
		cout << " View list of courses in the current semester " << endl;
		cout << " View list of students of a course " << endl;
		cout << " View attendance list of a course " << endl;
		cout << " Edit an attendance " << endl;
		cout << " Import scoreboard of a course (midterm, final, lab, bonus) from a cvs file " << endl;
		cout << " Edit grade of student " << endl;
		cout << " View a scoreboard " << endl;
	}
	if (result.type == 3) // student
	{
		cout << "\t \t STUDENT MENU " << endl;
		cout << " Check-in " << endl;
		cout << " View check-in result " << endl;
		cout << " View schedules " << endl;
		cout << " View scores of a course " << endl;
	}

}
