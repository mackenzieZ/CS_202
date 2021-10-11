//Purpose: testing main
#include <iostream>
#include <fstream>
#include <StringModule/my_string.h>
#include <MenuModule/menu.h>
//#include <AgencyModule/agency.h>
using namespace std;
#define FILE_MAX 256

int main(){

Agency a1;
int menuChoice;

do{
menuChoice = userMenuPrompt();
switch(menuChoice){
    case 1:
        //readIn(a1);
        a1.readAllData();
    break;
    case 2:
        printAll(a1);
        a1.printAllCars();  
    break;     
    case 3:
        printFiltered(a1);  
        a1.printAvailableCars();      
    break;
    case 4:
        a1.reserveOne();    
        //reserveOne(a1);
    break;
}
}while(menuChoice != 5);

return 0;
}