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

        int checkDataTime();
    public:
        sensorHandler();
        //sensorData getSensorData();
};

sensorHandler::sensorHandler() {
    enableIMU();
    float inFloats[3];
    printSensorData(inFloats);
    currData.update(inFloats); 
    lastUpdate = mymillis();    
    needData = 0;
}

int sensorHandler::checkDataTime() {
    if(mymillis()-lastUpdate > 20) {
        needData = 1;
    }
}

