//Purpose: header file for declarations of menu functions
//Name: menu.h
//Author: Mackenzie Zappe
//Date: 2/10/2020



#ifndef MENU_H_
#define MENU_H_

#include <fstream>
#include "agency.h"

int userMenuPrompt();
void readCars(std::ifstream & input, Agency * agency_ptr);
void convert(int temp, int * arrVers);
void printAgenciesTerminal(Agency * agency_ptr);
int estimateRentalCost();
void findCheapestDeal();
void reserveCar();


#endif