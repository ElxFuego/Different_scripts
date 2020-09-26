#include <iostream>
#include <conio.h>

using namespace std;

int menuOptions() {
	
	int choice;
	bool state;
	
	cout<<"\n1. Copy files"<<endl;
	cout<<"2. Create settings file"<<endl;
	cout<<"3. Delete settings file"<<endl;
	cout<<"4. Exit"<<endl;
	

	do{
		
		choice = getch();
		state = true;
	
		switch(choice)
		{
			case '1':
			
				return 1;
				break;
				
			case '2':
			
				return 2;
				break;
				
			case '3':
			
				return 3;
				break;
				
			case '4':
			
				return 4;
				break;	
				
			default:
				state = false;
				break;
		}
	}while(!state);
		
			
	
}
