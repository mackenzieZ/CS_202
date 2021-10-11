//Purpose: Car implementation file
//Name: car.cpp
//AUthor: Mackenzie Zappe
//Date: 3/10/2020

#include <my_car/car.h>

Car::Car()
: Vehicle()
{
    cout << "Car: Default-ctor" << endl;
}
Car::Car(float * location)
: Vehicle(location), m_throttle(0)
{
    //SetLLA(location);
    cout << "Car: Parameterized-Ctor"<< endl;

}
Car::Car(Car & c)
:   Vehicle(c.getLocation()), m_throttle(c.getThrottle())
{
    //SetLLA(c.getLocation());
    cout << "Car: copy-Ctor" << endl;
}

Car:: ~Car(){
    cout << "Car: Dtor" << endl;
}

Car & Car:: operator=(Car & c){
    setThrottle(c.getThrottle());
    SetLLA(c.getLocation());
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

void Car:: Move(float * location){
    drive(75);
    cout << "Car: DRIVE to destination, with throttle @ " << getThrottle() << endl;

}

void Car:: serialize(ostream & os){
    float * location_ptr = getLocation();
    os << "Car: Throttle: " << getThrottle() << " [";
    for(int i = 0; i < 3; i++, location_ptr++){
        os << " " << *location_ptr << " "; 
    }
    os << "]" << endl;
}
