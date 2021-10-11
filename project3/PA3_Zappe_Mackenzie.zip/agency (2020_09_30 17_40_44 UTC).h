//Purpose: declaration of struct agency
//Name: agency.h
//Author: Mackenzie Zappe
//Date: 2/10/2020

#include "rentalCar.h"
#define MAX_CARS 5
#define MAX_ZIP 5
struct Agency{
 char name[256];
 int zipCode[MAX_ZIP];
 RentalCar carInvetory[MAX_CARS];
};