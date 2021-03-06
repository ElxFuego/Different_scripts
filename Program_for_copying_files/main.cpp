#include <iostream>
#include <fstream>
#include <string>
#include "Division.h"
#include "FilesDir.h"
#include <vector>

using namespace std;

vector<string> read_file_names(char* filename);
int nofiles(int x);
void menu();
std::string OpenSettingsFile(int mode, char* filename);
int SettingsFile(char* settingsF);
int menuOptions();

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	menu();
	fstream file;
	fstream program1;
	string sourcefile, fullsource;
	string sourcepath, path;
	char* settingsFile = "SettingsFile.txt";
	bool status;
	int choice;
	bool token = true;
		
	
	do{
		system("cls");
		menu();
		choice = menuOptions();
		
		switch(choice)
		{

			case 1:
			{

				if(!(OpenSettingsFile(1, settingsFile) == "")){		
					sourcepath = OpenSettingsFile(1, settingsFile);	
					cout<<"\nDirectory of files to copy: "<<sourcepath<<endl<<endl;	
				}
				else{	
					cout<<"Directory of files to copy: ";
					cin>>sourcepath;
					cout<<endl;			
				}
			
				vector<string>filenames = read_file_names(settingsFile);
				
				int size = filenames.size();
				FilesDir File[size/2], Dir[size/2];
				
				int i = 0;
				
				for(vector<string>::iterator it = filenames.begin(); it != filenames.end(); it++)
				{
					File[i].set_file_dir(*it);
					it++;
					Dir[i].set_file_dir(*it);
					i++;
				}
								
			
				for(int no = 0; no < size/2; no++)
				{	
					
					status = true;
					system("pause");
					
					system("cls");
					menu();
					
					sourcefile = File[no].get_file_dir();
					fullsource = sourcepath + "/" + sourcefile;
					string filename = "/" + sourcefile;
					path = Dir[no].get_file_dir();
					string fullpath = path + filename;
					
					cout<<endl<<fullpath<<endl;
					
					program1.open(fullsource.c_str(),ios::in | ios::binary);
						
					if(!program1.is_open())
					{	
						cout<<"\nFile name '" <<File[no].get_file_dir()<<"' not recognized or directory does not exist"<<endl<<endl;
						status = false;	
						Dir[no].set_file_dir("error");		
					}
					
					if(!status)
					{
						//system("cls");	
						//menu();
					}	
					else
					{
				
						vector<string> filelines;
						
						int i=0;
						int nolines=0;	
						string temp;			
							
						if(program1.is_open())
						{	
						
							do
							{		
							getline(program1,temp);	  //przydatne gowno. Funkcja zczytuje cala linie z danego pliku 
							filelines.push_back(temp);
							i++;
							}
							while(!program1.eof());	cout<<endl<<sourcefile<<" has "<< i << " lines\n"<<endl;
						}
						else
						{
							cout<<"Source file does not exist"<<endl;
							Dir[no].set_file_dir("error");
							program1.close();
							continue;
						}
						
						file.open(fullpath.c_str() ,ios::out| ios::binary);
						
						if(file.is_open())
						{	
							int j = 0;
							
							do
							{	
							file<<filelines[j]<<endl;
							j++;	
							}
							while(j < i);		
						}
						else
						{
							cout<<"Error - Probably directory does not exist"<<endl<<endl;
							Dir[no].set_file_dir("error");
						}
						file.close();
						program1.close();
				
					}
				}
				system("pause");
				system("cls");	
				menu();
				
				bool all = true;
				
				for(int i=0; i<size/2; i++)
				{
					if(Dir[i].get_file_dir()=="error")
					all = false;		
				}
				if(!all)
				{
				
					for(int i=0; i<size/2; i++)
					{
						if(Dir[i].get_file_dir()=="error")
						{
							cout<<"\n---------------File "<<File[i].get_file_dir()<<" is corrupted. Check desired directory or file itself---------------"<<endl;		
							all = false;
						}
						else
						{
							cout<<"\nFile '"<< File[i].get_file_dir()<<"' copied to folder '"<< Dir[i].get_file_dir()<<"'"<<endl;
						}
					}
				}
				else
				{			
					cout<<"\nAll files has been succesfully copied"<<endl;
					
					for(int i=0; i<size/2;i++)
					{
						cout<<"\nFile '"<< File[i].get_file_dir()<<"' copied to folder '"<< Dir[i].get_file_dir()<<"'"<<endl;	
					}
				}
				cout<<endl;
				system("pause");
				break;
			}
			case 2:
			{	
				system("cls");	
				menu();
				SettingsFile(settingsFile);
			
				break;
			}
			case 3:
			{	
				if( remove( settingsFile ) != 0 )
    			perror( "Error deleting file" );   //funkcja ktora wypisuje komunikat b��du na standardowy strumie� b��d�w . Najpierw jest wiadomosc w (), a potem komunikat systemowy o bledzie (error deleting file: no such file or directory)
  				else
    			puts( "File successfully deleted" );  //do rozkminy nowe funkcje
				system("pause");			
				break;
			}
			case 4:
			{
				token = false;
				break;
			}

		}
				
				
		}while(token);
		
		
	cout<<endl;	
	return 0;
}
//////////////////////////////////////////////////////////
vector<string> read_file_names(char* filename)
{
	fstream file;
	string delimiter = ";";
	string dir;
	
	string buffer;
	
	if(!(OpenSettingsFile(2, filename) == "")){	
		
		dir = OpenSettingsFile(2, filename);	
		cout<<"Directory of fnames.txt file: "<<dir<<endl<<endl;	
	}
	else{
		
		cout<<"Directory of fnames.txt file: ";
		cin>>dir;
		cout<<endl;
	}
	
	dir = dir +"/fnames.txt";
	
	vector<string> filenames;
	vector<string>::iterator it = filenames.begin();
	
	file.open(dir.c_str(),ios::in);		
	
	string temp;
	
	int size = 0;
	
	if(file.is_open())
		{	
		
		do
		{		

			getline(file,temp);	  //przydatne gowno. Funkcja zczytuje cala linie z danego pliku 
			filenames.push_back(temp);
			it++;
			filenames.push_back("null");
			it++;
			size++;
		}
		while(!file.eof());	cout<<"Source file has "<<size<< " lines"<<endl<<endl<<"-------------------------------------"<<endl<<endl;
		}
		else
		{
			cout<<"Source file does not exist"<<endl;
			exit (0);
		}

												
	string token;
	Division txt;
	unsigned int pos;
	
	it = filenames.begin();
	
	bool status = true;	
				
	for(int i = 0; i<size*2; i +=2)
	{	
			string	temp, temp2;
			temp = filenames[i];
			pos = txt.find_delimiter(temp,delimiter);
				
			if(pos>temp.size())
			{
				cout<<"File in line "<<(i/2 +1)<<" has no delimiter"<<endl<<endl;
				status = false;
			}
			
		    token = txt.first_text(pos, temp);
		    temp2 = txt.second_text(pos, temp, delimiter.length());
				
			filenames.at(i) = token;
			filenames.at(i+1) = temp2;			


			if(filenames[i]=="")
			{
				cout<<"Line "<<i<<" missing file name or path"<<endl<<endl;
				status = false;	
			}
			else if(filenames[i + 1] == "")	
			{
				cout<<"Line "<<i<<" missing file name or path"<<endl<<endl;
				status = false;
			}

	}
	if(!status)
	{
		cout<<"Check fnames.txt file before continuing"<<endl;
		exit(0);
	}
			
	file.close();
	return filenames;			
}

void menu()
{
	cout<<"--------------------------------------------"<<endl;
	cout<<"|Program for updating Cadmatic custom files|"<<endl;	
	cout<<"--------------------------------------------"<<endl;
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
