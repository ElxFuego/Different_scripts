// 1 is reading Directory path
// 2 is reading fnames path

#include <fstream>
#include <string>
#include <iostream>
#include "Division.h"
#include <vector>

using namespace std;

string OpenSettingsFile(int mode,  char* filename) {
	
	//	if(file.peek() ==fstream::traits_type::eof())  Tez dziala, ale jest za madre na ten moment

	fstream file;
	file.open(filename ,ios::in| ios::binary);
	Division txt;
	string delimiter1 = "Files- ";
	string delimiter2 = "Fnames- ";
	int pos = 0;
	string temp;

	if(file.peek() ==fstream::traits_type::eof())
	{		
		cout<<"No Settings File detected"<<endl;
		return "";		
	}
	else{
	
		
		if(file.is_open()){
			
		
			if(mode == 1){
				
				do{
				
					getline(file,temp);
					pos = txt.find_delimiter(temp, delimiter1);			
					if(pos == -1) 
					{
						temp = "error";				//pos == string::npos
						continue;
					}                   
					temp = txt.second_text(pos, temp, delimiter1.length());
					if(pos >= 0) break;
				}
				while(!file.eof());
				file.close();
				return temp;
				
			}
			else if(mode == 2){	

				do{
					getline(file,temp);
					pos = txt.find_delimiter(temp, delimiter2);				
					if(pos == -1) 
					{
						temp = "error";
						continue;
					}
					temp = txt.second_text(pos, temp, delimiter2.length());
					if(pos >= 0) break;
				}
				while(!file.eof());
				file.close();
				return temp;	
				 
			}
	   }
	   else return "";		
	}
}

