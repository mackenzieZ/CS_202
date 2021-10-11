//Purpose: source code file for implementations of menu functions
//Name: menu.cpp
//Author: Mackenzie Zappe
//Date: 2/10/2020

#include "my_string.h"
#include "menu.h"

#include <iostream>
#include <fstream>
using namespace std;

int userMenuPrompt(){
    int userInput;
        cout << "*****CAR MENU*****"<< endl;
        cout << "1) Enter File Name" << endl;
        cout << "2) Print Data to Terminal"<< endl;
        cout << "3) Estimate Rental Cost "<< endl;
        cout << "4) Find Cheapest Rental"<< endl;
        cout << "5) Reserve Car" << endl;
        cout << "6) Exit" << endl;
        cin >> userInput;
        if(userInput > 7 || userInput < 1){
        cout << "Invalid Menu Choice. Try Again." << endl;
        }
return userInput;
}
void readCars(ifstream & input, Agency * agency_ptr){
    RentalCar * agencyCar_ptr = agency_ptr -> carInvetory;
    while(!input.eof()){
    for(int i = 0; i < 3 ; i++){
        char tempName[256];
        int tempZip;
        int array[5];
        input >> tempName;
        input >> tempZip;
        strcpy(agency_ptr->name, tempName);
        convert(tempZip, array);

        for(int k =0; k<5;k++){
            agency_ptr->zipCode[k] = array[k];
        }

        for(int j = 0; j < MAX_CARS; j++,++agencyCar_ptr){
            int year;
            float price;
            char make[256];
            char model[256]; 
            bool available;
            input >> year >> make  >> model >> price >> available;
            agencyCar_ptr->setYear(year);
            agencyCar_ptr-> setMake(make);
            agencyCar_ptr->setModel(model);
            agencyCar_ptr->setPrice(price);
            agencyCar_ptr->setAvailable(available);
            
        
        }
        cout<<i<<endl;
        agency_ptr++;
    }
    }
}

void convert(int temp, int * arrVers){

    do{
        for(int i = 0; i < 5; i++){
        temp % 10;
        temp /= 10;
        *arrVers= temp;
        arrVers++;
        }
    }while(temp/10 !=0);
}
void printAgenciesTerminal(Agency * agency_ptr){
    cout<<"entering print()"<<endl;
    RentalCar * agencyCar_ptr = agency_ptr -> carInvetory;

    for(int i=0; i < 3; i++){
        cout << i+1 << " " << agency_ptr->name << " "<< agency_ptr->zipCode << endl;
        for(int j=0; j < MAX_CARS; j++){
            cout << j+1 << " ";
            agencyCar_ptr->print();
        }
    }
}
int estimateRentalCost(){
    Agency listAgencies[3];
    Agency * agency_ptr = listAgencies;
    RentalCar * agencyCar_ptr = agency_ptr -> carInvetory;


    int agencyChoice, carChoice, daysWanted, i, j;
    cout << "Enter an Agency: ";
    cin >> agencyChoice;
    cout << "Enter a car: ";
    cin >> carChoice;
    cout << "Enter how many days you want to rent the car:";
    cin >> daysWanted;
    while(i < agencyChoice){
        agency_ptr++;
    }
    while(j < carChoice){
        agencyCar_ptr++;
    }
    return agencyCar_ptr->estimateCost(daysWanted);
}
void findCheapestDeal(){
    Agency listAgencies[3];
    Agency * agency_ptr = listAgencies;
    RentalCar * agencyCar_ptr = agency_ptr -> carInvetory;
    
    RentalCar * compare_ptr = agencyCar_ptr++;
    RentalCar currentCheap = *agencyCar_ptr;
    RentalCar compare = *compare_ptr;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < MAX_CARS; j++){
            if(currentCheap.getAvailability()== false){
                agencyCar_ptr++;
                compare_ptr++;
            }else if(compare.getAvailability()==false){
                compare_ptr++;
            }else{
                if(currentCheap.getPrice() > compare.getPrice()){
                    currentCheap = compare;
                    compare_ptr++;
                }
                compare_ptr++;
            }
            
        }
    agency_ptr++;
    }
    currentCheap.print();

}
void reserveCar(){
    Agency listAgencies[3];
    Agency * agency_ptr = listAgencies;
    RentalCar * agencyCar_ptr = agency_ptr -> carInvetory;


    int agencyChoice, carChoice, daysWanted, i, j;
    cout << "Enter an Agency: ";
    cin >> agencyChoice;
    cout << "Enter a car: ";
    cin >> carChoice;
    cout << "Enter how many days you want to rent the car:";
    cin >> daysWanted;
    while(i < agencyChoice){
        agency_ptr++;
    }
    while(j < carChoice){
        agencyCar_ptr++;
    }

    if(agencyCar_ptr->getAvailability()==false){
        cout << "Im sorry, the car selected is unavailable. Try again." << endl;
    }else{
        agencyCar_ptr->setAvailable(true);
    }

}
