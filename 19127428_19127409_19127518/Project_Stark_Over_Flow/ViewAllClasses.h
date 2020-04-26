#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#define N 100
namespace fs = std::filesystem;
using namespace std;

void ViewAllClasses();

string ViewAllTextFile(string *&exclude,int i); // in D:\\project 

string ExcludeClass(string path);