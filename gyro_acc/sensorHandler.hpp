/*
    Sensor Handler Class - manages the sensor
    Passes a sensorData class back and forth to the flight controller
    Created by jamesfe
    MOD LOG:
        10JUN2014 - Created
    
*/

#ifdef __cplusplus
extern "C"{
#endif 

#include "gyro-acc.c"

#ifdef __cplusplus
}
#endif

#include "sensorData.hpp"

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

sensorHandler::sensorHandler() {
    float inFloats[3] = {0.0, 0.0, 0.0};
    //inFloats = {0.0, 0.0, 0.0};
    currData.update(inFloats);
}

int sensorHandler::initializeSensorHandler() {
    // Initialize Everything
    enableIMU();
    float inFloats[3];
    readSensorData(inFloats);
    currData.update(inFloats); 
    lastUpdate = mymillis();    
    needData = 0;
    updateBoundary = 20;
    return(0);
}

int sensorHandler::checkDataTime() {
    // see if we need to update the sensor's data
    if(mymillis()-lastUpdate > updateBoundary) {
        needData = 1;
    }
}

void sensorHandler::updateSensorData() {
    // Read data from the sensor (if necessary)
    checkDataTime();
    if(needData==1) {
        float inFloats[3];
        readSensorData(inFloats);
        currData.update(inFloats);
        lastUpdate = mymillis();
        needData = 0;
    }
}
