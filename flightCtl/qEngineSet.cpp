/* 
    Quadrotor Engine Set (of 4 engines)
    Created by jamesfe
    
    02JUL2014 - Created

*/

#include<iostream>

#include "qEngineSet.hpp"

using namespace std;

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

int qEngineSet::terminate() {
    float qRet = 0.0;
    for(int i = 0; i < numEngines; i++) {
        qRet+=quadEngines[i].stop();
    }  
    gpioTerminate();
    if(qRet>0) {
        return(1);    
    }
    return(0);
}
