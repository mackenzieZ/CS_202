//Purpose: source code file w/ main() function
//Name:proj2.cpp
//Author: Mackenzie Zappe
//Date:1/31/2020

#include "str.h"
#include "menu.h"
#include <iostream>
using namespace std;

#define FILE_MAX 100
#define NUM_CARS 5

int main(){

    vehicle carListRaw[NUM_CARS];
    vehicle carListSorted[NUM_CARS];
    ifstream input;
    ofstream output;
    char inputDoc[FILE_MAX];
    char outputDoc[FILE_MAX];

int menuChoice;

do{
menuChoice = userMenuPrompt();
switch(menuChoice){
    case 1:
        cout << "Enter the input file name" << endl;
        cin >> inputDoc;
        input.open(inputDoc);
        readCars(input, carListRaw);
    break;
    case 2:
        printCarsTerminal(carListRaw);
    break;
    case 3:
        cout << "Enter the output file name" << endl;
        cin >> outputDoc;
        output.open(outputDoc);
        printCarsFile(output, carListRaw);
    break;
    case 4:
        sortCarsPrice(carListRaw, carListSorted);
        printCarsTerminal(carListSorted);
    break;
    case 5:
        rentalCarQuery(carListSorted);
    break;
    case 6:
        rentalCarReserve(carListSorted);
    break;
}
}while(menuChoice != 7);


input.close();
output.close();
return 0;    
}