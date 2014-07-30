/*
    qEngine - CPP for an engine
    Created by jamesfe

    02JUL2014 - Created
    29JUL2014 - Adding gpio/pigpio interaction
*/

#include<iostream>
#include<unistd.h>

#define qEngine_hpp
#include "qEngine.hpp"
#include "includes.hpp"

using namespace std;

qEngine::qEngine() {
    setDefaults();
}

qEngine::qEngine(int inLEDMode) {
    /* 
        Constructor for an enigne.  ledMode is for debugging.
        ledMode can be {0, 1} - 1 for debugging, 0 for ESC
    */
    setDefaults();
    ledMode = inLEDMode;
}

void qEngine::setDefaults() {
    engineMax = 2000;
    engineMin = 1000;
    ledMode = 0;  // LEDs instead of Engines
    GPIONum = -1; // GPIO Not Set
    sleepTime = 2000;
}

float qEngine::incPower(float intensity) {
    /* 
        Increase power to qEngine by intensity.
    */
    if(ledMode==0) {
        if(currPower+intensity<=engineMax) {
            gpioServo(GPIONum, currPower+intensity);
            currPower = currPower-intensity;
        }
    }

    return(-1.0);
}

float qEngine::decPower(float intensity) {
    /* 
        Decrease power to qEngine by intensity.
    */
    if(ledMode==0) {
        if(currPower-intensity>=engineMin) {
            gpioServo(GPIONum, currPower-intensity);
            currPower = currPower-intensity;
        }
    }
    return(-1.0);
}

float qEngine::stop() {
    /*
        currPower = 0;
    */
    if(ledMode==0) {
        gpioServo(GPIONum, 1000);
    }
    return(0.0);
}

int qEngine::setupForFlight() {
    if(ledMode==1) {
        cout << "LED Mode is on, unable to send GPIO Messages." << endl;
        return(-1);
    }
    if(GPIONum==-1) {
        cout << "GPIO Not set." << endl;
        return(-1);
    }

    int retVal = 0;
    retVal = gpioServo(GPIONum, 1000);
    if(retVal!=0) {
        cout << "There is a problem with the engine on GPIO " << GPIONum << endl;
    }

    // wait for a few seconds while the ESC initializes 
    usleep(sleepTime);
    return(retVal);

}

void qEngine::spinTest(int sec) {
        
}

