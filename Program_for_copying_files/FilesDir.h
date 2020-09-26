#ifndef FILESDIR_H
#define FILESDIR_H
#include <string>

class FilesDir
{
	std::string x;
	
	public:
		FilesDir();
		~FilesDir();
		std::string get_file_dir();
		void set_file_dir(std::string);

};

#endif
