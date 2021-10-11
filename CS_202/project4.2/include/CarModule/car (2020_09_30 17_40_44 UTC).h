//Purpose: Car class header file
//Name: car.header
//Author: Mackenzie Zappe
//Date: 2/21/2020


#ifndef CAR_H_
#define CAR_H_

#include <SensorModule/sensor.h>

#define MAX_SIZE 256
#define MAX_SENSORS 3


class Car{
    public:
    Car();
    Car(int yr, const char * make, const char * model, float basePrice);
    Car(const Car &car);

    char * getMake();
    char * getModel(); 
    char * getOwner();
    int getYear() const;
    Sensor * getSensors(int index);
    float getBasePrice() const;
    float getFinalPrice() const;
    bool getAvailable() const;

    void setMake(const char * str);
    void setModel(const char * str);
    void setOwner(const char * str);
    void setYear(int yr);
    void setBasePrice(float price);
    void setAvailable(bool available);

    float updatePrice();

    void printCar();

    float estimatePrice(int days);

    Car & operator+(Sensor & sNew);
    void operator+(char * newOwner);

    private:
    char m_make[MAX_SIZE];
    char m_model[MAX_SIZE];
    char m_owner[MAX_SIZE];
    int m_year;
    Sensor m_sensors[MAX_SENSORS];
    float m_basePrice;
    float m_finalPrice;
    bool m_available;
    int m_sensorCount;

};
#endif