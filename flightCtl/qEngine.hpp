/*

    qEngine - Component of qEngineSet
    Created by jamesfe

    02JUL2014 - Created

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

