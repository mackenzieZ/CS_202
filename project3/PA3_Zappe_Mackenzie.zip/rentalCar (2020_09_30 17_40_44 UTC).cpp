//Purpose: source file for RentalCar implementation
//Name: rentalCar.cpp
//Author: Mackenzie Zappe
//Date: 2/10/2020

#include "rentalCar.h"
#include "my_string.h"
#include <iostream>
using namespace std;

//Constructors
RentalCar:: RentalCar(){
    m_available = false;
}
RentalCar:: RentalCar(int year, char * make, char * model, float price, bool availabile){

}

//Set Methods
void RentalCar::setYear(int yr){
    m_year = yr;    
}
void RentalCar:: setMake(const char * str){
    strcpy(m_make,str);
}
void RentalCar:: setModel(const char * str){
    strcpy(m_model, str);
}
void RentalCar:: setPrice(float price){
    m_price = price;
}
void RentalCar:: setAvailable(bool open){
    m_available = open; 
}

//Get Methods
int RentalCar:: getYear() const{
    return m_year;
}

const char * RentalCar:: getMake() const{
    return m_make;
}
const char * RentalCar:: getModel() const{
    return m_model;
}


float RentalCar:: getPrice() const{
    return m_price;
}
bool RentalCar:: getAvailability() const{
    return m_available;
}

//Other Methods

void RentalCar:: print() const{
    cout << m_year << " " << m_make << " "<< m_model << ", $"<< m_price << " per day, Available: " << m_available << endl;
}
float RentalCar:: estimateCost(int days){
    int cost = m_price * days;
    return cost;
}
