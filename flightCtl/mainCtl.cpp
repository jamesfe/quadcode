// Some wrapper functions for the flight framework
// created by jamesfe
// CHANGELOG
//      26MAY2014 - Created

#include "mainctl.h"

float engine::engine(int inLEDMode) {
    /* 
        Constructor for an enigne.  ledMode is for debugging.
        ledMode can be {0, 1} - 1 for debugging, 0 for ESC
    */
    ledMode = inLEDMode;
    
}

float engine::incPower(float intensity) {
    /* 
        Increase power to engine by intensity.
        (TODO: unsure what intensity will be)
    */
    return(-1.0);
}

float engine::decPower(float intensity) {
    /* 
        Decrease power to engine by intensity.
        (TODO: unsure what intensity will be.)
    */
    return(-1.0);
}

float engine::stop() {
    /*
        currPower = 0;
        TODO: set this up
    */
    return(0.0);
}

void engineSet::updateLEDMode(int newMode) {
    for(i = 0; i < numEngines; i++) {
        //quadEngines[i].updateLEDMode(newMode);
    }
}
