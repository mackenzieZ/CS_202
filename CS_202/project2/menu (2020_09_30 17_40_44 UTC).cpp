//Purpose: header file w/ menu function declarations
//Name: menu.cpp
//Author: Mackenzie Zappe
//Date:1/31/2020

#include "menu.h"
#include <iostream>
using namespace std;

#define NUM_CARS 5

int userMenuPrompt(){
    int userInput;
        cout << "1) Enter File Name" << endl;
        cout << "2) Print Data to Terminal"<< endl;
        cout << "3) Print Data to File"<< endl;
        cout << "4) Sort Cars by Price"<< endl;
        cout << "5) Estimate Cost to Rent" << endl;
        cout << "6) Rent a Car" << endl;
        cout << "7) Exit" << endl;
        cin >> userInput;
        if(userInput > 7 || userInput < 1){
        cout << "Invalid Menu Choice. Try Again." << endl;
        }
return userInput;
}
void readCars(ifstream & input, vehicle * carList){
   for(int i = 0; i < NUM_CARS; i++){
       input >> carList[i].year >> carList[i].make >> carList[i].model >> carList[i].price >> carList[i].available;
   }

}
void printCarsTerminal(vehicle * carList){
    for(int i = 0; i < NUM_CARS; i++){
       cout << i << " " << carList[i].year << " " << carList[i].make << " " << carList[i].model << " " << carList[i].price << " " << carList[i].available << endl;
   }
}
void printCarsFile(ofstream & output,  vehicle * carList){
    for(int i = 0; i < NUM_CARS; i++){
       output  << carList[i].year << " " << carList[i].make << " " << carList[i].model << " " << carList[i].price << " " << carList[i].available << endl;
   }
}
void sortCarsPrice(const vehicle * carsList, vehicle  * carsListSorted){
    for(int i = 0; i < NUM_CARS; i++){
    carsListSorted[i] = carsList[i];
    }
      for (int i=0; i < NUM_CARS; i++){
        for (int j=i; j < NUM_CARS; j++){
            if(carsListSorted[i].price < carsListSorted[j].price){

                vehicle tempC = carsListSorted[i];
                carsListSorted[i] = carsListSorted[j];
                carsListSorted[j] = tempC;
            }
        }
    }
}
void rentalCarQuery( vehicle * carListSorted){
    int daysWanted;
    double adjustedPrice;
    cout << "How many days do you want to rent a car?";
    cin >> daysWanted;
    for(int i = 0; i < NUM_CARS; i ++){
        if(carListSorted[i].available == true){
            adjustedPrice = daysWanted * carListSorted[i].price;
            cout << i << " " << carListSorted[i].year << " " << carListSorted[i].make << " " << carListSorted[i].model << " " << adjustedPrice << " " << carListSorted[i].available << endl;
        }
    }
}
int rentalCarReserve(vehicle * carListSorted){
    int choice, daysWanted;
    double adjustedPrice;
    printCarsTerminal(carListSorted);
    cout << "Which car do you want to rent?";
    cin >> choice;
    if(carListSorted[choice].available == false){
        cout << "Car unavailble for rent. Try again." << endl;
        return 0;
    }else{
    carListSorted[choice].available = false;
    cout << "This car is available for rent!" << endl;
    cout << "How many days do you want to rent a car?";
    cin >> daysWanted;
    adjustedPrice = daysWanted * carListSorted[choice].price;
    cout << "You have rented the " << carListSorted[choice].year << " " << carListSorted[choice].make << " " << carListSorted[choice].model << " for " << daysWanted << "days." << endl;
    cout << "This will cost you $" << adjustedPrice << endl;

    }


return 0;
}

