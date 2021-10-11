//Vehicle class implementation code
//Name: vehicle.cpp
//Author: Mackenzie Zappe
//Date: 3/9/2020

#include <my_vehicle/vehicle.h>
#include <iostream>
using namespace std;


Vehicle::Vehicle(){
    cout << "Vehicle: Default Ctor"<< endl;
}

Vehicle::Vehicle(float * location){
    SetLLA(location);
    cout << "Vehicle: Parametrized Ctor" << endl;
}

Vehicle:: Vehicle(Vehicle & v){
    SetLLA(v.getLocation());

}
Vehicle:: ~Vehicle(){
    cout << "Vehicle: Dtor" << endl;
}


void Vehicle:: SetLLA(float * location){
    float * original = m_lla;
    for(int i = 0; i < 3; i++, original++){
        *original = location[i];
    }
}

float * Vehicle:: getLocation(){
    return m_lla;
}

void Vehicle:: Move(float * location){
    SetLLA(location);
}

void Vehicle:: serialize(ostream & os){
    float * location_ptr = this -> getLocation();
    os << "Vehicle @ [";
     for(int i = 0; i < 3; i++, location_ptr++){
        os << " " << *location_ptr << " "; 
    }
    os << "]" << endl;
}

ostream & operator<<(ostream & os, Vehicle & v){
    v.serialize(os);
}

Vehicle & Vehicle:: operator=(Vehicle & v){
    float * copy = v.getLocation();
    for(int i = 0; i < 3; i++, copy++){
        SetLLA(copy);
    }
    cout << "Vehicle: Assignment" << endl;
}
