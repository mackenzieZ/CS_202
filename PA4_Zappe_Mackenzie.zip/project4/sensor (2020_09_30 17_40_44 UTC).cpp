//Purpose: Sensor Class source file
//Name: sensor.cpp
//Author: Mackenzie Zappe
//Date: 2/19/2020

#include <AgencyModule/sensor.h>
#include <StringModule/my_string.h>
#include <iostream>

using namespace std; 

#define cCost 10.00
#define gCost 5.00
#define lCost 15.00
#define rCost 20.00

//Static initializations
int Sensor::gps_cnt = 0;
int Sensor :: camera_cnt = 0;
int Sensor :: radar_cnt = 0;
int Sensor :: lidar_cnt = 0;
//default constructor
Sensor::Sensor(){

}
//parametarized constructor
Sensor::Sensor(const char * type){
    if(strcmp("camera", type) == 0){
        camera_cnt++;
        setType(type);
        setExtraCost(cCost);
    }else if(strcmp("radar", type) == 0){
        radar_cnt++;
        setType(type);
        setExtraCost(rCost);
    }else if(strcmp("lidar", type) == 0){
        lidar_cnt++;
        setType(type);
        setExtraCost(lCost);
    }else if(strcmp("gps", type) == 0){
        gps_cnt++;
        setType(type);
        setExtraCost(gCost);
    }else if(strcmp("}", type) == 0){
        //setType("none");
        //setExtraCost(0);
    }
}
//ctor constructor
Sensor :: Sensor(const Sensor &sensor){
    m_extraCost = sensor.m_extraCost;
    strcpy(m_type, sensor.m_type);
    if(strcmp("camera", m_type) == 0){
    camera_cnt++;
    }else if(strcmp("radar", m_type) == 0){
        radar_cnt++;
    }else if(strcmp("lidar", m_type) == 0){
        lidar_cnt++;
    }else if(strcmp("gps", m_type) == 0){
        gps_cnt++;
    }
}

//set functions
void Sensor::setType(const char * str){
    strcpy(m_type, str);
    if(strcmp("camera", m_type) == 0){
    camera_cnt++;
    setExtraCost(cCost);
    }else if(strcmp("radar", m_type) == 0){
        radar_cnt++;
        setExtraCost(rCost);
    }else if(strcmp("lidar", m_type) == 0){
        lidar_cnt++;
        setExtraCost(lCost);
    }else if(strcmp("gps", m_type) == 0){
        gps_cnt++;
        setExtraCost(gCost);
    }else if(strcmp("\0", m_type) ==0){
        setType("none");
        setExtraCost(0);
    }
    
}
void Sensor:: setExtraCost(const float cost){
    m_extraCost = cost;
}

//get functions
float Sensor:: getExtraCost() const{
    return m_extraCost;
}
char * Sensor:: getType(){
    return m_type;
}
int Sensor :: getGpsCt() {
    return gps_cnt;
}
int Sensor ::getCameraCt(){
    return camera_cnt;
}
int Sensor ::getLidarCt(){
    return lidar_cnt;
}
int Sensor ::getRadarCt(){
    return radar_cnt;
}

//reset functions
void Sensor :: resetGpsCt() {
    gps_cnt = 0;
}
void Sensor :: resetCameraCt(){
    camera_cnt = 0;
}
void Sensor :: resetRadarCt(){
    radar_cnt = 0;
}
void Sensor :: resetLidarCt(){
    lidar_cnt = 0;
}
void Sensor :: resetAll(const char * type){
    if(strcmp("camera", m_type) == 0){
    camera_cnt--;
    }else if(strcmp("radar", m_type) == 0){
        radar_cnt--;
    }else if(strcmp("lidar", m_type) == 0){
        lidar_cnt--;
    }else if(strcmp("gps", m_type) == 0){
        gps_cnt--;
    }
    

}
bool Sensor:: operator==(const Sensor & s1) const{
        return strcmp(m_type, s1.m_type);
    }