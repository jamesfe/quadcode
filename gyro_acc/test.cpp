/*
    Test Module for funcitonalized module
    Created by jamesfe
    CHANGELOG
        26MAY2014 - Created

*/
#ifdef __cplusplus
extern "C"{
#endif 

#include "gyro-acc.c"

#ifdef __cplusplus
}
#endif

#include<stdio.h>

class sensorData {
    private:
        float axisAngles[3];
    public:
        float* getAxisAngles();
};

float* sensorData::getAxisAngles() {
    return(&axisAngles);
}

class sensorHandler {
    private:
        float lastUpdate;
        sensorData currData;
        int needData;        

        sensorHandler();
        int checkDataTime();
        

    public:
        sensorData getSensorData();
};

void sensorHandler::sensorHandler() {
    lastUpdate = mymillis();
    needData = 0;
}

int sensorHandler::checkDataTime() {
    if(mymillis()-lastUpdate > 20):
        needData = 1;
}
// TODO: FINISH THESE CLASSES


int main() {
    printSensorData();
    return(0);
}
