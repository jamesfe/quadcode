/*
    qEngineSet
    Created by jamesfe

    02JUL2014 - Created
    28JUL2014 - Modding to add pigpiod

*/

//#include "qEngine.hpp"
// used to include selfdata
#define qEngineSet_hpp
#include "includes.hpp"

class qEngineSet {
    private:
        qEngine quadEngines[4];
        int numEngines; 
    public:
        qEngineSet();
        float stabilize(selfData inSensorData);
        float* getEngineVals();
        void updateLEDMode(int newMode); 
};

