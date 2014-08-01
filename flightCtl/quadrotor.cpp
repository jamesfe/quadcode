/*
    Quadrotor CPP Stuff
    by jamesfe

    01JUL2014 - Created
*/


//#include "../PIGPIO/pigpio.h"

#include<iostream>


#ifndef quadrotor_hpp
#define quadrotor_hpp
#include "quadrotor.hpp"
#endif

#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
 
int kbhit(void)
{
  struct termios oldt, newt;
  int ch;
  int oldf;
 
  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
 
  ch = getchar();
 
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  fcntl(STDIN_FILENO, F_SETFL, oldf);
 
  if(ch != EOF)
  {
    ungetc(ch, stdin);
    return 1;
  }
 
  return 0;
}


//#include "kbhit.cpp"
using namespace std;

int quadrotor::prepForFlight() {
    // Prepare systems for flight; return flight readiness status
    // -1 is a failure
    // 0 is ready
    int retVal = 0;
    if(usingSensor==true) {
        int sensorSetup;
        sensorSetup = mySensor.initializeSensorHandler();
        if(sensorSetup < 0) {
            retVal = -1;
        }
    }

    if(usingEngines==true) {
        int engineSetup = -1;
        engineSetup = qEngines.setupEngines();
    }

    return(retVal);
}

quadrotor::quadrotor() {
    // Wrapper
    usingSensor = true;
    
}

void quadrotor::dumpAngleDataLoop() {
    while(!kbhit()) {
        cout <<  "hello world." << endl;
    } 
}

void quadrotor::setSensor(bool sensorVal) {
    usingSensor = sensorVal;
}

void quadrotor::setEngines(bool engineVal) {
    usingEngines = engineVal;
}

int quadrotor::postFlight() {
    qEngines.terminate();
}
