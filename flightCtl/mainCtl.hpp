// Loose framework for quadcopter
// created by jamesfe
// 26MAY2014 - Created


class quadrotor {

    private:
        engineSet engines;
        // some sensor set

    public:  

        void enterKeyControlLoop();
            // a function where a user controls with a laptop

};

class engine {
    private:
        float currPower;
        int ledMode;

    public:

        engine(int inLEDMode);
        float incPower(float intensity);
        float decPower(float intensity);
        float stop();
        float getPower();
        void updateLEDMode(int newMode);
};

class engineSet {
    private:
        engine quadEngines[4];
     
    public:
        float stabilize(selfData inSensorData);
        float* getEngineVals();
        void updateLEDMode(int newMode); 
};

class selfData {
    
};
