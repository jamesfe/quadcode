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
        float currPower;
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

        int setupForFlight();
        
        float incPower(float intensity);
        float decPower(float intensity);
        float stop();
        float getPower();
        void updateLEDMode(int newMode);
        void spinTest(int sec);

};

