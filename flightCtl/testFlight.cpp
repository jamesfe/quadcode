#include<iostream>
#include<string>
#include<algorithm>

#ifndef quadrotor_hpp
#define quadrotor_hpp
#include "quadrotor.hpp"
#endif


using namespace std;

int main(int argc, char* argv[]) {
    bool sensorVal = true;
    bool engineVal = true;
    string thisLower;
    if(argc>1) {
        for(int i = 0; i < argc; i++) {
            thisLower = argv[i];
            transform(thisLower.begin(), thisLower.end(), thisLower.begin(), ::tolower);
            switch(thisLower) {
                case "-nosensor": 
                    sensorVal = false;
                    break;
                case "-noengine":
                    engineVal = false;
                    break;
                case default:
                    break;
            }
            
        }
    }
    else {
        cout << "Usage: flightCtl [options]" << endl;
        cout << " -nosensor : fly without a sensor " << endl;
        cout << " -noengine : init without engines " << endl;
    }
    int flightprep;
    quadrotor myQuad;
    myQuad.setSensor(sensorVal);
    myQuad.setEngines(engineVal);
    myQuad.prepForFlight();


    return(0);
}
