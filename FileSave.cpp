#include <fstream>
#include <string>
#include <iostream>
#include <vector>

int FileSave(std::vector<char> text) {
		
	
		std::fstream file;
		std::vector<char>::iterator it = text.begin();	
		
		file.open("GPasswords.txt" ,std::ios::out| std::ios::binary);		
	
	if(file.is_open())
	{		
		//wypisywanie do pliku tych hase³
		for(auto a : text)
			file<<a;
		
		file.close();
		return 0;
	}
	else 
	{
		std::cout<<"File with generated passwords could not be created"<<std::endl;
		
		return -1;			
	}
				
}	
