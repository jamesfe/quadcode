#all:
#	gcc -o gyro-acc-testmod -l rt gyro-acc.c -lm
CC=g++
CFLAGS=-static -std=c++11 -L./ -L../PIGPIO -L../gyro-acc
testmod:
	gcc -l rt gyro-acc.c -lm

test:
	g++ -c *.cpp $(CFLAGS) 
	g++ -o main $(CFLAGS) *.o 
#	rm main


