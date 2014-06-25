/*

    Sensor Data class - holds an array of three.
    Created by jamesfe
    MOD LOG:
        10JUN2014 - Created


*/

#include<array>

using namespace std;

class sensorData {
    /*
        sensorData is an object that we can pass between the portions
        of the quadcode in order to package the three angles
        and allow various access to them. 
    */
    private:
        array<float,3> axisAngles;
    public:
        sensorData(array<float,3> &inAxisAngles);   // done
        sensorData();                               //done
        array<float,3> getAxisAngles();             // done
        void update(float *inFloat);
};

array<float,3> sensorData::getAxisAngles() {
    return(axisAngles);
}

sensorData::sensorData(array<float,3> &inAxisAngles) {
    // Initialize data to k
    axisAngles = inAxisAngles;
}

sensorData::sensorData() {
    // initialize to null
    axisAngles = {0.0, 0.0, 0.0};
}

void sensorData::update(float *inFloat) {
    // sets axisAngles to input data
    axisAngles[0] = inFloat[0];
    axisAngles[1] = inFloat[1];
    axisAngles[2] = inFloat[2];
}
