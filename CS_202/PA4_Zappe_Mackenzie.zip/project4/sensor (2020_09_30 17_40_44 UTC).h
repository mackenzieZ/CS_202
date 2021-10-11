//Purpose: Sensor Class Header File 
//Name: sensor.h
//Author: Mackenzie Zappe
//Date: 2/19/2020

#define MAX_CHARS 256

class Sensor{
    public:
    Sensor();
    Sensor(const char * type);
    Sensor(const Sensor &sensor);

    void setType(const char * str);
    void setExtraCost(const float cost);
    
    char * getType(); 
    float getExtraCost() const;
    static int getGpsCt();
    static int getCameraCt();
    static int getLidarCt();
    static int getRadarCt();

    void resetGpsCt();
    void resetCameraCt();
    void resetLidarCt();
    void resetRadarCt();
    void resetAll(const char * type);

    bool operator==(const Sensor & s1) const;



    private:
    char m_type[MAX_CHARS];
    float m_extraCost;
    static int gps_cnt;
    static int camera_cnt;
    static int lidar_cnt;
    static int radar_cnt;

};
