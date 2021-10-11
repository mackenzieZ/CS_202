//Purpose: Car implementation file
//Name: car.cpp
//AUthor: Mackenzie Zappe
//Date: 3/10/2020

#include "car.h"

Car::Car(){
    cout << "Car: Default-ctor" << endl;
}
Car::Car(float * location)
: m_throttle(0)
{
    Vehicle(location);
    cout << "Car: Parameterized-Ctor"<< endl;

}
Car::Car(Car & c)
:   m_throttle(c.getThrottle())
{
    cout << "Car: copy-Ctor" << endl;
}

Car:: ~Car(){
    cout << "Car: Dtor" << endl;
}

Car & Car:: operator=(Car & c){
    setThrottle(c.getThrottle());
}

int Car ::getThrottle() const{
    return m_throttle;
}
void Car:: setThrottle(int throttle){
    m_throttle = throttle;
}

void Car:: drive(int value){
    setThrottle(value);
}

void Car:: move(float * location){
    drive(75);
    cout << "Car: DRIVE to destination, with throttle @ " << getThrottle() << endl;
    
}