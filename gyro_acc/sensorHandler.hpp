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


class sensorHandler {
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
};

