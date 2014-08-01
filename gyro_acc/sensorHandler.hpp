/*
    Sensor Handler Class - manages the sensor
    Passes a sensorData class back and forth to the flight controller
    Created by jamesfe
    MOD LOG:
        10JUN2014 - Created
        02JUL2014 - Broken out to CPP too    
*/

#ifdef __cplusplus
extern "C"{
#endif 

#include "gyro-acc.h"
#include "sensor.h"
//#include "gyro-acc.c"

#ifdef __cplusplus
}
#endif

#ifndef sensorData_hpp
#define sensorData_hpp
#include "sensorData.hpp"
#endif

/*
    TODO:
    One thing we don't have is a method to figure out if the
    sensor is working properly.  Maybe a check for that?
*/

class sensorHandler {
    /*
     * This class represents the sensor as the quadcopter controls it.  
     * We initialize the class, then we call on it (if desired) to 
     * access the sensor and turn it on.  We then call on it from
     * time to time to update the sensor data it holds within it.  
     */
    private:
        float lastUpdate;
        sensorData currData;
        int needData;       
        // How long between updates? - updateBoundary in ms 
        int updateBoundary; 
        int checkDataTime();
    public:
        sensorHandler();
        int initializeSensorHandler();
        void updateSensorData();
        sensorData getCurrentData();
        // gets data in XYZ format
};

