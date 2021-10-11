//Purpose: Car source code file
//Name: car.cpp
//Author: Mackenzie Zappe
//Date: 3/2/2020



#include <my_car/car.h>
//#include <iostream>
#include <cstring>
//using namespace std;

Car:: Car()
: m_throttle(0), m_plates("defaultName")
{

    cout << "Car #" << getVin() << ": Default-ctor" << endl;
}
Car:: ~Car(){
    cout << "Car #" << getVin() << ": Dtor" << endl;
}

Car::Car(char * str, const int vin, float * lla)
: Vehicle(vin, lla), m_throttle(0)
{
    setPlates(str);
    cout << "Car #" << getVin() <<": Parametrized-ctor" << endl;
}
Car:: Car(Car & c)
: Vehicle()
{
    setPlates(c.getPlates());
    setLla(c.getLla());
    setThrottle(c.getThrottle());
    cout << "Car #" << getVin() <<": Copy-ctor" << endl;
}


Car & Car::operator=(Car & c){
    this->setThrottle(c.getThrottle());
    this->setPlates(c.getPlates());
    this->setLla(c.getLla());
    cout << "Car # " << this->getVin() << ": Assignment" << endl;
}

int Car:: getThrottle() const{
    return m_throttle;
}
char * Car:: getPlates(){
    return m_plates;
}

void Car:: setThrottle(int throttle){
    m_throttle = throttle;
}
void Car:: setPlates(char * str){
    strcpy(m_plates,str);
}
void Car:: drive(int throttle){
    m_throttle = throttle;
}
void Car:: move(float * newLocation){
    cout << "Car #" << getVin() << ": DRIVE to destination, with throttle @ 75" << endl;
    drive(75);
    setLla(newLocation);
}

//Friend methods
ostream & operator <<(ostream & os, Car & c){
    cout << "Car #" << c.getVin() << " Plates: " << c.getPlates() << " Throttle: " << c.getThrottle() << " @ [";
    float * location_ptr = c.getLla();
    for(int i = 0; i < 3; i++, location_ptr++){
        os << " " << *location_ptr << " "; 
    }
    os << " ]" << endl;
}