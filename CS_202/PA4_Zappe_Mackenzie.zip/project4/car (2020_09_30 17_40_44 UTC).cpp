//Purpose: Car Class method implementations
//Name: car.cpp
//Author: Mackenzie Zappe
//Date: 2/21/2020

#include <AgencyModule/car.h>
#include <StringModule/my_string.h>
#include <iostream>
using namespace std;
    Car :: Car(){
        m_sensorCount = 0;
    }
    //Parametarized Constructor
    Car::Car(int yr, const char * make, const char * model, float basePrice){
        strcpy(m_make, make);
        strcpy(m_model,model);
        m_year = yr;
        m_basePrice=basePrice;
        m_sensorCount = 0;

        /*look here for issues!
        Sensor * inventory_ptr = m_sensors;
        for(int i = 0; i < 3; i++, sensor++, inventory_ptr++){
            inventory_ptr->setType(sensor->getType());
            inventory_ptr->setExtraCost(sensor->getExtraCost());
            m_sensorCount++;
        }
        */
    }
    //Ctor Constructor
    Car:: Car(const Car & car){
        strcpy(m_make,car.m_make);
        strcpy(m_model,car.m_make);
        m_year = car.m_year;
        m_basePrice = car.m_basePrice;

    }
    //Getting Functions
    char * Car :: getMake(){
        return m_make;
    }
    char * Car :: getModel(){
        return m_model;
    }
    char * Car:: getOwner(){
        return m_owner;
    }
    int Car :: getYear() const{
        return m_year;
    }
    Sensor * Car :: getSensors(int index){
        Sensor * ptr = m_sensors;
        int i = 0;
        for(; i == index; ptr++, i++);
        return  ptr;
    }
    float Car:: getBasePrice() const{
        return m_basePrice;
    }
    float Car:: getFinalPrice() const{
        return m_finalPrice;
    }
    bool Car:: getAvailable() const{
        return m_available;
    }
    //Setting Functions
    void Car:: setMake(const char * str){
        strcpy(m_make, str);
    }
    void Car:: setModel(const char * str){
        strcpy(m_model,str);
    }
    void Car:: setOwner(const char * str){
        strcpy(m_owner,str);
    }
    void Car:: setYear(int yr){
        m_year = yr;
    }
    void Car:: setBasePrice(float price){
        m_basePrice = price;
    }
    void Car:: setAvailable(bool available){
        m_available = available;
    }
    float Car:: updatePrice(){
        //loop through sensors and add prices to base price
        m_finalPrice = m_basePrice;
        Sensor * sensor_ptr = m_sensors;
        int i = 0;
        for(; i < m_sensorCount;  sensor_ptr++, i++){
        m_finalPrice += sensor_ptr ->getExtraCost();
        }
    return m_finalPrice;
    }
    //Print Function
    void Car:: printCar(){
        m_finalPrice = updatePrice();
        //cout << m_finalPrice <<endl;
        cout << m_year << " " << m_make << " " << m_model << " \tBase: "<< m_basePrice << " With {";
        Sensor * sensorPtr = m_sensors;
        for(int i = 0; i<m_sensorCount; i++, sensorPtr++){
            cout <<sensorPtr->getType() << " ";
        } 
        cout<< "}  :\t" << m_finalPrice << " \tAvailable:"<< m_available << endl;

    }
    //Estimate Price 
    float Car:: estimatePrice(int days){
        float estimate = m_finalPrice * days;
        return estimate; 
    }
    Car & Car:: operator+(Sensor & sNew){
        //go to a point in the sensor inventory and save new sensor in the array
        //car int to keep track of sensors to be index
        if(m_sensorCount > MAX_SENSORS){
            cout << "Too many sensors" << endl;
        }else{
        m_sensors[m_sensorCount].setType(sNew.getType());
        m_sensors[m_sensorCount].setExtraCost(sNew.getExtraCost());
        }
        m_sensorCount++;
        return *this; 
    }
    void Car:: operator+(char * newOwner){
        strcpy(m_owner, newOwner);
        //what else is effected?  availability
        m_available = false;
    }



