#pragma once
#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include "Projec.h"
using namespace std;
namespace fs = std::filesystem;
void edit_attendance();
void change_attendance(list_attendance* a, int n, string namefile, string tempname);

