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

    public:
        qEngine();
        qEngine(int inLEDMode);
        
        float incPower(float intensity);
        float decPower(float intensity);
        float stop();
        float getPower();
        void updateLEDMode(int newMode);
};

