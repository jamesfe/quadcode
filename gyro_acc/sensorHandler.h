/*
    Sensor Handler Class - manages the sensor
    Passes a sensorData class back and forth to the flight controller
    Created by jamesfe
    MOD LOG:
        10JUN2014 - Created
    
*/


class sensorHandler {
    private:
        float lastUpdate;
        sensorData currData;
        int needData;        

        int checkDataTime();
    public:
        sensorHandler();
        //sensorData getSensorData();
};

sensorHandler::sensorHandler() {
    lastUpdate = mymillis();
    needData = 0;
}

int sensorHandler::checkDataTime() {
    if(mymillis()-lastUpdate > 20) {
        needData = 1;
    }
}

