//Purpose: Agency class header file
//Name: agency.h
//Author: Mackenzie Zappe
//Date: 2/23/2020

#ifndef AGENCY_H_
#define AGENCY_H_

#define MAX_SIZE 256
#define MAX_CARS 5
#include <CarModule/car.h>
using namespace std;

class Agency{
    public:
    Agency();
    Agency(char * str, int zip);
    Agency(const Agency &a1);

    void setName(char * str);
    void setZip(int zip);
    void setInventory(Car * inventory);

    char * getName();
    int getZip() const;
    Car * getInventory();

    Car & operator[](int index);
    void readAllData();
    void printActiveSensors() const;
    void printData();
    void printAllCars();
    void printAvailableCars();
    void  reserveOne();

    private:
    char m_name[MAX_SIZE];
    int m_zipCode;
    Car carInventory[5];
};
#endif
