/*
    Test Module for funcitonalized module
    Created by jamesfe
    CHANGELOG
        26MAY2014 - Created
        30MAY2014 - More modifications, framework
        10JUN2014 - Broke CPP, H files out leaving only shell
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
#include "sensorData.h"
#include "sensorHandler.h"

using namespace std;

int main() {
    printSensorData();
    return(0);
}
