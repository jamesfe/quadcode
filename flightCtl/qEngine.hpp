/*

    qEngine - Component of qEngineSet
    Created by jamesfe

    02JUL2014 - Created

*/
/*
#ifdef __cplusplus
extern "C" {
#endif
#include "../PIGPIO/pigpio.h"
#ifdef __cplusplus
}
#endif
*/
class qEngine {
    private:
        int currPower;
        int ledMode;
        int GPIONum;
        int engineMax;
        int engineMin;
        int sleepTime;

    public:
        qEngine();
        qEngine(int inLEDMode);

        // some default parameters common to all constructors
        void setDefaults();
        void setGPIO(int newGPIO);

        int setupForFlight();
        
        int incPower(int intensity);
        int decPower(int intensity);
        int stop();
        int getPower();
        void updateLEDMode(int newMode);
        void spinTest(int sec);


};

