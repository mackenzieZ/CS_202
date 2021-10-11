//Purpose: Vehicle header file
//Name: vehicle.header
//Author: Mackenzie Zappe
//Date: 2/29/2020

#ifndef VEHICLE_H_
#define VEHICLE_H_


#include <iostream>
using namespace std;

class Vehicle{
    public:
    Vehicle();
    Vehicle(int vin, float * location);
    Vehicle(Vehicle & v);
    ~Vehicle();

    Vehicle & operator=(Vehicle & v);

    //void setVin(int vin);
    void setLla(float * temp);

    int getVin() const;
    float * getLla();

    void move(float * newLocation);

    static int getIdgen();

    friend ostream & operator <<(ostream & os, Vehicle & v1);

    protected:
    float m_lla[3];
    const int m_vin;

    private:
    static int s_idgen;
};

#endif