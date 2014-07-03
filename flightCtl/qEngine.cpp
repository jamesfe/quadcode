/*
    qEngine - CPP for an engine
    Created by jamesfe

    02JUL2014 - Created

*/


#include "qEngine.hpp"

qEngine::qEngine() {
    ledMode = 0;
}

qEngine::qEngine(int inLEDMode) {
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

