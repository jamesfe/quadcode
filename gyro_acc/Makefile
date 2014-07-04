#all:
#	gcc -o gyro-acc-testmod -l rt gyro-acc.c -lm
CC=g++
CFLAGS=-std=c++11 -L./ -L../PIGPIO
testmod:
	gcc -l rt gyro-acc.c -lm

test:
	gcc -c -w *.c
	g++ -c $(CFLAGS) *.cpp
	g++ -o main $(CFLAGS) *.o 
	rm test.o
	cp *.o ../flightCtl/
#	rm main


