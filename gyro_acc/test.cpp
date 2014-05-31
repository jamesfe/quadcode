/*
    Test Module for funcitonalized module
    Created by jamesfe
    CHANGELOG
        26MAY2014 - Created
        30MAY2014 - More modifications, framework
*/
#ifdef __cplusplus
extern "C"{
#endif 

#include "gyro-acc.c"

#ifdef __cplusplus
}
#endif

#include<stdio.h>
#include <array>

using namespace std;


class sensorData {
    /*
        sensorData is an object that we can pass between the portions
        of the quadcode in order to package the three angles
        and allow various access to them. 
    */
    private:
        array<float,3> axisAngles;
    public:
        sensorData(array<float,3> &inAxisAngles);       // done
        array<float,3> getAxisAngles();     // done
};

array<float,3> sensorData::getAxisAngles() {
    return(axisAngles);
}

sensorData::sensorData(array<float,3> &inAxisAngles) {
    // Initialize data to k
    axisAngles = inAxisAngles;
}

class sensorHandler {
    private:
        float lastUpdate;
        sensorData currData;
        int needData;        

        int checkDataTime();
        

    public:
        //sensorHandler();
        //sensorData getSensorData();
};
/*
sensorHandler::sensorHandler() {
    lastUpdate = mymillis();
    needData = 0;
}
*/
int sensorHandler::checkDataTime() {
    if(mymillis()-lastUpdate > 20) {
        needData = 1;
    }
}
// TODO: FINISH THESE CLASSES


int main() {
    printSensorData();
    return(0);
}
