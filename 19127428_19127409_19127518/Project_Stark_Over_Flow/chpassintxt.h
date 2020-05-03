#pragma once
#include <iostream>
#include <fstream>
#include "Projec.h"
#include <filesystem>
namespace fs = std::filesystem;
void chpassintxt(member user, loginresult type);
// if only chpass function return true; then we will process in the txt file
