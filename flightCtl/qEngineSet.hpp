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
    /*  
        qEngineSet manages all the engines.
        Its duties are to 
        - Initialize the GPIO interface
        - Allow the engines to perform their duties
        - Manage collective engine actions (stabilization, etc.)
        - Terminate/Manage GPIO connection when the time is right

     */
    private:
        qEngine quadEngines[4];
        int numEngines; 
        int spinTestMS;
    public:
        qEngineSet();
        int setupEngines();

        void updateLEDMode(int newMode); 
        int* getEngineVals();

        void handleKey(char k, bool shiftMode);
        int stabilize(sensorData inSensorData);
        int terminate();
};

