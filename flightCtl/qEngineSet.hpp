/*
    qEngineSet
    Created by jamesfe

    02JUL2014 - Created
*/

#include "qEngine.hpp"

#ifndef selfData_hpp
#define selfData_hpp
#include "selfData.hpp"
#endif

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

