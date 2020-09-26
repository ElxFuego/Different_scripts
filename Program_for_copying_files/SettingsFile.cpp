#include <fstream>
#include <string>
#include <iostream>

std::string OpenSettingsFile(char* filename);

using namespace std;

int SettingsFile(char* settingsF) {
	
	fstream file;
	string directory, fnamesDir;
	
		
	file.open(settingsF ,ios::out| ios::binary);
	
	if(file.is_open())
	{
		cout<<"Directory of files to copy: ";
		cin>>directory;
		file<<"Files- "<<directory<<endl;
		
		cout<<"Directory of fnames.txt file: ";
		cin>>fnamesDir;
		file<<"Fnames- "<<fnamesDir<<endl;
		cout<<endl;
		
		file.seekg(ios::beg);
		
		file.close();

		return 0;
	}
	else 
	{
		cout<<"Settings file could not be created"<<endl;
		
		return -1;			
	}
				
}
