//Car header file
//Name: car.h
//Author: Mackenzie Zappe
//Date: 3/2/2020

#ifndef CAR_H_
#define CAR_H_

#include <my_vehicle/vehicle.h>

#define MAX_SIZE 256

class Car : public Vehicle{
    public:
    Car();
    Car(char * str, int vin, float * location);
    Car(Car & c);
    ~Car();
    Car & operator=(Car &c);

    int getThrottle() const;
    char * getPlates();

    void setPlates(char * str);
    void setThrottle(int throttle);

    void drive(int throttle);

    void move(float * newLocation);

    friend ostream & operator<<(ostream & os, Car & c);


    private:
    char m_plates[MAX_SIZE];
    int m_throttle;

};

#endif