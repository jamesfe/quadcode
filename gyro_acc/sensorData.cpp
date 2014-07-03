/*
    sensorData class def
    Created by jamesfe

    02JUL2014 - Created

*/


#ifndef sensorData_hpp
#define sensorData_hpp
#include "sensorData.hpp"
#endif

array<float,3> sensorData::getAxisAngles() {
    return(axisAngles);
}

sensorData::sensorData(array<float,3> &inAxisAngles) {
    // Initialize data to k
    axisAngles = inAxisAngles;
}

sensorData::sensorData() {
    // initialize to null
    axisAngles = {0.0, 0.0, 0.0};
}

void sensorData::update(float *inFloat) {
    // sets axisAngles to input data
    axisAngles[0] = inFloat[0];
    axisAngles[1] = inFloat[1];
    axisAngles[2] = inFloat[2];
}
