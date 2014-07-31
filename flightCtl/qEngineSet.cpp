/* 
    Quadrotor Engine Set (of 4 engines)
    Created by jamesfe
    
    02JUL2014 - Created

*/

#include<iostream>

#include "qEngineSet.hpp"

using namespace std;

    qEngineSet::qEngineSet() {
    numEngines = 4;
    spinTestMS = 2000;
}

int qEngineSet::setupEngines() {
    int GPIOSet = gpioInitialise();
    if(GPIOSet==PI_INIT_FAILED) {
        cout << "PIGPIO Initialization Failed." << endl;
        return(-1);
    }
    
    // perform spin test
    // this is dangerous!! we need to warn the user.
    for(int i = 0; i < 4; i++) {
        quadEngines[i].stop();
    }
    cout << "DANGER!!!" << endl;
    cout << "About to perform the spin test; connect power supply and " << endl;
    cout << "press enter to continue." << endl;
    cout << "All rotors will spin for some time." << endl;
    char k;
    cin >> k; 
    for(int i = 0; i < 4; i++) {
        quadEngines[i].spinTest(spinTestMS);
    }
}

void qEngineSet::updateLEDMode(int newMode) {
    for(int i = 0; i < numEngines; i++) {
        quadEngines[i].updateLEDMode(newMode);
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

int* qEngineSet::getEngineVals() {
    int eVals[numEngines];
    for(int i = 0; i < numEngines; i++) {
        eVals[i] = quadEngines[i].getPower();
    }    
}

int qEngineSet::stabilize(sensorData inSensorData) {
    /*
     * Stablize the quadcopter.   
     */
}
