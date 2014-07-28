/*
    Quadrotor CPP Stuff
    by jamesfe

    01JUL2014 - Created
*/


//#include "../PIGPIO/pigpio.h"


#ifndef quadrotor_hpp
#define quadrotor_hpp
#include "quadrotor.hpp"
#endif

int quadrotor::prepForFlight() {
    // Prepare systems for flight; return flight readiness status
    // -1 is a failure
    // 0 is ready
    int retVal = 0;
    if(usingSensor==true) {
        int sensorSetup;
        sensorSetup = mySensor.initializeSensorHandler();
        if(sensorSetup < 0) {
            retVal = -1;
        }
    }

    if(usingEngines==true) {
        int engineSetup = -1;
        engineSetup = qEngines.setupEngines();
    }

    return(retVal);
}

quadrotor::quadrotor() {
    // Wrapper
    usingSensor = true;
    
}

void quadrotor::setSensor(bool sensorVal) {
    usingSensor = sensorVal;
}

void quadrotor::setEngines(bool engineVal) {
    usingEngines = engineVal;
}
