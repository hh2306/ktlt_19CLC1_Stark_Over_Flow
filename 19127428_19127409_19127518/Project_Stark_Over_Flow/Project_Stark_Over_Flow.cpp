#include <iostream>
#include "All_roles.h"
#include "import_csv.h"
using namespace std;

int main()
{
	int N_students;
	student* arr;
	open_csv(N_students, arr);
	delete[]arr;
	return 0;

}

