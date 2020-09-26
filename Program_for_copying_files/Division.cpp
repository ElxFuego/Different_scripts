#include <iostream>
#include <string>
#include "Division.h"

using namespace std;
Division::Division()
{
            
}
Division::~Division()
{
                     
}
int Division::find_delimiter(string source, string delimiter)
{
    int pos = source.find(delimiter);  
	return(pos);  
	//zwraca pozycje delimitera w danym ciagu znakow           
}
string Division::first_text(int pos, string source)
{
    string token = source.substr(0, pos);
    return token;
	//zwraca pierwszy czlon textu ze zrodla, az do napotkania delimitera           
}
string Division::second_text(int pos, string source, int length)
{
    string token = source.erase(0, pos+length);	
    return token;
	//zwraca drugi czlon textu ze zrodla, usuwajac z calosci textu, pierwszy czlon      
}
