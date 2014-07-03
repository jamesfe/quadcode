/*
    Quadrotor Code
    Created by jamesfe

    02JUL2014 - Created
*/

#include "includes.hpp"

class quadrotor {

    private:
        qEngineSet qEngines;
        // some sensor set
        sensorHandler mySensor;

    public: 
        quadrotor(); 
        int prepForFlight();
        void enterKeyControlLoop();
            // a function where a user controls with a laptop

};

