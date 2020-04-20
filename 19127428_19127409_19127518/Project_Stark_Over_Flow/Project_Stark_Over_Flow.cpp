#include <iostream>
#include "Projec.h"
using namespace std;


int main()
{
    cout << " Project ez " << endl;
    staff* a;
    int N_staff;
    Read_staff(a, N_staff);
    delete[]a;
    return 0;
}

