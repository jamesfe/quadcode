quadcode
========

Quadcopter Code


This code is a working project in the initial stages to build a flight engine for a quadcopter.

Currently the sensor is a 3-axis acc/gyro/mag called a MinIMU-9 v2 from Pololu.
http://www.pololu.com/product/1268

The board is a Raspberry Pi 2011.12 running the following:
Linux raspberrypi 3.6.11+ #456 PREEMPT Mon May 20 17:42:15 BST 2013 armv6l GNU/Linux

I am using code to gather information from the Gyro that was written by Mark Williams:
http://ozzmaker.com/2013/04/29/guide-to-interfacing-a-gyro-and-accelerometer-with-a-raspberry-pi/

Also I am going to use piGPIO to control the ESCs.


