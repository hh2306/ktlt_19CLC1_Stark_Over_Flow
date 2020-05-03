#include "Show_menu.h"
void showmenu(loginresult result)
{
	if (result.type == 1) // Staff
	{
		cout << "\t \t \t \t  STAFF MENU " << endl;
		cout << " Import student of a class such as 19CLC1 from a csv file                            ( Enter 1  )" << endl;
		cout << " Manually add a new student to a class                                               ( Enter 2  )" << endl;
		cout << " Edit an existing student                                                            ( Enter 3  )" << endl;
		cout << " Remove a student                                                                    ( Enter 4  )" << endl;
		cout << " Change students from class A to class B                                             ( Enter 5  )" << endl;
		cout << " View list of classes                                                                ( Enter 6  )" << endl;
		cout << " View list of students in class                                                      ( Enter 7  )" << endl;
		cout << " Create / update /  delete / view academic years (2019-2020), and semesters (Spring) ( Enter 8  )" << endl;
		cout << " Import courses such as CTT008, CTT010 from a csv file                               ( Enter 9  )" << endl;
		cout << " Manually add a new course                                                           ( Enter 10 )" << endl;
		cout << " Edit an existing course                                                             ( Enter 11 )" << endl;
		cout << " Remove specific student from a course                                               ( Enter 12 )" << endl;
		cout << " Add a specific student to a course                                                  ( Enter 13 )" << endl;
		cout << " View list of courses in current semester                                            ( Enter 14 )" << endl;
		cout << " View list of student of a course                                                    ( Enter 15 )" << endl;
		cout << " Create / update / delete / view all lectures                                        ( Enter 16 )" << endl;
		cout << " Seach and view the scoreboard of a course                                           ( Enter 17 )" << endl;
		cout << " Export a scoreboard list to a csv file                                              ( Enter 18 )" << endl;
		cout << " Seach and view attendance list of a course                                          ( Enter 19 )" << endl;
		cout << " Export a attendance list to a csv file                                              ( Enter 20 )" << endl;
		cout << " Exit                                                                                ( Enter 0  )" << endl;
		cout << endl;
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