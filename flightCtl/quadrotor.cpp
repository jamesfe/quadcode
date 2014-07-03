/*
    Quadrotor CPP Stuff
    by jamesfe

    01JUL2014 - Created
*/


#include "../PIGPIO/pigpio.h"

#ifndef sensorHandler_hpp
#define sensorHandler_hpp
#include "../gyro_acc/sensorHandler.hpp"
#endif

#ifndef selfData_hpp
#define selfData_hpp
#include "selfData.hpp"
#endif

#ifndef qEngineSet_hpp
#define qEngineSet_hpp
#include "qEngineSet.hpp"
#endif

#include "quadrotor.hpp"



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
