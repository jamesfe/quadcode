/*
    qEngine - CPP for an engine
    Created by jamesfe

    02JUL2014 - Created

*/

#include<iostream>

#include "qEngine.hpp"

using namespace std;

qEngine::qEngine() {
    ledMode = 0;
    GPIONum = -1;
}

qEngine::qEngine(int inLEDMode) {
    /* 
        Constructor for an enigne.  ledMode is for debugging.
        ledMode can be {0, 1} - 1 for debugging, 0 for ESC
    */
    ledMode = inLEDMode;
    GPIONum = -1; 
}

qEngine::qEngine(int newGPIONum) {
    GPIONum = newGPIONum;
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
    */
    if(ledMode==0) {
        gpioServo(GPIONum, currPower-intensity);
        currPower = currPower-intensity;
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

int setupForFlight() {
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
    return(retVal);

}
