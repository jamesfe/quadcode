/* 
    Quadrotor Engine Set (of 4 engines)
    Created by jamesfe
    
    02JUL2014 - Created

*/

#include "qEngineSet.hpp"

void qEngineSet::updateLEDMode(int newMode) {
    for(int i = 0; i < this->numEngines; i++) {
        //quadEngines[i].updateLEDMode(newMode);
    }
}

qEngineSet::qEngineSet() {
    numEngines = 4;
    
}

int qEngineSet::setupEngines() {
    int GPIOSet = gpioInitialise();
    if(GPIOSet==PI_INIT_FAILED) {
        cout << "PIGPIO Initialization Failed." << endl;
        return(-1);
        
    }
}
