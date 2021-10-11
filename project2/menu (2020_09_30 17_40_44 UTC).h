//Purpose: header file w/ menu function declarations
//Name: menu.h
//Author: Mackenzie Zappe
//Date:1/31/2020
#ifndef MENU_H_
#define MENU_H_

#include <fstream>
#include<iostream>
using namespace std;

#define MAX_SIZE 10

struct vehicle{
    int year;
    char make[MAX_SIZE];
    char model[MAX_SIZE];
    double price;
    bool available; 
};


int userMenuPrompt();
void readCars(ifstream & input, vehicle * carList);
void printCarsTerminal(vehicle * carList);
void printCarsFile(ofstream & output, vehicle * carsList);
void sortCarsPrice(const vehicle * carList,vehicle * carListSorted);
void rentalCarQuery(vehicle * carListSorted);
int rentalCarReserve(vehicle * carListSorted);




#endif
