#include <iostream>
<<<<<<< HEAD
#include "All_roles.h"
=======
#include "Projec.h"
#include "LogIn.h"
#include "Readmember.h"
>>>>>>> ac657d99f53674730eef7ce2f57f8368cc9f1db2
using namespace std;
int a;

int main()
{
<<<<<<< HEAD
    all_first_function();
=======
    cout << "Login                 ( Press 1 )" << endl;
    cout << "Show Menu             ( Press 2 )" << endl;
    cout << "View Profile Info     ( Press 3 )" << endl;
    cout << "Change Password       ( Press 4 )" << endl;
    cout << "Logout                ( Press 5 )" << endl;
    string username, pass;
    member a;
    loginresult F;
    int n_lec,  n_staff,  n_stdnt;
    Read_lecture(a.lec, n_lec);
    Read_staff(a.stf, n_staff);
    Read_student(a.stdnt, n_stdnt);
    F = login(username, pass, a, n_lec, n_staff, n_stdnt);
    cout << F.location << " " << F.type;
    ViewProfileInfo(a, F);
>>>>>>> ac657d99f53674730eef7ce2f57f8368cc9f1db2
    return 0;

}

