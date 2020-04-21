#include <iostream>
#include "Projec.h"
<<<<<<< HEAD
<<<<<<< HEAD
#include "Readmember.h"
#include "LogIn.h"
#include "chpassintxt.h"
#include "changepassword.h"
=======
#include "LogIn.h"
#include "Readmember.h"
>>>>>>> 347267266f849be3c597e8dd0de1f9f4d9ef0854
=======
#include "LogIn.h"
#include "Readmember.h"
>>>>>>> 347267266f849be3c597e8dd0de1f9f4d9ef0854
using namespace std;


int main()
{
<<<<<<< HEAD
<<<<<<< HEAD
    // khong dung vao day
    // tao class rieng de lam
  
    loginresult F;
    member user;
    int n_staff, n_lec, n_stdnt;
    Read_lecture(user.lec, n_lec);
    Read_staff(user.stf, n_staff);
    Read_student(user.stdnt, n_stdnt);

    string username, password; // for logging in
    F = login(username, password, user, n_staff, n_lec, n_stdnt);
    if (chpass(user, password, F) == true)
    {
        chpassintxt(user, F, n_staff, n_lec, n_stdnt);
    }
=======
=======
>>>>>>> 347267266f849be3c597e8dd0de1f9f4d9ef0854
    cout << "Login                 ( Press 1 )" << endl;
    cout << "Show Menu             ( Press 2 )" << endl;
    cout << "View Profile Info     ( Press 3 )" << endl;
    cout << "Change Password       ( Press 4 )" << endl;
    cout << "Logout                ( Press 5 )" << endl;


    return 0;

<<<<<<< HEAD
>>>>>>> 347267266f849be3c597e8dd0de1f9f4d9ef0854
=======
>>>>>>> 347267266f849be3c597e8dd0de1f9f4d9ef0854
}

