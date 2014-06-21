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
        void updateSensorData();
};

sensorHandler::sensorHandler() {
    // Initialize Everything
    enableIMU();
    float inFloats[3];
    readSensorData(inFloats);
    currData.update(inFloats); 
    lastUpdate = mymillis();    
    needData = 0;
    updateBoundary = 20;
}

int sensorHandler::checkDataTime() {
    
    if(mymillis()-lastUpdate > updateBoundary) {
        needData = 1;
    }
}

void sensorHandler::updateSensorData() {
    float inFloats[3];
    readSensorData(inFloats);
    currData.update(inFloats);
    lastUpdate = mymillis();
    needData = 0;
}
