#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <string>
#include <vector>


static const char special_tab[8] = {'!','#','$','%','&','*','?','@'};
static const char number_tab[10] = {'1','2','3','4','5','6','7','8','9','0'};
static const char lettersC_tab[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
static const char letters_tab[] = "abcdefghijklmnopqrstuvwxyz";

void menu();
int MenuOptions();
int yesno();
bool InputChecker(std::string);
int FileSave(std::vector<char>);
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	std::string fname = "GPasswords.txt";
	srand(time(NULL));
	int choice;
	int no_passwords;
	char yn;
	int special_char;
	char special;
	int up_char = 0;
	int lo_char = 1;
	int overal_no_char = 0;
	int number_char = 0;
	char number;
	char password_char;
	
	
	bool char_choice;
	bool special_char_status;
	bool up_char_status;
	bool lo_char_status;
	bool number_char_status;
	
	int special_char_count;
	int lo_char_count;
	int up_char_count;
	int number_char_count;
	
	std::vector<char> passwords_txt;
	
	menu();
	choice = MenuOptions();
	
	switch(choice)
		{

			case 1: 
			{
				system("cls");
				menu();	
				std::cout<<"\nWhat is the number of passwords to generate ?"<<std::endl;
					
				do{				
					std::cin>>no_passwords;				
				}
			    while(!InputChecker("\nNot a number. Enter value one more time"));
				
				system("cls");
				menu();
				std::cout<<"\nWhat is the overall number of characters ?"<<std::endl;				
				
				do{				
					std::cin>>overal_no_char;	
				}
			    while(!InputChecker("\nNot a number. Enter value one more time"));
				
				
				system("cls");
				menu();					
				std::cout<<"\nShould password contain lower and uppercase letters ?"<<std::endl;   //2   65-90  ;  97-122
				std::cout<<"Y\\N ?"<<std::endl;
				up_char = yesno();
							
				std::cout<<"Should password contain special characters ?"<<std::endl;  //1   33-47  ;   58-64
				std::cout<<"Y\\N ?"<<std::endl;
				special_char = yesno();
				
				std::cout<<"Should password contain numbers?"<<std::endl;  //1   48-57
				std::cout<<"Y\\N ?"<<std::endl;
				number_char = yesno();
				
				if(lo_char + up_char + special_char + number_char > overal_no_char)
				{
					system("cls");
					menu();
					std::cout<<"\nOverall number of characters is to small. It will be set to '4'."<<std::endl;
					overal_no_char = 4;
					std::cout<<"\nPress any key to continue"<<std::endl;
					getch();			
				}
				
				system("cls");
				menu();
							
				std::cout<<"Passwords are "<<std::endl;
				
				for(int i =0; i < no_passwords; i++)
				{
					
					special_char_status = true;
					up_char_status = true;
					lo_char_status = true;
					number_char_status =true;
					special_char_count =0;
					up_char_count = 0;
					lo_char_count = 0;
					number_char_count =0;
					
					
					for(int j = 0; j < overal_no_char; j++)
		     		{
		     			choice = (rand()%4);
		     							
			     			if((up_char ==1) && (choice == 1) && (up_char_status == true))
			     			{		     				
			     				password_char = lettersC_tab[rand() % (sizeof(lettersC_tab)/sizeof(*lettersC_tab)-1)];	
								std::cout<<password_char;
								up_char_count++;						   				
							}
					
					
							else if((special_char ==1) && (choice == 2) && (special_char_status == true))
			     			{		     				
			     				password_char = special_tab[rand() % 8];
								std::cout<<password_char;
								special_char_count++;	     				
							}
							
						
							else if((number_char ==1) && (choice == 3) && (number_char_status == true))
			     			{		     				
			     				 password_char = number_tab[rand() % 10];
								 std::cout<<password_char;
								 number_char_count++;										     				
							}
							else if((choice == 0) && (lo_char_status == true))
							{						
								password_char = letters_tab[rand() % (sizeof(letters_tab)/sizeof(*letters_tab)-1)];
								std::cout<<password_char;
								lo_char_count++;
							}
							else
							{
							
							 j--;
							 continue;
							}
				
							
							if((overal_no_char -j -1 )< 4)
							{
								
								if(up_char_count > 0 || up_char == 0)
									up_char_status = false;
								if(special_char_count >0 || special_char == 0)
									special_char_status = false;
								//	std::cout<<"gowno special"<<std::endl;
								if(number_char_count > 0 || number_char == 0)
									number_char_status = false;
								//	std::cout<<"gowno number"<<std::endl;
								if(lo_char_count > 0)
								//	std::cout<<"gowno lochar"<<std::endl;
								lo_char_status = false;
								if(up_char_status ==false && special_char_status ==false && number_char_status ==false && lo_char_status  ==false)
								lo_char_status = true;	
							}
							
						passwords_txt.push_back(password_char);										 
			     	}
	     	
			    	std::cout<<std::endl;
					passwords_txt.push_back('\n');	 
		    	}
		    	
				FileSave(passwords_txt);
				
				std::cout<<"\nPress any key to continue"<<std::endl;
				getch();
				system("cls");
				menu();
				std::cout<<"\nPasswords saved in file "<<fname<<std::endl;	
				 
				break;						
			}
		
				
			case 2:;
			//future features
			default:;
	}
		
	std::cout<<"\nPress any key to continue"<<std::endl;
	getch();
	return 0;	
}

void menu()
{
	std::cout<<"+---------------------------------------+"<<std::endl;
	std::cout<<"|Program for Generating random passwords|"<<std::endl;	
	std::cout<<"+---------------------------------------+"<<std::endl;
}

int yesno()
{
	char x;
	bool state;
	
	do{		
		state = true;
		x  = getch();
		x = toupper(x);
		
		if(x != 'Y' && x != 'N')
		{
			state = false;
		}
	
				
	}while(!state);	
		
	if(x == 'Y')
		return 1;
	else if(x == 'N')
		return 0;
	else{
	 	std::cout<<"Coœ sie zepsulo!!"<<std::endl;
	 	return -1;
	}
	
}

bool InputChecker(std::string message)
{
		if(std::cin.rdstate())
		{
			std::cin.clear();
	        std::cin.ignore(1024, '\n');
			system("cls");
			menu();	
	        std::cout<<message<<std::endl;
	        return false;
		}
		else	
			return true;		
}	
