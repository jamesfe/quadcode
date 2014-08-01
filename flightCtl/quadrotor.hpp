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

        //TODO: queue sensor history
        sensorHandler mySensor;
        bool usingSensor;
        bool usingEngines;
    public: 
        quadrotor(); 
        int prepForFlight();
        int postFlight();

        // a function where a user controls with a laptop
        void enterKeyControlLoop();
        void dumpAngleDataLoop();
        
        // Below two functions modify whether or not we
        // are going to use engines or sensors
        void setSensor(bool sensorVal);
        void setEngines(bool engineVal);

};

