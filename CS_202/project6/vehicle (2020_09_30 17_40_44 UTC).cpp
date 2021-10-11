//Vehicle class implementation code
//Name: vehicle.cpp
//Author: Mackenzie Zappe
//Date: 3/9/2020

#include "vehicle.h"
#include <iostream>
using namespace std;


Vehicle::Vehicle(){

}

Vehicle::Vehicle(float * location){
    setLocation(location);
    cout << "Vehicle: Parametrized Ctor" << endl;
}

Vehicle:: Vehicle(Vehicle & v){
    setLocation(v.getLocation());

}
Vehicle:: ~Vehicle(){
    cout << "Vehicle: dtor" << endl;
}


void Vehicle:: setLocation(float * location){
    float * original = m_lla;
    for(int i = 0; i < 3; i++, original++){
        *original = location[i];
    }
}

float * Vehicle:: getLocation(){
    return m_lla;
}

void Vehicle:: move(float * location){
    setLocation(location);
}

void Vehicle:: serialize(ostream & os){
    float * location_ptr = this -> getLocation();
    os << "Vehicle @ [";
     for(int i = 0; i < 3; i++, location_ptr++){
        os << " " << *location_ptr << " "; 
    }
    os << "]" << endl;
}

void Vehicle:: operator<<(ostream & os){
    serialize(os);
}

Vehicle & Vehicle:: operator=(Vehicle & v){
    float * copy = v.getLocation();
    for(int i = 0; i < 3; i++, copy++){
        setLocation(copy);
    }
    cout << "Vehicle: Assignment" << endl;
}