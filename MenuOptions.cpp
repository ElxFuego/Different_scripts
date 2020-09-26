//szkielet do robienia menu

#include <iostream>
#include <conio.h>

int MenuOptions() {
	
	int choice;
	bool state;
	
	std::cout<<"\n1. Generate Passwords"<<std::endl;
	std::cout<<"2. Exit"<<std::endl;
	

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
								
			default:
				state = false;
				break;
		}
	}while(!state);			
}
