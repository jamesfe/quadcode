/*

    Loose framework for quadcopter
    created by jamesfe
    CHANGELOG
        26MAY2014 - Created
        23JUN2014 - Refactor, Rearrange, Rename


*/

#include "../PIGPIO/pigpio.h"
#include "../gyro_acc/sensorHandler.hpp"

class selfData {
    
};

class qEngine {
    private:
        float currPower;
        int ledMode;

    public:

        qEngine(int inLEDMode);
        float incPower(float intensity);
        float decPower(float intensity);
        float stop();
        float getPower();
        void updateLEDMode(int newMode);
};

class qEngineSet {
    private:
        qEngine quadEngines[4];
     
    public:
        float stabilize(selfData inSensorData);
        float* getEngineVals();
        void updateLEDMode(int newMode); 
};

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

