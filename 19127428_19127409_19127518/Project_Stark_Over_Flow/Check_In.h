#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <ctime>
#include "Projec.h"
#include <filesystem>
namespace fs = std::filesystem;
using namespace std;
void Check_In(string ID);
string current_time();
string* split_stringwithspace(string str);
string* split_stringwith2dots(string str);
Time cur_time_format(string* time, string* clock);


