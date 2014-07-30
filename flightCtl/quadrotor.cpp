/*
    Quadrotor CPP Stuff
    by jamesfe

    01JUL2014 - Created
*/


//#include "../PIGPIO/pigpio.h"

#include<iostream>

#ifndef quadrotor_hpp
#define quadrotor_hpp
#include "quadrotor.hpp"
#endif

using namespace std;

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

    // perform spin test
    // this is dangerous!! we need to warn the user.
    cout << "About to perform the spin test; press enter to continue." << endl;
    cout << "All rotors will spin for a second." << endl;
    char k;
    cin >> k; 



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

int quadrotor::postFlight() {
    qEngines.terminate();
}
