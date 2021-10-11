//Purpose: Vehicle class source file
//Name: vehicle.cpp
//Author: Mackenzie Zappe
//Date: 2/29/2020

#include <my_vehicle/vehicle.h>
#include <iostream>
#include <string>

using namespace std;

int Vehicle:: s_idgen = 0;

Vehicle::Vehicle()
: m_vin(s_idgen++)
{
    float temp[3] = {0.0, 0.0, 0.0};
    setLla(temp);
    cout << "Vehicle #" << getVin() <<": Default-ctor" << endl;
}
Vehicle::Vehicle(int vin, float * location)
: m_vin(vin <= s_idgen ? s_idgen++ : vin)
{
    setLla(location);
    cout << "Vehicle #" << getVin() <<": Parametrized-ctor" << endl;
}
Vehicle::Vehicle(Vehicle & v)
: m_vin(s_idgen++)
{
    float * temp = v.getLla();
    this->setLla(temp);
    cout << "Vehicle #" << getVin() <<": Copy-ctor" << endl;
}
Vehicle:: ~Vehicle(){
    cout << "Vehicle #" << getVin() <<": Dtor" << endl;
}

Vehicle & Vehicle:: operator=(Vehicle & v){
    this->setLla(v.getLla());
    cout << "Vehicle #" << getVin() << ": Assignment" << endl;
}
//Setting Methods
void Vehicle:: setLla(float * temp){
    float * original = m_lla;
    for(int i = 0; i < 3; i++, original++){
        *original = temp[i];
    }
}
//Getting Methods
int Vehicle:: getVin() const{
    return m_vin;
}
float * Vehicle:: getLla() {
    return m_lla;
}

//Move Function
void Vehicle:: move(float * newLocation){
    cout << "Vehicle #" << getVin() << ": CAN'T MOVE - IDK HOW" << endl;
}

int Vehicle:: getIdgen(){
    return s_idgen;
}

// friend methods
ostream & operator<<(ostream & os, Vehicle &v){
    float * location_ptr = v.getLla();
    os << "Vehicle # " << v.getVin() << " @ [ ";
    for(int i = 0; i < 3; i++, location_ptr++){
        os << " " << *location_ptr << " "; 
    }
    os << " ]" << endl;
    return os; 
}