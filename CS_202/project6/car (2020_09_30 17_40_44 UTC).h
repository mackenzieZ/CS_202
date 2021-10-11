//Purpose: Car class header file
//Name: car.h 
//Author: Mackenzie Zappe
//Date: 3/10/2020

#include "vehicle.h"

class Car : public Vehicle{

    public:
    Car();
    Car(float * location);
    Car( Car & c);
    virtual ~Car();

    Car & operator=(Car & c);

    int getThrottle() const;
    void setThrottle(int throttle);

    void drive(int value);

    virtual void move(float * location);

    

    private:
    int m_throttle;
    virtual void serialize(ostream & os);

};