#include "FilesDir.h"
#include <iostream>

using namespace std;

FilesDir::FilesDir()
{
	x = "empty dir or file";
}

FilesDir::~FilesDir()
{
}

string FilesDir::get_file_dir()
{
	return x;	
}

void FilesDir::set_file_dir(string y)
{
	x = y;	
}

