/*

    Sensor Data class - holds an array of three.
    Created by jamesfe
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
        sensorData(array<float,3> &inAxisAngles);       // done
        array<float,3> getAxisAngles();     // done
};

array<float,3> sensorData::getAxisAngles() {
    return(axisAngles);
}

sensorData::sensorData(array<float,3> &inAxisAngles) {
    // Initialize data to k
    axisAngles = inAxisAngles;
}
