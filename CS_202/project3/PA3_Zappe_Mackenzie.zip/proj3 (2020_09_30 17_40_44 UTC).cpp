//Purpose: Source Code file w/ main()
//Name:proj.cpp
//Author: Mackenzie Zappe
//Date: 2/10/2020

#include <iostream>
#include <fstream>

#include "menu.h"

using namespace std;

#define FILE_MAX 100

int main(){

char inputDoc[FILE_MAX]; 
ifstream input;
int menuChoice;

Agency listAgencies[3];


do{
menuChoice = userMenuPrompt();
switch(menuChoice){
    case 1:
        cout << "Enter the input file name" << endl;
        cin >> inputDoc;
        input.open(inputDoc);
        cout << "in case 1"<< endl;
        readCars(input, listAgencies);
    
    break;
    case 2:
        printAgenciesTerminal(listAgencies);
    break;
    case 3:
        printAgenciesTerminal(listAgencies);
        estimateRentalCost();
    break;
    case 4:
        findCheapestDeal();
    break;
    case 5: 
        printAgenciesTerminal(listAgencies);
        reserveCar();
    break;
}
}while(menuChoice != 6);

input.close();

return 0;
}