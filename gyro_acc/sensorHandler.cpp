/*
    sensorHandler - CPP code
    Created by jamesfe

    02JUL2014 - Created

*/

#ifndef sensorHandler_hpp
#define sensorHandler_hpp
#include "sensorHandler.hpp"
#endif

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

sensorData sensorHandler::getCurrentData() {
    updateSensorData();
    return(currData);
}
