
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

