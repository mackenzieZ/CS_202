//Purpose: Menu source code File
//Name: menu.cpp
//Author: Mackenzie Zappe
//Date: 2/25/2020

#include <MenuModule/menu.h>
#define FILE_MAX 256

#include <iostream>
#include <fstream>
using namespace std;

int userMenuPrompt(){
    int userInput;
        cout << "*****CAR MENU*****"<< endl;
        cout << "1) Enter File Name" << endl;
        cout << "2) Print All Data to Terminal"<< endl;
        cout << "3) Print Available Cars "<< endl;
        cout << "4) Reserve a Car"<< endl;
        cout << "5) Exit" << endl;
        cin >> userInput;
        if(userInput > 7 || userInput < 1){
        cout << "Invalid Menu Choice. Try Again." << endl;
        }
return userInput;
}
void readIn(Agency a1){
    a1.readAllData();
}
void printAll(Agency a1){
    a1.printData();
    //a1.printAllCars();
}
void printFiltered(Agency a1){
    //a1.printAvailableCars();
}
void reserveOne(Agency a1, int choice){
    Car * carPtr = a1.getInventory();
    for(int i = 0; i < choice; i++, carPtr++){
        if(!carPtr->getAvailable()){
            cout << "Car unavailable"<<endl;
            return;
        }else{
            carPtr->setAvailable(0);
            char newOwner[MAX_SIZE];
            cout << "Enter the name of the lessee:";
            cin >> newOwner;
            carPtr->setOwner(newOwner);
        }
    }
    printAll(a1);
}
