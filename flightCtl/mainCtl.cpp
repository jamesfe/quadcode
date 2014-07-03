/*

    Some wrapper functions for the flight framework
    created by jamesfe

    CHANGELOG
        26MAY2014 - Created
        23JUN2014 - Additional refactor & rename

*/

#include "mainCtl.hpp"

float qEngine::qEngine(int inLEDMode) {
    /* 
        Constructor for an enigne.  ledMode is for debugging.
        ledMode can be {0, 1} - 1 for debugging, 0 for ESC
    */
    ledMode = inLEDMode;
    
}

float qEngine::incPower(float intensity) {
    /* 
        Increase power to qEngine by intensity.
        (TODO: unsure what intensity will be)
    */
    return(-1.0);
}

float qEngine::decPower(float intensity) {
    /* 
        Decrease power to qEngine by intensity.
        (TODO: unsure what intensity will be.)
    */
    return(-1.0);
}

float qEngine::stop() {
    /*
        currPower = 0;
        TODO: set this up
    */
    return(0.0);
}

void qEngineSet::updateLEDMode(int newMode) {
    for(i = 0; i < numEngines; i++) {
        //quadEngines[i].updateLEDMode(newMode);
    }
}

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
    cout << "Hello world!";    
}
