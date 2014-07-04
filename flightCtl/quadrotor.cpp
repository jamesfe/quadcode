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
    int sensorSetup;
    sensorSetup = mySensor.initializeSensorHandler();
    if(sensorSetup < 0) {
        retVal = -1;
    }

    // TODO: Setup engine & ESC test here

    return(retVal);
}

quadrotor::quadrotor() {
    // Wrapper

}
