/*Purpose: Vehicle class header file
Name: vehicle.h
Author: Mackenzie Zappe
Date: 3/9/2020
*/


#include <iostream>
using namespace std;

class Vehicle{
    public:
    Vehicle();
    Vehicle(float * location);
    Vehicle(Vehicle & v);
    virtual ~Vehicle();

    Vehicle & operator=(Vehicle & v);
    void operator<<(ostream & os);


    void setLocation(float * location);
    float * getLocation();

    virtual void move(float * loacation) = 0;


    protected:
    float m_lla[3];

    private:
    virtual void serialize(ostream & os);
};