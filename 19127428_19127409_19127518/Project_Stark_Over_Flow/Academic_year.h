#pragma once
#include <iostream>
#include <fstream>
#include "Projec.h"
#include "import_csv.h"
using namespace std;

void Academic();
void change_course_in_txt(course* a, int N_course, string namefile, string tempname);
void delete_course(string namefile, string tempname, course* a, int N_course, int location);